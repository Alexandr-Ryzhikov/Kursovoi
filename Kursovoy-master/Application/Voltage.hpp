#pragma once
#include <array>
#include "IVariable.hpp"

using namespace std;

class Voltage : public IVariable
{
  
public:
  using IVariable::IVariable;
   void Calculation(std::uint32_t code) override
  {
    Value = k*code + b;
  }
  
   float GetValue() override
  {
    return Value;
  }
  
  void GetValueAndName() override
  {}
};
