/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: system_alloc.c                                                     */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 9-July-13: Version 1.0: Last Updated                                       */
/* 9-July-13: Version 1.0: Created                                            */
/*                                                                            */
/* Timeperiod: ev7                                                            */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "system_alloc.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    alloc_sys_mem                                                           */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    size_t: process ID of the process be allocated resources                */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    void*: pointer to the page of memory that has been allocated            */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

void* alloc_sys_mem(size_t _ProcessId)
{

   size_t* _FreePageNumber = malloc(sizeof(size_t));

   void* _PageLocation;

   /* in the future this will need a global lock */

   free_page_list* _g_page_table_reference = sys_get_free_page_list();

   process* _g_process = sys_get_process(_ProcessId);

   #if DEBUG 

      if (!_g_process) 
      {

         printf("Attempting to allocate a page to a non-existant process, dumping the process table...\n");

         exit();

      }

   #endif

   _FreePageNumber = _Pagedouble_linked_list_pop_front(free_page_list);

   vector_push_back(_g_process.heap_pages, _FreePageNumber);

   /* set up page to rw within only that process */

   _PageLocation = sys_set_page_properties(_g_process, _FreePageNumber);

   /* unlock global alloc lock */

   return _PageLocation;

}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    free_sys_mem                                                            */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    void*: pointer to a page of memory that will no longer be allocated     */
/*         : to a particular process                                          */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    uint8_t: a vga color to be used in a terminal                           */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

void free_sys_mem(void*)
{

}

/* ************************************************************************** */
/* ************************************************************************** */
