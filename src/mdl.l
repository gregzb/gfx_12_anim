%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <cstring> // strerror
# include <string>
# include "MDLDriver.hpp"
# include "y.tab.h"
%}

%option noyywrap nounput noinput batch debug

%{
  // A number symbol corresponding to the value in S.
  yy::parser::symbol_type
  make_NUMBER (const std::string &s, const yy::parser::location_type& loc);
%}

blank [ \t\r]

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}

%%
%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = drv.location;
  // Code run each time yylex is called.
  loc.step ();
%}
{blank}+   loc.step ();
\n+        loc.lines (yyleng); loc.step ();

\-?[0-9]+ |
\-?[0-9]+\. |
\-?[0-9]+\.[0-9]+ |
\-?\.[0-9]+ { return yy::parser::make_DOUBLE(atof(yytext), loc);}

"//".* { return yy::parser::make_COMMENT(loc);}

"light" {return yy::parser::make_LIGHT(yytext, loc);}
"constants" {return yy::parser::make_CONSTANTS(yytext, loc);}
"save_coord_system" {return yy::parser::make_SAVE_COORDS(yytext, loc);}
"camera" {return yy::parser::make_CAMERA(yytext, loc);}
"ambient" {return yy::parser::make_AMBIENT(yytext, loc);}

"torus" { return yy::parser::make_TORUS(yytext, loc);}
"sphere" { return yy::parser::make_SPHERE(yytext, loc);}
"box" {return yy::parser::make_BOX(yytext, loc);}
"line" {return yy::parser::make_LINE(yytext, loc);}
"mesh" {return yy::parser::make_MESH(yytext, loc);}
"texture" {return yy::parser::make_TEXTURE(yytext, loc);}

"set" {return yy::parser::make_SET(yytext, loc);}
"move" {return yy::parser::make_MOVE(yytext, loc);}
"scale" {return yy::parser::make_SCALE(yytext, loc);}
"rotate" {return yy::parser::make_ROTATE(yytext, loc);}
"basename" {return yy::parser::make_BASENAME(yytext, loc);}
"save_knobs" {return yy::parser::make_SAVE_KNOBS(yytext, loc);}
"tween" {return yy::parser::make_TWEEN(yytext, loc);}
"frames" {return yy::parser::make_FRAMES(yytext, loc);}
"vary" {return yy::parser::make_VARY(yytext, loc);}

"push" {return yy::parser::make_PUSH(yytext, loc);}
"pop" {return yy::parser::make_POP(yytext, loc);}
"save" {return yy::parser::make_SAVE(yytext, loc);}
"generate_rayfiles" {return yy::parser::make_GENERATE_RAYFILES(yytext, loc);}

"shading" {return yy::parser::make_SHADING(yytext, loc);}

phong|flat|gouraud|raytrace|wireframe {
    return yy::parser::make_SHADING_TYPE (yytext, loc);
}

"setknobs" {return yy::parser::make_SETKNOBS(yytext, loc);}
"focal" {return yy::parser::make_FOCAL(yytext, loc);}
"display" {return yy::parser::make_DISPLAY(yytext, loc);}
"web" {return yy::parser::make_WEB(yytext, loc);}

":" {return yy::parser::make_CO(yytext, loc);}

[a-zA-Z][\.a-zA-Z0-9_]* {
    return yy::parser::make_STRING (yytext, loc);
}

<<EOF>>    return yy::parser::make_END (loc);
%%

void
MDLDriver::scan_begin ()
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      std::cerr << "cannot open " << file << ": " << strerror(errno) << '\n';
      exit (EXIT_FAILURE);
    }
}

void
MDLDriver::scan_end ()
{
  fclose (yyin);
}