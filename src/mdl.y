%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0.4"
%defines

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  # include <string>
  # include <optional>
  # include "Vec4.hpp"
  # include "Light.hpp"
  # include "Timeline.hpp"
  class MDLDriver;
}

%param { MDLDriver& drv }

%locations

%define parse.trace
%define parse.error verbose

%code {
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

}

%define api.token.prefix {TOK_}
%token END 0 "end of file"
%token COMMENT
%token <double> DOUBLE
%token <std::string> STRING
%token <std::string> LIGHT AMBIENT
%token <std::string> CONSTANTS SAVE_COORDS CAMERA
%token <std::string> SPHERE TORUS BOX LINE CS MESH TEXTURE
%token <std::string> SET MOVE SCALE ROTATE BASENAME SAVE_KNOBS TWEEN FRAMES VARY
%token <std::string> PUSH POP SAVE GENERATE_RAYFILES
%token <std::string> SHADING SHADING_TYPE SETKNOBS FOCAL DISPLAY WEB
%token <std::string> CO

%%
input:
| input command
;

command:

COMMENT {}|

SPHERE DOUBLE DOUBLE DOUBLE DOUBLE
{
    addSphereOp(drv, {$2, $3, $4}, $5, std::nullopt, std::nullopt);
}|
SPHERE DOUBLE DOUBLE DOUBLE DOUBLE STRING
{
    addSphereOp(drv, {$2, $3, $4}, $5, std::nullopt, $6);
}|
SPHERE STRING DOUBLE DOUBLE DOUBLE DOUBLE
{
    addSphereOp(drv, {$3, $4, $5}, $6, $2, std::nullopt);
}|
SPHERE STRING DOUBLE DOUBLE DOUBLE DOUBLE STRING
{
    addSphereOp(drv, {$3, $4, $5}, $6, $2, $7);
}|
TORUS DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE
{
    addTorusOp(drv, {$2, $3, $4}, $5, $6, std::nullopt, std::nullopt);
}|
TORUS DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE STRING
{
    addTorusOp(drv, {$2, $3, $4}, $5, $6, std::nullopt, $7);
}|
TORUS STRING DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE
{
    addTorusOp(drv, {$3, $4, $5}, $6, $7, $2, std::nullopt);
}|
TORUS STRING DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE STRING
{
    addTorusOp(drv, {$3, $4, $5}, $6, $7, $2, $8);
}|
BOX DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE
{
    addBoxOp(drv, {$2, $3, $4}, {$5, $6, $7}, std::nullopt, std::nullopt);
}|
BOX DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE STRING
{
    addBoxOp(drv, {$2, $3, $4}, {$5, $6, $7}, std::nullopt, $8);
}|
BOX STRING DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE
{
    addBoxOp(drv, {$3, $4, $5}, {$6, $7, $8}, $2, std::nullopt);
}|
BOX STRING DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE STRING
{
    addBoxOp(drv, {$3, $4, $5}, {$6, $7, $8}, $2, $9);
}|

LINE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE
{
    addLineOp(drv, {$2, $3, $4}, {$5, $6, $7}, std::nullopt, std::nullopt, std::nullopt);
}|
/* first do cs0, then cs1, then both - BUT NO CONSTANTS */
LINE DOUBLE DOUBLE DOUBLE STRING DOUBLE DOUBLE DOUBLE
{
    addLineOp(drv, {$2, $3, $4}, {$6, $7, $8}, std::nullopt, $5, std::nullopt);
}|
LINE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE STRING
{
    addLineOp(drv, {$2, $3, $4}, {$5, $6, $7}, std::nullopt, std::nullopt, $8);
}|
LINE DOUBLE DOUBLE DOUBLE STRING DOUBLE DOUBLE DOUBLE STRING
{
    addLineOp(drv, {$2, $3, $4}, {$6, $7, $8}, std::nullopt, $5, $9);
}|
/* now do constants, and constants with the cs stuff */
LINE STRING DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE
{
    addLineOp(drv, {$3, $4, $5}, {$6, $7, $8}, $2, std::nullopt, std::nullopt);
}|
LINE STRING DOUBLE DOUBLE DOUBLE STRING DOUBLE DOUBLE DOUBLE
{
    addLineOp(drv, {$3, $4, $5}, {$7, $8, $9}, $2, $6, std::nullopt);
}|
LINE STRING DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE STRING
{
    addLineOp(drv, {$3, $4, $5}, {$6, $7, $8}, $2, std::nullopt, $9);
}|
LINE STRING DOUBLE DOUBLE DOUBLE STRING DOUBLE DOUBLE DOUBLE STRING
{
    addLineOp(drv, {$3, $4, $5}, {$7, $8, $9}, $2, $6, $10);
}|

