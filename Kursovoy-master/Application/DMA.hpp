#pragma once
#include "dmaregisters.hpp"

class DMA
{
public:
  
  void ChanellSet() //vibor canala, c kotoromu podkluchaemsya (S0 - stream 0, CHSEL::Value0 - chanell 0)
  {
    DMA2::S0CR::CHSEL::Value0::Set(); 
  }
  
  void DirectionSet() //Ustanavlivaem napravlemie (periferiya-pamyat')
  {
    
  }
  
  void DataSizeSet() //Ustanavlivaem ob'emi pamati periferii i pamaty
  {
    
  }
  
  void TargetSet() //Ustanabvimaem oblast pamati gde budut schitannie znachenia
  {
    
  }
  
  void StreamOn()  //Vkluchaen CircularMode, zapuskaem flow
  {
    
  }
};