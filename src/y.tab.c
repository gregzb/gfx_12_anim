// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "y.tab.c" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "y.tab.h"

// User implementation prologue.

#line 51 "y.tab.c" // lalr1.cc:412
// Unqualified %code blocks.
#line 25 "mdl.y" // lalr1.cc:413

# include "MDLDriver.hpp"

    void addSphereOp(MDLDriver& drv, Vec4 pos, double r, std::optional<std::string> mat = std::optional<std::string>(), std::optional<std::string> coordSys = std::optional<std::string>()) {
        drv.ops.push_back(Operation());
        Operation &o = drv.ops.back();
        o.op = "SPHERE";
        o.vecs.push_back(pos);
        o.vals.push_back(r);
        if (mat.has_value()) {
            o.mat = mat.value();
        }

        if (coordSys.has_value()) {
            o.cs1 = coordSys.value();
        }
    }

    void addTorusOp(MDLDriver& drv, Vec4 pos, double r1, double r2, std::optional<std::string> mat = std::optional<std::string>(), std::optional<std::string> coordSys = std::optional<std::string>()) {
        drv.ops.push_back(Operation());
        Operation &o = drv.ops.back();
        o.op = "TORUS";
        o.vecs.push_back(pos);
        o.vals.push_back(r1);
        o.vals.push_back(r2);
        if (mat.has_value()) {
            o.mat = mat.value();
        }

        if (coordSys.has_value()) {
            o.cs1 = coordSys.value();
        }
    }

    void addBoxOp(MDLDriver& drv, Vec4 pos, Vec4 dims, std::optional<std::string> mat = std::optional<std::string>(), std::optional<std::string> coordSys = std::optional<std::string>()) {
        drv.ops.push_back(Operation());
        Operation &o = drv.ops.back();
        o.op = "BOX";
        o.vecs.push_back(pos);
        o.vecs.push_back(dims);
        if (mat.has_value()) {
            o.mat = mat.value();
        }

        if (coordSys.has_value()) {
            o.cs1 = coordSys.value();
        }
    }

    void addLineOp(MDLDriver& drv, Vec4 pos1, Vec4 pos2, std::optional<std::string> mat = std::optional<std::string>(), std::optional<std::string> cs1 = std::optional<std::string>(), std::optional<std::string> cs2 = std::optional<std::string>()) {
        drv.ops.push_back(Operation());
        Operation &o = drv.ops.back();
        o.op = "LINE";
        o.vecs.push_back(pos1);
        o.vecs.push_back(pos2);
        if (mat.has_value()) {
            o.mat = mat.value();
        }

        if (cs1.has_value()) {
            o.cs1 = cs1.value();
        }

        if (cs2.has_value()) {
            o.cs2 = cs2.value();
        }
    }

    void addMeshOp(MDLDriver& drv, std::string fileName, std::optional<std::string> mat = std::optional<std::string>(), std::optional<std::string> coordSys = std::optional<std::string>()) {
        drv.ops.push_back(Operation());
        Operation &o = drv.ops.back();
        o.op = "MESH";
        o.data = fileName;
        if (mat.has_value()) {
            o.mat = mat.value();
        }

        if (coordSys.has_value()) {
            o.cs1 = coordSys.value();
        }
    }

    void addMoveOp(MDLDriver& drv, Vec4 transform, std::optional<std::string> knob = std::optional<std::string>()) {
        drv.ops.push_back(Operation());
        Operation &o = drv.ops.back();
        o.op = "MOVE";
        o.vecs.push_back(transform);
        if (knob.has_value()) {
            o.knob = knob.value();
        }
    }

    void addScaleOp(MDLDriver& drv, Vec4 transform, std::optional<std::string> knob = std::optional<std::string>()) {
        drv.ops.push_back(Operation());
        Operation &o = drv.ops.back();
        o.op = "SCALE";
        o.vecs.push_back(transform);
        if (knob.has_value()) {
            o.knob = knob.value();
        }
    }

    void addRotOp(MDLDriver& drv, std::string axis, double amount, std::optional<std::string> knob = std::optional<std::string>()) {
        drv.ops.push_back(Operation());
        Operation &o = drv.ops.back();
        o.op = "ROTATE";
        o.data = axis;
        o.vals.push_back(amount);
        if (knob.has_value()) {
            o.knob = knob.value();
        }
    }


