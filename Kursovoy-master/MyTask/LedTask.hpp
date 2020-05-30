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
    Value = Variabletask.GetVolt();
    Sleep(500ms);
    led1.SetDutyCycle();
  }
  
  
};