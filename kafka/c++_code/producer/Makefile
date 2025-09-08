


CC = gcc
CXX = g++ -std=c++17 -lstdc++
LD = g++ -std=c++17  -lstdc++
INC =
LIB =



CFLAGS =  -Wall

INCLUDE= $(INC) -I/usr/src/so/include 
LIB_PATH = /usr/src/so/lib
LIB_SO =  -lrdkafka++ -lrdkafka -lpthread -lz -lssl -lcrypto -lsasl2


LO = main.o

gv: $(LO)
	$(LD) -o gv $(LO) -L$(LIB_PATH)  $(LIB_SO)  -Wl,--copy-dt-needed-entries -Wl,-rpath=$(LIB_PATH) -lm -lpthread  /usr/lib/x86_64-linux-gnu/libpthread.a

main.o: main.c
	$(CXX) $(CFLAGS) $(INCLUDE) -c main.c -o main.o

clean:
	rm gv *.o

