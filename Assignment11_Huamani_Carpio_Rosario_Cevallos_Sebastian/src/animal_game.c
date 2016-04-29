// TODO: Use this file for your game logic.

#include <stdio.h>
#include "binary_tree.h"
#include "binary_tree_io.h"

struct animal_game {


};
bool affirmative_answer(char* str){
  char first = *str;
  return first == 'y';

}

void play(char* input, FILE* stream, char* output ){
  //open input file for reading
  FILE *input_file = fopen(input, "r");

  binary_tree* tree = binary_tree_create_f(input_file);

  size_t len;
  char* answer = fgetln(stream, &len);
  //while person wants to play
  while (affirmative_answer(answer) ){
    //play round

    answer= fgetln(stream, &len);

  }

}

binary_tree* play_round(FILE* stream, binary_tree* tree){

  char* answer = NULL;
  binary_tree* root = tree;

  while (!binary_tree_is_leaf(tree)){

    char* str = NULL;
    binary_tree_get_string(tree, str);
    printf("%s\n", str );
    size_t len;
    answer = fgetln(stream, &len);

    if(affirmative_answer(answer)){
      tree = binary_tree_get_right(tree);

    }else {
      tree= binary_tree_get_left(tree);
    }


  }
  //check if guess was correct
  char* guess= NULL;
  binary_tree_get_string(tree, guess);
  printf("Were you thinking of a %s\n ?",guess);
  size_t len;
  char* final_answer= fgetln(stream, &len);

  if (affirmative_answer(final_answer)){

    //game was guessed, its over
    printf("GOALS");
    return root;
  }else {
    printf("Wow I'm dumb...what was the animal?");
    char* animal = fgetln(stream, &len);
    printf("What question separates %s\n from %s\n ?", animal,guess );
    char* question = fgetln(stream, &len);
    printf("What is the correct answer for this animal?");
    char* correct_answer = fgetln(stream, &len);


    binary_tree* parent = NULL;

    //something here is checkde but its a lil weird i dont get it
    //

  }

  return NULL;

}
