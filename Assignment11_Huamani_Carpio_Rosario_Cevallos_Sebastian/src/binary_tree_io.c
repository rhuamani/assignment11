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

binary_tree* binary_tree_create_f(FILE* stream){
  // if input strem does not represent a pre-order traversal of a bin tree
  // if there's a line in the input file that does not begin with Q or A
  // if there's a blank line in input file
  // other unexpected errors
  binary_tree* new_tree=NULL;
  binary_tree* left_tree;
  binary_tree* right_tree;
  size_t len;
  char *line = fgetln(stream, &len);
  // if line starts with Q or A and is not a blank line
  if (len > 0){
    char first = *line;
    if (first == 'Q'){
      left_tree = binary_tree_create_f(stream);
      right_tree = binary_tree_create_f(stream);
      new_tree = binary_tree_create_stt(line, left_tree, right_tree);
    } else if (first== 'A') {
      return binary_tree_create_s(line);
    }

  }

  return new_tree;
}

// binary_tree* binary_tree_create_f_help(char *str, FILE* stream){
//   //get first char
//   binary_tree* tree;
//   size_t len;
//   char first = *str;
//   if (first == 'Q'){
//     str = fgetln(stream, &len);
//     binary_tree_set_left(tree, binary_tree_create_f_help(str, stream));
//     binary_tree_set_right(tree, binary_tree_create_f_help(str, stream));
//
//   } else if (first == 'A'){
//       return binary_tree_create_s(str);
//   }
// }
