CCX = mpicxx
CC = mpicc
INCLUDEFILES = /usr/local/fri/complex.o /usr/local/fri/fft.o /usr/local/fri/rbmat.o 
FFTW_LIB = -lfftw3_mpi -lfftw3 -lm
HDF5_LIB = -L/home/mirco/Scrivania/hdf5/lib /home/mirco/Scrivania/hdf5/lib/libhdf5_hl.a \
			/home/mirco/Scrivania/hdf5/lib/libhdf5.a -lz -ldl -lm -Wl,-rpath -Wl,/home/mirco/Scrivania/hdf5/lib \
			-I/usr/local/include -pthread -Wl,-rpath -Wl,/usr/local/lib -Wl,--enable-new-dtags -L/usr/local/lib -lmpi
#OPTFLAGS = -O2 -fPIC -march=native
OPTFLAGS = -O2 -fPIC 

all: translation exe

translation: channel_mpi.cpl
	/usr/local/fri/fri /usr/local/fri/cpl channel_mpi.cpl
initialization.o: 
	$(CC) $(OPTFLAGS) -c initialization.c 
convol_trasp.o: convol_trasp.c
	$(CC) $(OPTFLAGS) -c convol_trasp.c
fft_support.o: fft_support.c
	$(CC) $(OPTFLAGS) -c fft_support.c
data_man.o: data_man.c
	$(CC) $(OPTFLAGS) -c data_man.c
channel_mpi.o: channel_mpi.c
	$(CC) $(OPTFLAGS) -c channel_mpi.c
dnsdata.o: dnsdata.c
	$(CC) $(OPTFLAGS) -c dnsdata.c
dnsdirect.o: dnsdirect.c
	$(CC) $(OPTFLAGS) -c dnsdirect.c

exe: channel_mpi.o dnsdata.o dnsdirect.o data_man.o fft_support.o convol_trasp.o initialization.o	
	$(CCX) $(INCLUDEFILES) -o exe channel_mpi.o initialization.o fft_support.o data_man.o dnsdata.o convol_trasp.o dnsdirect.o \
		 							/home/mirco/Scrivania/fftmpi-1Oct18/src/libfft2dmpi.so $(FFTW_LIB) $(HDF5_LIB)
		#--> Executable ready <--
		#--> run as mpiexec -n "#procs" exe <--

remove_useless:
	rm *.o
	rm *.d
	rm convol_trasp.c initialization.c channel_mpi.c dnsdata.c data_man.c dnsdirect.c

clean: 
	make remove_useless
	rm exe
	#rm results/Field.h5
	rm Runtimedata
	rm results/time_out

