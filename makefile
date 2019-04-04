CCX = mpicxx
CC = mpicc
CFLAGS = /usr/local/fri/complex.o /usr/local/fri/fft.o /usr/local/fri/rbmat.o 
OPTFLAGS = -O2 -fPIC -march=native


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
	$(CCX) $(CFLAGS) $(OPTFLAGS) -o exe channel_mpi.o initialization.o convol_trasp.o fft_support.o data_man.o dnsdata.o dnsdirect.o /home/mirco/Scrivania/fftmpi-1Oct18/src/libfft3dmpi.a -L/home/mirco/Scrivania/hdf5/lib /home/mirco/Scrivania/hdf5/lib/libhdf5_hl.a /home/mirco/Scrivania/hdf5/lib/libhdf5.a -lz -ldl -lm -Wl,-rpath -Wl,/home/mirco/Scrivania/hdf5/lib -I/usr/local/include -pthread -Wl,-rpath -Wl,/usr/local/lib -Wl,--enable-new-dtags -L/usr/local/lib -lmpi
	make remove_useless
		#--> Executable ready <--
		#--> run as mpiexec -n "#procs" exe <--

remove_useless:
	rm convol_trasp.c initialization.c channel_mpi.c dnsdata.c data_man.c dnsdirect.c
	rm *.o
	rm *.d

clean: 
	rm exe
	rm results/Field.h5
	rm results/convol_trasp_profile
	rm results/profiler*
	rm Runtimedata
	rm results/time_out
	

