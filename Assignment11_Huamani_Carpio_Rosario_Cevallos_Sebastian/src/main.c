
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "animal_game.h"
#include "binary_tree_io.h"
#include "binary_tree.h"

// Program entry point
int main()
{

    while (true){
    play("src/input.txt", stdin);
    }
    //
    // binary_tree* left = binary_tree_create_s("left");
    // binary_tree* right = binary_tree_create_s("right");
    //
    // binary_tree* leaf = binary_tree_create_stt("lmao", left, right);
    // int height = binary_tree_height(leaf);
    //
    // binary_tree* leftchild = binary_tree_get_left(leaf);
    // int heightLeft = binary_tree_height(leftchild);
    // printf("%d\n",heightLeft );



    //open input file for reading (aka the game)
    // FILE *input_file = fopen("src/input.txt", "r");

    //make binary tree with input file
    // binary_tree* tree = binary_tree_create_f(input_file);

    // char *get = NULL;
    // char *q = binary_tree_get_string(tree, get);
    // printf("%s <== should be the question", q);


    //binary_tree *l = binary_tree_create();
    // binary_tree *r = binary_tree_create_s("right");
    // binary_tree *t = binary_tree_create_stt("test", l, r);
    //
    // bool a = binary_tree_is_empty(l);
    // printf("%d \n ^should be 1", a);

    // binary_tree_write(tree, stdout);

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
