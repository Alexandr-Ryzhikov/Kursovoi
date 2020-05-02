#pragma once
#include <array>

class IVariable
{
private:

public:

  virtual void Calucaltion(std::array<uint32_t, 2> codes) = 0;
  
  virtual float GetValue() = 0;
    
  virtual auto GetValueAndName() = 0;
  
};