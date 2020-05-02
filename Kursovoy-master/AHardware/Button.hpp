#pragma once
#include "MyPin.hpp"

template<typename Pin>
class Button
{
  public:
   bool IsPushed()
    {
      return !Pin::IsSet();
        
    }
};