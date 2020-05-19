#pragma once

#include "thread.hpp"
#include "event.hpp"
#include "ButtonTask.hpp"
#include "ADC.hpp"
#include "USART.hpp"
#include "IVariable.hpp"

class VariableTask : public OsWrapper::Thread<128>
{
private:
  float VoltageValue;
  float TemperatureValue;
  OsWrapper::Event& myEvent;  

  
public:
  void Execute() override;
  VariableTask(OsWrapper::Event& event);
};