#pragma once

#include "thread.hpp"
#include "event.hpp"
#include "Voltage.hpp"

class LedTask : public OsWrapper::Thread<512> 
{
private:
  Voltage VoltageValue=Voltage((3.3F/4096), 0);
  float Value;
  float VoltValue = VoltageValue.GetValue();
    
  OsWrapper::Event& myEvent;  
public:
  void Execute() override
  {
    Value = VoltValue;
  }
  
  LedTask(OsWrapper::Event& event): myEvent(event)
  {}
};