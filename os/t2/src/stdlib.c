/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: stdlib.c                                                           */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 13-June-13: Version 1.0: Last Updated                                      */
/* 13-June-13: Version 1.0: Created                                           */
/*                                                                            */
/* Timeperiod: ev7                                                            */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "stdlib.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    itoa                                                                    */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    int: integer to be converted                                            */
/*    char*: string to store the integer into                                 */
/*    int: base of the number                                                 */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    char*: pointer to a string                                              */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

char* itoa(int _Integer, char* _String, int _Base)
{

   int _Signed = 0;

   char _Buffer[39 + 1]; /* 39 digits -- size of a 128 bit integer + 1 for sign */

   char* _Pointer = _Buffer + 39; /* leave the last character to be '\0' */

   *(_Pointer + 1) = '\0';

   if (_Integer < 0)
   {

      _Integer * -1;

      _Signed = 1;

   }

   do
   {

      if ((_Integer % _Base) > 9) *--_Pointer = '0' + (_Integer % _Base) + 7;

      else *--_Pointer = '0' + (_Integer % _Base); /* character 0 + whatever number it is, gets the ascii value of that number */

   } while (_Integer / _Base);

   if (_Signed) *--_Pointer = '-';

   strcpy(_String, _Pointer);

   return _Pointer;

}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    free                                                                    */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    void*: pointer to be freed                                              */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    void                                                                    */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

void free(void* _Memory)
{



}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    malloc                                                                  */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    size: size in bytes to be allocated                                     */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    void* pointer to the memory allocated                                   */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

void* malloc(size_t _Size)
{

   static char* _s_malloc_array = 0;
   static size_t _s_current_size = 0;

   char* _ReturnPointer = 0;
   _Size = next_power_of_two(_Size);

   if (_Size > _s_current_size)
   {

      if (!_s_malloc_array) _s_malloc_array = sysbrk(MALLOC_SIZE);
      
      /* check free list for memory */

      else
      {

         if (_s_current_size < MALLOC_UPDATE_THRESHOLD)
         {

            /* This operation will tolerate a memory leak of < 256 bytes */

            _s_malloc_array = sysbrk(MALLOC_SIZE);

            _s_current_size = MALLOC_SIZE;

         }

         else 
         {

            /* if larger than 1MB then get the memory from the operating system directly */
            return sysbrk(_Size);

         }

      }

   }

   _ReturnPointer = _s_malloc_array;

   _s_malloc_array += _Size;

   _s_current_size += _Size;

   return (void*)_ReturnPointer;

}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    manage_free_list                                                        */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    void* : pointer to a block of memory to be used with malloc             */
/*    enum MALLOC_STATE: state in which to manage the free list               */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    void*: pointer to a block of memory to be used by malloc                */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

void* manage_free_list(void* _Memory, MALLOC_STATE _State)
{

   static bn_tree* _s_tree = 0;

   static hash_table* _s_mem_beg = 0;

   static hash_table* _s_mem_end = 0;

   static hash_table* _s_loaned_nodes = 0;

   if (!_s_tree)
   {
      
      _s_tree = (bn_tree*)malloc(sizeof(bn_tree));
      
      bn_tree_create(_s_tree);

   }

   if (!_s_mem_beg)
   {

      _s_mem_beg = (hash_table*)malloc(sizeof(hash_table));
      
      hash_table_create(_s_mem_beg, 10000); /* 40,000 byte hash table */

   }

   if (!_s_mem_end)
   {

      _s_mem_end = (hash_table*)malloc(sizeof(hash_table));

      hash_table_create(_s_mem_end, 10000); /* 40,000 byte hash table */

   }

   if (!_s_loaned_nodes)
   {

      _s_loaned_nodex = (hash_table*)malloc(sizeof(hash_table));

      hash_table_create(_s_loaned_nodes, 10000); /* 40,000 byte hash table */

   }

   switch (_State):
   {

      case MALLOC_REMOVE:
      {
      
         break;

      }

      case MALLOC_INSERT:
      {

         break;

      }

      case MALLOC_UPDATE:
      {

         break;

      }

   }
}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    uitoa                                                                   */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    usigned int: integer to be converted                                    */
/*    char*: string to store the integer into                                 */
/*    int: base of the number                                                 */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    char*: pointer to a string                                              */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

char* uitoa(unsigned int _Integer, char* _String, int _Base)
{

   int _Signed = 0;

   char _Buffer[39 + 1]; /* 39 digits -- size of a 128 bit integer + 1 for sign */

   char* _Pointer = _Buffer + 39; /* leave the last character to be '\0' */

   *(_Pointer + 1) = '\0';

   if (_Integer < 0)
   {

      _Integer * -1;

      _Signed = 1;

   }

   do
   {

      if ((_Integer % _Base) > 9) *--_Pointer = '0' + (_Integer % _Base) + 7;

      else *--_Pointer = '0' + (_Integer % _Base); /* character 0 + whatever number it is, gets the ascii value of that number */

   } while (_Integer / _Base);

   if (_Signed) *--_Pointer = '-';

   strcpy(_String, _Pointer);

   return _String;

}

/* ************************************************************************** */
/* End of file stdlib.c                                                        */
/* ************************************************************************** */
/* ************************************************************************** */
