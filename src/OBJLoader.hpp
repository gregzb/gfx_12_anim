#pragma once

#include <vector>
#include <unordered_map>
#include <string>

#include "Vec4.hpp"
#include "Mat4.hpp"
#include "Utils.hpp"
#include "PixelGrid.hpp"

#include "OBJStructs.hpp"

class OBJLoader
{
private:
    std::unordered_map<std::string, OBJObject> objects;
    std::unordered_map<std::string, OBJMaterial> materials;

    std::string mtlFileName;

    OBJObject * currentObject;
    OBJMaterial * currentMaterial;

    std::vector<Vec4> v;
    std::vector<Vec4> vt;
    std::vector<Vec4> vn;

    void parseMTL();

public:
    OBJLoader(std::string const &fileName);
    void addToMatrix(Mat4 & mat, std::string name) const;
    void addAllToMatrix(Mat4 & mat) const;
};