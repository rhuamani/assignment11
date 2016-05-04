#ifndef __BINARY_TREE_IO_H__
#define __BINARY_TREE_IO_H__

#include <stdio.h>
#include "binary_tree.h"

// This function takes a binary tree and prints the text (Q's & A's) to stdout
//
// @param self tree to write/create
// @param stream to write to
void binary_tree_write( binary_tree* self, FILE* stream);

// This fuction creates a binary tree from the input file stream, which should
// be a series of questions and answers in pre-order.
//
// @param stream to create tree from
binary_tree* binary_tree_create_f(FILE* stream);

#endif//__BINARY_TREE_IO_H__
