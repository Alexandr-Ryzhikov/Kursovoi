#pragma once
#include "gpioaregisters.hpp" //for GPOA
#include "gpioaregisters.hpp"//for GPOC

class Led
{
public
template <typename Port, std::uint32_t pinNum>
{
  static void Toggle()
  {
    Port::ODR::Toggle(1<<pinNum);
  }
};
