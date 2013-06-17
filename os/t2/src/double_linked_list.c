/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: double_linked_list.c                                               */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 16-June-13: Version 2.0: Last Updated                                      */
/* 16-June-13: Version 2.0: Created tag, added to ev7 and began bug fixing    */
/*                                                                            */
/* Timeperiod: ev7                                                            */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */

#include "double_linked_list.h"

/* ************************************************************************** */
/* ************************************************************************** */

/* general function for creating and deleting a linked_list struct           */

/* ************************************************************************** */
/* ************************************************************************** */

void double_linked_list_create(double_linked_list* _List)
{

   _List->m_head = malloc(sizeof(double_linked_list_node));
   _List->m_tail = malloc(sizeof(double_linked_list_node));

   memset(_List->m_head, 0, sizeof(double_linked_list_node));

   memset(_List->m_tail, 0, sizeof(double_linked_list_node));

   _List->_size = 0;

}

void delete_linked_list(double_linked_list* _List)
{

   clear_list(_List);  

}

/* ************************************************************************** */
/* ************************************************************************** */

/* General functions for a linked_list struct                                */

/* ************************************************************************** */
/* ************************************************************************** */

void** double_linked_list_at(double_linked_list* _List, int _Position)
{

   int _Count;

   double_linked_list_node* _Pointer = _List->m_head;

   for (_Count = 0; _Count < _Position; ++_Count) _Pointer = _Pointer->m_next;

   return &_Pointer->m_data;

}

void** double_linked_list_back(double_linked_list* _List)
{

   return &_List->m_tail->m_prev->m_data;

}

void double_linked_list_clear(double_linked_list* _List)
{

   double_linked_list_node* _AheadPointer = _List->m_head;
   double_linked_list_node* _BehindPointer = _AheadPointer;

   while (_AheadPointer != 0)
   {
      
      _AheadPointer = _AheadPointer->m_next;
      free(_BehindPointer);
      _BehindPointer = _AheadPointer;
   
   }

   _List->m_head->m_head = _List->m_tail;
   _List->m_tail->m_prev = _List->m_head;
   _List->m_size = 0;

}

void double_linked_list_empty(doublelinked_list* _List)
{

   double_linked_list_clear(_List);

}

void** double_linked_list_front(double_linked_list* _List)
{

   return &_List->m_head->m_head->m_data;

}

void* double_linked_list_pop_back(double_linked_list* _List)
{

   int _Position;
   bidirectional_node* _List_ptr = _List->_node;
   void** _Return;

   for (_Position = 0; _Position < _List->_size - 1; ++_Position) _List_ptr = _List_ptr->_next;

   _Return = _List_ptr->_data;

   if (_List->_size == 1)
   {

      free(_List->_node);
      _List->_size = 0;
      _List->_node = 0;
   }

   else
   {
      _List_ptr = _List_ptr->_prev;
      free(_List_ptr->_next);
      _List_ptr->_next = 0;
      --_List->_size;
   }

   return _Return;

}

void push_back_list(linked_list* _List, void* _Data)
{
   
   int _Pos;
   bidirectional_node* _List_ptr = _List->_node;
   
   for (_Pos = 0; _Pos < _List->_size - 1; ++_Pos) _List_ptr = _List_ptr->_next;

   if (_List->_size == 0)
   {
      _List->_node = (bidirectional_node*)malloc(sizeof(linked_list));
      _List->_node->_next = 0;
      _List->_node->_data = _Data;
      ++_List->_size;
   }

   else
   {
      _List_ptr->_next = (bidirectional_node*)malloc(sizeof(linked_list));
      _List_ptr->_next->_next = 0;
      _List_ptr->_next->_prev = _List_ptr;
      _List_ptr->_next->_data = _Data;
      ++_List->_size;
   }

}

void remove_from_list(linked_list* _List, int _Position)
{
 
   int _Pos;
   bidirectional_node* _Next_ptr;
   bidirectional_node* _Prev_ptr;
   bidirectional_node* _List_ptr = _List->_node;

   if (_Position > _List->_size || _List->_size < 0) return;

   for (_Pos = 0; _Pos < _Position; ++_Pos) _List_ptr = _List_ptr->_next;

   if (_List->_size == 1)
   {
      free(_List->_node);
      _List->_node = 0;
      _List->_size = 0;
   }

   else if(_Position == 0)
   {
      _List->_node = _List_ptr->_next;
      free(_List_ptr->_next->_prev);
      --_List->_size;
   }

   else if (_Position == _List->_size - 1)
   {
      _Prev_ptr = _List_ptr->_prev;
      free(_Prev_ptr->_next);
      _Prev_ptr->_next = 0;
      --_List->_size;
   }
 
   else
   {
      _Next_ptr = _List_ptr->_next;
      _Prev_ptr = _List_ptr->_prev;
 
      _Prev_ptr->_next = _Next_ptr;
      free(_Next_ptr->_prev);
      _Next_ptr->_prev = _Prev_ptr;
      
      --_List->_size;
   }

}

int size_of_list(linked_list* _List)
{

   return _List->_size;

}
