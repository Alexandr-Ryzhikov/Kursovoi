#pragma once
#include <array>

using namespace std;

class Voltage : public IVariable
{
private:
  float K = 3.3F/1024;
  float B = 25.0F - 0.76F/0.0025F;
  float Value;
  std::uint32_t code = codes[1];
public:
  Voltage(float k1, float b1): K(k1), B(b1) {};
  
  float GetValue() override
  {
    return Value;
  }
  
   void Calculation(std::uint32_t code) override
  {
    Value = code*K + B;
  }
   
};
