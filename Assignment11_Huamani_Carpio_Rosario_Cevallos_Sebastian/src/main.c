// TODO: Add Javadoc style header

#include <stdlib.h>
#include <stdio.h>
// TODO: You will probably need to add more includes...
#include <string.h>

// Program entry point
int main()
{
    printf("Welcome to the Animals game!\n");

    char test[100];
    char *word = "QDoes it moo?";
    
    char *rest = *word[1];
    printf("s <-- should be Does it moo? \n", rest);

    // TODO: Add the game...

    return EXIT_SUCCESS;
}
