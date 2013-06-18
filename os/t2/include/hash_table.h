/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: hash_table.h                                                       */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 17-June-13: Version 1.0: Last Updated                                      */
/* 17-June-13: Version 1.0: Created                                           */
/*                                                                            */
/* Version: 1.0                                                               */
/*                                                                            */
/* Timeperiod: ev7                                                            */
/*                                                                            */
/* Notes: To Properly use and free memory use the create or delete functions  */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

/* ************************************************************************** */
/* ************************************************************************** */

#ifdef __unix__

   #include <stdlib.h>
   #include <stdio.h>
   #include <string.h>

#elif WIN32

   #include <stdlib.h>
   #include <stdio.h>
   #include <string.h>

#else

   #include "stdlib.h"
   #include "stdio.h"
   #include "string.h"

#endif

#include "array.h"
#include "pair.h"
#include "vector.h"

/* ************************************************************************** */
/* ************************************************************************** */

/* type definitions */

typedef struct hash_table
{
   
   array* m_array;
   size_t m_size;
   size_t m_capacity;
   size_t m_collisions;

   vector* m_vector;

} hash_table;

/* ************************************************************************** */
/* ************************************************************************** */

/* functions for creating and deleting a hash_table struct */

void hash_table_create(hash_table*, size_t);

void hash_table_free(hash_table*);

/* ************************************************************************** */
/* ************************************************************************** */

/* general functions for a hash_table */

size_t hash_table_capacity(hash_table*);
void hash_table_clear(hash_table*);
size_t hash_table_collisions(hash_table*);
int hash_table_contains(hash_table*, void*, int (*)(void*, void*), size_t (*)(void*));
void hash_table_insert(hash_table*, void*, void*, size_t (*)(void*));
void hash_table_remove(hash_table*, void*, int (*)(void*, void*), size_t (*)(void*));
void* hash_table_search(hash_table*, void*, int (*)(void*, void*), size_t (*)(void*));
size_t hash_table_size(hash_table*);

/* ************************************************************************** */
/* ************************************************************************** */

#endif /* __HASH_TABLE_H__ */

/* ************************************************************************** */
/* ************************************************************************** */
