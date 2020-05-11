#pragma once
#include "gpiocregisters.hpp"
#include "rccregisters.hpp"
#include "tim3registers.hpp"

template <typename Timer>
class PWM
{
public: 
  void SetDuty (uint16_t DutyCycle)
  { 
    Timer::CCR3=DutyCycle;
  }

};

extern "C"
{
int_low_level_init (void)
{
  //taktirovan'e
  RCC::CR::HSEON::On::Set();
  RCC::CFGR::SW::Hse::Set();
  RCC::APB1ENR::TIM3EN::Enable::Set();
  
  RCC::AHB1ENR::GPOICEN::Enable::Set();// takt na port C
  GPIOC::MODER::MODER8::Alternate::Set();
  GPIOC::AFRH::AFRH8::AF2::Set();
  // Settings PWM
  TIM3::CCER1::CC2E::Set();
  // inverst PWM
  TIM3::CCMR1::OC2M=0;
  // Run TIM2
  TIM3::CR1::CEN::Enable::Set();
  //data for TIM2 CCR
 
}
}