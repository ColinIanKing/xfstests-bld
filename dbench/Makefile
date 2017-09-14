VERSION=4.00

srcdir=.


prefix=/usr/local
exec_prefix=${prefix}
bindir=${exec_prefix}/bin
mandir=${prefix}/share/man
datadir=/root/xfstests/lib
INSTALLCMD=/usr/bin/install -c
LIBS= -L/home/king/xfstests-bld/bld/lib -lpopt

CC=gcc
CFLAGS=-g -O2 -I/home/king/xfstests-bld/bld/include -Wall -W -I. -DVERSION=\"$(VERSION)\" -DDATADIR=\"$(datadir)\"
LDFLAGS=-static
EXEEXT=

DB_OBJS = fileio.o util.o dbench.o child.o system.o snprintf.o
TB_OBJS = sockio.o util.o dbench.o child.o socklib.o snprintf.o
SRV_OBJS = util.o tbench_srv.o socklib.o

all: dbench tbench tbench_srv

dbench: $(DB_OBJS)
	$(CC) -o $@ $(LDFLAGS) $(DB_OBJS) $(LIBS)

tbench: $(TB_OBJS)
	$(CC) -o $@ $(LDFLAGS) $(TB_OBJS) $(LIBS)

tbench_srv: $(SRV_OBJS)
	$(CC) -o $@ $(LDFLAGS) $(SRV_OBJS) $(LIBS)

# Careful here: don't install client.txt over itself.
install: all
	${INSTALLCMD} -d $(bindir) $(datadir) $(mandir)
	${INSTALLCMD} dbench tbench tbench_srv $(bindir)
	${INSTALLCMD} client.txt $(datadir)
	${INSTALLCMD} -m644 dbench.1 $(mandir)
	ln -sf dbench.1 $(mandir)/tbench.1
	ln -sf dbench.1 $(mandir)/tbench_srv.1

clean:
	rm -f *.o *~ dbench tbench tbench_srv

proto:
	./mkproto.pl *.c > proto.h
