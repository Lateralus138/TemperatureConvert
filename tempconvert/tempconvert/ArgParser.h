#pragma once
#ifndef ARGPARSER_H
#define ARGPARSER_H
#include "Globals.h"
void next_arg_test(int index, std::vector<std::string>& args, int iferror);
void ArgParser
(
  int argc, const char* argv[],
  Regex& regex, Switches& swicthes, Parameters& parameters
);
#endif // !ARGPARSER_H
