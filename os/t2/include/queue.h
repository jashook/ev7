/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: queue.h                                                            */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 16-June-13: Last Updated                                                   */
/* 14-June-13: updated to ev7 and began fixing bugs                           */
/* 19-Feb-13: Version 1.0: Created                                            */
/*                                                                            */
/* Timeperiod: ev7                                                            */
/*                                                                            */
/* Notes: An empty queue is defined to be a queue struct that points to an    */
/*        queue struct of size 0.                                             */
/*        To Properly use and free memory use the create or delete functions  */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#ifndef __QUEUE_H__
#define __QUEUE_H__

/* ************************************************************************** */
/* ************************************************************************** */

#ifdef __unix__

   #include <stdlib.h>
   #include <stdio.h>
   #include <string.h>

#elif WIN32

   #include <stdlib.h>
   #include <stdio.h>
   #include <string.h>

#else

   #include "stdlib.h"
   #include "stdio.h"
   #include "string.h"

#endif

#include <stddef.h>

#include "double_linked_list.h"

/* ************************************************************************** */
/* ************************************************************************** */

/* type definitions */

typedef struct queue
{
   
   double_linked_list* m_list;

} queue;

/* ************************************************************************** */
/* ************************************************************************** */

/* functions for creating and deleting an stack struct */

void queue_create(queue*);

void queue_free(queue*);

/* ************************************************************************** */
/* ************************************************************************** */

/* general functions for a stack */

void queue_push(queue*, void*);
void* queue_pop(queue*);
int size_queue(queue*);

/* ************************************************************************** */
/* ************************************************************************** */

#endif /* __QUEUE_H__ */

/* ************************************************************************** */
/* ************************************************************************** */
