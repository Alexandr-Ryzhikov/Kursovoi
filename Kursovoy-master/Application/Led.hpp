#pragma once

#include "LedTask.hpp"
#include "PWM.hpp"

using namespace std;
class Led
{
protected:
  uint16_t DutyCycle;
  float k = 18431.875;
  float b = 4709.8125;
public:
  void CalculateDutyCycle(uint16_t Value)
  {
    DutyCycle = k*Value + b;
  }
};