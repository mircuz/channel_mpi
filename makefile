CCX = mpicxx
CC = mpicc
CFLAGS = /usr/local/fri/complex.o /usr/local/fri/fft.o /usr/local/fri/rbmat.o 


all: translation compilation linking

translation:
	/usr/local/fri/fri /usr/local/fri/cpl channel_mpi.cpl

compilation: 
	$(CC) -O3 -fPIC -c initialization.c
	$(CC) -O3 -fPIC -c convol_trasp.c
	$(CC) -O3 -fPIC -c fft_support.c
	$(CC) -O3 -fPIC -c data_man.c
	$(CC) -O3 -fPIC -c channel_mpi.c
	$(CC) -O3 -fPIC -c dnsdata.c
	$(CC) -O3 -fPIC -c dnsdirect.c

linking:	
	$(CCX) $(CFLAGS) -O3 -o exe channel_mpi.o initialization.o convol_trasp.o fft_support.o data_man.o dnsdata.o dnsdirect.o /home/mirco/Scrivania/fftmpi-1Oct18/src/libfft3dmpi.a -L/home/mirco/Scrivania/hdf5/lib /home/mirco/Scrivania/hdf5/lib/libhdf5_hl.a /home/mirco/Scrivania/hdf5/lib/libhdf5.a -lz -ldl -lm -Wl,-rpath -Wl,/home/mirco/Scrivania/hdf5/lib -I/usr/local/include -pthread -Wl,-rpath -Wl,/usr/local/lib -Wl,--enable-new-dtags -L/usr/local/lib -lmpi
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
	rm results/time_out
	rm Runtimedata

