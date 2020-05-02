#pragma once
#include "susudefs.hpp"

class IUnits
{
private:
  float Value;
  const float k;
  const float b;
public:
  IUnits(float k2, float b2): k(k2), b(b2) {};
  
   virtual float GetValue()
  {
    return Value;
  }
  
  virtual void Calculation(float Temper) = 0;

  
   virtual const SusuStringView& GetName() const = 0;
};

