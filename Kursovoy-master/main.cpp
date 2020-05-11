#include "rtos.hpp"         // for Rtos
#include "event.hpp"        // for Event
#include "rccregisters.hpp" // for RCC
#include "ADC.hpp" //for ADC
#include "adc1registers.hpp" //for ADC1
#include "susudefs.hpp"
#include "Temperature.hpp"
#include "Celsius.hpp"
#include "Button.hpp"
#include "IUnits.hpp"
#include "Fahrenheit.hpp"
#include "Kelvin.hpp"
#include "ButtonTask.hpp"
#include "MyPin.hpp"
#include "IVariable.hpp"

std::uint32_t SystemCoreClock = 16'000'000U;

extern "C" {
int __low_level_init(void)
{
  //Switch on external 16 MHz oscillator
  RCC::CR::HSION::On::Set();
  while (RCC::CR::HSIRDY::NotReady::IsSet())
  {

  }
  //Switch system clock on external oscillator
  RCC::CFGR::SW::Hsi::Set();
  while (!RCC::CFGR::SWS::Hsi::IsSet())
  {

  }
  
  RCC::APB2ENR::SYSCFGEN::Enable::Set(); 
  

  return 1;
}
}

//OsWrapper::Event event{500ms, 1}; //FIXME ����� ��� �������
OsWrapper::Event event(500ms, 1);
//MyTask myTask(event, UserButton::GetInstance()); //FIXME ����� ��� �������
using myADC = ADC<ADC1>;
ButtonTask myTaskButton (event);
;

int main()
{
  using namespace OsWrapper;
  //Rtos::CreateThread(myTask, "myTask", ThreadPriority::lowest);   //FIXME ����� ��� �������
  //Rtos::Start();
  myADC::On();
  myADC::adcConfig(Resolution::Bits12, tSampleRate::Cycles480, tSampleRate::Cycles144);
  myADC::SetChannels(0, 18);
    using namespace OsWrapper;
  Rtos::CreateThread(myTaskButton, "UserButton", ThreadPriority::normal);
  Temperature Tempe( (3.3f/(4096.0f*0.0025f)) ,(25.0f-0.76f/0.0025f) ) ;
  
  return 0;
}
