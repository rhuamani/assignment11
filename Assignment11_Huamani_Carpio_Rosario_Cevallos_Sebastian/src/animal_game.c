// Game logic

#include <stdio.h>
#include "binary_tree.h"
#include "binary_tree_io.h"

//check that string begins with y, indicating a yes
bool affirmative_answer(char* str){
  char first = *str;
  return first == 'y';
}

// method to play rounds
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
    printf("%s \n", str );
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
  guess = binary_tree_get_string(tree, guess);
  printf("Were you thinking of a %s \n ?",guess);
  size_t len;
  //read answer
  char* final_answer= fgetln(stream, &len);
  //if said yes, the game was guessed and its over
  if (affirmative_answer(final_answer)){
    printf("Great!");
    return root;
  }else {
    printf("Doh! What was the animal?");
    char* animal = fgetln(stream, &len);
    printf("What question separates %s from %s ?", animal,guess );
    char* question = fgetln(stream, &len);
    printf("What is the correct answer for this animal?");
    char* correct_answer = fgetln(stream, &len);


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
      return new_tree;
    } else {
      if (affirmative_answer(answer)){
        // we're at the right child of the parent
        binary_tree_set_right(parent, new_tree);
      } else {
        // we're the left child of our parent
        binary_tree_set_left(parent, new_tree);
      }

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
  printf("Welcome to the Animals game! \n");
  printf("Shall we play a game? ");

  // beg: open file in read
  // create tree from file
  // close file then play game
  // end game & write to file

  //read answer through stream
  char hold[MAX_STRING_SIZE];
  char* answer = fgets(hold, MAX_STRING_SIZE, stream);
  //while person wants to play
  while (affirmative_answer(answer) ){
    //play round
    tree = play_round(stream ,tree);
    char hold[MAX_STRING_SIZE];
    answer= fgets(hold, MAX_STRING_SIZE, stream);

  }
  // close file for writing
  fclose(input_file);

  //opens output for reading , we want to write the tree here
  FILE *output_file = fopen(text, "w");


  printf("BYE!");

  //writes tree to output file
  binary_tree_write(tree, output_file);

}
