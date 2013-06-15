/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: array.h                                                            */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 14-June-13: Version 2.0: Updated to ev7 and began fixing bugs              */
/* 16-Feb-13: Version 1.0: Created                                            */
/*                                                                            */
/* Version: 1.0                                                               */
/*                                                                            */
/* Timeperiod: Ev6                                                            */
/*                                                                            */
/* Notes: An empty array is defined to be a array struct that points to an    */
/*        array struct of size 0.                                             */
/*        To Properly use and free memory use the create or delete functions  */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#ifndef __ARRAY_H__
#define __ARRAY_H__

/* ************************************************************************** */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* ************************************************************************** */
/* ************************************************************************** */

/* type definitions */

typedef struct array
{
   
   void** m_array;
   int m_capacity;
   int m_size;

} array;

/* ************************************************************************** */
/* ************************************************************************** */

/* functions for creating and deleting an array struct */

array* array_create();

void array_free(array*);

/* ************************************************************************** */
/* ************************************************************************** */

/* general functions for a array */

void* array_at(array*, int);
void* array_at_safe(array*, int);
void* array_back(array*);
void array_clear(array*);
void array_empty(array*);
void* array_front(array*);
void array_insert(array*, int, void*);
void* array_pop_back(array*);
void* array_pop_front(array*);
void array_push_back(array*, void*);
void array_push_front(array*, void*);
void array_remove(array*, int);
void array_shift_left(array*, int);
void array_shift_right(array*, int);
int array_size(array*);

/* ************************************************************************** */
/* ************************************************************************** */

#endif /* __ARRAY_H__ */

/* ************************************************************************** */
/* ************************************************************************** */
