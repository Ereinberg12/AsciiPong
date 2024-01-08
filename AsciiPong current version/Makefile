compiler = g++
flags = -g -Wall -std=c++11 -pthread
compile = $(compiler) $(flags)

asciiPong: asciiPong.cpp PongManager.cpp Ball.cpp PlayGame.cpp
	$(compile) asciiPong.cpp PongManager.cpp Ball.cpp PlayGame.cpp -o asciiPong
 
 .PHONY: clean
clean:
	rm -rf *.o asciiPong