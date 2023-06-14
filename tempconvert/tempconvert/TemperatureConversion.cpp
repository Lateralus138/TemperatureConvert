#include "TemperatureConversion.h"
double TemperatureConversion(double temp, TemperatureType& type)
{
  if (type == Celsius)
  {
    temp = ((temp - 32.000000000000000) * (5.000000000000000 / 9.000000000000000));
  }
  else
  {
    temp = ((temp * (9.000000000000000 / 5.000000000000000)) + 32.000000000000000);
  }
  return temp;
}