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

  binary_tree* new_tree;
  binary_tree* left_tree;
  binary_tree* right_tree;
  size_t len;
  char *line = fgetln(stream, &len);

  // if line starts with Q or A and is not a blank line
  if ((strcmp(line, "Q") == 0 || strcmp(line, "A") == 0) && len > 0){

  }


  char first = *line;
  if (first == 'Q'){
    left_tree = binary_tree_create_f();
    right_tree = binary_tree_create_f();
    new_tree = binary_tree_create_stt(line, left_tree, right_tree);
  } else {
    return binary_tree_create_s(line);
  }


  return NULL;
}

binary_tree* binary_tree_create_f_help(FILE* stream){

  char *line = NULL;
  size_t len;
  line = fgetln(stream, &len);
  
  char first = *line;
  char *rest = *line[1];


  if (first == 'Q'){
    return binary_tree_create_stt()
  } 


    else if( line.startsWith("Q") ){
      return new AnimalTree(line.substring(1),
          readFileHelper(in),
          readFileHelper(in));
    }else if( line.startsWith("A") ){
      return new AnimalTree(line.substring(1));
    }else{
      throw new RuntimeException("readFile::File parse errro");
    }



  //get first char
  binary_tree* tree;
  size_t len;
  char first = *str;
  if (first == 'Q'){
    // str = fgetln(stream, &len);
    binary_tree_set_left(tree, binary_tree_create_f_help(str, stream));
    binary_tree_set_right(tree, binary_tree_create_f_help(str, stream));

  } else if (first == 'A'){
      return binary_tree_create_s(str);
  }
}
