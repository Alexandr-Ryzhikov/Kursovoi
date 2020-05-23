//osnovnaya hren'
#include "rtos.hpp"         // for Rtos
#include "event.hpp"        // for Event
#include "rccregisters.hpp" // for RCC
#include "gpioaregisters.hpp"  //for Gpioa
#include "gpiocregisters.hpp"  //for Gpioc
#include "adc1registers.hpp" //for ADC1
#include "susudefs.hpp"
#include "thread.hpp"
//Vetka ButtonTask
#include "MyPin.hpp"
#include "Button.hpp"
#include "ButtonTask.hpp"
//Vetka VariableTask
#include "VariableTask.hpp"
#include "ADC.hpp" //for ADC
#include "adccommonregisters.hpp" //for ADCCommon
#include "USART.hpp"
#include "IVariable.hpp"
#include "Voltage.hpp"
#include "Temperature.hpp"
#include "IUnits.hpp"
#include "Celsius.hpp"
#include "Fahrenheit.hpp"
#include "Kelvin.hpp"
#include "PWM.hpp"
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
  
    //taktirovan'e
  RCC::CR::HSEON::On::Set();
  RCC::CFGR::SW::Hse::Set();
  RCC::APB1ENR::TIM3EN::Enable::Set();
  RCC::APB2ENR::ADC1EN::Enable::Set(); //tekt na adc
  ADC_Common::CCR::TSVREFE::Enable::Set();//switch to temperature sensor
  RCC::AHB1ENR::DMA2EN::Enable::Set(); //takt na dma2
  RCC::AHB1ENR::GPIOCEN::Enable::Set();// takt na port C
  RCC::AHB1ENR::GPIOAEN::Enable::Set();// takt na port C
  GPIOA::MODER::MODER0::Analog::Set();
  GPIOC::MODER::MODER8::Alternate::Set();
  GPIOC::AFRH::AFRH8::Af2::Set();
  // Settings PWM
  TIM3::CCER::CC2E::Value1::Set();
  // inverst PWM
  TIM3::CCMR1_Output::OC2M::Value0::Set();
  // Run TIM3
  TIM3::CR1::CEN::Value1::Set();
  //data for TIM3 CCR
  

  return 1;
}
}

//OsWrapper::Event event{500ms, 1}; //FIXME Чисто для примера
OsWrapper::Event event(500ms, 1);
//MyTask myTask(event, UserButton::GetInstance()); //FIXME Чисто для примера
using myADC = ADC<ADC1>;

ButtonTask myTaskButton (event);
VariableTask<myADC> myVariableTask (event);
;

int main()
{
  using namespace OsWrapper;
  //Rtos::CreateThread(myTask, "myTask", ThreadPriority::lowest);   //FIXME Чисто для примера
  
  using namespace OsWrapper;
  Rtos::CreateThread(myTaskButton, "UserButton", ThreadPriority::normal);
  Rtos::CreateThread(myVariableTask, "Execute", ThreadPriority::normal);
  Rtos::Start();
  return 0;
}
