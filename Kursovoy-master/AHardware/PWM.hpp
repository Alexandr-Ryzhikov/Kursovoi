#pragma once
#include "gpiocregisters.hpp"
#include "rccregisters.hpp"
#include "tim3registers.hpp"

template <typename Timer>
class PWM
{
public: 
  void SetDuty (uint16_t DutyCycle)
  { 
    Timer::CCR3=DutyCycle;
  }

};
