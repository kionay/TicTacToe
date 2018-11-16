# TicTacToe
An unnecessarily overengineered game of tic-tac-toe.

input can be config file location
or it can be all command line inputs
config file contains effectively those command line inputs

inputs are like:

-p == --Player

--Player x green	// one player using the symbol 'x' and the color green
--Player o blue	// one player using the symbol 'o' and the color blue
--Player r blue 	// error, a player already is using that color
--Player x red	// error, a player is already using that symbol
--Player cha red	// error, symbols must be a single non-whitespace character
--Player red	// error, a symbol must be provided
--Player y	// one player using the symbol y and a color not used by any other player

( 7 player max as there are 7 available colors)

-b == --Board

--Board 3	// 3x3 grid
--Board 2,3	// 2x3 grid
--Board		// 3x3 grid default
--Board a,3	// error
--Board smile	// error
