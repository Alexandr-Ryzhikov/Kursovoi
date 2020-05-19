#pragma once
#include "IUnits.hpp"
#include <array>


using namespace std;

class Temperature
{
private:
  float Value;
  std::array <IUnits*, 3> units;
  std::uint8_t CurrentUnits;
  float k = (3.3f/(4096.0f*0.0025f));
  float b = (25.0f-0.76f/0.0025f);
  constexpr SusuStringView Name();
  int CurrentIndex = 0;
  
public:
  Temperature(float k1, float b1): k(k1), b(b1) {};

  void NextUnits()
  {
      for(int i=0; i<2; i++)
      {
        CurrentIndex = i;
        CurrentUnits = Value; 
      }
      if(CurrentIndex >= 2)
        CurrentIndex = 0;
  }
  
  void Calculation(uint32_t codes) override
  {
    float Temper = k * codes[0] + b;
    Value = Temper;
  }
  
  auto GetValueAndName()
  {
    ///units[currentIndex].Calculate() ;
    auto Value = units[CurrentIndex]->GetValue();
    auto Name = units[CurrentIndex]->GetName();

    auto tuple_ = std::make_tuple(Value, Name) ;
  } 
};