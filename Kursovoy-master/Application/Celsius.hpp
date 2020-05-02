#ifndef CELSIUS_HPP
#define CELSIUS_HPP
#include "IUnits.hpp"
#include "susudefs.hpp"

class Celsius : public IUnits
{
private: 
  const float k = 1.0F;
  const float b = 0.0F;
  float Value = 0.0F;
  const SusuStringView Name(Celsius);

public:
  
   void Calculation(float Temper) override
  {
    Value = k * Temper + b;
  }
  
   const SusuStringView& GetName() const override
  {
    return Name;
  }

};

#endif