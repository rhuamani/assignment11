#include "binary_tree.h"

// We have provided you with the binary tree struct. This struct must not be
// changed. You should implement the binary tree functions declared in
// binary_tree.h, and any helper functions you would like in this file.

struct binary_tree
{
    char value[MAX_STRING_SIZE];
    binary_tree* left;
    binary_tree* right;
    binary_tree* parent;
};

binary_tree *new_tree = NULL;

// Constructors
binary_tree* binary_tree_create(){

  new_tree = malloc(sizeof(binary_tree));
  new_tree->parent= NULL;
  new_tree->right= new_tree;
  new_tree->left = new_tree;
  new_tree->value[0]= '\n';

  return new_tree;
}

binary_tree* binary_tree_create_s(char* str){

  if (str != NULL){
    binary_tree *new_tree = malloc(sizeof(binary_tree));
    new_tree->right = new_tree->left = binary_tree_create();

    return new_tree;
  }
  return NULL;

}
binary_tree* binary_tree_create_stt(char* str, binary_tree* left, binary_tree* right){

  if (str != NULL) {
    if (left == NULL) {
      left = binary_tree_create();
      binary_tree_set_left(new_tree, new_tree->left);
    }
    if (right == NULL){
      right = binary_tree_create();
      binary_tree_set_right(new_tree, new_tree->right);
    }
    return new_tree;
  }
    return NULL;

}

void binary_tree_destroy(binary_tree* self){


}
void binary_tree_set_left(binary_tree* self, binary_tree* left){

  if (binary_tree_is_empty(self)) return;

  if (self->left != NULL && self->left->parent == self){
    self->left->parent= NULL;
  }
  self->left = left;
  self->left->parent = self;
}
void binary_tree_set_right(binary_tree* self, binary_tree* right){
  if (binary_tree_is_empty(self)) return;

  if (self->right != NULL && self->right->parent == NULL) {
    self->right->parent= NULL;
  }
  self->right = right;
  self->right->parent = self;
}
bool binary_tree_is_empty(binary_tree* self){


  ///CHECK ARRAY IS EMPTYYY??
  return self->value[0] == '\n';
}
bool binary_tree_is_leaf(binary_tree* self){

  return binary_tree_get_left(self)==NULL && binary_tree_get_right(self)== NULL;

}
bool binary_tree_is_left(binary_tree* self){

  if (self->parent == NULL) return false;
  return self == self->parent->left;
}
bool binary_tree_is_right(binary_tree* self){
  if (self->parent == NULL) {
    return false;
    }
  return self == self->parent->right;
}
bool binary_tree_is_root(binary_tree* self){

  return self->parent == NULL ;

}
int binary_tree_height(binary_tree* self){

  int maxHeight= 0;
  if (binary_tree_is_empty(self)){
     return -1 ;
   }
  int leftHeight =   binary_tree_height(binary_tree_get_left(self)  );
  int rightHeight =  binary_tree_height(binary_tree_get_right(self) ) ;
  if (leftHeight < rightHeight){
    maxHeight = rightHeight;
  }else {
    maxHeight = leftHeight;
  }
  return 1+ maxHeight;

}
int binary_tree_depth(binary_tree* self){

  if (self->parent == NULL) return 0;
  return 1 + binary_tree_depth(self->parent);
}


binary_tree* binary_tree_get_left(binary_tree* self){
  return self->left;
}

binary_tree* binary_tree_get_right(binary_tree* self){
  return self->right;
}

binary_tree* binary_tree_get_parent(binary_tree* self){
  return self->parent;
}
binary_tree* binary_tree_get_root(binary_tree* self){
  if (self->parent == NULL){
    return self;
  }else {
    return binary_tree_get_root(self->parent);

  }

}
