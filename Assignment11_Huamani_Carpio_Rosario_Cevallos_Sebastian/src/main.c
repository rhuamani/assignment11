
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "animal_game.h"
#include "binary_tree_io.h"
#include "binary_tree.h"

// Program entry point
// Just calls play
int main()
{
    // intro to the game!
    printf("Welcome to the Animals game! \n");
    play("src/input.txt", stdin);
    return EXIT_SUCCESS;
}