#line 168 "y.tab.c" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 254 "y.tab.c" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (MDLDriver& drv_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 4: // DOUBLE
        value.move< double > (that.value);
        break;

      case 5: // STRING
      case 6: // LIGHT
      case 7: // AMBIENT
      case 8: // CONSTANTS
      case 9: // SAVE_COORDS
      case 10: // CAMERA
      case 11: // SPHERE
      case 12: // TORUS
      case 13: // BOX
      case 14: // LINE
      case 15: // CS
      case 16: // MESH
      case 17: // TEXTURE
      case 18: // SET
      case 19: // MOVE
      case 20: // SCALE
      case 21: // ROTATE
      case 22: // BASENAME
      case 23: // SAVE_KNOBS
      case 24: // TWEEN
      case 25: // FRAMES
      case 26: // VARY
      case 27: // PUSH
      case 28: // POP
      case 29: // SAVE
      case 30: // GENERATE_RAYFILES
      case 31: // SHADING
      case 32: // SHADING_TYPE
      case 33: // SETKNOBS
      case 34: // FOCAL
      case 35: // DISPLAY
      case 36: // WEB
      case 37: // CO
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 4: // DOUBLE
        value.copy< double > (that.value);
        break;

      case 5: // STRING
      case 6: // LIGHT
      case 7: // AMBIENT
      case 8: // CONSTANTS
      case 9: // SAVE_COORDS
      case 10: // CAMERA
      case 11: // SPHERE
      case 12: // TORUS
      case 13: // BOX
      case 14: // LINE
      case 15: // CS
      case 16: // MESH
      case 17: // TEXTURE
      case 18: // SET
      case 19: // MOVE
      case 20: // SCALE
      case 21: // ROTATE
      case 22: // BASENAME
      case 23: // SAVE_KNOBS
      case 24: // TWEEN
      case 25: // FRAMES
      case 26: // VARY
      case 27: // PUSH
      case 28: // POP
      case 29: // SAVE
      case 30: // GENERATE_RAYFILES
      case 31: // SHADING
      case 32: // SHADING_TYPE
      case 33: // SETKNOBS
      case 34: // FOCAL
      case 35: // DISPLAY
      case 36: // WEB
      case 37: // CO
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 4: // DOUBLE
        yylhs.value.build< double > ();
        break;

      case 5: // STRING
      case 6: // LIGHT
      case 7: // AMBIENT
      case 8: // CONSTANTS
      case 9: // SAVE_COORDS
      case 10: // CAMERA
      case 11: // SPHERE
      case 12: // TORUS
      case 13: // BOX
      case 14: // LINE
      case 15: // CS
      case 16: // MESH
      case 17: // TEXTURE
      case 18: // SET
      case 19: // MOVE
      case 20: // SCALE
      case 21: // ROTATE
      case 22: // BASENAME
      case 23: // SAVE_KNOBS
      case 24: // TWEEN
      case 25: // FRAMES
      case 26: // VARY
      case 27: // PUSH
      case 28: // POP
      case 29: // SAVE
      case 30: // GENERATE_RAYFILES
      case 31: // SHADING
      case 32: // SHADING_TYPE
      case 33: // SETKNOBS
      case 34: // FOCAL
      case 35: // DISPLAY
      case 36: // WEB
      case 37: // CO
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 4:
#line 160 "mdl.y" // lalr1.cc:859
    {}
#line 749 "y.tab.c" // lalr1.cc:859
    break;

  case 5:
#line 163 "mdl.y" // lalr1.cc:859
    {
    addSphereOp(drv, {yystack_[3].value.as< double > (), yystack_[2].value.as< double > (), yystack_[1].value.as< double > ()}, yystack_[0].value.as< double > (), std::nullopt, std::nullopt);
}
#line 757 "y.tab.c" // lalr1.cc:859
    break;

  case 6:
#line 167 "mdl.y" // lalr1.cc:859
    {
    addSphereOp(drv, {yystack_[4].value.as< double > (), yystack_[3].value.as< double > (), yystack_[2].value.as< double > ()}, yystack_[1].value.as< double > (), std::nullopt, yystack_[0].value.as< std::string > ());
}
#line 765 "y.tab.c" // lalr1.cc:859
    break;

  case 7:
