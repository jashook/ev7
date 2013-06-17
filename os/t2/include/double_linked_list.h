/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: double_linked_list.h                                               */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 16-June-13: Version 2.0: Last updated                                      */
/* 14-June-13: Version 2.0: Updated to ev7 and began fixing bugs              */
/* 27-Dec-12: Version 1.1: Small updates                                      */
/* 22-Oct-12: Version 1.0: Created                                            */
/*                                                                            */
/* Version: 1.0                                                               */
/*                                                                            */
/* Timeperiod: ev7                                                            */
/*                                                                            */
/* Notes: An empty linked_list is defined to be a linked_list struct that     */
/*        points to a linked_list node and has size = 0                       */
/*        To Properly use and free memory use the create or delete functions  */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__

/* ************************************************************************** */
/* ************************************************************************** */

#ifdef __unix__

   #include <stdlib.h>
   #include <stdio.h>
   #include <string.h>

#else

   #include "stdlib.h"
   #include "stdio.h"
   #include "string.h"

#endif

#include "node.h"

/* ************************************************************************** */
/* ************************************************************************** */

/* type definitions */

typedef struct double_linked_list
{
   
   double_linked_list_node* m_head;
   double_linked_list_node* m_tail;
   int m_size;

} double_linked_list;

/* ************************************************************************** */
/* ************************************************************************** */

/* functions for creating and deleting a linked_list struct */

void double_linked_list_create(double_linked_list*);

void double_linked_list_free(double_linked_list*);

/* ************************************************************************** */
/* ************************************************************************** */

/* general functions for a linked_list */

void** double_linked_list_at(double_linked_list*, int);
void** double_linked_list_back(double_linked_list*);
void double_linked_list_clear(double_linked_list*);
void double_linked_list_empty(double_linked_list*);
void** double_linked_list_front(double_linked_list*);
void double_linked_list_insert(double_linked_list*, int);
void* double_linked_list_pop_back(double_linked_list*);
void* double_linked_list_pop_front(double_linked_list*);
void double_linked_list_push_back(double_linked_list*, void*);
void double_linked_list_push_front(double_linked_list*, void*);
void double_linked_list_remove(double_linked_list*, int);
int double_linked_list_size(double_linked_list*);

/* ************************************************************************** */
/* ************************************************************************** */

#endif /* __DOUBLE_LINKED_LIST_H__ */

/* ************************************************************************** */
/* ************************************************************************** */
