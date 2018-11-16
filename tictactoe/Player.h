#pragma once

#include <cstdint>

struct Player {
	char symbol; // 1 byte
	uint16_t color; // 2 bytes
	bool isComputer; // 1 byte
	unsigned long long wins; // 8 bytes
	unsigned long long losses; // 8 bytes
	unsigned long long ties; // 8 bytes
	// total: 28 bytes

	Player(char symbol, uint16_t color);
};