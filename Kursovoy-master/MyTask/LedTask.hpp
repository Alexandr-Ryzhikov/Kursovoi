#pragma once

#include "thread.hpp"
#include "VariableTask.hpp"
#include "Led.hpp"

template <auto& Variabletask>
class LedTask : public OsWrapper::Thread<128> 
{
private:
  float Value;
  Led led1;
public:
  void Execute() override
  {
    for( ; ; )
    {
    Value = Variabletask.GetVolt();
    Sleep(100ms);
    led1.CalculateDutyCycle(Value);
    led1.SetDutyCycle();
    }
  }
  
  
};