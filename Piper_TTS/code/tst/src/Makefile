


CC = gcc
CXX =  g++ -std=c++17 -lstdc++
LD =   g++ -std=c++17  -lstdc++
INC =
LIB =



CFLAGS =  -Wall

INCLUDE= $(INC) -I/usr/src/piper_tts/cpp -I/usr/src/piper_tts/pi/include 

LIB_PATH_pi = /usr/src/piper_tts/pi/lib



LIB_SO =  -lonnxruntime -lpiper_phonemize -lespeak-ng

LO = main.o piper.o


pipers: $(LO)
	$(LD) -o pipers $(LO) -L$(LIB_PATH_pi)  $(LIB_SO) -Wl,--copy-dt-needed-entries -Wl,-rpath=$(LIB_PATH_pi) -lm -lpthread  /usr/lib/x86_64-linux-gnu/libpthread.a

piper.o: piper.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) -c piper.cpp -o piper.o

main.o: main.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) -c main.cpp -o main.o


clean:
	rm pipers *.o *.wav

