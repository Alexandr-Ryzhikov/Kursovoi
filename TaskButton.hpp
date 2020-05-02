#pragma once
#include "thread.hpp" //for thread
#include "event.hpp"  //for OsWrapper event
#include "MyPin.hpp"  //for MyPin
#include "gpiocregisters.hpp" //for gpiocregisters
#include "Button.hpp" //for Button


class TaskButton : public OsWrapper::Thread<128>
{ 
public:
  void Execute() override;
  TaskButton(OsWrapper::Event& event);

private:
  Button<MyPin<GPIOC,13>> userButton;
  OsWrapper::Event& myEvent;
};