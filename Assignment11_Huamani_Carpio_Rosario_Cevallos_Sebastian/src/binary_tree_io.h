#ifndef __BINARY_TREE_IO_H__
#define __BINARY_TREE_IO_H__

#include <stdio.h>
#include "binary_tree.h"
// TODO: You may want to add additional includes

// This function creates a tree and hands off the work to the constructor of the tree
//
// @parm self tree to write/create
// @parm stream to write to
void binary_tree_write( binary_tree* self, FILE* stream);

binary_tree* binary_tree_create_f(FILE* stream);

#endif//__BINARY_TREE_IO_H__
