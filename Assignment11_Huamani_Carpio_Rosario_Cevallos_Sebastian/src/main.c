
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "animal_game.h"
#include "binary_tree_io.h"
#include "binary_tree.h"

// Program entry point
int main()
{

    // play("src/input.txt", stdin);
    //
    //open input file for reading (aka the game)
    FILE *input_file = fopen("src/input.txt", "r");

    //make binary tree with input file
    binary_tree* tree = binary_tree_create_f(input_file);

    char *get = NULL;
    get = binary_tree_get_string(tree, get);
    printf("%s <== should be the question", get);


    //binary_tree *l = binary_tree_create();
    // binary_tree *r = binary_tree_create_s("right");
    // binary_tree *t = binary_tree_create_stt("test", l, r);
    //
    // bool a = binary_tree_is_empty(l);
    // printf("%d \n ^should be 1", a);

    binary_tree_write(tree, stdout);

    // binary_tree *gl = binary_tree_get_left(t);
    // char *gotten = binary_tree_get_string(gl, "lol");


    // binary_tree_destroy(t);
    // bool a = t == NULL;


    // typedef struct test{
    //   char value[MAX_STRING_SIZE];
    // } test;
    //
    // test t;




    return EXIT_SUCCESS;
}