#line 171 "mdl.y" // lalr1.cc:859
    {
    addSphereOp(drv, {yystack_[3].value.as< double > (), yystack_[2].value.as< double > (), yystack_[1].value.as< double > ()}, yystack_[0].value.as< double > (), yystack_[4].value.as< std::string > (), std::nullopt);
}
#line 773 "y.tab.c" // lalr1.cc:859
    break;

  case 8:
#line 175 "mdl.y" // lalr1.cc:859
    {
    addSphereOp(drv, {yystack_[4].value.as< double > (), yystack_[3].value.as< double > (), yystack_[2].value.as< double > ()}, yystack_[1].value.as< double > (), yystack_[5].value.as< std::string > (), yystack_[0].value.as< std::string > ());
}
#line 781 "y.tab.c" // lalr1.cc:859
    break;

  case 9:
#line 179 "mdl.y" // lalr1.cc:859
    {
    addTorusOp(drv, {yystack_[4].value.as< double > (), yystack_[3].value.as< double > (), yystack_[2].value.as< double > ()}, yystack_[1].value.as< double > (), yystack_[0].value.as< double > (), std::nullopt, std::nullopt);
}
#line 789 "y.tab.c" // lalr1.cc:859
    break;

  case 10:
#line 183 "mdl.y" // lalr1.cc:859
    {
    addTorusOp(drv, {yystack_[5].value.as< double > (), yystack_[4].value.as< double > (), yystack_[3].value.as< double > ()}, yystack_[2].value.as< double > (), yystack_[1].value.as< double > (), std::nullopt, yystack_[0].value.as< std::string > ());
}
#line 797 "y.tab.c" // lalr1.cc:859
    break;

  case 11:
#line 187 "mdl.y" // lalr1.cc:859
    {
    addTorusOp(drv, {yystack_[4].value.as< double > (), yystack_[3].value.as< double > (), yystack_[2].value.as< double > ()}, yystack_[1].value.as< double > (), yystack_[0].value.as< double > (), yystack_[5].value.as< std::string > (), std::nullopt);
}
#line 805 "y.tab.c" // lalr1.cc:859
    break;

  case 12:
#line 191 "mdl.y" // lalr1.cc:859
    {
    addTorusOp(drv, {yystack_[5].value.as< double > (), yystack_[4].value.as< double > (), yystack_[3].value.as< double > ()}, yystack_[2].value.as< double > (), yystack_[1].value.as< double > (), yystack_[6].value.as< std::string > (), yystack_[0].value.as< std::string > ());
}
#line 813 "y.tab.c" // lalr1.cc:859
    break;

  case 13:
#line 195 "mdl.y" // lalr1.cc:859
    {
    addBoxOp(drv, {yystack_[5].value.as< double > (), yystack_[4].value.as< double > (), yystack_[3].value.as< double > ()}, {yystack_[2].value.as< double > (), yystack_[1].value.as< double > (), yystack_[0].value.as< double > ()}, std::nullopt, std::nullopt);
}
#line 821 "y.tab.c" // lalr1.cc:859
    break;

  case 14:
#line 199 "mdl.y" // lalr1.cc:859
    {
    addBoxOp(drv, {yystack_[6].value.as< double > (), yystack_[5].value.as< double > (), yystack_[4].value.as< double > ()}, {yystack_[3].value.as< double > (), yystack_[2].value.as< double > (), yystack_[1].value.as< double > ()}, std::nullopt, yystack_[0].value.as< std::string > ());
}
#line 829 "y.tab.c" // lalr1.cc:859
    break;

  case 15:
#line 203 "mdl.y" // lalr1.cc:859
    {
    addBoxOp(drv, {yystack_[5].value.as< double > (), yystack_[4].value.as< double > (), yystack_[3].value.as< double > ()}, {yystack_[2].value.as< double > (), yystack_[1].value.as< double > (), yystack_[0].value.as< double > ()}, yystack_[6].value.as< std::string > (), std::nullopt);
}
#line 837 "y.tab.c" // lalr1.cc:859
    break;

  case 16:
#line 207 "mdl.y" // lalr1.cc:859
    {
    addBoxOp(drv, {yystack_[6].value.as< double > (), yystack_[5].value.as< double > (), yystack_[4].value.as< double > ()}, {yystack_[3].value.as< double > (), yystack_[2].value.as< double > (), yystack_[1].value.as< double > ()}, yystack_[7].value.as< std::string > (), yystack_[0].value.as< std::string > ());
}
#line 845 "y.tab.c" // lalr1.cc:859
    break;

  case 17:
