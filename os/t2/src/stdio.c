/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: stdio.c                                                            */
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

#include "stdio.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    printf                                                                  */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    const char*: string                                                     */
/*    vargs: formatted input                                                  */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    int: amount of characters written                                       */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

int printf(const char* _String, ...)
{
   const char* _Pointer;

   static terminal _Terminal;

   static int _Initialized = 0;

   if (!_Initialized) terminal_create_terminal(_Terminal);

   va_list _Args;

   va_start(_Args, _String);

   for (_Pointer = _String; *_Pointer != '\0'; ++_Pointer)
   {

      if (*_Pointer != '%')
      {

         putchar(*_Pointer);

         continue;

      }

      switch(*++_Pointer)
      {

         int _Integer;

         unsigned int _UInteger;

         char _Buffer[40];

         char* _String;

         case 'i':

            _Integer = va_arg(_Args, int);

            _String = itoa(_Integer, _Buffer, 10);

            terminal_write_string(&_Terminal, _String);
   
            break;
   
         case 'd':

            _Integer = va_arg(_Args, int);

            terminal_write_string(&_Terminal, itoa(_Integer, _Buffer, 10));
   
            break;
   
         case 'u':

            _UInteger = va_arg(_Args, unsigned int);

            terminal_write_string(&_Terminal, uitoa(_UInteger, _Buffer, 10));
   
            break;
   
         case 'o':

            _Integer = va_arg(_Args, int);

            terminal_write_string(&_Terminal, itoa(_Integer, _Buffer, 8));
   
            break;
   
         case 'x':

            _UInteger = va_arg(_Args, unsigned int);

            _String = uitoa(_UInteger, _Buffer, 16);

            for (; _String != '\0'; ++_String) if (*_String > 64) *_String = *_String + 32;

            terminal_write_string(&_Terminal, _Buffer);

            break;

         case 'X':

            _UInteger = va_arg(_Args, unsigned int);

            _String = uitoa(_UInteger, _Buffer, 16);

            terminal_write_string(&_Terminal, _Buffer);

            break;

         case 'c':

            _Integer = va_arg(_Args, int);

            terminal_put_char(&_Terminal, _Integer);

            break;

         case 's':

            _String = va_arg(_Args, char*);

            terminal_write_string(&_Terminal, _String);

            break;

         case 'p':

            _UInteger = (int)va_arg(_Args, void*);

            terminal_write_string(&_Terminal, uitoa(_UInteger, _Buffer, 16));

            break;
         
         case '%':

            terminal_put_char(&_Terminal, '%');

            break;    

      }

   }

}

/* ************************************************************************** */
/* ************************************************************************** */
/* End of file stdio.c                                                        */
/* ************************************************************************** */
/* ************************************************************************** */
