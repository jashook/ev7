/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/* Author: Jarret Shook                                                       */
/*                                                                            */
/* Module: raw_spin_lock.h                                                    */
/*                                                                            */
/* Modifications:                                                             */
/*                                                                            */
/* 16-July-13: Version 1.0: Last Updated                                      */
/* 16-July-13: Version 1.0: Created                                           */
/*                                                                            */
/* Timeperiod: ev7n                                                           */
/*                                                                            */
/* Notes:                                                                     */
/*                                                                            */
/*    This file provides the definitions for a raw spin lock, which is        */
/*    defined to be a busy wait lock that uses the cmpxchg x86 instruction.   */
/*                                                                            */
/*    This lock is not intended to be used alone or by users simply due to    */
/*    the amount of potential waiting.  Users are therefore suggested to      */
/*    look at the mutex, semaphore or spin_lock definitions for more process  */
/*    friendly locking mechanisms.                                            */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

void spin_lock(int volatile* _Pointer)
{
   while (!__sync_bool_compare_and_swap(_Pointer, 0, 1))
   {

      while(*_Pointer) _mm_pause();
   
   }
}

void spin_unlock(int volatile* _Pointer)
{
   asm volatile (""); // acts as a memory barrier.
    
   *p = 0;
}
