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

/* functions for creating and deleting a hash_table struct */

void hash_table_create(hash_table* _Table, size_t _Size)
{

   _Table->m_array = (vector*)malloc(sizeof(array));

   array_create(_Table->m_array, _Size);

   _Table->m_size = _Table->m_collisions = 0;

   _Table->m_capacity = _Size;

   _Table->m_head = _Table->m_current = 0;
   
}

void hash_table_free(hash_table* _Table)
{

   hash_table_clear(_Table);

   array_free(_table->m_array);

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

   linked_list_node* _Pointer, *_BehindPointer = _Table->m_head;

   while (_Pointer != 0)
   {

      _Pointer = _Pointer->m_next;

      free (_BehindPointer);

      _BehindPointer = _Pointer;

   }

   _Table->m_size = 0;

}

size_t hash_table_collisions(hash_table* _Table)
{

   return _Table->m_collisions;

}

int hash_table_contains(hash_table* _Table, void* _Key, size_t (*_Hash)(void*))
{

   hash_node* _Node = (hash_node*)(*array_at(_Table->m_array, _Hash(_Key) % _Table->m_capacity));

   if (_Node == NULL) return 0;

   while (_Node != NULL)
   {

      _Node->m_key == _Key ? return 1 : _Node = _Node->m_next; continue;

   }

   return 0; /* default is false */

}

void hash_table_insert(hash_table* _Table, void* _Key, void* _Data, size_t (*_Hash)(void*))
{

   hash_node* _Node = (hash_node*)malloc(sizeof(hash_node));

   hash_node* _NodeSpot = *(hash_node**)(array_at(_Table->m_array, _Hash(_Key) % _Table->m_capacity));

   _Node->m_key = _Key;
   _Node->m_data = _Data;

   if (_NodeSpot != NULL)
   {

      while (_NodeSpot->m_next != NULL) _NodeSpot = _NodeSpot->m_next;

      _NodeSpot->m_next = _Node;

   }

   if (_Table->m_size == 0) _Table->m_head = _Node;

   else _Table->m_current->m_next = _Node; _Table->m_current = _Node;

}

void hash_table_remove(hash_table* _Table, void* _Key, size_t(*_Hash)(void*))
{

   hash_node* _Node = (hash_node*)(*array_at(_Table->m_array, _Hash(_Key) % _Table->m_capacity));

   hash_node* _PreviousNode = _Node;

   if (_Node == NULL) return;

   if (_Node->_Key == _Key)
   {

      _Node = _Node->m_next;

      free(_Node)      

   }

   else
   {

      _Node = _Node->m_next;

   }

   while (_Node != NULL)
   {
      
      if (_Node->m_key == _Key)
      {

         _PreviousNode->m_next = _Node->m_next;

         free(_Node);  

      }

      else
      {

         _Node = _Node->m_next;

         _PreviousNode = _PreviousNode->m_next;

         continue;

      }

   }

   return; /* default is false */

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
