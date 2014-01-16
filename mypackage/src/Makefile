OBJECTS = LYC-SocketPackage

all : $(OBJECTS)

PKG_NAME=docs 

LYC-SocketPackage: main.o
	$(CC) $(LDFLAGS) $^ -o $@ 

main.o:main.c  
	$(CC) $(CFLAGS)  -c $< 

.PHONY:clean
clean:
	@-rm *.o LYC-SocketPackage
