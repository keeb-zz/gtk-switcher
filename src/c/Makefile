GCC=g++
PREFIX=/usr/local
CFLAGS=-O2 -Wall $(shell pkg-config --cflags gtk+-2.0)
LIBS = $(shell pkg-config --libs gtk+-2.0)
PYTHON=-I/usr/include/python2.6 

all: refresh.c
	${GCC} -fpic -c refresh.c ${CFLAGS} ${LIBS} ${PYTHON}
	${GCC} refresh.o -fpic -shared ${CFLAGS} ${LIBS} -o refresh.so


	

clean:
	rm refresh.o
	rm refresh.so

