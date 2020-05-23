#pragma once
#include <array>
#include "VariableTask.hpp"

class IVariable
{
protected:
  float Value;
  const float k;
  const float b;
 
public:
  IVariable( float k1, float b1): k(k1), b(b1) {};
  
  virtual void Calculation(std::uint32_t code) = 0;
  
  virtual float GetValue() = 0;
    
  virtual void GetValueAndName() = 0;
  
};