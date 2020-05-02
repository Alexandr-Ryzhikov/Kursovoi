#ifndef ADC_HPP
#define ADC_HPP
#include <array>



enum class Resolution
{
  Bits12,
  Bits10,
  Bits8,
  Bits6
};

enum class tSampleRate
{
  Cycles3,
  Cycles15,
  Cycles28,
  Cycles56,
  Cycles84,
  Cycles112,
  Cycles144,
  Cycles480
};

template<class T>


class ADC
{
private:

  std::array<uint32_t, 2> codes;
  
  static void Start()
  {
   T::CR2::SWSTART::On::Set(); //Start conversion
  }
    

  static bool IsReady()
  {
   return T::SR::EOC::ConversionComplete::IsSet();
  }
    
  static std::uint32_t Get()
  {
    return T::DR::Get();
  }

public:
  
  static void On()
  {
    T::CR2::ADON::Enable::Set(); // Enable ADC1
  }
    
  static void adcConfig(Resolution resolution, tSampleRate tsamplerate, tSampleRate vsamplerate)
  {
    switch(resolution)
    {
      case Resolution::Bits12:
      T::CR1::RES::Bits12::Set();
      break;
      
      case Resolution::Bits10:
      T::CR1::RES::Bits10::Set();
      break;
      
      case Resolution::Bits8:
      T::CR1::RES::Bits8::Set();
      break;
      
      case Resolution::Bits6:
      T::CR1::RES::Bits6::Set();
      break;
      
      default:
      T::CR1::RES::Bits12::Set();
      break;
    }
    
    switch(tsamplerate)
    {
      case tSampleRate::Cycles3:
      T::SMPR1::SMP18::Cycles480::Set();
      break;
      case tSampleRate::Cycles15:
      T::SMPR1::SMP18::Cycles15::Set();
      break;
      case tSampleRate::Cycles28:
      T::SMPR1::SMP18::Cycles28::Set();
      break;
      case tSampleRate::Cycles56:
      T::SMPR1::SMP18::Cycles56::Set();
      break;
      case tSampleRate::Cycles84:
      T::SMPR1::SMP18::Cycles84::Set();
      break;
      case tSampleRate::Cycles112:
      T::SMPR1::SMP18::Cycles112::Set();
      break;
      case tSampleRate::Cycles480:
      T::SMPR1::SMP18::Cycles480::Set();
      break;
      
      default:
      T::SMPR1::SMP18::Cycles480::Set();
      break;
    }
    
    switch(vsamplerate)
    {
      case tSampleRate::Cycles3:
      T::SMPR2::SMP0::Cycles3::Set();
      break;
      case tSampleRate::Cycles15:
      T::SMPR2::SMP0::Cycles15::Set();
      break;
      case tSampleRate::Cycles28:
      T::SMPR2::SMP0::Cycles28::Set();
      break;
      case tSampleRate::Cycles56:
      T::SMPR2::SMP0::Cycles56::Set();
      break;
      case tSampleRate::Cycles84:
      T::SMPR2::SMP0::Cycles84::Set();
      break;
      case tSampleRate::Cycles112:
      T::SMPR2::SMP0::Cycles112::Set();
      break;
      case tSampleRate::Cycles480:
      T::SMPR2::SMP0::Cycles480::Set();
      break;
      
      default:
      T::SMPR2::SMP0::Cycles480::Set();
      break;
    }
    
  }  
    
  static void SetChannels (std::uint32_t channelNum1, std::uint32_t channelNum2)
  {
    T::SQR1::L::Conversions2::Set();
    T::CR1::SCAN::Enable::Set();
    T::CR2::EOCS::SingleConversion::Set();
    T::CR2::CONT::SingleConversion::Set();
    assert(channelNum1 <19);
    assert(channelNum2 <19);
    T::SQR3::SQ1::Set(channelNum1);
    T::SQR3::SQ2::Set(channelNum2);
  } 
  
  std::array<uint32_t, 2> GetMeasureAndValue()
  {
    codes[0] = T::DR::Get();
    codes[1] = T::DR::Get();
    return codes;
    
  }
  
};

#endif