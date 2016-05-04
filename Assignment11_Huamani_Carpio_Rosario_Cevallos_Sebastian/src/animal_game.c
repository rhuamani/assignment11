// Game logic

#include <stdio.h>
#include "binary_tree.h"
#include "binary_tree_io.h"

//check that string begins with y, indicating a yes
bool affirmative_answer(char* str){
  char first = *str;
  return first == 'y' || first == 'Y';
}

// method to play rounds **ISSUES IN THIS METHOD**
binary_tree* play_round(FILE* stream, binary_tree* tree){
  //variable to save answer coming from stream
  char* answer = NULL;
  binary_tree* root = tree;

  //while the tree passed in is not a leaf
  while (!binary_tree_is_leaf(tree)){

    char* str = NULL;

    // ask about str and returned string
    str = binary_tree_get_string(tree, str);


    //print out question
    printf("%s ", str);
    //read response to question
    char hold11[MAX_STRING_SIZE];
    answer = fgets(hold11, MAX_STRING_SIZE, stream);
    //if answer is yes
    if(affirmative_answer(answer)){
      tree = binary_tree_get_right(tree);

    }else {
      tree= binary_tree_get_left(tree);

    }


  }
  //check if guess was correct
  char* guess= NULL;
  guess = binary_tree_get_string(tree, guess);


  printf("Were you thinking of a %s? ",guess);
  //read answe
  char hold0[MAX_STRING_SIZE];
  char* final_answer = fgets(hold0, MAX_STRING_SIZE, stream);
  //if said yes, the game was guessed and its over
  if (affirmative_answer(final_answer)){
    printf("Great!\n");
    return root;
  }else {
    printf("Doh! What was the animal? ");
    char hold[MAX_STRING_SIZE];
    char* animal = fgets(hold, MAX_STRING_SIZE, stream);
    // trim the \n
    char *nice_print = NULL;
    nice_print = strdup(animal);
    nice_print[strlen(nice_print) - 1] = '\0';
    printf("What question separates %s from %s? ", nice_print,guess);
    char hold2[MAX_STRING_SIZE];
    char* question = fgets(hold2, MAX_STRING_SIZE, stream);
    printf("What is the correct answer for this animal? ");
    char hold3[MAX_STRING_SIZE];
    char* correct_answer = fgets(hold3, MAX_STRING_SIZE, stream);


    binary_tree* parent = NULL;

    if (answer != NULL){
      parent = binary_tree_get_parent(tree);
    }

    binary_tree* new_tree = NULL;
    if (affirmative_answer(correct_answer)){
      new_tree = binary_tree_create_stt(question, tree, binary_tree_create_s(animal));
    } else {
      new_tree = binary_tree_create_stt(question, binary_tree_create_s(animal), tree);
    }

    if (answer == NULL){
      // binary_tree_destroy(root);
      return new_tree;
    } else {
      if (affirmative_answer(answer)){
        // we're at the right child of the parent
        binary_tree_set_right(parent, new_tree);
      } else {
        // we're the left child of our parent
        binary_tree_set_left(parent, new_tree);
      }
      //binary_tree_destroy(new_tree);
      return root;
    }

  }

}

void play(char* text, FILE* stream){
  //open input file for reading (aka the game)
  FILE *input_file = fopen(text, "r");

  //make binary tree with input file
  binary_tree* tree = binary_tree_create_f(input_file);

  // Intro to the game
  printf("Shall we play a game? ");

  //read answer through stream
  char hold[MAX_STRING_SIZE];
  char* answer = fgets(hold, MAX_STRING_SIZE, stream);
  //while person wants to play
  while (affirmative_answer(answer) ){
    //play round
    tree = play_round(stream ,tree);

    // close file for writing
    fclose(input_file);

    //opens output for reading , we want to write the tree here
    FILE *output_file = fopen(text, "w");

    //writes tree to output file
    binary_tree_write(tree, output_file);

    fclose(output_file);

    printf("Shall we play a game? ");

    char hold[MAX_STRING_SIZE];
    answer = fgets(hold, MAX_STRING_SIZE, stream);

  }

  binary_tree_destroy(tree);
  // Says bye to end game
  printf("Bye! \n");
  return;



}
