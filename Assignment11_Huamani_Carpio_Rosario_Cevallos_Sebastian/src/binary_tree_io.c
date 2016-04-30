#include <stdio.h>
#include "binary_tree_io.h"
#include "binary_tree.h"

#include <string.h>

// TODO: comments here

struct binary_tree_io {

};

void binary_tree_write(binary_tree* self, FILE* stream){
  //print string of tree in pre order recursively

// string to output text with
char line[MAX_STRING_SIZE];

// if it's a leaf
  if (binary_tree_get_left(self) == NULL && binary_tree_get_right(self)== NULL){
    binary_tree_get_string(self, line);
    fprintf(stream, "%s", line);
  }else {
    binary_tree_get_string(self, line);
    fprintf(stream, "%s", line);
    binary_tree_write(binary_tree_get_left(self), stream);
    binary_tree_write(binary_tree_get_right(self), stream);

  }
}

binary_tree* binary_tree_create_f_help(FILE* stream){

  char *line = NULL;
  size_t len;
  line = fgetln(stream, &len);

  char first = *line;
  char *rest = (line + 1);


  if (first == 'Q'){
    return binary_tree_create_stt(rest, binary_tree_create_f_help(stream), binary_tree_create_f_help(stream));
  } else if (first == 'A'){
    return binary_tree_create_s(rest);
  }
}

binary_tree* binary_tree_create_f(FILE* stream){
  // if input strem does not represent a pre-order traversal of a bin tree
  // if there's a line in the input file that does not begin with Q or A
  // if there's a blank line in input file
  // other unexpected errors
  binary_tree* new_tree = NULL;
  binary_tree* left_tree = NULL;
  binary_tree* right_tree = NULL;
  size_t len;
  char *line = fgetln(stream, &len);
  // if line starts with Q or A and is not a blank line
  if (len > 0){
    binary_tree_create_f_help(stream);
  }

  return new_tree;
}
