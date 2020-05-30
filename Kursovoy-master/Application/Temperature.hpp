#pragma once
#include "IUnits.hpp"
#include "IVariable.hpp"
#include <array>
using namespace std;

class Temperature : public IVariable
{
private:
  float Value;
  float Temper = Value;
  std::array <IUnits*, 3> units;
  std::uint8_t CurrentUnits;
  constexpr SusuStringView Name();
  int CurrentIndex = 0;
public:
  using IVariable::IVariable;
  
  void NextUnits()
  {
      for(int i=0; i<2; i++)
      {
        CurrentIndex = i;
       // CurrentUnits = Value; 
      }
      if(CurrentIndex >= 2)
        CurrentIndex = 0;
  }
  
    void Calculation(std::uint32_t code) override
  {
    Value = k * code + b;
  }
  
    float GetValue() override
  {
    return Value;
  }
  
  void GetValueAndName() override
  {
    //units[currentIndex].Calculate() ;
    auto Value = units[CurrentIndex]->GetValue();
    auto Name = units[CurrentIndex]->GetName();

    auto tuple_ = std::make_tuple(Value, Name) ;
  } 
};