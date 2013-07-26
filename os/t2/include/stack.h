/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: stack.h                                                            */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 15-June-13: Version 2.0: Last Updated                                      */
/* 15-June-13: Version 2.0: Updated to ev7 and starting bug fixing            */
/* 19-Feb-13: Version 1.0: Created                                            */
/*                                                                            */
/* Timeperiod: ev7                                                            */
/*                                                                            */
/* Notes: An empty stack is defined to be a stack struct that points to an    */
/*        stack struct of size 0.                                             */
/*        To Properly use and free memory use the create or delete functions  */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#ifndef __STACK_H__
#define __STACK_H__

/* ************************************************************************** */
/* ************************************************************************** */

#ifdef __Ev7__

   #include "stdlib.h"
   #include "stdio.h"
   #include "string.h"

#elif __unix__

   #include <stdlib.h>
   #include <stdio.h>
   #include <string.h>

#elif WIN32

   #include <stdlib.h>
   #include <stdio.h>
   #include <string.h>

#endif

#include <stddef.h>

#include "double_linked_list.h"

/* ************************************************************************** */
/* ************************************************************************** */

/* type definitions */

typedef struct stack
{
   
   double_linked_list* m_list;
   int m_size;

} stack;

/* ************************************************************************** */
/* ************************************************************************** */

/* functions for creating and deleting an stack struct */

void create_stack(stack*);

/* ************************************************************************** */
/* ************************************************************************** */

/* general functions for a stack */

void stack_push(stack*, void*);
void* stack_pop(stack*);
int stack_size(stack*);

/* ************************************************************************** */
/* ************************************************************************** */

#endif /* __STACK_H__ */

/* ************************************************************************** */
/* ************************************************************************** */
