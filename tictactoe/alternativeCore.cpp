#include "Game.h"
#include "ParameterEngine.h"



int main(int arc, char* argv[]) {
	ParameterEngine engine = ParameterEngine(arc, argv);
	int * parameterDimensions = engine.renderedBoardDimensions;
	//retrieve other must-have information from the engine
	//pass that information to the game's setup
	Game TicTacToe = Game(parameterDimensions[0], parameterDimensions[1]);
	//setup the rest of the game's parameters (players, board, etc)
	//start the game
}