MESH CO STRING
{
    addMeshOp(drv, $3, std::nullopt, std::nullopt);
}|
MESH STRING CO STRING
{ /* name and constants */
    addMeshOp(drv, $4, $3, std::nullopt);
} |
MESH STRING CO STRING STRING
{
    addMeshOp(drv, $4, $3, $5);
} |

MOVE DOUBLE DOUBLE DOUBLE STRING
{
    addMoveOp(drv, {$2, $3, $4}, $5);
}|
MOVE DOUBLE DOUBLE DOUBLE
{
    addMoveOp(drv, {$2, $3, $4}, std::nullopt);
}|

SCALE DOUBLE DOUBLE DOUBLE STRING
{
    addScaleOp(drv, {$2, $3, $4}, $5);
}|
SCALE DOUBLE DOUBLE DOUBLE
{
    addScaleOp(drv, {$2, $3, $4}, std::nullopt);
}|
ROTATE STRING DOUBLE STRING
{
    addRotOp(drv, $2, $3, $4);
}|
ROTATE STRING DOUBLE
{
    addRotOp(drv, $2, $3, std::nullopt);
}|

PUSH
{
    drv.ops.push_back(Operation());
    drv.ops.back().op = "PUSH";
}|

POP
{
    drv.ops.push_back(Operation());
    drv.ops.back().op = "POP";
}|

DISPLAY
{
    drv.ops.push_back(Operation());
    drv.ops.back().op = "DISPLAY";
}|

SAVE STRING
{
    drv.ops.push_back(Operation());
    drv.ops.back().op = "SAVE";
    drv.ops.back().data = $2;
}|

LIGHT STRING DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE
{
    drv.ops.push_back(Operation());
    drv.ops.back().op = "DIRECTIONAL_LIGHT";
    drv.ops.back().data = $2;
    drv.ops.back().vecs.push_back({$3, $4, $5});
    drv.ops.back().vecs.push_back({$6, $7, $8});
}|

LIGHT DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE
{
    drv.ops.push_back(Operation());
    drv.ops.back().op = "DIRECTIONAL_LIGHT";
    drv.ops.back().vecs.push_back({$2, $3, $4});
    drv.ops.back().vecs.push_back({$5, $6, $7});
}|

CONSTANTS STRING DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE
{
    MDLDriver::matTable[$2] = {{$3, $6, $9}, {$4, $7, $10}, {$5, $8, $11}, {0, 0, 0}};
}|

CONSTANTS STRING DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE DOUBLE
{
    MDLDriver::matTable[$2] = {{$3, $6, $9}, {$4, $7, $10}, {$5, $8, $11}, {$12, $13, $14}};
}|

SAVE_COORDS STRING
{
    drv.ops.push_back(Operation());
    drv.ops.back().op = "SAVE_COORDS";
    drv.ops.back().data = $2;
}|

SET STRING DOUBLE
{
    drv.ops.push_back(Operation());
    drv.ops.back().op = "SET";
    drv.ops.back().data = $2;
    drv.ops.back().vals.push_back($3);
}|

BASENAME STRING
{
    Timeline::setName($2);
}|
SAVE_KNOBS STRING
{
    drv.ops.push_back(Operation());
    drv.ops.back().op = "SAVE_KNOBS";
    drv.ops.back().data = $2;
}|

TWEEN DOUBLE DOUBLE STRING STRING
{
    drv.ops.push_back(Operation());
    drv.ops.back().op = "TWEEN";
    drv.ops.back().vals.push_back($2);
    drv.ops.back().vals.push_back($3);
    //storing knoblists instead of coord systems
    drv.ops.back().cs1 = $4;
    drv.ops.back().cs2 = $5;
}|

FRAMES DOUBLE
{
    Timeline::setFrames($2);
}|

VARY STRING DOUBLE DOUBLE DOUBLE DOUBLE
{
    Timeline::addKnob($2, $3, $4, $5, $6);
}|

SHADING SHADING_TYPE
{
    drv.ops.push_back(Operation());
    drv.ops.back().op = "SHADING";
    drv.ops.back().data = $2;
}|
SETKNOBS DOUBLE
{
    drv.ops.push_back(Operation());
    drv.ops.back().op = "SET_KNOBS";
    drv.ops.back().vals.push_back($2);
}|
FOCAL DOUBLE
{
    drv.ops.push_back(Operation());
    drv.ops.back().op = "FOCAL";
    drv.ops.back().vals.push_back($2);
}|

WEB
{
    drv.ops.push_back(Operation());
    drv.ops.back().op = "WEB";
}|
AMBIENT DOUBLE DOUBLE DOUBLE
{
    drv.ops.push_back(Operation());
    drv.ops.back().op = "AMBIENT_LIGHT";
    drv.ops.back().vecs.push_back({$2, $3, $4});
}|

GENERATE_RAYFILES
{
    drv.ops.push_back(Operation());
    drv.ops.back().op = "GENERATE_RAYFILES";
};
%%


void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}