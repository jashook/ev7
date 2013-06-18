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

   _Table->m_list = (double_linked_list*)malloc(sizeof(double_linked_list));

   array_create(_Table->m_array, _Size);

   double_linked_list_create(_Table->m_list);

   memset(_Table->m_array->m_array, 0, _Table->m_array->m_capacity);

   _Table->m_size = _Table->m_collisions = 0;

   _Table->m_capacity = _Size;

}

void hash_table_free(hash_table* _Table)
{

   hash_table_clear(_Table);

   array_free(_Table->m_array);

   double_linked_list_free(_Table->m_list);

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

   for (_Count = 0, _Size = double_linked_list_size(_Table->m_list); _Count < _Size; ++_Count)
   {

      double_linked_list_free(*(double_linked_list**)double_linked_list_at(_Table->m_list), _Count);

   }

   memset(_Table->m_array->m_array, 0, _Table->m_capacity);

}

size_t hash_table_collisions(hash_table* _Table)
{

   return _Table->m_collisions;

}

int hash_table_contains(hash_table* _Table, void* _Key, size_t (*_Hash)(void*))
{

   int _Count, _Size;   

   double_linked_list* _List = (double_linked_list*)(*(double_linked_list**)array_at(_Table->m_array, _Hash(_Key) % _Table->m_capacity));

   if (_List == NULL) return 0;

   for (_Count = 0, _Size = double_linked_list_size(_List); _Count < _Size; ++_Count)
   {

      if (*(pair**)double_linked_list_at(_List, _Count)->m_first == _Key) return 1;

      else continue;

   }

   return 0; /* default is false */

}

void hash_table_insert(hash_table* _Table, void* _Key, void* _Data, size_t (*_Hash)(void*))
{

   pair* _KeyPair = (pair*)malloc(sizeof(pair));

   double_linked_list* _List = *(double_linked_list**)(array_at(_Table->m_array, _Hash(_Key) % _Table->m_capacity));

   _KeyTuple->m_first = _Key;
   _KeyTuple->m_second = _Data;

   if (_List != NULL)
   {

      _List = (double_linked_list*)malloc(sizeof(double_linked_list));

      double_linked_list_create(_List);

      double_linked_list_push_back(_Table->m_list, _List);
   
   }

   else
   {

      ++_Table->m_colisions;

   }

   double_linked_list_push_back(_List, _KeyTuple);

}

void hash_table_remove(hash_table* _Table, void* _Key, size_t(*_Hash)(void*))
{

   int _Count, _Size;   

   double_linked_list* _List = (double_linked_list*)(*(double_linked_list**)array_at(_Table->m_array, _Hash(_Key) % _Table->m_capacity));

   if (_List == NULL) return;

   for (_Count = 0, _Size = double_linked_list_size(_List); _Count < _Size; ++_Count)
   {

      if (*(pair**)double_linked_list_at(_List, _Count)->m_first == _Key) double_linked_list_remove(_List, _Count);

      else continue;

   }

}

void* hash_table_search(hash_table* _Table, void* _Key, size_t (*_Hash)(void*))
{

   hash_node* _Node = (hash_node*)(*array_at(_Table->m_array, _Hash(_Key) % _Table->m_capacity));

   if (_Node == NULL) return 0;

   while (_Node != NULL)
   {

      _Node->m_key == _Key ? return _Node->m_data : _Node = _Node->m_next; continue;

   }

   return 0; /* default is false */

}

size_t hash_table_size(hash_table* _Table)
{

   return _Table->m_size;

}

/* ************************************************************************** */
/* ************************************************************************** */
