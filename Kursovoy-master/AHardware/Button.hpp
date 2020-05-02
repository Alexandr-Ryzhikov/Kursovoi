#pragma once
#include "MyPin.hpp"  //for MyPin

template<typename Pin>

class Button
{
  public:
   bool IsPushed()
    {
      return !Pin::IsSet();   
    }
};