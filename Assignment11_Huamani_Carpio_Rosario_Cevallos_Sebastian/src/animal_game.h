#include "binary_tree.h"

// Function that determines if user inputted string begins with a y, indicating yes
//
// @param str user inputted string response
bool affirmative_answer(char* str);

// Function that asks player for answer and does appropriate behavior
//
// @param stream file to read/write
// @param tree to get questions/answers from
// @return updated tree
binary_tree* play_round(FILE* stream, binary_tree* tree);

// Function that plays the rounds of the game according to player input
//
// @param text file name to read from & write from
// @param stream to read/write from/to
void play(char* text, FILE* stream);
