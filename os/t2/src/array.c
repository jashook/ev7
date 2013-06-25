/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: array.c                                                            */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 16-June-13: Version 2.0: Last Updated                                      */
/* 16-June-13: Version 2.0: Updated to ev7 and began bug fixing               */
/* 16-Feb-13: Version 1.0: Created                                            */
/*                                                                            */
/* Timeperiod: ev7                                                            */
/*                                                                            */
/* Notes: An empty array is defined to be a array struct that points to an    */
/*        array struct of size 0.                                             */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "array.h"

/* ************************************************************************** */
/* ************************************************************************** */

/* functions for creating and deleting an array struct */

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*   array_create                                                             */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*   array*: pointer to an array structure to be allocated                    */
/*   size_t: a size to allocate the array to                                  */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*   void                                                                     */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

void array_create(array* _Array, size_t _Size)
{

   _Array->m_capacity = _Size;

   _Array->m_size = 0;

   _Array->m_array = (void**)malloc(sizeof(void*) * _Size);

   #if DEBUG

      memset(_Array->m_array, 0, _Array->m_capacity);

   #endif

}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    array_free                                                              */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    array*: pointer to an array structure to free                           */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    void                                                                    */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

void array_free(array* _Array)
{
   #if DEBUG
   
      memset(_Array->m_array, 0, _Array->m_capacity);

   #endif

   free(_Array->m_array);

}

/* ************************************************************************** */
/* ************************************************************************** */

/* general functions for an array */

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    array_at                                                                */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    array*: pointer to an array structure to be used                        */
/*    int: index of an array                                                  */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    void**: returns the pointer at location _Index by pointer               */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

void** array_at(array* _Array, int _Index)
{
   return array_at_safe(_Array, _Index);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    array_at_safe                                                           */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    array*: pointer to an array structure to be used                        */
/*    int: index of the array                                                 */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    void**: returns the pointer at location _Index by pointer               */
/*                                                                            */
/* Notes:                                                                     */
/*                                                                            */
/*    if in debug mode then it will check to see if the array is in bounds    */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

void** array_at_safe(array* _Array, int _Index)
{
   #if DEBUG

      if (_Index > _Array->m_capacity - 1) 
      {
         printf("Attempting to read out of bounds.  Exiting the program...\n");
         
         exit(1);
      }

   #endif

   return (_Array->m_array + _Index);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    array_back                                                              */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    array*: pointer to an array structure to be used                        */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    void**: returns a pointer at location _Index

void** array_back(array* _Array)
{
   return (_Array->m_array + _Array->m_size - 1);
}

void array_clear(array* _Array)
{
   _Array->m_size = 0;

   memset(_Array->m_array, 0, _Array->m_capacity);
}

void array_empty(array* _Array)
{
   array_clear(_Array);
}

void** array_front(array* _Array)
{
   return _Array->m_array;
}

void array_insert(array* _Array, int _Index,  void* _Data)
{
   /* Note: Linear time insertion */

   #if DEBUG
   
      if ((_Array->m_capacity == _Array->m_size) || ( _Index >= _Array->m_size) || (_Index < 0))
      {
         printf("Attempting to write out of bounds.  Exiting the program...\n");
         
         exit(1);
      }

   #endif

   array_shift_right(_Array, _Index);

   _Array->m_array[_Index] = _Data;

   ++_Array->m_size;

}

void* array_pop_back(array* _Array)
{
   #if DEBUG

      if (_Array->m_size == 0)
      {
         printf("Attempting to read out of bounds.  Exiting the program...\n");
         
         exit(1);
      }
   
   #endif

   return _Array->m_array[_Array->m_size--];
}

void* array_pop_front(array* _Array)
{
   /* Note: Linear time removal */

   #if DEBUG

      if (_Array->m_size == 0)
      {
         printf("Attempting to read out of bounds.  Exiting the program...\n");
         
         exit(1);
      }
   
   #endif

   void* _Return = _Array->m_array[0];

   array_shift_left(_Array, 0);
   
   --_Array->m_size;

   return _Return;
}

void array_push_back(array* _Array, void* _Data)
{
   #if DEBUG
   
      if (_Array->m_capacity == _Array->m_size)
      {
         printf("Attempting to write out of bounds.  Exiting the program...\n");
         
         exit(1);
      }

   #endif

   _Array->m_array[_Array->m_size++] = _Data;

}

void array_push_front(array* _Array, void* _Data)
{
   /* Note: Linear time insertion */

   #if DEBUG
   
      if (_Array->m_capacity == _Array->m_size)
      {
         printf("Attempting to write out of bounds.  Exiting the program...\n");
         
         exit(1);
      }

   #endif

   array_shift_right(_Array, 0);

   ++_Array->m_size;
   
   _Array->m_array[0] = _Data;

}

void array_remove(array* _Array, int _Index)
{
   /* Note: Linear time removal */

   #if DEBUG

      if (_Array->m_size == 0)
      {
         printf("Attempting to read out of bounds.  Exiting the program...\n");
         
         exit(1);
      }
   
   #endif

   array_shift_left(_Array, _Index);
   
   --_Array->m_size;
  
}

void array_shift_left(array* _Array, int _Index)
{
   #if DEBUG
   
      if (( _Index <= _Array->m_size) || (_Index < 0))
      {
         printf("Attempting to write out of bounds.  Exiting the program...\n");
         
         exit(1);
      }

   #endif

   /* move all pointers down by one */

   int i;

   for (i = _Index; i < _Array->m_size; ++i)
   {
      _Array->m_array[i] = _Array->m_array[i + 1];
   }
}

void array_shift_right(array* _Array, int _Index)
{
   #if DEBUG
   
      if (( _Index >= _Array->m_size) || (_Index < 0))
      {
         printf("Attempting to write out of bounds.  Exiting the program...\n");
         
         exit(1);
      }

   #endif

   /* move all pointers down by one */

   int i;

   for (i = _Array->m_size; i > _Index; --i)
   {
      _Array->m_array[i] = _Array->m_array[i - 1];
   }
}

int array_size(array* _Array)
{
   return _Array->m_size;
}

/* ************************************************************************** */
/* ************************************************************************** */
