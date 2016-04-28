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
    char *word = "";
    printf("%zu <--should be zero", strlen(word));
    char *word2 = "    ";
    printf("%zu <-- should be four", strlen(word2));

    // TODO: Add the game...

    return EXIT_SUCCESS;
}
