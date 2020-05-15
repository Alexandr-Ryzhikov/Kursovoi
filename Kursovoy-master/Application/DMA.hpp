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
    DMA2::S0CR::DIR::Value0::Set();
  }
  
  void DataSizeSet() //Ustanavlivaem ob'emi pamati periferii i pamaty
  {
    DMA2::S0CR::MSIZE::Value1::Set();
    DMA2::S0CR::PSIZE::Value1::Set();
  }
  
  void TargetSet() //Ustanabvimaem oblast pamati gde budut schitannie znachenia
  {
    DMA2::S0CR::CT::Value0::Set();
  }
  
  void StreamOn()  //Vkluchaen CircularMode, zapuskaem flow
  {
    DMA2::S0CR::CIRC::Value1::Set();
    DMA2::S0CR::EN::Value1::Set();
  }
};