#pragma once
struct ParameterEngine
{
public:
	int renderedBoardDimensions[2];
	//detail other functions for retrieving data by command line
	//if that data is a file path we'll use another class to handle file IO, it'll probably be a small class if C++ will hold ours hands
	ParameterEngine(int argumentCount, char* argumentVector[]);
	~ParameterEngine();
};

