#include "pch.h"
#include "Game.h"

//write other functions that the game performs (ergo the game loop will be implemented here)

Game::Game(int boardDimension)
{
	this->boardDimensionX = boardDimension;
	this->boardDimensionY = boardDimension;
}

Game::Game(int dimensionX, int dimensionY)
{
	this->boardDimensionX = dimensionX;
	this->boardDimensionY = dimensionY;
}

Game::~Game()
{
}
