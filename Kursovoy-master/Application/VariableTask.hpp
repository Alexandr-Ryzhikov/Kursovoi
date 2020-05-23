#pragma once
#include "Voltage.hpp"
#include "Temperature.hpp"
#include "thread.hpp"
#include "event.hpp"
#include "ADC.hpp" //for Resolution, tSampleRate
#include "IVariable.hpp"
#include <iostream> //for std::cout

template <typename myADC>
class VariableTask : public OsWrapper::Thread<512> 
{
private:
  Voltage VoltageValue=Voltage((3.3F/4096), 0);
  Temperature TemperatureValue=Temperature((3.3f/(4096.0f*0.0025f)),(25.0f-0.76f/0.0025f));
  
  
  OsWrapper::Event& myEvent;  

  
public:
  void Execute() override
  {
    //Koldunstvo s ADC//////////////////////////////////////////////////////////////////////////////////////////
    
   
    
    myADC::adcConfig(Resolution::Bits12, tSampleRate::Cycles480, tSampleRate::Cycles480); //nastraivaem adc
    myADC::SetChannels(0, 18); //podkluchaem kanali
    myADC::dmaConfig(); //podkluchaem DMA
    myADC::On(); //vkluchaen adc
    myADC::Start();
       
   for( ; ;)
  {
    auto codes = myADC::GetValue(); //po idee, uzhe ne nuzhen
    
    //Koldunstvo s Voltage(poluchaem voltage)////////////////////////////////////////////////////////////////////
    
    VoltageValue.Calculation(codes[0]); //chitaem
    VoltageValue.GetValueAndName();
    
    Sleep(100ms);
    //TemperatureValue =  tuple_;//poluchaem temperaturu
    //VoltageValue = IVariable::GetValue(); //poluchaem voltage
    
    //Koldunstvo s Temperature(poluchaem temperature)////////////////////////////////////////////////////////////
    TemperatureValue.Calculation(codes[1]);
   // TemperatureValue.GetValueAndName();
    
    //Vivodim chernila///////////////////////////////////////////////////////////////////////////////////////////
    
    //std::cout << "Temperature: " << std::get<0>(TemperatureValue) << std::get<1>(TemperatureValue) << std::endl;
    std::cout << "Voltage: " << VoltageValue.GetValue() << " V. " << std::endl;
    std::cout << "Temperature: " << TemperatureValue.GetValue() << std::endl;
    //Koldunstvo s knopkoi
    //Sleep(500ms);
  } 
  }
  
  VariableTask(OsWrapper::Event& event): myEvent(event)
  {}
};