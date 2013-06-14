/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: string.c                                                           */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 12-June-13: Version 1.0: Last Updated                                      */
/* 12-June-13: Version 1.0: Created                                           */
/*                                                                            */
/* Timeperiod: ev7                                                            */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "string.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    strcmp                                                                  */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    const char*: string to be compared to                                   */
/*    const char*: string to be compared against                              */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    int: ( -1 if less than) ( 0 if equal ) ( 1 if greater than )            */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

int strcmp(const char* _String1, const char* _String2)
{

   int _ReturnValue = 0;

   while (*_String1 != '\0')
   {

      if (*_String2 == '\0')
      {

         _ReturnValue = 1;

         break;

      }

      if (*_String1 != *_String2)
      {

         if (*_String1 < *_String2) _ReturnValue = -1;

         else _ReturnValue = 1;
         
      }

      ++_String1;
      ++_String2;

   }
   
   if (_ReturnValue == 0 && *_String2 == '\0') return _ReturnValue;

   else _ReturnValue = -1;

   return _ReturnValue;

}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    strcpy                                                                  */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    char*: destination string                                               */
/*    const char*: source string                                              */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    void                                                                    */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

void strcpy(char* _Destination, const char* _Source)
{

   while(*_Source != '\0') *_Destination++ = *_Source++;

}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    strlen                                                                  */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    const char*: c-string                                                   */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    int: size of the string                                                 */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

int strlen(const char* _String)
{

   int _Count;

   while(_String[_Count] != '\0') ++_Count;

   return _Count;

}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    mem_cpy                                                                 */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    void*: destination array                                                */
/*    void*: source array                                                     */
/*    size_t: number of elements to copy                                      */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    void* copied array                                                      */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

void* memcpy(void* _DestinationArray, void* _SourceArray, size_t _NumberOfElements)
{

   char* _DestinationArrayBytes = (char*)_DestinationArray;
   char* _SourceArrayBytes = (char*)_SourceArray;

   while(--_NumberOfElements)
   {

      *_DestinationArrayBytes++ = *_SourceArrayBytes++;

   }

   return _DestinationArray;

}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    memset                                                                  */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    void*: array to be set                                                  */
/*    int: value to set                                                       */
/*    size_t: size of the array                                               */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    void                                                                    */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

void memset(void* _Array, int _Value, size_t _Size)
{
   
   size_t _Count;

   for (_Count = 0; _Count < _Size; ++_Count) ((int*)_Array)[_Count] = _Value;

}

/* ************************************************************************** */
/* ************************************************************************** */
/* End of file string.c                                                       */
/* ************************************************************************** */
/* ************************************************************************** */
