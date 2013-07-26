////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// Author: Jarret Shook
//
// Module: frame.hpp
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

#ifndef __FRAME_HPP__
#define __FRAME_HPP__

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include "base.hpp"

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

namespace el {
namespace ev7n {

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

class frame
{

   private:   // Member Variables

      std::size_t _m_frame_number;
      std::size_t _m_page_number;
      bool _m_resident;

   public:   // Member Functions

      std::size_t get_frame_number() { return _get_frame_number(); }
      std::size_t get_page_number() { return _get_page_number(); }
      std::size_t resident() { return _resident(); }

      void set_frame_number(std::size_t _FrameNumber) { _set_frame_number(_FrameNumber); }
      void set_page_number(std::size_t _PageNumber) { _set_page_number(_PageNumber); }
      void set_resident(bool _Resident) { _set_resident(_Resident); }

   public:   // Contructor | Destructor

      frame(std::size_t _PageNumber, std::size_t _FrameNumber) : _m_page_number(_PageNumber), _m_frame_number(_FrameNumber), _m_resident(true) { }

      virtual ~frame() { }

   private:   // private Member Functions

      std::size_t _get_frame_number() { return _m_frame_number; }
      std::size_t _get_page_number() { return _m_page_number; }
      std::size_t _resident() { return _m_resident; }

      void _set_frame_number(std::size_t _FrameNumber) { _m_frame_number = _FrameNumber; }
      void _set_page_number(std::size_t _PageNumber) { _m_page_number = _PageNumber; }
      void _set_resident(bool _Resident) { _m_resident = _Resident; }

};   // end of class frame

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

} // end of namespace(ev7n)
} // end of namespace(el)

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#endif   // __FRAME_HPP__

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////