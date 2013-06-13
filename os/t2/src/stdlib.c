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

   str_cpy(_String, _Pointer);

   return _String;

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

   str_cpy(_String, _Pointer);

   return _String;

}

/* ************************************************************************** */
/* End of file stdlib.c                                                        */
/* ************************************************************************** */
/* ************************************************************************** */
