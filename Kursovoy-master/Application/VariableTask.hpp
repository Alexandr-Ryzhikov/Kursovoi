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
  
  void Execute() override;
  VariableTask(Oswrapper::Event& event);
  
public:
  OsWrapper::Event& myEvent;
};