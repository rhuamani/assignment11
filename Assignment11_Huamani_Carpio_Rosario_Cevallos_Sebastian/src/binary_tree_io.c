#include <stdio.h>
#include "binary_tree_io.h"
#include "binary_tree.h"

#include <string.h>

// TODO: comments here

struct binary_tree_io {

};

void binary_tree_write(binary_tree* self, FILE* stream){
  //print string of tree in pre order recursively

  if (binary_tree_get_left(self) == NULL && binary_tree_get_right(self)== NULL){
    char line[1000];
    binary_tree_get_string(self, line);
    fprintf(stream, "%s", line);
  }else {
    char line[1000];
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

  binary_tree* new_tree = binary_tree_create();
  size_t len;
  char *line = fgetln(stream, &len);
  // if line starts with Q or A and is not a blank linegi
  if ((strcmp(line, "Q") == 0 || strcmp(line, "A") == 0) && len > 0){

  }

  return NULL;
}
