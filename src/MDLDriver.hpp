# pragma once
# include <string>
# include <map>
# include "y.tab.h"
# include <variant>
# include <optional>

// Give Flex the prototype of yylex we want ...
# define YY_DECL \
  yy::parser::symbol_type yylex (MDLDriver& drv)
// ... and declare it for the parser's sake.
YY_DECL;

# include "Mat4.hpp"
# include "Material.hpp"
# include "Light.hpp"

// using SymObject = std::variant<Mat4, Material, Light, double>;
// //using SymObject = std::variant<Mat4, Light, double>;

// enum class SymType {
//     Mat4, Material, Light, Double
// };

struct Operation {
    std::string op;
    std::optional<std::string> mat;
    std::optional<std::string> cs1, cs2;
    std::optional<std::string> data;
    std::optional<std::string> knob;
    std::vector<Vec4> vecs;
    std::vector<double> vals;
};

// Conducting the whole scanning and parsing of Calc++.
class MDLDriver
{
public:
  MDLDriver ();

  //std::map<std::string, int> variables;

  //std::map<std::string, std::pair<SymType, SymObject>> symTable;

  static std::vector<Operation> ops;
  static std::map<std::string, Material> matTable;
  static std::map<std::string, Mat4> coordTable;

  // Run the parser on file F.  Return 0 on success.
  int parse (const std::string& f);
  // The name of the file being parsed.
  std::string file;
  // Whether to generate parser debug traces.
  bool trace_parsing;

  // Handling the scanner.
  void scan_begin ();
  void scan_end ();
  // Whether to generate scanner debug traces.
  bool trace_scanning;
  // The token's location used by the scanner.
  yy::location location;
};
