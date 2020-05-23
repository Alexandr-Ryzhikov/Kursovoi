#pragma once

#include "thread.hpp" //for thread
#include "event.hpp"  //for OsWrapper event
#include "MyPin.hpp"  //for MyPin
#include "gpiocregisters.hpp" //for gpiocregisters
#include "Button.hpp" //for Button

class ButtonTask : public OsWrapper::Thread<512>
{
private:
  
  Button<MyPin<GPIOC,13>> UserButton;
  OsWrapper::Event& myEvent;

public:
  
  void Execute() override;
  ButtonTask(OsWrapper::Event& event);
  
};