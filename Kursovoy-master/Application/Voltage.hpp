#include "IVariable.hpp"

class Voltage : public IVariable
{
private:
  float K = 3.3F/1024;
  float B = 25.0F - 0.76F/0.0025F;
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
