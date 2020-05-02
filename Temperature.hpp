#include "IVariable.hpp"
#include <math.h>
class Temperature: public IVariable
{
private:
  float k1;
  float k2;
  float k3;
public:
  float GetValue() override
  {
    return value;
  }
  
  void Calculation (uint32_t code) override
  {
    value = k1*pow(code,2)+k2*code+k3; //temp Celsius
  };
   
};