LOADLIBES+=-lm

channel : .cpl/channel.o /usr/local/fri/complex.o /usr/local/fri/fft.o /usr/local/fri/rbmat.o  /usr/local/fri/parallel.o .cpl/dnsdata.o .cpl/rbmatmod.o .cpl/dnsdirect.o
	$(CC) $(LDFLAGS) -o channel .cpl/channel.o /usr/local/fri/complex.o /usr/local/fri/fft.o /usr/local/fri/rbmat.o  /usr/local/fri/parallel.o .cpl/dnsdata.o .cpl/rbmatmod.o .cpl/dnsdirect.o $(LOADLIBES) $(LDLIBS)

.cpl/channel.c .cpl/channel.d : channel.cpl /usr/local/fri/complex.cpl /usr/local/fri/fft.cpl /usr/local/fri/rbmat.cpl /usr/local/fri/matrix.cmn /usr/local/fri/parallel.cpl dnsdata.cpl rbmatmod.cpl dnsdirect.cpl