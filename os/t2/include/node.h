/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: node.h                                                             */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 14-June-13: Version 1.0: Created                                           */
/*                                                                            */
/* Timeperiod: ev7                                                            */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#ifndef __NODE_H__
#define __NODE_H__

/* ************************************************************************** */
/* ************************************************************************** */

#include <stddef.h>

/* ************************************************************************** */
/* ************************************************************************** */

typedef struct avl_tree_node
{
   void* m_key;
   void* m_data;
   struct avl_tree_node* m_left_child;
   struct avl_tree_node* m_right_child;
   struct avl_tree_node* m_parent;
   size_t m_height;

} avl_tree_node;

typedef struct bn_tree_node
{
   void* m_key;
   void* m_data;
   struct bn_tree_node* m_left;
   struct bn_tree_node* m_right;

} bn_tree_node;

typedef struct double_linked_list_node
{
   void* m_data;
   struct double_linked_list_node* m_prev;
   struct double_linked_list_node* m_next;

} double_linked_list_node;

typedef struct linked_list_node
{
   void* m_data;
   struct linked_list_node* m_next;

} linked_list_node;

/* ************************************************************************** */
/* ************************************************************************** */
 
#endif /* __NODE_H__ */

/* ************************************************************************** */
/* ************************************************************************** */
