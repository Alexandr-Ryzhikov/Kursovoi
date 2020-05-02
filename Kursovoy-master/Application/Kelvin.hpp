#ifndef KELVIN_HPP
#define KELVIN_HPP
#include "IUnits.hpp"

class Kelvin : public IUnits
{
private:
  const float k = 1.0F;
  const float b = -273.0F;
  float Value = 0.0F;
  static constexpr SusuString Name("Celsius");
public:
     float GetValue()
  {
    return Value;
  }
  
   void Calculation(float Temper) override
  {
    Value = k * Temper + b;
  }
  
  constexpr SusuString& GetName()
  {
    return Name;
  }
  
};

#endif