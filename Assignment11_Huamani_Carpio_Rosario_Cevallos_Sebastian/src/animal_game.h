// TODO: Use this file for your game logic.
#include "binary_tree.h"

// Function that determines if user inputted string begins with a y, indicating yes
//
// @param str user inputted string response
bool affirmative_answer(char* str);

//
binary_tree* play_round(FILE* stream, binary_tree* tree);
void play(char* input, FILE* stream, char* output);
