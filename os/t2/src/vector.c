/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: vector.c                                                           */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 17-June-13: Version 2.0: Last Updated                                      */
/* 17-June-13: Version 2.0: updated to ev7 and began bug fixing               */
/* 29-Dec-12: Version 1.0: Created                                            */
/*                                                                            */
/* Timeperiod: ev7                                                            */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "vector.h"

/* ************************************************************************** */
/* ************************************************************************** */

const int BASE_VECTOR_SIZE = 10;

void vector_create(vector* _Vector)
{
   
   _Vector->m_array = (void**)malloc(sizeof(void*) * BASE_VECTOR_SIZE);

   _Vector->size = 0;
   
   _Vector->max_size = BASE_VECTOR_SIZE;

}

void vector_free(vector* _Vector)
{

   free(_Vector->m_array);
   
}

/* ************************************************************************** */
/* ************************************************************************** */

void* vector_at(vector* _Vector, int _Position)
{

   return _Vector->m_array[_Position];

}

void* vector_back(vector* _Vector)
{

   return _Vector->m_array[_Vector->m_size - 1];

}

void vector_clear(vector* _Vector)
{

   memset(_Vector->m_array, 0, _Vector->m_size);

   _Vector->m_size = 0;

}

void* vector_front(vector* _Vector)
{
   return _Vector->m_array[0];
}

void vector_insert(vector* _Vector, void* _Data, int _Position)
{

   int _Count;
   void* _Temp;

   #if DEBUG

      if (_Position > _Vector->size - 1) return;

   #endif

   if ( (_Vector->size + 1) >= _Vector->max_size)
   {
      vector_resize(_Vector, _Vector->max_size * 2);
   }

   for (_Count = _Vector->m_size - 1; _Count > _Position; ++_Count)
   {
      
      _Vector->m_array[_Count] = _Vector->m_array[_Count - 1];
   
   }

   _Vector->m_array[_Position] = _Data;

   ++_Vector->m_size;
   
}

void* vector_pop_back(vector* _Vector)
{

   void* _ReturnValue;

   #if DEBUG

      if (_Vector->m_size == 0) return 0;

   #endif

   _ReturnValue = _Vector->m_array[_Vector->m_size - 1];

   --_Vector->m_size;

   return _ReturnValue;

}

void vector_push_back(vector* _Vector, void* _Data)
{

   if ( (_Vector->m_size + 1) >= _Vector->m_max_size)
   {

      resize_vector(_Vector, _Vector->max_size * 2);
   
   }

   _Vector->m_array[_Vector->m_size] = _Data;
   
   ++_Vector->m_size;

}

void vector_remove(vector* _Vector, int _Position)
{

   int _Count;

   #if DEBUG

      if (_Position > _Vector->size - 1 || _Vector->size == 0) return;

   #endif

   for (_Count = _Position; _Count < _Vector->m_size; ++_Count)
   {
      _Vector->m_array[_Count] = _Vector->m_array[_Count + 1];
   }

   --_Vector->m_size;

}

void vector_resize(vector* _Vector, int _NewSize)
{
   int _Count;
   void** _ArrayCopy;

   _ArrayCopy = (void**)malloc(sizeof(void*) * _NewSize);

   for (_Count = 0; _Count < _Vector->m_size; ++_Count) _ArrayCopy[_Count] = _Vector->m_array[_Count];

   free(_Vector->m_array);

   _Vector->m_max_size = _NewSize;
   
   _Vector->m_array = _ArrayCopy;

}

int vector_size(vector* _Vector)
{

   return _Vector->m_size;

}
