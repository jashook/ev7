/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: system_terminal.h                                                  */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 12-June-13: Version 1.0: Last Updated                                      */
/* 12-June-13: Version 1.0: Created                                           */
/*                                                                            */
/* Version: 1.0                                                               */
/*                                                                            */
/* Timeperiod: ev7                                                            */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#ifndef __SYSTEM_TERMINAL_H__
#define __SYSTEM_TERMINAL_H__

/* ************************************************************************** */
/* ************************************************************************** */

#include "stdint.h"
#include "string.h"

/* ************************************************************************** */
/* ************************************************************************** */

enum VGA_COLOR
{
   COLOR_BLACK = 0,
   COLOR_BLUE = 1,
   COLOR_GREEN = 2,
   COLOR_CYAN = 3,
   COLOR_RED = 4,
   COLOR_MAGENTA = 5,
   COLOR_BROWN = 6,
   COLOR_LIGHT_GREY = 7,
   COLOR_DARK_GREY = 8,
   COLOR_LIGHT_BLUE = 9,
   COLOR_LIGHT_GREEN = 10, 
   COLOR_LIGHT_CYAN = 11, 
   COLOR_LIGHT_RED = 12, 
   COLOR_LIGHT_MAGENTA = 13, 
   COLOR_LIGHT_BROWN = 14, 
   COLOR_WHITE = 15, 
};

/* ************************************************************************** */
/* ************************************************************************** */

typedef struct terminal
{

   size_t m_vga_width;
   size_t m_vga_height;
   size_t m_row;
   size_t m_column;
   uint8_t m_color;
   uint16_t* m_buffer;

} terminal;

/* ************************************************************************** */
/* ************************************************************************** */

uint8_t make_color(enum VGA_COLOR, enum VGA_COLOR);
uint16_t make_vga_entry(char, uint8_t);

void terminal_clear_row(terminal*, size_t);
void terminal_copy_entry_at(terminal*, size_t, size_t);
void terminal_create(terminal*, size_t, size_t);
void terminal_put_char(terminal*, char);
void terminal_put_entry_at(terminal*, char);
void terminal_set_color(terminal*, uint8_t);
void terminal_write_string(terminal*, const char*);

/* ************************************************************************** */
/* ************************************************************************** */



#endif /* __SYSTEM_TERMINAL_H__ */

/* ************************************************************************** */
/* ************************************************************************** */
