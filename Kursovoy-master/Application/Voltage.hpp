#pragma once
#include <array>
#include "IVariable.hpp"
using namespace std;

class Voltage : public IVariable
{
private:
  float k = 3.3F/1024;
  float b = 25.0F - 0.76F/0.0025F;
  float Value;
  uint32_t code = codes[1];
public:
  
   void Calculation(std::uint32_t code) override
  {
    Value = code*k + b;
  }
  
   float GetValue() override
  {
    return Value;
  }
  
};
