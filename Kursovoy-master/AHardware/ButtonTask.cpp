#include "ButtonTask.hpp"

void ButtonTask::Execute()
{
  for(;;)
  {
    if (UserButton.IsPushed())
    {
      myEvent.Signal();
    }
    Sleep(300ms);
  }
}

ButtonTask::ButtonTask(OsWrapper::Event& event): myEvent(event)
{
}

