// Input/Output nonsense

#include <stdio.h>
#include "binary_tree_io.h"
#include "binary_tree.h"

#include <string.h>

void binary_tree_write(binary_tree* self, FILE* stream){
//print string of tree in pre order recursively

// string to output text with
char *place = NULL;

// if it's a leaf
  if (binary_tree_is_leaf(self)){
    place = binary_tree_get_string(self, place);
    fprintf(stream, "A%s", place);
    return;
  } else {
    place = binary_tree_get_string(self, place);
    fprintf(stream, "Q%s", place);
    binary_tree_write(binary_tree_get_left(self), stream);
    binary_tree_write(binary_tree_get_right(self), stream);

  }
}

binary_tree* binary_tree_create_f_help(FILE* stream){

  char *line = NULL;
  char hold[MAX_STRING_SIZE];
  line = fgets(hold, MAX_STRING_SIZE, stream);

  if (line != NULL){
  char first = *line;
  char *rest = (line + 1);

  if (first == 'Q'){
    binary_tree *left = binary_tree_create_f_help(stream);
    binary_tree *right = binary_tree_create_f_help(stream);
    return binary_tree_create_stt(rest, left, right);
  } else if (first == 'A'){
    return binary_tree_create_s(rest);
  } else {
      printf("going to NULL\n");
      return NULL;
    }
  } else
    return NULL;
}

binary_tree* binary_tree_create_f(FILE* stream){
  // if input stream does not represent a pre-order traversal of a bin tree
  // if there's a line in the input file that does not begin with Q or A
  // if there's a blank line in input file
  // other unexpected errors
  binary_tree* new_tree = NULL;
  // binary_tree* left_tree = NULL;
  // binary_tree* right_tree = NULL
  // if line starts with Q or A and is not a blank line
  if (!feof(stream)){
    new_tree = binary_tree_create_f_help(stream);
  }

  return new_tree;
}
