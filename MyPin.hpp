#pragma once

template<typename Port, std::uint32_t num>
class MyPin
{
public:
  static void Toggle()
  {
    Port::ODR::Toggle(1<<num);
  }
   static bool IsSet()
  {
    return ((Port::IDR::Get() & (1<< num))!= 0);
  } 
  
};