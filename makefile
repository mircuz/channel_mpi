CC = mpicc
CFLAGS = /usr/local/fri/complex.o /usr/local/fri/fft.o /usr/local/fri/parallel.o /usr/local/fri/rbmat.o 


all: translation compilation

translation:

	/usr/local/fri/fri /usr/local/fri/cpl channel_mpi.cpl

compilation: 

	$(CC) -O3 -fPIC -c convol_trasp.c
	$(CC) -O3 -fPIC -c fft_support.c
	$(CC) -O3 -fPIC -c channel_mpi.c
	#$(CC) -O3 -fPIC -c fft_functions.c
	$(CC) -O3 -fPIC -c dnsdata.c
	$(CC) -O3 -fPIC -c rbmatmod.c

	$(CC) $(CFLAGS) -o exe channel_mpi.o convol_trasp.o fft_support.o dnsdata.o rbmatmod.o -lfft3dmpi -lm 
		#Ricordarsi dnsdirect.o !!


clean: 
	rm convol_trasp.c channel_mpi.c dnsdata.c rbmatmod.c
	rm *.o
	rm *.d
	rm exe
	rm Runtimedata

