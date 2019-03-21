CC = /home/mirco/Scrivania/hdf5/bin/h5pcc
CFLAGS = /usr/local/fri/complex.o /usr/local/fri/fft.o /usr/local/fri/rbmat.o 


all: translation compilation

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
	
	$(CC) $(CFLAGS) -O3 -o exe channel_mpi.o initialization.o convol_trasp.o fft_support.o data_man.o dnsdata.o dnsdirect.o -lfft3dmpi -lm 
		#--> Executable ready <--
		#--> run as mpiexec -n "#procs" exe <--

clean: 
	rm convol_trasp.c initialization.c channel_mpi.c dnsdata.c data_man.c dnsdirect.c
	rm *.o
	rm *.d
	rm Runtimedata
	rm exe

