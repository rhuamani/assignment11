#include "binary_tree.h"

// Binary tree struct
struct binary_tree
{
    char *value;
    binary_tree* left;
    binary_tree* right;
    binary_tree* parent;
};

// Constructors
binary_tree* binary_tree_create(){
  binary_tree *new_tree = NULL;
  if(new_tree ==NULL){
  new_tree = malloc(sizeof(binary_tree));
  new_tree->parent= NULL;
  new_tree->right= NULL;
  new_tree->left = NULL;
  new_tree->value = NULL;
}
  return new_tree;
}

binary_tree* binary_tree_create_s(char* str){

  if (str != NULL){
    binary_tree* new_tree = malloc(sizeof(binary_tree));
    // make sure enough space
    if (new_tree != NULL){
    // set the children
    new_tree->left = binary_tree_create();
    new_tree->right = binary_tree_create();

    // set parents
    new_tree->left->parent = new_tree;
    new_tree->right->parent = new_tree;

    // set value of new node
    new_tree->value = strdup(str);
    }
    return new_tree;
  }
  return NULL;

}

binary_tree* binary_tree_create_stt(char* str, binary_tree* left, binary_tree* right){

  binary_tree *new_tree = NULL;
  if (str != NULL) {
    if (left == NULL) {
      left = binary_tree_create();

    }
    if (right == NULL){
      right = binary_tree_create();

    }

    // make the tree with the string in it
    new_tree = binary_tree_create_s(str);
    // assign its children
    binary_tree_set_left(new_tree, left);
    binary_tree_set_right(new_tree, right);

    return new_tree;

  }
    return NULL;
}

void binary_tree_destroy(binary_tree* self){
    if (self->right != NULL && self->left !=NULL){
      binary_tree_destroy(self->left);
      binary_tree_destroy(self->right);
    } else{
      free(self);
      self= NULL;
    }
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

  if(self == NULL){
    return false;
  }
  // using NULL to signify empty in this case
  return self->value == NULL;
}

bool binary_tree_is_leaf(binary_tree* self){

  return (binary_tree_height(self) == 0);

}

bool binary_tree_is_left(binary_tree* self){

  if (self->parent == NULL) return false;
  return self == self->parent->left;
}
bool binary_tree_is_right(binary_tree* self){
  if (self->parent == NULL) return false;

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
  int leftHeight =  binary_tree_height(binary_tree_get_left(self));
  int rightHeight = binary_tree_height(binary_tree_get_right(self));
  // get the max of the two
  if (leftHeight < rightHeight){
    maxHeight = rightHeight;
  }else {
    maxHeight = leftHeight;
  }
  return 1 + maxHeight;

}
int binary_tree_depth(binary_tree* self){

  if (self->parent == NULL) return 0;
  return 1 + binary_tree_depth(self->parent);
}

char* binary_tree_get_string(binary_tree* self, char* str){

  if (self != NULL){
    str = strdup(self->value);
    return str;
  }
  return NULL;

}

binary_tree* binary_tree_get_left(binary_tree* self){
 if (self != NULL){
    return self->left;
 } else {
   return NULL;
  }
}

binary_tree* binary_tree_get_right(binary_tree* self){
  if (self != NULL){
    return self->right;
  } else {
  return NULL;
  }
}

binary_tree* binary_tree_get_parent(binary_tree* self){
  if (self != NULL){
    return self->parent;
  } else {
  return NULL;
  }
}
binary_tree* binary_tree_get_root(binary_tree* self){
  if (self->parent == NULL){
    return self;
  } else {
    return binary_tree_get_root(self->parent);
  }

}
