// Input/Output nonsense

#include <stdio.h>
#include "binary_tree_io.h"
#include "binary_tree.h"
#include <string.h>

//print string of tree in pre order recursively
void binary_tree_write(binary_tree* self, FILE* stream){

// string to output text with
char *str = NULL;

// if it's a leaf
  if (binary_tree_is_leaf(self)){
    str = binary_tree_get_string(self, str);
    fprintf(stream, "A%s", str);
    return;
  } else {
    // it's not a leaf
    str = binary_tree_get_string(self, str);
    fprintf(stream, "Q%s", str);
    binary_tree_write(binary_tree_get_left(self), stream);
    binary_tree_write(binary_tree_get_right(self), stream);

  }
}

// helper function for create method that does the work
binary_tree* binary_tree_create_f_help(FILE* stream){

  // line to read the text with
  char *line = NULL;
  char hold[MAX_STRING_SIZE];
  line = fgets(hold, MAX_STRING_SIZE, stream);

  // if the text is not null
  if (line != NULL){
  // get the first character
  char first = *line;
  // get the rest of the line (trim out Q or A)
  char *rest = (line + 1);

  // if it's a question
  if (first == 'Q'){
    binary_tree *left = binary_tree_create_f_help(stream);
    binary_tree *right = binary_tree_create_f_help(stream);
    binary_tree *root = binary_tree_create_stt(rest, left, right);
    return root;
  } else if (first == 'A'){
    binary_tree *leaf = binary_tree_create_s(rest);
    return leaf;
  } else {
      return NULL;
    }
  } else
    return NULL;
}

// creates a binary tree given an input file which hands off the work to the help
binary_tree* binary_tree_create_f(FILE* stream){

  // new tree to be created
  binary_tree* new_tree = NULL;

  // hand off the work to the helper function
  new_tree = binary_tree_create_f_help(stream);

  return new_tree;
}
