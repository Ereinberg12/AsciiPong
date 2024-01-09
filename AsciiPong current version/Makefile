compiler = g++
flags = -g -Wall -std=c++11 -pthread
compile = $(compiler) $(flags)

asciiPong: asciiPong.cpp PongManager.cpp Ball.cpp PlayGame.cpp screensToPrint.cpp
	$(compile) asciiPong.cpp PongManager.cpp Ball.cpp PlayGame.cpp screensToPrint.cpp -o asciiPong
 
 .PHONY: clean
clean:
	rm -rf *.o asciiPong