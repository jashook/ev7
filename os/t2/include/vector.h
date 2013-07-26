/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: vector.h                                                           */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 17-June-13: Version 2.0: Last Updated                                      */
/* 17-June-13: Version 2.0: Updated to ev7 and began bug fixing               */
/* 27-Dec-12: Version 1.1: Renamed from ArrayList to vector                   */
/* 22-Oct-12: Version 1.0: Created                                            */
/*                                                                            */
/* Version: 1.1                                                               */
/*                                                                            */
/* Timeperiod: ev7                                                            */
/*                                                                            */
/* Notes: An empty vector is defined to be a vector struct that has size 0    */
/*        To properly allocate and free memory, use the create and delete     */
/*        functions                                                           */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#ifndef __VECTOR_H__
#define __VECTOR_H__

/* ************************************************************************** */
/* ************************************************************************** */

#ifdef __Ev7__

   #include "stdio.h"
   #include "stdlib.h"
   #include "string.h"

#elif __unix__

   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>

#elif WIN32

   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>

#endif

#include <stddef.h>

/* ************************************************************************** */
/* ************************************************************************** */

/* type definitions */

typedef struct vector
{
   void** m_array;
   int m_size;
   int m_max_size;

} vector;

extern const int BASE_VECTOR_SIZE;

/* ************************************************************************** */
/* ************************************************************************** */

/* functions for creating and delete a vector */

void vector_create(vector*, size_t);
void vector_free(vector*);

/* ************************************************************************** */
/* ************************************************************************** */

/* general functions for a vector */

void** vector_at(vector*, int);
void** vector_back(vector*);
void vector_clear(vector*);
void** vector_front(vector*);
void vector_insert(vector*, void*, int);
void* vector_pop_back(vector*);
void vector_push_back(vector*, void*);
void vector_remove(vector*, int);
void vector_resize(vector*, int);
int vector_size(vector*);

/* ************************************************************************** */
/* ************************************************************************** */

#endif   /* __VECTOR_H__ */

/* ************************************************************************** */
/* ************************************************************************** */
