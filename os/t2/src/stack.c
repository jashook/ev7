/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: stack.c                                                            */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 17-June-13: Version 2.0: Last Updated                                      */
/* 17-June-13: Version 2.0: Updated to ev7 and started bug fixes              */
/* 16-Feb-13: Version 1.0: Created                                            */
/*                                                                            */
/* Timeperiod: ev7                                                            */
/*                                                                            */
/* Notes: An empty stack is defined to be a stack struct that points to an    */
/*        stack struct of size 0.                                             */
/*        To Properly use and free memory use the create or delete functions  */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "stack.h"

/* ************************************************************************** */
/* ************************************************************************** */

/* functions for creating and deleting an stack struct */

void stack_create(stack* _Stack)
{

   _Stack->m_list = (void*)malloc(sizeof(double_linked_list));

   double_linked_list_create(_Stack->m_list);

}

void stack_free(stack* _Stack)
{

   double_linked_list_free(_Stack->m_list);

   free(_Stack->m_list);

}

/* ************************************************************************** */
/* ************************************************************************** */

/* general functions for a stack */

void* stack_pop(stack* _Stack)
{

   return double_linked_list_pop_back(_Stack->m_list);

}

void stack_push(stack* _Stack, void* _Data)
{

   double_linked_list_push_back(_Stack->m_list, _Data);

}

int stack_size(stack* _Stack)
{
   return double_linked_list_size(_Stack->m_list);
}

/* ************************************************************************** */
/* ************************************************************************** */
