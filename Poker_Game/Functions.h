#pragma once
#include <iostream>
#include "Card.h"

// Clear screen command based on OS
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

// Function declarations
unsigned int mainMenu();
void displayCardsSideBySide(const std::vector<Card>& cards);