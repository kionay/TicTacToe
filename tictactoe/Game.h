#pragma once
class Game
{
	private:
		int boardDimensionX;
		int boardDimensionY;

	public:
		Game() : Game(3) {};		// default value of 3x3 board
		Game(int boardDimension);
		Game(int dimensionX, int dimensionY);
		~Game();
};

