#pragma once

template<typename Port, std::uint32_t PortNum>
class MyPin
{
public:
  
  static void Toggle()
    {
      Port::ODR::Toggle(1<<PortNum);
    }
  
  static bool IsSet()
    {
      return ((Port::IDR::Get() & (1 << PortNum))! = 0)
    }
  
};