#pragma once
#include <array>
#include "VariableTask.hpp"

class IVariable
{
private:
  const std::uint32_t code;
  const float k;
  const float b;
 
public:
  IVariable(std::uint32_t Code, float k1, float b1): code(Code), k(k1), b(b1) {};
  
  virtual void Calculation(std::uint32_t code) = 0;
  
  virtual float GetValue() = 0;
    
  virtual void GetValueAndName() = 0;
  
};