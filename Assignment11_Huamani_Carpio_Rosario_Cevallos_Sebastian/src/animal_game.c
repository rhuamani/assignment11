// TODO: Use this file for your game logic.

#include <stdio.h>
#include "binary_tree.h"
#include "binary_tree_io.h"

struct animal_game {


};

//check that string begins with y, indicating a yes
bool affirmative_answer(char* str){
  char first = *str;
  return first == 'y';
}

//method to play rounds lmao...NOT FINISHED!!
binary_tree* play_round(FILE* stream, binary_tree* tree){
  //variable to save answer coming from stream
  char* answer = NULL;
  binary_tree* root = tree;

  //while the tree passed in is not a leaf
  while (!binary_tree_is_leaf(tree)){


    char* str = NULL;

    binary_tree_get_string(tree, str);
    //print out question
    printf("%s\n", str );
    size_t len;
    //read response to question
    answer = fgetln(stream, &len);

    //if answer is yes
    //but why calling on different sides ?
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
  //read answer
  char* final_answer= fgetln(stream, &len);
  //if said yes, the game was guessed and its over
  if (affirmative_answer(final_answer)){
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
    //its related to adding tree stuff accordingly

  }

  return NULL;

}


void play(char* input, FILE* stream, char* output ){
  //open input file for reading (aka the game)
  FILE *input_file = fopen(input, "r");
  //opens output for reaading , we want to write the tree here
  FILE *output_file = fopen(output, "r");

  //make binary tree with input file
  binary_tree* tree = binary_tree_create_f(input_file);

  size_t len;
  //read answer through stream
  char* answer = fgetln(stream, &len);
  //while person wants to play
  while (affirmative_answer(answer) ){
    //play round
    tree = play_round(stream ,tree);
    printf("Wanna play a game?");
    answer= fgetln(stream, &len);

  }

  printf("BYE!");

  //writes tree to output file
  binary_tree_write(tree, output_file);

}
