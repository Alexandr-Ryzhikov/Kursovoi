#pragma once
#include "IUnits.hpp"

#include <array>
using namespace std;

class Temperature : public IVariable
{
private:
  float Value;
  float Temper;
  std::array <IUnits*, 3> units;
  //std::uint8_t CurrentUnits;
  float k = (3.3f/(4096.0f*0.0025f));
  float b = (25.0f-0.76f/0.0025f);
  constexpr SusuStringView Name();
  int CurrentIndex = 0;
public:

  void NextUnits()
  {
      for(int i=0; i<2; i++)
      {
        CurrentIndex = i;
        //CurrentUnits = Value; 
      }
      if(CurrentIndex >= 2)
        CurrentIndex = 0;
  }
  
    void Calculation(std::uint32_t code) override
  {
    float Value = k * code + b;
    Temper = Value;
  }
  
  void GetValueAndName()
  {
    //units[currentIndex].Calculate() ;
    auto Value = units[CurrentIndex]->GetValue();
    auto Name = units[CurrentIndex]->GetName();

    auto tuple_ = std::make_tuple(Value, Name) ;
  } 
};