#line 212 "mdl.y" // lalr1.cc:859
    {
    addLineOp(drv, {yystack_[5].value.as< double > (), yystack_[4].value.as< double > (), yystack_[3].value.as< double > ()}, {yystack_[2].value.as< double > (), yystack_[1].value.as< double > (), yystack_[0].value.as< double > ()}, std::nullopt, std::nullopt, std::nullopt);
}
#line 853 "y.tab.c" // lalr1.cc:859
    break;

  case 18:
#line 217 "mdl.y" // lalr1.cc:859
    {
    addLineOp(drv, {yystack_[6].value.as< double > (), yystack_[5].value.as< double > (), yystack_[4].value.as< double > ()}, {yystack_[2].value.as< double > (), yystack_[1].value.as< double > (), yystack_[0].value.as< double > ()}, std::nullopt, yystack_[3].value.as< std::string > (), std::nullopt);
}
#line 861 "y.tab.c" // lalr1.cc:859
    break;

  case 19:
#line 221 "mdl.y" // lalr1.cc:859
    {
    addLineOp(drv, {yystack_[6].value.as< double > (), yystack_[5].value.as< double > (), yystack_[4].value.as< double > ()}, {yystack_[3].value.as< double > (), yystack_[2].value.as< double > (), yystack_[1].value.as< double > ()}, std::nullopt, std::nullopt, yystack_[0].value.as< std::string > ());
}
#line 869 "y.tab.c" // lalr1.cc:859
    break;

  case 20:
#line 225 "mdl.y" // lalr1.cc:859
    {
    addLineOp(drv, {yystack_[7].value.as< double > (), yystack_[6].value.as< double > (), yystack_[5].value.as< double > ()}, {yystack_[3].value.as< double > (), yystack_[2].value.as< double > (), yystack_[1].value.as< double > ()}, std::nullopt, yystack_[4].value.as< std::string > (), yystack_[0].value.as< std::string > ());
}
#line 877 "y.tab.c" // lalr1.cc:859
    break;

  case 21:
#line 230 "mdl.y" // lalr1.cc:859
    {
    addLineOp(drv, {yystack_[5].value.as< double > (), yystack_[4].value.as< double > (), yystack_[3].value.as< double > ()}, {yystack_[2].value.as< double > (), yystack_[1].value.as< double > (), yystack_[0].value.as< double > ()}, yystack_[6].value.as< std::string > (), std::nullopt, std::nullopt);
}
#line 885 "y.tab.c" // lalr1.cc:859
    break;

  case 22:
#line 234 "mdl.y" // lalr1.cc:859
    {
    addLineOp(drv, {yystack_[6].value.as< double > (), yystack_[5].value.as< double > (), yystack_[4].value.as< double > ()}, {yystack_[2].value.as< double > (), yystack_[1].value.as< double > (), yystack_[0].value.as< double > ()}, yystack_[7].value.as< std::string > (), yystack_[3].value.as< std::string > (), std::nullopt);
}
#line 893 "y.tab.c" // lalr1.cc:859
    break;

  case 23:
#line 238 "mdl.y" // lalr1.cc:859
    {
    addLineOp(drv, {yystack_[6].value.as< double > (), yystack_[5].value.as< double > (), yystack_[4].value.as< double > ()}, {yystack_[3].value.as< double > (), yystack_[2].value.as< double > (), yystack_[1].value.as< double > ()}, yystack_[7].value.as< std::string > (), std::nullopt, yystack_[0].value.as< std::string > ());
}
#line 901 "y.tab.c" // lalr1.cc:859
    break;

  case 24:
#line 242 "mdl.y" // lalr1.cc:859
    {
    addLineOp(drv, {yystack_[7].value.as< double > (), yystack_[6].value.as< double > (), yystack_[5].value.as< double > ()}, {yystack_[3].value.as< double > (), yystack_[2].value.as< double > (), yystack_[1].value.as< double > ()}, yystack_[8].value.as< std::string > (), yystack_[4].value.as< std::string > (), yystack_[0].value.as< std::string > ());
}
#line 909 "y.tab.c" // lalr1.cc:859
    break;

  case 25:
