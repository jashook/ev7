////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// Author: Jarret Shook
//
// Module: process.hpp
//
// Modifications:
//
// 25-July-13: Version 1.0: Last Updated
// 25-July-13: Version 1.0: Created
//
// Timeperiod: ev7n
//
// Notes:
//
//    To compile: g++ -i include/ *.cpp
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#ifndef __PROCESS_HPP__
#define __PROCESS_HPP__

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "base.hpp"
#include "frame_list.hpp"
#include "kernel.hpp"

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

namespace el {
namespace ev7n {

template <typename __Type, std::size_t __MinCycles, std::size_t __MaxCycles> class process : public kernel<_s_frame_size>
{
   
   private:   // Member Variables

      frame_list<__Type>* _m_frames;
      std::size_t _m_clock_cycles;
      std::size_t _m_max_clock_cycles;
      std::size_t _m_min_clock_cycles;
      std::size_t _m_pid;

      enum _m_logging_type { CREATION, READ, WRITE, READFAULT, WRITEFAULT, TERMINATING };
      
   public:   // Member Functions

      void increment_clock() { _increment_clock(); }
      void log(_m_logging_type _Message) { _log(_Message); }
      void read_page(std::size_t _PageNumber) { _read_page(_PageNumber); }
      void scan_the_use_bits() { _scan_the_use_bits(); }

   public:   // Constructor | Destructor

      process(std::size_t _Pid, std::size_t _Frames) : _m_clock_cycles(0), _m_max_clock_cycles(__MaxCycles), _m_min_clock_cycles(__MinCycles), _m_pid(_Pid) 
      { 
         _ctor(_Frames);

         this->log(CREATION); 
         
      }

      ~process() 
      {
         _dtor();
      
      }

   private:   // Private Member Functions

      void _ctor(std::size_t _Frames)
      {
         _m_frames = new frame_list<__Type>(_Frames);

      }

      void _dtor()
      {
         delete _m_frames;

      }

      void _increment_clock()
      {
         ++_m_clock_cycles;

         // check if the current amount of clock cycles is equal to the max amount of clock cycles

         if (_m_clock_cycles >= _m_max_clock_cycles)
         {
            this->scan_use_bits();

         }

      }

      void _log(_m_logging_type _Message, std::size_t _Page)
      {
         switch (_Message)
         {
            case CREATION:
            
               std::cout << "Creating a new process, Process: " << _m_pid << ".  Size: " << _m_frames.size() << ".  Page Table size is " << _m_frames.size() << "." << std::endl;

               break;

            case READ:

               std::cout << "Process: " << _m_pid << " is reading from page number " << _Page << ". Page already in memory, setting use bit to 1." << std::endl;

               break;

            case WRITE:
            
               std::cout << "Process: " << _m_pid << " is writing to page number " << _Page << ". Page already in memory, setting use bit to 1." << std::endl;

               break;

            case READFAULT:

               std::cout << "Process: " << _m_pid << " is reading from page number " << _Page << ". Page fault, setting use bit to 1." << std::endl;
               
               break;
            
            case WRITEFAULT:

               std::cout << "Process: " << _m_pid << " is writing to page number " << _Page << ". Page fault, setting use bit to 1." << std::endl;
               
               break;

            case TERMINATING:

               std::cout << "Process: " << _m_pid << " is terminating.  Page frames being released." << std::endl;
               
               break;

         }

      }

      void _read_page(std::size_t _PageNumber)
      {

         bool _Resident = _m_frames->check_resident(_PageNumber);

         if (_Resident)
         {
            this->log(READ);

         }

         else
         {
            this->log(READFAULT);

         }

         // check if page is resident
         // log if resident
         // log if fault
         // allocate frame for page if fault
         // increase global clock

      }

      void _scan_the_use_bits()
      {

         _m_frames->scan_use_bits();

      }

};   // end of class process

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

} // end of namespace(ev7n)
} // end of namespace(el)

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#endif // __PROCESS_HPP__

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
