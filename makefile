CCX = mpicxx
CC = mpicc
CFLAGS = /usr/local/fri/complex.o /usr/local/fri/fft.o /usr/local/fri/rbmat.o 
OPTFLAGS= -O2 -fPIC -march=native
HDF5_LIB= -L/home/mirco/Scrivania/hdf5/lib /home/mirco/Scrivania/hdf5/lib/libhdf5_hl.a /home/mirco/Scrivania/hdf5/lib/libhdf5.a \
			-lz -ldl -lm -Wl,-rpath -Wl,/home/mirco/Scrivania/hdf5/lib -I/usr/local/include -pthread -Wl,-rpath -Wl,/usr/local/lib \
			-Wl,--enable-new-dtags -L/usr/local/lib -lmpi
REMAP_LIB= /home/mirco/Scrivania/fftmpi-1Oct18/src/libfft3dmpi.a 

all: translation exe

translation:
	/usr/local/fri/fri /usr/local/fri/cpl channel_mpi.cpl

initialization.o: initialization.c 
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
	$(CCX) $(CFLAGS) -o exe channel_mpi.o initialization.o convol_trasp.o fft_support.o data_man.o dnsdata.o dnsdirect.o $(REMAP_LIB) $(HDF5_LIB)
		#--> Executable ready <--
		#--> run as mpiexec -n "#procs" exe <--

remove_useless:
	rm convol_trasp.c initialization.c channel_mpi.c dnsdata.c data_man.c dnsdirect.c
	rm *.o
	rm *.d

clear:
	rm Runtimedata
	rm results/Field.h5
	rm results/time_out

clean: 
	make remove_useless
	rm exe
	rm results/Field.h5
	rm results/time_out
	rm Runtimedata

