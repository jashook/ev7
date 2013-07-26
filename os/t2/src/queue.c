/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: queue.c                                                            */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 16-June-13: Version 2.0: Last Updated                                      */
/* 16-June-13: Version 2.0: Updated to ev7 and began bug fixing               */
/* 16-Feb-13: Version 1.0: Created                                            */
/*                                                                            */
/* Timeperiod: ev7                                                            */
/*                                                                            */
/* Notes: An empty queue is defined to be a queue struct that points to an    */
/*        queue struct of size 0.                                             */
/*        To Properly use and free memory use the create or delete functions  */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "queue.h"

/* ************************************************************************** */
/* ************************************************************************** */

/* functions for creating and deleting an stack struct */

void queue_create(queue* _Queue)
{
   _Queue->m_list = (void*)malloc(sizeof(double_linked_list));

   double_linked_list_create(_Queue->m_list);
}

void queue_free(queue* _Queue)
{
   double_linked_list_free(_Queue->m_list);
}

/* ************************************************************************** */
/* ************************************************************************** */

/* general functions for a stack */

void* queue_pop(queue* _Queue)
{
   return double_linked_list_pop_back(_Queue->m_list);
}

void queue_push(queue* _Queue, void* _Data)
{
   double_linked_list_push_front(_Queue->m_list, _Data);
}

int queue_size(queue* _Queue)
{
   double_linked_list_size(_Queue->m_list);
}

/* ************************************************************************** */
/* ************************************************************************** */