#line 247 "mdl.y" // lalr1.cc:859
    {
    addMeshOp(drv, yystack_[0].value.as< std::string > (), std::nullopt, std::nullopt);
}
#line 917 "y.tab.c" // lalr1.cc:859
    break;

  case 26:
#line 251 "mdl.y" // lalr1.cc:859
    { /* name and constants */
    addMeshOp(drv, yystack_[0].value.as< std::string > (), yystack_[1].value.as< std::string > (), std::nullopt);
}
#line 925 "y.tab.c" // lalr1.cc:859
    break;

  case 27:
#line 255 "mdl.y" // lalr1.cc:859
    {
    addMeshOp(drv, yystack_[1].value.as< std::string > (), yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
}
#line 933 "y.tab.c" // lalr1.cc:859
    break;

  case 28:
#line 260 "mdl.y" // lalr1.cc:859
    {
    addMoveOp(drv, {yystack_[3].value.as< double > (), yystack_[2].value.as< double > (), yystack_[1].value.as< double > ()}, yystack_[0].value.as< std::string > ());
}
#line 941 "y.tab.c" // lalr1.cc:859
    break;

  case 29:
#line 264 "mdl.y" // lalr1.cc:859
    {
    addMoveOp(drv, {yystack_[2].value.as< double > (), yystack_[1].value.as< double > (), yystack_[0].value.as< double > ()}, std::nullopt);
}
#line 949 "y.tab.c" // lalr1.cc:859
    break;

  case 30:
#line 269 "mdl.y" // lalr1.cc:859
    {
    addScaleOp(drv, {yystack_[3].value.as< double > (), yystack_[2].value.as< double > (), yystack_[1].value.as< double > ()}, yystack_[0].value.as< std::string > ());
}
#line 957 "y.tab.c" // lalr1.cc:859
    break;

  case 31:
#line 273 "mdl.y" // lalr1.cc:859
    {
    addScaleOp(drv, {yystack_[2].value.as< double > (), yystack_[1].value.as< double > (), yystack_[0].value.as< double > ()}, std::nullopt);
}
#line 965 "y.tab.c" // lalr1.cc:859
    break;

  case 32:
#line 277 "mdl.y" // lalr1.cc:859
    {
    addRotOp(drv, yystack_[2].value.as< std::string > (), yystack_[1].value.as< double > (), yystack_[0].value.as< std::string > ());
}
#line 973 "y.tab.c" // lalr1.cc:859
    break;

  case 33:
#line 281 "mdl.y" // lalr1.cc:859
    {
    addRotOp(drv, yystack_[1].value.as< std::string > (), yystack_[0].value.as< double > (), std::nullopt);
}
#line 981 "y.tab.c" // lalr1.cc:859
    break;

  case 34:
#line 286 "mdl.y" // lalr1.cc:859
    {
    drv.ops.push_back(Operation());
    drv.ops.back().op = "PUSH";
}
#line 990 "y.tab.c" // lalr1.cc:859
    break;

  case 35:
#line 292 "mdl.y" // lalr1.cc:859
    {
    drv.ops.push_back(Operation());
    drv.ops.back().op = "POP";
}
#line 999 "y.tab.c" // lalr1.cc:859
    break;

  case 36:
#line 298 "mdl.y" // lalr1.cc:859
    {
    drv.ops.push_back(Operation());
    drv.ops.back().op = "DISPLAY";
}
#line 1008 "y.tab.c" // lalr1.cc:859
    break;

  case 37:
#line 304 "mdl.y" // lalr1.cc:859
    {
    drv.ops.push_back(Operation());
    drv.ops.back().op = "SAVE";
    drv.ops.back().data = yystack_[0].value.as< std::string > ();
}
#line 1018 "y.tab.c" // lalr1.cc:859
    break;

  case 38:
#line 311 "mdl.y" // lalr1.cc:859
    {
    drv.ops.push_back(Operation());
    drv.ops.back().op = "DIRECTIONAL_LIGHT";
    drv.ops.back().data = yystack_[6].value.as< std::string > ();
    drv.ops.back().vecs.push_back({yystack_[5].value.as< double > (), yystack_[4].value.as< double > (), yystack_[3].value.as< double > ()});
    drv.ops.back().vecs.push_back({yystack_[2].value.as< double > (), yystack_[1].value.as< double > (), yystack_[0].value.as< double > ()});
}
#line 1030 "y.tab.c" // lalr1.cc:859
    break;

  case 39:
#line 320 "mdl.y" // lalr1.cc:859
    {
    drv.ops.push_back(Operation());
    drv.ops.back().op = "DIRECTIONAL_LIGHT";
    drv.ops.back().vecs.push_back({yystack_[5].value.as< double > (), yystack_[4].value.as< double > (), yystack_[3].value.as< double > ()});
    drv.ops.back().vecs.push_back({yystack_[2].value.as< double > (), yystack_[1].value.as< double > (), yystack_[0].value.as< double > ()});
}
#line 1041 "y.tab.c" // lalr1.cc:859
    break;

  case 40:
#line 328 "mdl.y" // lalr1.cc:859
    {
    MDLDriver::matTable[yystack_[9].value.as< std::string > ()] = {{yystack_[8].value.as< double > (), yystack_[5].value.as< double > (), yystack_[2].value.as< double > ()}, {yystack_[7].value.as< double > (), yystack_[4].value.as< double > (), yystack_[1].value.as< double > ()}, {yystack_[6].value.as< double > (), yystack_[3].value.as< double > (), yystack_[0].value.as< double > ()}, {0, 0, 0}};
}
#line 1049 "y.tab.c" // lalr1.cc:859
    break;

  case 41:
#line 333 "mdl.y" // lalr1.cc:859
    {
    MDLDriver::matTable[yystack_[12].value.as< std::string > ()] = {{yystack_[11].value.as< double > (), yystack_[8].value.as< double > (), yystack_[5].value.as< double > ()}, {yystack_[10].value.as< double > (), yystack_[7].value.as< double > (), yystack_[4].value.as< double > ()}, {yystack_[9].value.as< double > (), yystack_[6].value.as< double > (), yystack_[3].value.as< double > ()}, {yystack_[2].value.as< double > (), yystack_[1].value.as< double > (), yystack_[0].value.as< double > ()}};
}
#line 1057 "y.tab.c" // lalr1.cc:859
    break;

  case 42:
#line 338 "mdl.y" // lalr1.cc:859
    {
    drv.ops.push_back(Operation());
    drv.ops.back().op = "SAVE_COORDS";
    drv.ops.back().data = yystack_[0].value.as< std::string > ();
}
#line 1067 "y.tab.c" // lalr1.cc:859
    break;

  case 43:
#line 345 "mdl.y" // lalr1.cc:859
    {
    drv.ops.push_back(Operation());
    drv.ops.back().op = "SET";
    drv.ops.back().data = yystack_[1].value.as< std::string > ();
    drv.ops.back().vals.push_back(yystack_[0].value.as< double > ());
}
#line 1078 "y.tab.c" // lalr1.cc:859
    break;

  case 44:
#line 353 "mdl.y" // lalr1.cc:859
    {
    Timeline::setName(yystack_[0].value.as< std::string > ());
}
#line 1086 "y.tab.c" // lalr1.cc:859
    break;

  case 45:
#line 357 "mdl.y" // lalr1.cc:859
    {
    drv.ops.push_back(Operation());
    drv.ops.back().op = "SAVE_KNOBS";
    drv.ops.back().data = yystack_[0].value.as< std::string > ();
}
#line 1096 "y.tab.c" // lalr1.cc:859
    break;

  case 46:
#line 364 "mdl.y" // lalr1.cc:859
    {
    drv.ops.push_back(Operation());
    drv.ops.back().op = "TWEEN";
    drv.ops.back().vals.push_back(yystack_[3].value.as< double > ());
    drv.ops.back().vals.push_back(yystack_[2].value.as< double > ());
    //storing knoblists instead of coord systems
    drv.ops.back().cs1 = yystack_[1].value.as< std::string > ();
    drv.ops.back().cs2 = yystack_[0].value.as< std::string > ();
}
#line 1110 "y.tab.c" // lalr1.cc:859
    break;

  case 47:
#line 375 "mdl.y" // lalr1.cc:859
    {
    Timeline::setFrames(yystack_[0].value.as< double > ());
}
#line 1118 "y.tab.c" // lalr1.cc:859
    break;

  case 48:
#line 380 "mdl.y" // lalr1.cc:859
    {
    Timeline::addKnob(yystack_[4].value.as< std::string > (), yystack_[3].value.as< double > (), yystack_[2].value.as< double > (), yystack_[1].value.as< double > (), yystack_[0].value.as< double > ());
}
#line 1126 "y.tab.c" // lalr1.cc:859
    break;

  case 49:
#line 385 "mdl.y" // lalr1.cc:859
    {
    drv.ops.push_back(Operation());
    drv.ops.back().op = "SHADING";
    drv.ops.back().data = yystack_[0].value.as< std::string > ();
}
#line 1136 "y.tab.c" // lalr1.cc:859
    break;

  case 50:
#line 391 "mdl.y" // lalr1.cc:859
    {
    drv.ops.push_back(Operation());
    drv.ops.back().op = "SET_KNOBS";
    drv.ops.back().vals.push_back(yystack_[0].value.as< double > ());
}
#line 1146 "y.tab.c" // lalr1.cc:859
    break;

  case 51:
#line 397 "mdl.y" // lalr1.cc:859
    {
    drv.ops.push_back(Operation());
    drv.ops.back().op = "FOCAL";
    drv.ops.back().vals.push_back(yystack_[0].value.as< double > ());
}
#line 1156 "y.tab.c" // lalr1.cc:859
    break;

  case 52:
#line 404 "mdl.y" // lalr1.cc:859
    {
    drv.ops.push_back(Operation());
    drv.ops.back().op = "WEB";
}
#line 1165 "y.tab.c" // lalr1.cc:859
    break;

  case 53:
#line 409 "mdl.y" // lalr1.cc:859
    {
    drv.ops.push_back(Operation());
    drv.ops.back().op = "AMBIENT_LIGHT";
    drv.ops.back().vecs.push_back({yystack_[2].value.as< double > (), yystack_[1].value.as< double > (), yystack_[0].value.as< double > ()});
}
#line 1175 "y.tab.c" // lalr1.cc:859
    break;

  case 54:
#line 416 "mdl.y" // lalr1.cc:859
    {
    drv.ops.push_back(Operation());
    drv.ops.back().op = "GENERATE_RAYFILES";
}
#line 1184 "y.tab.c" // lalr1.cc:859
    break;


#line 1188 "y.tab.c" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -4;

  const signed char parser::yytable_ninf_ = -1;

  const short int
  parser::yypact_[] =
  {
      -4,     0,    -4,    -4,    -3,     1,    -1,    10,    33,    35,
      39,    41,     5,    12,    28,    37,    46,    47,    48,    50,
      51,    52,    -4,    -4,    53,    -4,    24,    55,    56,    -4,
      -4,    -4,    57,    58,    59,    60,    -4,    61,    62,    63,
      64,    65,    66,    67,    68,    36,    69,    71,    72,    73,
      74,    -4,    -4,    75,    -4,    76,    -4,    -4,    -4,    -4,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -4,    -4,    91,    92,    93,    94,    96,
      97,    98,    -4,    99,   100,   101,   102,   103,   104,   105,
      43,   106,   107,   108,   109,    -4,   110,   112,   113,   114,
     115,   116,   118,   119,   120,   121,   122,   123,   124,    45,
      -4,    -4,    -4,    -4,   125,   126,   127,   128,    -4,   129,
     130,   132,   133,   134,   135,   136,   137,   138,    -4,    -4,
     139,   140,    -4,    -4,   141,   142,   144,   145,   147,   148,
     149,    -4,   150,    -4,    -4,   151,    -4,   152,   153,   155,
     156,    -4,    -4,    -4,   157,   159,    -4,   160,   161,   162,
      -4
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     0,     1,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,    35,     0,    54,     0,     0,     0,    36,
      52,     3,     0,     0,     0,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    44,    45,     0,    47,     0,    37,    49,    50,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    43,     0,     0,    33,     0,     0,
       0,     0,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,    29,    31,    32,     0,     0,     0,     0,
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    28,    30,    46,     0,     0,     0,     0,     6,     7,
       9,     0,     0,     0,     0,     0,     0,     0,    48,    39,
       0,     0,     8,    10,    11,    13,     0,    17,     0,     0,
       0,    38,     0,    12,    14,    15,    19,    18,    21,     0,
       0,    16,    20,    23,    22,     0,    24,    40,     0,     0,
      41
  };

  const signed char
  parser::yypgoto_[] =
  {
      -4,    -4,    -4
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,    31
  };

  const unsigned char
  parser::yytable_[] =
  {
       2,    32,    33,     3,    35,    34,     4,     5,     6,     7,
      45,     8,     9,    10,    11,    36,    12,    47,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    48,    27,    28,    29,    30,    37,    38,    39,
      40,    49,    46,    41,    42,    43,    44,   107,   108,   126,
     127,    50,    51,    52,    53,    54,    57,    55,    56,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,    92,    93,    94,     0,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     109,     0,   110,   111,   112,   113,   114,   115,   116,   117,
       0,   118,   119,   120,   121,   122,   123,   124,   125,   128,
     129,   130,   131,     0,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,     0,   143,   144,   145,     0,
     146,   147,   148,   149,   150,     0,   151,   152,   153,   154,
     155,     0,   156,   157,   158,   159,   160
  };

  const signed char
  parser::yycheck_[] =
  {
       0,     4,     5,     3,     5,     4,     6,     7,     8,     9,
       5,    11,    12,    13,    14,     5,    16,     5,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     4,    33,    34,    35,    36,     4,     5,     4,
       5,     4,    37,     4,     5,     4,     5,     4,     5,     4,
       5,     5,     5,     5,     4,     4,    32,     5,     5,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,    37,     5,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,    -1,     5,     4,     4,    -1,     5,     5,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,    -1,     5,     5,     5,     5,     4,     4,     4,     4,
      -1,     5,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,    -1,     5,     5,     4,     4,     4,     4,
       4,     4,     4,     4,     4,    -1,     5,     5,     4,    -1,
       5,     4,     4,     4,     4,    -1,     5,     5,     5,     4,
       4,    -1,     5,     4,     4,     4,     4
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    39,     0,     3,     6,     7,     8,     9,    11,    12,
      13,    14,    16,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    33,    34,    35,
      36,    40,     4,     5,     4,     5,     5,     4,     5,     4,
       5,     4,     5,     4,     5,     5,    37,     5,     4,     4,
       5,     5,     5,     4,     4,     5,     5,    32,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,    37,     5,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     4,     4,     5,     5,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     4,
       5,     5,     5,     5,     4,     4,     4,     4,     5,     4,
       4,     4,     4,     4,     4,     4,     4,     5,     4,     4,
       4,     4,     5,     5,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     5,     5,     4,     5,     4,     4,     4,
       4,     5,     5,     5,     4,     4,     5,     4,     4,     4,
       4
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    38,    39,    39,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     1,     5,     6,     6,     7,     6,
       7,     7,     8,     7,     8,     8,     9,     7,     8,     8,
       9,     8,     9,     9,    10,     3,     4,     5,     5,     4,
       5,     4,     4,     3,     1,     1,     1,     2,     8,     7,
      11,    14,     2,     3,     2,     2,     5,     2,     6,     2,
       2,     2,     1,     4,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "COMMENT", "DOUBLE", "STRING",
  "LIGHT", "AMBIENT", "CONSTANTS", "SAVE_COORDS", "CAMERA", "SPHERE",
  "TORUS", "BOX", "LINE", "CS", "MESH", "TEXTURE", "SET", "MOVE", "SCALE",
  "ROTATE", "BASENAME", "SAVE_KNOBS", "TWEEN", "FRAMES", "VARY", "PUSH",
  "POP", "SAVE", "GENERATE_RAYFILES", "SHADING", "SHADING_TYPE",
  "SETKNOBS", "FOCAL", "DISPLAY", "WEB", "CO", "$accept", "input",
  "command", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,   154,   154,   155,   160,   162,   166,   170,   174,   178,
     182,   186,   190,   194,   198,   202,   206,   211,   216,   220,
     224,   229,   233,   237,   241,   246,   250,   254,   259,   263,
     268,   272,   276,   280,   285,   291,   297,   303,   310,   319,
     327,   332,   337,   344,   352,   356,   363,   374,   379,   384,
     390,   396,   403,   408,   415
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1651 "y.tab.c" // lalr1.cc:1167
#line 420 "mdl.y" // lalr1.cc:1168



void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
