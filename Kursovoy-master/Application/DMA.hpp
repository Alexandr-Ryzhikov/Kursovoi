#pragma once
#include "dma2registers.hpp"

class DMA
{
public:
  
  void ChannelSet() //vibor canala, c kotoromu podkluchaemsya (S0 - stream 0, CHSEL::Value0 - chanell 0)
  {
    DMA2::S0CR::CHSEL::Value0::Set(); 
  }
  
  void DirectionSet() //Ustanavlivaem napravlemie (periferiya-pamyat')
  {
    DMA2::S0CR::DIR::Value0::Set();
  }
  
  void DataSizeSet() //Ustanavlivaem ob'emi pamati periferii i pamaty
  {
    DMA2::S0NDTR::NDT::Set(2);
    DMA2::S0CR::MSIZE::Value2::Set();
    DMA2::S0CR::MINC::Value1::Set();
    DMA2::S0CR::PSIZE::Value2::Set();
    DMA2::S0CR::PINC::Value0::Set();
  }
  
  void TargetSet(uint32_t poscode) //Ustanabvimaem oblast pamati gde budut schitannie znachenia
  {
    DMA2::S0CR::CT::Value0::Set();
    DMA2::S0M0AR::M0A::Set(poscode);
  }
  
  void StreamOn()  //Vkluchaen CircularMode, zapuskaem flow
  {
    DMA2::S0CR::CIRC::Value1::Set();
    DMA2::S0CR::EN::Value1::Set();
  }
};