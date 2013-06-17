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

   _List->m_head = (double_linked_list_node*)malloc(sizeof(double_linked_list_node));
   
   _List->m_tail = (double_linked_list_node*)malloc(sizeof(double_linked_list_node));

   memset(_List->m_head, 0, sizeof(double_linked_list_node));

   memset(_List->m_tail, 0, sizeof(double_linked_list_node));

   _List->m_head->m_next = _List->m_tail;

   _List->m_tail->m_prev = _List->m_head;

   _List->m_size = 0;

}

void double_linked_list_free(double_linked_list* _List)
{

   double_linked_list_clear(_List);  

}

/* ************************************************************************** */
/* ************************************************************************** */

/* General functions for a linked_list struct                                */

/* ************************************************************************** */
/* ************************************************************************** */

void** double_linked_list_at(double_linked_list* _List, int _Position)
{

   int _Count;

   double_linked_list_node* _Pointer = _List->m_head->m_next;

   for (_Count = 0; _Count < _Position; ++_Count) _Pointer = _Pointer->m_next;

   return &_Pointer->m_data;

}

void** double_linked_list_back(double_linked_list* _List)
{

   return &_List->m_tail->m_prev->m_data;

}

void double_linked_list_clear(double_linked_list* _List)
{

   double_linked_list_node* _AheadPointer = _List->m_head->m_next;
   double_linked_list_node* _BehindPointer = _AheadPointer;

   while (_AheadPointer != _List->m_tail)
   {
      
      _AheadPointer = _AheadPointer->m_next;
      free(_BehindPointer);
      _BehindPointer = _AheadPointer;
   
   }

   _List->m_head->m_next = _List->m_tail;
   _List->m_tail->m_prev = _List->m_head;
   _List->m_size = 0;

}

void double_linked_list_empty(double_linked_list* _List)
{

   double_linked_list_clear(_List);

}

void** double_linked_list_front(double_linked_list* _List)
{

   return &_List->m_head->m_next->m_data;

}

void* double_linked_list_pop_back(double_linked_list* _List)
{

   void* _Return;

   _Return = _List->m_tail->m_prev->m_data;

   if (_List->m_size == 1)
   {

      free(_List->m_tail->m_prev);
      
      _List->m_size = 0;
      
      _List->m_tail->m_prev = _List->m_head;
   
      _List->m_head->m_next = _List->m_tail;
   
   }

   else
   {

      _List->m_tail->m_prev = _List->m_tail->m_prev->m_prev;

      free(_List->m_tail->m_prev->m_next);
      
      _List->m_tail->m_prev->m_next = _List->m_tail;
      
      --_List->m_size;
   
   }

   return _Return;

}

void double_linked_list_push_back(double_linked_list* _List, void* _Data)
{

   double_linked_list_node* _Prev;

   if (_List->m_size == 0)
   {

      _List->m_head->m_next = (double_linked_list_node*)malloc(sizeof(double_linked_list_node));
   
      _List->m_head->m_next->m_next = _List->m_tail;

      _List->m_tail->m_prev = _List->m_head->m_next;
      
      _List->m_head->m_next->m_data = _Data;
      
      ++_List->m_size;
   
   }

   else
   {

      _Prev = _List->m_tail->m_prev;

      _List->m_tail->m_prev = (double_linked_list_node*)malloc(sizeof(double_linked_list_node));
      
      _List->m_tail->m_prev->m_next = _List->m_tail;

      _List->m_tail->m_prev->m_prev = _Prev;
      
      _Prev->m_next = _List->m_tail->m_prev;
      
      _List->m_tail->m_prev->m_data = _Data;
      
      ++_List->m_size;
   
   }

}

void double_linked_list_push_front(double_linked_list* _List, void* _Data)
{

   double_linked_list_node* _Prev;

   if (_List->m_size == 0)
   {

      _List->m_head->m_next = (double_linked_list_node*)malloc(sizeof(double_linked_list_node));
   
      _List->m_head->m_next->m_next = _List->m_tail;

      _List->m_tail->m_prev = _List->m_head->m_next;
      
      _List->m_head->m_next->m_data = _Data;
      
      ++_List->m_size;
   
   }

   else
   {

      _Prev = _List->m_head->m_next;

      _List->m_head->m_next = (double_linked_list_node*)malloc(sizeof(double_linked_list_node));
      
      _List->m_head->m_next->m_prev = _List->m_head;

      _List->m_head->m_next->m_next = _Prev;
      
      _Prev->m_prev = _List->m_head->m_next;
      
      _List->m_head->m_next->m_data = _Data;
      
      ++_List->m_size;
   
   }

}

void double_linked_list_remove(double_linked_list* _List, int _Position)
{
 
   int _Count;
   double_linked_list_node* _Pointer;

   _Pointer = _List->m_head->m_next;

   #if DEBUG

      if (_Position > _List->m_size || _List->m_size == 0) return;

   #endif

   if (_List->m_size == 1)
   {

      free(_List->m_head->m_next);
      
      _List->m_head->m_next = _List->m_tail;

      _List->m_tail->m_prev = _List->m_head;
      
      _List->m_size = 0;
   
      return;

   }

   else if(_Position == 0)
   {

      _List->m_head->m_next = _List->m_head->m_next->m_next;
      
      free(_List->m_head->m_next->m_prev);

      _List->m_head->m_next->m_prev = _List->m_head;
      
      --_List->m_size;

      return;
   
   }

   else if (_Position == _List->m_size - 1)
   {

      _List->m_tail->m_prev = _List->m_tail->m_prev->m_prev;

      free(_List->m_tail->m_prev->m_next);

      _List->m_tail->m_prev->m_next = _List->m_tail;
      
      --_List->m_size;

      return;
   
   }

   for (_Count = 0; _Count < _Position - 1; ++_Count) _Pointer = _Pointer->m_next;
 
   _Pointer->m_next = _Pointer->m_next->m_next;

   free(_Pointer->m_next->m_prev);

   _Pointer->m_next->m_prev = _Pointer;
      
   --_List->m_size;

}

int double_linked_list_size(double_linked_list* _List)
{

   return _List->m_size;

}
