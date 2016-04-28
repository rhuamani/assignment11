#include <stdio.h>
#include "binary_tree_io.h"
#include <string.h>

// TODO: comments here

struct binary_tree_io {

};

void binary_tree_write(binary_tree* self, FILE* stream){

}

binary_tree* binary_tree_create_f(FILE* stream){
  // if input strem does not represent a pre-order traversal of a bin tree
  // if there's a line in the input file that does not begin with Q or A
  // if there's a blank line in input file
  // other unexpected errors

  size_t len;
  char *line = fgetln(stream, &len);
  // if line starts with Q or A and is not a blank linegi
  if ((strcmp(line, "Q") == 0 || strcmp(line, "A") == 0) && len > 0){

  }

  return NULL;
}
