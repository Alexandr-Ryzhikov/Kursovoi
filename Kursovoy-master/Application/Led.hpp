#pragma once

#include "LedTask.hpp"
#include "PWM.hpp"
#include "tim3registers.hpp"

using namespace std;
class Led
{
protected:
  uint16_t DutyCycle;
  float k = 18431.875F;
  float b = 4709.8125F;
  PWM<TIM3> pwm;
public:
  void CalculateDutyCycle(uint16_t Value)
  {
    if (Value >= 0.3F)
    {
      DutyCycle = static_cast<uint16_t>(k*static_cast<float>(Value) + b);
    }
    else
      DutyCycle = 0;
  }
  void SetDutyCycle()
  {
    pwm.SetDuty(DutyCycle);
  }
};