#pragma once
#include "Voltage.hpp"
#include "thread.hpp"
#include "event.hpp"
#include "ADC.hpp" //for Resolution, tSampleRate
#include "IVariable.hpp"
#include <iostream> //for std::cout

template <typename myADC>
class VariableTask : public OsWrapper::Thread<512> 
{
private:
  Voltage VoltageValue=Voltage(1, 2);//(3.3F/1024)(25.0F - 0.76F/0.0025F)
  float TemperatureValue;
  
  OsWrapper::Event& myEvent;  

  
public:
  void Execute() override
  {
    myADC::On(); //vkluchaen adc
    myADC::adcConfig(Resolution::Bits12, tSampleRate::Cycles480, tSampleRate::Cycles480); //nastraivaem adc
    myADC::SetChannels(0, 18); //podkluchaem kanali
    myADC::dmaConfig(); //podkluchaem DMA
    
   for( ; ;)
  {
    //Koldunstvo s ADC
    
    auto codes = myADC::GetValue(); //po idee, uzhe ne nuzhen
    
    //Koldunstvo s IVariable(poluchaem temperature and voltage)
    VoltageValue.Calculation(codes[0]); //chitaem
    VoltageValue.GetValueAndName();
    //TemperatureValue =  tuple_;//poluchaem temperaturu
    //VoltageValue = IVariable::GetValue(); //poluchaem voltage
    
    //Vivodim chernila
    //std::cout << "Temperature: " << std::get<0>(TemperatureValue) << std::get<1>(TemperatureValue) << std::endl;
    std::cout << "Voltage: " << VoltageValue.GetValue() << " V. " << std::endl;
     
    //Koldunstvo s knopkoi
    Sleep(500ms);
    if (myEvent.Wait() !=0)
    {
      //Temperature::NextUnits;
    }
    
  } 
  }
  
  VariableTask(OsWrapper::Event& event): myEvent(event)
  {}
};