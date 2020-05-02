#ifndef FAHRENHEIT_HPP
#define FAHRENHEIT_HPP
#include "IUnits.hpp"
#include "susudefs

class Fahrenheit : public IUnits
{
private:
  const float k = 9/5;
  const float b = 32.0F;
  float Value = 0.0F;
  static SusuString Name("Fahrenheit");
public:
  
    void Calculation(float Temper)
  {
    Value = k * Temper + b;
  }
  
   SusuString& GetName() const override
  {
    return Name;
  }
  
};

#endif