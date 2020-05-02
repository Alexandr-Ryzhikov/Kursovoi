#include "IVariable.hpp"

class Voltage : public IVariable
{
public:
  Voltage(float voltage): IVariable(voltage "Voltage") {} ;
};
