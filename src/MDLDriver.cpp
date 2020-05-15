#include "MDLDriver.hpp"
#include "y.tab.h"

std::vector<Operation> MDLDriver::ops;
std::map<std::string, Material> MDLDriver::matTable;
std::map<std::string, Mat4> MDLDriver::coordTable;

MDLDriver::MDLDriver ()
  : trace_parsing (false), trace_scanning (false)
{
//   variables["one"] = 1;
//   variables["two"] = 2;
}

int
MDLDriver::parse (const std::string &f)
{
  file = f;
  location.initialize (&file);
  scan_begin ();
  yy::parser parse (*this);
  parse.set_debug_level (trace_parsing);
  int res = parse.parse();
  scan_end ();
  return res;
}
