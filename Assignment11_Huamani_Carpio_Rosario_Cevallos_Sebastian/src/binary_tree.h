#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// The maximum string size to handle
#define MAX_STRING_SIZE 1000

typedef struct binary_tree binary_tree;

// Constructors

// A one-time constructor, for constructing empty trees.
// Space efficiencies are possible if empty trees are reused.
// @post Constructor that generates an empty node
binary_tree* binary_tree_create();

//Constructs a tree node with no children.  Value of the node
//and subtrees are provided by the user
//
//@post Returns a tree referencing value and two empty subtrees
//@param value A non-null value to be referenced by node
binary_tree* binary_tree_create_s(char* str);

// Constructs a tree node with two children.  Value of the node
// and subtrees are provided by the user.
//
// @post Returns a tree referencing value and two subtrees
// @param value A non-null value to be referenced by node
// @param left The subtree to be left subtree of node
// @param right The subtree to be right subtree of node
binary_tree* binary_tree_create_stt(char* str, binary_tree* left, binary_tree* right);

// Destroys the tree and frees it and sets tree to null
void binary_tree_destroy(binary_tree* self);

// Sets a new tree to be the left tree of the tree passed on
// @param self
// @param left tree to be set
void binary_tree_set_left(binary_tree* self, binary_tree* left);

// Sets a new tree to be the right tree of the tree passed on
// @param self
// @param right tree to be set
void binary_tree_set_right(binary_tree* self, binary_tree* right);

// function to check if tree is empty
// @param self tree to check
// @return bool
bool binary_tree_is_empty(binary_tree* self);

// function to check that the tree passed on is just a leaf
// @param self tree to check
// @return bool
bool binary_tree_is_leaf(binary_tree* self);

// function to check if self has left child
// @param self tree to check
// @return bool
bool binary_tree_is_left(binary_tree* self);

// function to check if self has right child
// @param self tree to check
// @return bool
bool binary_tree_is_right(binary_tree* self);

// function to check if self is a root node
// @param self tree to check
// @return bool
bool binary_tree_is_root(binary_tree* self);

// function to check tree height
// @param self tree to check
// @return int height
int binary_tree_height(binary_tree* self);

// function to check tree depth
// @param self tree to check
// @return int depth
int binary_tree_depth(binary_tree* self);

// Getters
// Returns the value string of the given node
// @param self tree to get string of
// @param str string to copy value to
// @return str that has the value of the given tree
char* binary_tree_get_string(binary_tree* self, char* str);

// Gets the left child of the given tree
// @param self tree to get child of
// @return left child
binary_tree* binary_tree_get_left(binary_tree* self);

// Gets the right child of the given tree
// @param self tree to get child of
// @return right child
binary_tree* binary_tree_get_right(binary_tree* self);

// Gets the parent of the given tree
// @param self tree to get parent of
// @return parent node
binary_tree* binary_tree_get_parent(binary_tree* self);

// Gets the root node of the given tree
// @param self tree to get root of
// @return root node
binary_tree* binary_tree_get_root(binary_tree* self);

#endif//__BINARY_TREE_H__
