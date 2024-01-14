compiler = g++
flags = -g -Wall -std=c++11 -pthread
compile = $(compiler) $(flags)


AsciiPong: Game/AsciiPong.cpp Game/PongManager.cpp Game/Ball.cpp Game/PlayGame.cpp Game/ScreensToPrint.cpp TerminalCommands/TerminalCommands.cpp StartGameAnimation/LargeTextLibrary.cpp StartGameAnimation/LargeTextScreen.cpp StartGameAnimation/ParseStringIntoWords.cpp StartGameAnimation/StartGameAnimation.cpp
	$(compile) Game/AsciiPong.cpp Game/PongManager.cpp Game/Ball.cpp Game/PlayGame.cpp Game/ScreensToPrint.cpp TerminalCommands/TerminalCommands.cpp StartGameAnimation/LargeTextLibrary.cpp StartGameAnimation/LargeTextScreen.cpp StartGameAnimation/ParseStringIntoWords.cpp StartGameAnimation/StartGameAnimation.cpp -o AsciiPong

 .PHONY: clean
clean:
	rm -rf *.o AsciiPong

