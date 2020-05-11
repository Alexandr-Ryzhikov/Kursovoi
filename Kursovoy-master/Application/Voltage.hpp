#include "IVariable.hpp"

class Voltage : public IVariable
{
private:
  float K;
  float B;
public:
  Voltage(float k1, float b1): K(k1), B(b1) {};
  
  void GetValue override
  {
    return Value;
  }
  
  void Calculate(uint32_t code) override
  {
    Value = code*K + B;
  }
   
};
