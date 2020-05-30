#pragma once
#include "gpiocregisters.hpp"
#include "rccregisters.hpp"
#include "tim3registers.hpp"

using namespace std;
template <typename Timer>
class PWM
{
public: 
  void SetDuty(uint16_t DutyCycle)
  { 
    Timer::CCR3::Write(DutyCycle);
  }

};
