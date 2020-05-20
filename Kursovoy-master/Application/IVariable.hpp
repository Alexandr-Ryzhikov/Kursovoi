#pragma once
#include <array>

class IVariable
{
private:

public:

  virtual void Calucaltion(std::uint32_t code) = 0;
  
  virtual float GetValue() = 0;
    
  virtual void GetValueAndName() = 0;
  
};