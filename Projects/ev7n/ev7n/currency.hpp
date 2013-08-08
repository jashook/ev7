////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// Author: Jarret Shook
//
// Module: currency.hpp
//
// Modifications:
//
// 2-Aug-13: Version 1.0: Last Updated
// 2-Aug-13: Version 1.0: Created
//
// Timeperiod: ev7n
//
// Notes:
//
//    gcc -I include/ *.cpp -lrt
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#ifndef __CURRENCY_HPP__
#define __CURRENCY_HPP__

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

namespace ev7n {
namespace el {

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

class currency
{

   private:   // Member Variables

      std::size_t _m_gold;
      std::size_t _m_silver;
      std::size_t _m_bronze;

   public:   // Member Functions

      void add_currency(currency& _Currency) { _add_currency(_Currency); }
      bool remove_currency(currency& _CurrencyDestination, std::size_t _Gold = 0, std::size_t _Silver = 0, std::size_t _Bronze = 0) { _remove_currency(_CurrencyDestination, _Gold, _Silver, _Bronze); }

   public:   // Constructor | Destructor

      currency() : _m_gold(0), _m_silver(0), _m_bronze(0) { }
      ~currency() { }

   private:   // Copy Constructor

      currency(currency& _Rhs) { // do nothing }

   private:   // Helper Functions

      void _add_currency(currency& _Currency)
      {
         if (_Currency._m_gold) _m_gold += _Currency._m_gold;
      
         if (_Currency._m_silver) _m_silver += _Currency._m_silver;
   
         if (_Currency._m_bronze) _m_bronze += _Currency._m_bronze;

      }

      std::size_t _get_gold() { return _m_gold; }
      std::size_t _get_silver() { retun _m_silver; }
      std::size_t _get_bronze() { return _m_bronze; }

      bool _remove_currency(currency& _CurrencyDestination, std::size_t _Gold, std::size_t _Silver, std::size_t _Bronze)
      {
         if (_m_gold >= _Gold) 
         {
            _CurrencyDestination._m_gold += _Gold;

            _m_gold -= _Gold;   

         }

         if (_m_silver >= _Silver) 
         {
            _CurrencyDestination._m_silver += _Silver;

            _m_silver -= _Silver;

         }

         if (_m_bronze >= _Bronze)
         {
            _CurrencyDestination._m_bronze += _Bronze;

            _m_bronze -= _Bronze;

         } 

      }

};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

}   // end of namespace el
}   // end of namespace ev7n

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#endif // __CURRENCY_HPP__

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////