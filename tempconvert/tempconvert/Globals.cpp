#include "Globals.h"
#include <Windows.h>
#include <iostream>
void WaitCheck()
{
  const bool ISOWNWINDOW = []()
  {
    DWORD processList[2] = { 0 };
    const DWORD maxList = 2;
    DWORD result = GetConsoleProcessList((LPDWORD)processList, maxList);
    return (result == 1);
  }();
  if (ISOWNWINDOW)
  {
    std::cout << "Press [\x1b[1;3;93mEnter\x1b[m] to continue... > ";
    std::cin.ignore();
  }
}
void double_check(double& dbl, double dbl_min, double dbl_max, int min_error, int max_error)
{
  try
  {
    if (dbl < dbl_min)
    {
      const std::string error_message =
        "Value: [" +
        std::to_string(dbl) +
        "] is too small.\n";
      throw std::runtime_error(error_message);
    }
  }
  catch (std::runtime_error& error)
  {
    std::cerr << error.what();
    WaitCheck();
    std::exit(min_error);
  }
  try
  {
    if (dbl > dbl_max)
    {
      const std::string error_message =
        "Value: [" +
        std::to_string(dbl) +
        "] is too large.\n";
      throw std::runtime_error(error_message);
    }
  }
  catch (std::runtime_error& error)
  {
    std::cerr << error.what();
    WaitCheck();
    std::exit(max_error);
  }
}
void int_check(int& integer, int int_min, int int_max, int min_error, int max_error)
{
  try
  {
    if (integer < int_min)
    {
      const std::string error_message =
        "Value: [" +
        std::to_string(integer) +
        "] is too small.\n";
      throw std::runtime_error(error_message);
    }
  }
  catch (std::runtime_error& error)
  {
    std::cerr << error.what();
    WaitCheck();
    std::exit(min_error);
  }
  std::cout << "Here\n";
  try
  {
    if (integer > int_max)
    {
      //std::cout << "Here\n";
      const std::string error_message =
        "Value: [" +
        std::to_string(integer) +
        "] is too large.\n";
      throw std::runtime_error(error_message);
    }
  }
  catch (std::runtime_error& error)
  {
    std::cerr << error.what();
    WaitCheck();
    std::exit(max_error);
  }
}
