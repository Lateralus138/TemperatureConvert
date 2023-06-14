#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H
#include <regex>
void WaitCheck();
void double_check(double& dbl, double dbl_min, double dbl_max, int min_error, int max_error);
void int_check(int& integer, int int_min, int int_max, int min_error, int max_error);
struct Regex
{
  const std::regex HELP;
  const std::regex SYMBOL;
  const std::regex DOUBLEFLOAT;
  const std::regex CELSIUS;
  const std::regex FAHRENHEIT;
  const std::regex WIDTH;
  const std::regex TEMPERATURE;
  const std::regex DOUBLEDECIMALINT;
};
struct Switches
{
  bool symbol;
  bool celsius;
  bool fahrenheit;
};
struct Parameters
{
  int width;
  double temperature;
};
#endif // !GLOBALS_H


