/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: system_terminal.c                                                  */
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

#include "system_terminal.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    make_color                                                              */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    enum VGA_COLOR: A color that will be the forground                      */
/*    enum VGA_COLOR: A color that will be the background                     */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    uint8_t: a vga color to be used in a terminal                           */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

uint8_t make_color(enum VGA_COLOR _Foreground, enum VGA_COLOR _Background)
{

   /* 4 bits is half the size of an unsigned char */

   return _Foreground | _Background << 4;

}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    make_vga_entry                                                          */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    char: a character that will cast to an integer                          */
/*    uint8_t: a colore that will be cast to an integer                       */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    uint16_t: a entry that can be used to render a character                */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

uint16_t make_vga_entry(char _Character, uint8_t _Color)
{

   uint16_t _C16 = _Character;
   uint16_t _Color16 = _Color;

   return _C16 | _Color16 << 8;
   
}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    terminal_clear_row                                                      */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    terminal*: a pointer to a terminal struct to be initialized             */
/*    size_t: row number to clear                                             */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    void                                                                    */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

void terminal_clear_row(terminal* _Terminal, size_t _RowNumber)
{

   size_t _Count;

   for (_Count = 0; _Count < _Terminal->m_vga_width; ++_Count)
   {

      const size_t _Index = _RowNumber * _Terminal->m_vga_width + _Count;

      _Terminal->m_buffer[_Index] = make_vga_entry(' ', _Terminal->m_color);

   }

}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    terminal_copy_entry_at                                                  */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    terminal*: a pointer to a terminal struct to be initialized             */
/*    size_t: column source number                                            */
/*    size_t: row source number                                               */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    void                                                                    */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

void terminal_copy_entry_at(terminal* _Terminal, size_t _Column, size_t _Row)
{

   const size_t _DestinationIndex = _Terminal->m_row * _Terminal->m_vga_width + _Terminal->m_column;

   const size_t _SourceIndex = _Row * _Terminal->m_vga_width + _Column;

   _Terminal->m_buffer[_DestinationIndex] = _Terminal->m_buffer[_SourceIndex];

}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    terminal_create                                                         */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    terminal*: a pointer to a terminal struct to be initialized             */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    void                                                                    */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

void terminal_create(terminal* _Terminal, size_t _Width, size_t _Height)
{

   _Terminal->m_vga_height = _Height;
   _Terminal->m_vga_width = _Width;

   _Terminal->m_row = 0;
   _Terminal->m_column = 0;

   _Terminal->m_color = make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
   _Terminal->m_buffer = (uint16_t*)0xB8000;

   size_t _Outer, _Inner;

   for (_Outer = 0; _Outer < _Terminal->m_vga_height; ++_Outer)
   {

      for (_Inner = 0; _Inner < _Terminal->m_vga_width; ++_Inner)
      {

         const size_t _Index = _Outer * _Terminal->m_vga_width + _Inner;

         _Terminal->m_buffer[_Index] = make_vga_entry(' ', _Terminal->m_color);

      }

   }

}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    terminal_put_char                                                       */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    terminal*: a pointer to a terminal struct to be initialized             */
/*    char: character to be put into the terminal                             */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    void                                                                    */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

void terminal_put_char(terminal* _Terminal, char _Character)
{

   if (_Character == '\n') 
   {

      _Terminal->m_column = 0;
      ++_Terminal->m_row;

      return;

   }

   terminal_put_entry_at(_Terminal, _Character);

   if (++_Terminal->m_column == _Terminal->m_vga_width)
   {

      _Terminal->m_column = 0;

      if (++_Terminal->m_row == _Terminal->m_vga_height)
      {
   
         size_t _SavedRowNumber, _SavedColumnNumber, _ColumnCount, _RowCount;

         _SavedRowNumber = _Terminal->m_row;
         _SavedColumnNumber = _Terminal->m_column;

         for (_RowCount = 0; _RowCount < _Terminal->m_vga_height - 1; ++_RowCount)
         {

            _Terminal->m_row = _RowCount;
 
            for (_ColumnCount = 0; _ColumnCount < _Terminal->m_vga_width; ++_ColumnCount)
            {

               _Terminal->m_column = _ColumnCount;

               terminal_copy_entry_at(_Terminal, _Terminal->m_column, _Terminal->m_row + 1);

            }

         }

         terminal_clear_row(_Terminal, _Terminal->m_vga_height - 1);

         _Terminal->m_row = _SavedRowNumber - 1;
         _Terminal->m_column = _SavedColumnNumber;

      }

   }

}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    terminal_put_entry_at                                                   */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    terminal*: a pointer to a terminal struct to be initialized             */
/*    char: character to be put into the terminal                             */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    void                                                                    */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

void terminal_put_entry_at(terminal* _Terminal, char _Character)
{

   const size_t _Index = _Terminal->m_row * _Terminal->m_vga_width + _Terminal->m_column;

   _Terminal->m_buffer[_Index] = make_vga_entry(_Character, _Terminal->m_color);

}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    terminal_set_color                                                      */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    terminal*: a pointer to a terminal struct to be initialized             */
/*    uint8_t: a vga color (see make_color)                                   */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    void                                                                    */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

void terminal_set_color(terminal* _Terminal, uint8_t _Color)
{

   _Terminal->m_color = _Color;

}

/* ************************************************************************** */
/* ************************************************************************** */
/* Function:                                                                  */
/*                                                                            */
/*    terminal_write_string                                                   */
/*                                                                            */
/* Arguements:                                                                */
/*                                                                            */
/*    terminal*: a pointer to a terminal struct to be initialized             */
/*    const char*: pointer to a string to be written to the terminal          */
/*                                                                            */
/* Returns:                                                                   */
/*                                                                            */
/*    void                                                                    */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */


void terminal_write_string(terminal* _Terminal, const char* _String)
{

   size_t _Count = 0;

   while (_String[_Count] != '\0') terminal_put_char(_Terminal, _String[_Count++]);

}

/* ************************************************************************** */
/* ************************************************************************** */
/* End of file system_terminal.c                                              */
/* ************************************************************************** */
/* ************************************************************************** */
