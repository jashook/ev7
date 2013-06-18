/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: hash_table.c                                                       */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 17-June-13: Version 2.0: Last Updated                                      */
/* 17-June-13: Version 1.0: Created                                           */
/*                                                                            */
/* Timeperiod: ev7                                                            */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "hash_table.h"

/* ************************************************************************** */
/* ************************************************************************** */

/* functions for managing a hash_table struct */

void hash_table_create(hash_table* _Table, size_t _Size)
{

   _Table->m_array = (array*)malloc(sizeof(array));

   _Table->m_vector = (vector*)malloc(sizeof(vector));

   array_create(_Table->m_array, _Size);

   vector_create(_Table->m_vector, 100);

   memset(_Table->m_array->m_array, 0, _Table->m_array->m_capacity);

   _Table->m_size = _Table->m_collisions = 0;

   _Table->m_capacity = _Size;

}

void hash_table_free(hash_table* _Table)
{

   hash_table_clear(_Table);

   array_free(_Table->m_array);

   vector_free(_Table->m_vector);

}

/* ************************************************************************** */
/* ************************************************************************** */

/* general functions for a hash_table */

size_t hash_table_capacity(hash_table* _Table)
{

   return _Table->m_capacity;

}

void hash_table_clear(hash_table* _Table)
{

   int _Count, _Size;

   for (_Count = 0, _Size = vector_size(_Table->m_vector); _Count < _Size; ++_Count)
   {

      vector_free(*(vector**)vector_at(_Table->m_vector, _Count));

   }

   memset(_Table->m_array->m_array, 0, _Table->m_capacity);

}

size_t hash_table_collisions(hash_table* _Table)
{

   return _Table->m_collisions;

}

int hash_table_contains(hash_table* _Table, void* _Key, int (*_Compare)(void*, void*), size_t (*_Hash)(void*))
{

   int _Count, _Size;   

   vector* _Vector = *(vector**)array_at(_Table->m_array, _Hash(_Key) % _Table->m_capacity);

   if (_Vector == NULL) return 0;

   for (_Count = 0, _Size = vector_size(_Vector); _Count < _Size; ++_Count)
   {

      if (_Compare((*(pair**)vector_at(_Vector, _Count))->m_first, _Key)) return 1;

      else continue;

   }

   return 0; /* default is false */

}

void hash_table_insert(hash_table* _Table, void* _Key, void* _Data, size_t (*_Hash)(void*))
{

   pair* _KeyPair = (pair*)malloc(sizeof(pair));

   vector** _Vector;

   _Vector = (vector**)(array_at(_Table->m_array, _Hash(_Key) % _Table->m_capacity));

   _KeyPair->m_first = _Key;
   _KeyPair->m_second = _Data;

   if (*_Vector == NULL)
   {

      *(vector**)(array_at(_Table->m_array, _Hash(_Key) % _Table->m_capacity)) = (vector*)malloc(sizeof(vector));

      vector_create(*_Vector, 5);

      vector_push_back(_Table->m_vector, *_Vector);
   
   }

   else
   {

      ++_Table->m_collisions;

   }

   vector_push_back(*_Vector, _KeyPair);

}

void hash_table_remove(hash_table* _Table, void* _Key, int (*_Compare)(void*, void*), size_t(*_Hash)(void*))
{

   int _Count, _Size;   

   vector* _Vector = *(vector**)array_at(_Table->m_array, _Hash(_Key) % _Table->m_capacity);

   if (_Vector == NULL) return;

   for (_Count = 0, _Size = vector_size(_Vector); _Count < _Size; ++_Count)
   {

      if (_Compare((*(pair**)vector_at(_Vector, _Count))->m_first, _Key)) vector_remove(_Vector, _Count);

      else continue;

   }

}

void* hash_table_search(hash_table* _Table, void* _Key, int (*_Compare)(void*, void*), size_t (*_Hash)(void*))
{

   int _Count, _Size;

   vector* _Vector = (vector*)(*array_at(_Table->m_array, _Hash(_Key) % _Table->m_capacity));

   if (_Vector == NULL) return 0;

   for (_Count = 0, _Size = vector_size(_Vector); _Count < _Size; ++_Count)
   {

      if (_Compare((*(pair**)vector_at(_Vector, _Count))->m_first, _Key)) return (*(pair**)vector_at(_Vector, _Count))->m_second;

      else continue;

   }

   return 0; /* default is false */

}

size_t hash_table_size(hash_table* _Table)
{

   return _Table->m_size;

}

/* ************************************************************************** */
/* ************************************************************************** */
