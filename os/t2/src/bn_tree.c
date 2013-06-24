/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: bn_tree.c                                                          */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 21-June-13: Version 1.0: Last Updated                                      */
/* 21-June-13: Version 1.0: Created                                           */
/*                                                                            */
/* Timeperiod: ev7                                                            */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "bn_tree.h"

/* ************************************************************************** */
/* ************************************************************************** */

/* functions for creating and freeing a bn_tree struct */

void bn_tree_create(bn_tree* _Tree)
{

   memset(&_Tree->m_root, 0, sizeof(bn_tree_node));

   _Tree->m_size = 0;

}

void bn_tree_free(bn_tree* _Tree)
{

   bn_tree_free_with_children(&_Tree->m_root);

   #if DEBUG

      memset(_Tree->m_root, 0, sizeof(bn_tree_node));

   #endif

}

/* ************************************************************************** */
/* ************************************************************************** */

int bn_tree_contains(bn_tree* _Tree, void* _Key, int (*_compare)(void*, void*))
{

   bn_tree_node* _CurrentNode = &_Tree->m_root;

   while (_CurrentNode)
   {

      int _CompareValue;

      _CompareValue = _compare(_Key, _CurrentNode->m_key);

      if (_CompareValue == 0) return 1;

      _CurrentNode = _CompareValue > 1 ? _CurrentNode->m_right : _CurrentNode->m_left;

   }

   return 0;

}

void bn_tree_free_with_children(bn_tree_node* _Node)
{

   if (_Node->m_left) bn_tree_free_with_children(_Node);

   if (_Node->m_right) bn_tree_free_with_children(_Node);

   free(_Node);

}

void bn_tree_insert(bn_tree* _Tree, void* _Key, void* _Data, int (*_compare)(void*, void*))
{

   bn_tree_node* _CurrentNode, *_ParentNode = &_Tree->m_root;

   int _CompareValue;

   while (_CurrentNode)
   {

      _CompareValue = _compare(_Key, _CurrentNode->m_key);

      if (_CompareValue == 0) return;

      _CurrentNode = _CompareValue > 1 ? _CurrentNode->m_right : _CurrentNode->m_left;

      _ParentNode = _CurrentNode == 0 ? _ParentNode : _CurrentNode;

   }

   if (_CompareValue > 1) _ParentNode->m_right = (bn_tree_node*)malloc(sizeof(bn_tree_node));

   else _ParentNode->m_left = (bn_tree_node*)malloc(sizeof(bn_tree_node));

   _ParentNode = _CompareValue > 1 ? _ParentNode->m_right : _ParentNode->m_left;

   #if DEBUG

      memset(_ParentNode, 0, sizeof(bn_tree_node));

   #endif

   _ParentNode->m_key = _Key;

   _ParentNode->m_data = _Data;

   ++_Tree->m_size;

}

void bn_tree_remove(bn_tree* _Tree, void* _Key, int (*_compare)(void*, void*))
{

   bn_tree_node* _CurrentNode, *_ParentNode = &_Tree->m_root;

   int _CompareValue;

   while (_CurrentNode)
   {

      _CompareValue = _compare(_Key, _CurrentNode->m_key);

      if (_CompareValue == 0) break;

      _CurrentNode = _CompareValue > 1 ? _CurrentNode->m_right : _CurrentNode->m_left;

      _ParentNode = _CurrentNode == 0 ? _ParentNode : _CurrentNode;

   }

   if (_CurrentNode)
   {

      bn_tree_node* _DescendingPointer = _CurrentNode->m_left;

      _CompareValue = _compare(_Key, _ParentNode->m_key);

      if (_CompareValue > 1) _ParentNode->m_right = _CurrentNode->m_left; 

      else  _ParentNode->m_left = _CurrentNode->m_left;
   
      while (_DescendingPointer->m_right)
      {

         _DescendingPointer = _DescendingPointer->m_right;

      }

      _DescendingPointer->m_right = _CurrentNode->m_right;

      free(_CurrentNode);

   }

 }

void* bn_tree_search(bn_tree* _Tree, void* _Key, int (*_compare)(void*, void*))
{

   bn_tree_node* _CurrentNode = &_Tree->m_root;

   while (_CurrentNode)
   {

      int _CompareValue;

      _CompareValue = _compare(_Key, _CurrentNode->m_key);

      if (_CompareValue == 0) return _CurrentNode->m_data;

      _CurrentNode = _CompareValue > 1 ? _CurrentNode->m_right : _CurrentNode->m_left;

   }

   return 0;

}

int bn_tree_size(bn_tree* _Tree)
{

   return _Tree->m_size;

}

/* ************************************************************************** */
/* ************************************************************************** */
