/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: avl_tree.h                                                         */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 14-June-13: Version 2.0: Last Updated                                      */
/* 14-June-13: Version 2.0: Updated to ev7 and began fixing bugs              */
/* 19-Feb-13: Version 1.0: Created                                            */
/*                                                                            */
/* Timeperiod: ev7                                                            */
/*                                                                            */
/* Notes: An empty avl_tree is defined to be a avl_tree struct that points    */
/*        to an avl_tree struct of size 0.                                    */
/*        To Properly use and free memory use the create or delete functions  */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__

/* ************************************************************************** */
/* ************************************************************************** */

#ifdef __unix__

   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>

#elif WIN32

   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>

#else
   
   #include "stdio.h"
   #include "stdlib.h"
   #include "string.h"

#endif

#include <stddef.h>

#include "node.h"
#include "queue.h"
#include "stack.h"
#include "vector.h"

/* ************************************************************************** */
/* ************************************************************************** */

/* type definitions */

typedef struct avl_tree
{
   avl_node* m_root;
   avl_node* m_left_leaf_node;
   avl_node* m_right_leaf_node;
   int m_size;

} avl_tree;

/* ************************************************************************** */
/* ************************************************************************** */

/* functions for creating and deleting an avl_tree struct */

avl_tree* avl_tree_create();

void avl_tree_free(avl_tree*);

/* ************************************************************************** */
/* ************************************************************************** */

/* general functions for an avl_tree */

vector* avl_tree_breadth_first_traversal(avl_tree*);
int avl_tree_compare(void*, void*);
int avl_tree_contains(avl_tree*, void*);
void avl_tree_insert(avl_tree*, void*, void*);
void avl_tree_remove(avl_tree*, void*);
void* avl_tree_search(avl_tree*, void*);
int avl_tree_size(avl_tree*);

/* ************************************************************************** */
/* ************************************************************************** */

#endif /* __AVL_TREE_H__ */

/* ************************************************************************** */
/* ************************************************************************** */
