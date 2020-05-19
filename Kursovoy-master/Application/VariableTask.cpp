#include "VariableTask.hpp"

using myADC = ADC<ADC1>;

void VariableTask::Execute()
{
  for( ; ;)
  {
    //Koldunstvo s ADC
    myADC::On(); //vkluchaen adc
    myADC::adcConfig(Resolution::Bits12, tSampleRate::Cycles480, tSampleRate::Cycles480); //nastraivaem adc
    myADC::SetChannels(0, 18); //podkluchaem kanali
    myADC::dmaConfig(); //podkluchaem DMA
  //  myADC::GetValue(); //po idee, uzhe ne nuzhen
    
    //Koldunstvo s IVariable(poluchaem temperature and voltage)
    IVariable::Calculation(); //chitaem
    TemperatureValue = IVariable::GetValueAndName(); //poluchaem temperaturu
    VoltageValue = IVariable::GetValue(); //poluchaem voltage
    
    //Koldunstvo s knopkoi
    Sleep(500);
    if (myEvent.Wait() !=0)
    {
      Temperature::NextUnits;
    }
    
  }
}

VariableTask::VariableTask(OsWrapper::Event& event): myEvent(event)
{
}