#include "ArgParser.h"
#include <Windows.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include "Globals.h"
void next_arg_test(int index, std::vector<std::string> &args, int iferror)
{
  try
  {
    if ((index + 1) > (int)args.size())
    {
      std::string rtmsg = "No argument provided for [";
      rtmsg.append(args[index]);
      rtmsg.append("].\n");
      throw std::runtime_error(rtmsg);
    }
  }
  catch (std::runtime_error& rerr)
  {
    std::cerr << rerr.what();
    WaitCheck();
    std::exit(iferror);
  }
}
void ArgParser
(
  int argc, const char* argv[],
  Regex &regex, Switches &switches, Parameters &parameters
)
{
  std::vector<std::string> args(argv + 1, argv + argc);
  bool skip = false;
  for (unsigned int index = 0; index < (int)args.size(); index++)
  {
    if (skip)
    {
      skip = false;
      continue;
    }
    if (std::regex_match(args[index], regex.HELP))
    {
      const std::string HELPMESSAGE =
        "\n"
        "Temperature Convert -  Convert Fahrenheit to Celsius\n"
        "                       and vice versa. Defaults from\n"
        "                       Celsius to Fahrenheit.\n"
        "\n"
        "tempconvert  [/? | /h | /help] | [<temperature> &|\n"
        "  [/t | /temperature]] [/c | /celsius]\n"
        "  [/f | /fahrenheit] [/s | /symbol]\n"
        "  [[/w | /width] <decimal width>]\n"
        "\n"
        "  Temperature       Integer, float, or double float\n"
        "                    temperature value. \n"
        "  /?, /h, /help     This help screen.\n"
        "  /t, /temperature  Alternate method of providing\n"
        "                    the temperature.\n"
        "  /c, /celsius      Temperature is assumed\n"
        "                    Fahrenheit and returns a Celsius\n"
        "  /f, /fahrenheit   Temperature is assumed Celsius\n"
        "                    and returns a Fahrenheit value.\n"
        "  /s, /symbol       Appends 'F' or 'C' character to\n"
        "                    the result.\n"
        "  /w, /width        Width of any trailing decimal.\n"
        "                    Defaults to 2; range from 0-15.\n"
        "\n";
      std::cout << HELPMESSAGE;
      WaitCheck();
      std::exit(EXIT_SUCCESS);
    }
    if (std::regex_match(args[index], regex.DOUBLEFLOAT))
    {
      parameters.temperature = stod(args[index]);
      continue;
    }
    if (std::regex_match(args[index], regex.TEMPERATURE))
    {
      next_arg_test(index, args, 2);
      const int index_next = index + 1;
      if (std::regex_match(args[index_next], regex.DOUBLEFLOAT))
      {
        parameters.temperature = stod(args[index_next]);
      }
      skip = true;
      continue;
    }
    if (std::regex_match(args[index], regex.WIDTH))
    {
      next_arg_test(index, args, 3);
      const int index_next = index + 1;
      if (std::regex_match(args[index_next], regex.DOUBLEDECIMALINT))
      {
        parameters.width = stoi(args[index_next]);
      }
      else
      {
        int width = stoi(args[index_next]);
        int_check(width, 0, 15, 4, 5);
      }
      skip = true;
      continue;
    }
    if (std::regex_match(args[index], regex.SYMBOL))
    {
      switches.symbol = true;
      continue;
    }
    if (std::regex_match(args[index], regex.CELSIUS))
    {
      switches.celsius = true;
      switches.fahrenheit = false;
      continue;
    }
    if (std::regex_match(args[index], regex.FAHRENHEIT))
    {
      switches.celsius = false;
      switches.fahrenheit = true;
      continue;
    }
  }
}
