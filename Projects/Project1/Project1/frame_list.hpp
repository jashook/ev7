////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// Author: Jarret Shook
//
// Module: frame_list.hpp
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

#ifndef __FRAME_LIST_HPP__
#define __FRAME_LIST_HPP__

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include <vector>

#include "base.hpp"

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

namespace el {
namespace ev7n {

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template <typename __Type> class frame_list
{

   private:   // Member Variables

      std::vector<__Type>* _m_vector;

   public:   // Member Functions

      void add_page(std::size_t _PageFrame) { _add_page(_PageFrame); }
      bool check_resident(std::size_t _PageFrame) { _check_resident(_PageFrame); }
      void scan_use_bits() { _scan_use_bits(); }
      std::size_t size() { return _size(); }
     
   public:  // Constructor | Destructor

      frame_list(std::size_t _Size) : _m_vector(NULL) { _ctor(_Size); }

      ~frame_list() { _dtor(); }

   private:   // Helper Member Functions

      void _add_page(std::size_t _PageFrame) { _m_vector->push_back(_PageFrame); }

      bool _check_resident(std::size_t _PageFrame)
      {
         std::vector<__Type>::iterator _Iterator = _m_vector->begin();

         bool _Resident = false;

         while (_Iterator != _m_vector->end())
         {
            if ((*_Iterator).get_frame_number() == _PageFrame) 
            {
               _Resident = true;

               break;
            }

         }

         return _Resident;

      }

      void _ctor(std::size_t _Size) { _m_vector = new std::vector<__Type>(__Size); }

      void _dtor() { delete _m_vector; }

      void _scan_use_bits()
      {
         std::vector<__Type>::iterator _Iterator = _m_vector->begin();

         while (_Iterator != _m_vector->end())
         {
            if ((*_Iterator).resident()) (*_Iterator).set_resident(0);

            else _m_vector->erase(_Iterator);

         }

      }

      std::size_t _size() { return _m_vector->size(); }

};   // end of class frame_list.hpp

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

} // end of namespace(ev7n)
} // end of namespace(el)

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#endif   // __FRAME_LIST_HPP__

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////