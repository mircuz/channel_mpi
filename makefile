CCX = mpicxx
CC = mpicc
CFLAGS = /usr/local/fri/complex.o /usr/local/fri/fft.o /usr/local/fri/rbmat.o 
#OPTFLAGS = -O2 -fPIC -march=native
OPTFLAGS = -O2 -fPIC

all: translation compilation linking

translation:
	/usr/local/fri/fri /usr/local/fri/cpl channel_mpi.cpl

compilation: 
	$(CC) $(OPTFLAGS) -c initialization.c
	$(CC) $(OPTFLAGS) -c convol_trasp.c
	$(CC) $(OPTFLAGS) -c fft_support.c
	$(CC) $(OPTFLAGS) -c data_man.c
	$(CC) $(OPTFLAGS) -c channel_mpi.c
	$(CC) $(OPTFLAGS) -c dnsdata.c
	$(CC) $(OPTFLAGS) -c dnsdirect.c

linking:	
	$(CCX) $(CFLAGS) $(OPTFLAGS) -o exe channel_mpi.o initialization.o fft_support.o data_man.o dnsdata.o convol_trasp.o dnsdirect.o /home/mirco/Scrivania/fftmpi-1Oct18/src/libfft2dmpi.so
	make remove_useless
		#--> Executable ready <--
		#--> run as mpiexec -n "#procs" exe <--

remove_useless:
	rm *.o
	rm *.d
	rm convol_trasp.c initialization.c channel_mpi.c dnsdata.c data_man.c dnsdirect.c

clean: 
	rm exe
	#rm results/Field.h5
	rm Runtimedata
	rm results/time_out

