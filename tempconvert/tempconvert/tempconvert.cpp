// ╔════════════════════════════════════════════════════════════════════╗
// ║ 'Temp Convert' -    Convert Fahrenheit to Celsius and vice versa.  ║
// ║                     Defaults to Celsuis to Fahrenheit.             ║
// ║ © 2023 Ian Pride -  New Pride Software/Services                    ║
// ╚════════════════════════════════════════════════════════════════════╝
#include <Windows.h>
#include <iostream>
#include "Globals.h"
#include <vector>
#include "ArgParser.h"
#include "TemperatureConversion.h"
#include <iomanip>
int main(int argc, const char* argv[])
{
  HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
  SetConsoleMode(hInput, ENABLE_VIRTUAL_TERMINAL_INPUT);
  HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleMode(hOutput, ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleTitle(L"Temperature Convert");
  Regex regex =
  {
    std::regex("^/([\?]|[hH]|[hH][eE][lL][pP])$"),
    std::regex("^/([sS]|[sS][yY][mM][bB][oO][lL])$"),
    std::regex("^([0-9]+|[0-9]*[.]{1}[0-9]{1,15})$"),
    std::regex("^/([cC]|[cC][eE][lL][sS][iI][uU][sS])$"),
    std::regex("^/([fF]|[fF][aA][hH][rR][eE][nN][hH][eE][iI][tT])$"),
    std::regex("^/([wW]|[wW][iI][dD][tT][hH])$"),
    std::regex("^/([tT]|[tT][eE][mM][pP][eE][rR][aA][tT][uU][rR][eE])$"),
    std::regex("^([0-9]|[1][0-5])$")
  };
  Switches switches = { false, true, false };
  Parameters parameters = { 2, NULL };
  TemperatureType type = { Celsius };
  char symbol = '\0';
  if (argc > 1)
  {
    ArgParser(argc, argv, regex, switches, parameters);
  }
  else
  {
    std::cerr << "Nothing passed to the program.\n";
    WaitCheck();
    return 1;
  }
  double_check(parameters.temperature, -DBL_MIN, DBL_MAX, 6, 7);
  if (switches.fahrenheit)
  {
    type = Fahrenheit;
  }
  if (switches.symbol)
  {
    if (type == Celsius)
    {
      symbol = 'C';
    }
    else
    {
      symbol = 'F';
    }
  }
  const double conversion = TemperatureConversion(parameters.temperature, type);
  std::cout << std::fixed << std::setprecision(parameters.width)
            << conversion << symbol << std::endl;
  WaitCheck();
  return EXIT_SUCCESS;
}