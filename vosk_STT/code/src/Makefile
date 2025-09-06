


CC = gcc
CXX =  g++ -std=c++17 -lstdc++
LD =   g++ -std=c++17  -lstdc++
INC =
LIB =



CFLAGS =  -Wall

INCLUDE= $(INC) -I/usr/src/vosk_stt/include 
LIB_PATH = /usr/src/vosk_stt/lib


LIB_SO =  -lvosk

LO = main.o 


vosks: $(LO)
	$(LD) -o vosks $(LO) -L$(LIB_PATH)  $(LIB_SO) -Wl,--copy-dt-needed-entries -Wl,-rpath=$(LIB_PATH) -lm -lpthread -ldl  /usr/lib/x86_64-linux-gnu/libpthread.a


main.o: main.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) -c main.cpp -o main.o


clean:
	rm vosks *.o

