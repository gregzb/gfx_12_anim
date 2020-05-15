#include <vector>
#include <unordered_map>
#include <string>

#include <sstream>
#include <iostream>
#include <fstream>

#include <unordered_set>

#include "OBJLoader.hpp"
#include "Vec4.hpp"
#include "Utils.hpp"
#include "PixelGrid.hpp"

void OBJLoader::parseMTL()
{
    //resources is temporary!!!
    std::ifstream mtlFile("resources/" + mtlFileName);
    //std::cout << "resources/" + mtlFileName << std::endl;
    std::string line;

    Vec4 Ka, Kd, Ks, Ke;
    double Ns, Ni, opaqueness;

    while (std::getline(mtlFile, line))
    {
        std::istringstream iss(line);
        std::string infoType;
        iss >> infoType;

        if (infoType == "newmtl")
        {
            std::string matName;
            iss >> matName;

            materials.insert({matName, OBJMaterial()});
            currentMaterial = &materials.at(matName);
            currentMaterial->name = matName;
        }
        else if (infoType == "Ns")
        {
            double val;
            iss >> val;

            currentMaterial->Ns = val;
        }
        else if (infoType == "Ka")
        {
            Vec4 val;
            iss >> val;

            currentMaterial->Ka = val;
        }
        else if (infoType == "Kd")
        {
            Vec4 val;
            iss >> val;

            currentMaterial->Kd = val;
        }
        else if (infoType == "Ks")
        {
            Vec4 val;
            iss >> val;

            currentMaterial->Ks = val;
        }
        else if (infoType == "Ke")
        {
            Vec4 val;
            iss >> val;

            currentMaterial->Ke = val;
        }
        else if (infoType == "Ni")
        {
            double val;
            iss >> val;

            currentMaterial->Ni = val;
        }
        else if (infoType == "d")
        {
            double val;
            iss >> val;

            currentMaterial->opaqueness = val;
        }
        else if (infoType == "illum")
        {
            int val;
            iss >> val;

            currentMaterial->illum = val;
        }
        // else if (infoType == "map_Kd")
        // {
        //     std::string texName;
        //     iss >> texName;

        //     currentMaterial->mapKd = PixelGrid<Color>::loadTexture(texName);
        // }
    }
    mtlFile.close();
}

OBJLoader::OBJLoader(std::string const &fileName)
{
    currentObject = nullptr;
    currentMaterial = nullptr;

    std::ifstream objFile(fileName);
    std::string line;
    while (std::getline(objFile, line))
    {
        std::istringstream iss(line);
        std::string infoType;
        iss >> infoType;

        // std::cout << infoType << std::endl;

        if (infoType == "mtllib")
        {
            iss >> mtlFileName;
            parseMTL();
        }
        else if (infoType == "o")
        {
            std::string objectName;
            iss >> objectName;

            objects.insert({objectName, OBJObject()});
            currentObject = &objects.at(objectName);
            currentObject->name = objectName;
        }
        else if (infoType == "v")
        {
            Vec4 pos;
            iss >> pos;
            v.push_back(pos);
        }
        else if (infoType == "vt")
        {
            Vec4 pos;
            iss >> pos;
            vt.push_back(pos);
        }
        else if (infoType == "vn")
        {
            Vec4 pos;
            iss >> pos;
            vn.push_back(pos);
        }
        else if (infoType == "f")
        {
            std::vector<std::string> verts(3);
            iss >> verts[0] >> verts[1] >> verts[2];

            std::vector<std::vector<int>> indices(3);

            for (int i = 0; i < 3; i++)
            {
                indices[i].push_back(-1);
                indices[i].push_back(-1);
                indices[i].push_back(-1);
            }

            for (int i = 0; i < 3; i++)
            {
                int counter = 0;
                std::istringstream vertStream(verts[i]);
                std::string temp;
                while (std::getline(vertStream, temp, '/'))
                {
                    if (temp != "")
                        indices[counter][i] = std::stoi(temp);
                    counter++;
                }
            }

            currentObject->vertexIndices.push_back(indices[0]);
            currentObject->vertexTexIndices.push_back(indices[1]);
            currentObject->vertexNormalIndices.push_back(indices[2]);
        }
        else if (infoType == "usemtl")
        {
            std::string matName;
            iss >> matName;

            currentObject->mat = &materials.at(matName);
        }
        else if (infoType == "s")
        {
            std::string smooth;
            iss >> smooth;
            currentObject->smoothShading = smooth == "1";
        }
    }
    objFile.close();
}

void OBJLoader::addToMatrix(Mat4 &mat, std::string name) const
{
    OBJObject const &obj = objects.at(name);
    for (uint i = 0; i < obj.vertexIndices.size(); i++)
    {
        if (obj.vertexIndices[i].size() != 3)
        {
            std::cout << "no " << std::endl;
            exit(2);
        }
        for (uint j = 0; j < obj.vertexIndices[i].size(); j++)
        {
            auto pos = v[obj.vertexIndices[i][j] - 1];
            pos.setW(1);
            //auto tex = vt[obj.vertexTexIndices[i][j]-1];

            //temp.addVertex({pos, tex});
            mat.addPoint(pos);
        }
    }
}

void OBJLoader::addAllToMatrix(Mat4 &mat) const
{
    for (auto const &entry : objects)
    {
        auto const &obj = entry.second;
        for (uint i = 0; i < obj.vertexIndices.size(); i++)
        {
            if (obj.vertexIndices[i].size() != 3)
            {
                std::cout << "no " << std::endl;
                exit(2);
            }
            for (uint j = 0; j < obj.vertexIndices[i].size(); j++)
            {
                auto pos = v[obj.vertexIndices[i][j] - 1];
                pos.setW(1);
                //auto tex = vt[obj.vertexTexIndices[i][j]-1];

                //temp.addVertex({pos, tex});
                mat.addPoint(pos);
            }
        }
    }
}

// RenderObject OBJLoader::toRenderObject(std::string name) const
// {
//     RenderObject temp;
//     std::unordered_set<int> inserted;
//     // std::cout << objects.size() << std::endl;
//     // for (auto thing : objects) {
//     //     std::cout << thing.first << std::endl;
//     // }

//     OBJObject const &obj = objects.at(name);
//     // for (auto const & face : obj.getVertexIndices()) {
//     //     for (auto const & vertex : face) {
//     //         auto pos = v[vertex-1];
//     //         auto tex = vt[vertex-1];

//     //         temp.addVertex({pos, tex});
//     //     }
//     // }
//     // std::cout << obj.getVertexIndices().size() << std::endl;
//     // std::cout << obj.getVertexTexIndices().size() << std::endl;
//     for(uint i = 0; i < obj.vertexIndices.size(); i++) {
//         for (uint j = 0; j < obj.vertexIndices[i].size(); j++) {
//             auto pos = v[obj.vertexIndices[i][j]-1];
//             auto tex = vt[obj.vertexTexIndices[i][j]-1];

//             //std::cout << obj.getVertexIndices()[i][j]-1 << " " << obj.getVertexTexIndices()[i][j]-1 << std::endl;

//             temp.addVertex({pos, tex});
//         }
//     }
//     temp.setMaterial(obj.mat);
//     //temp.setTexture(obj.mat->mapKd);
//     //std::cout << obj.getMat()->getTexture().getWidth() << " " << obj.getMat()->getTexture().getHeight() << std::endl;
//     //exit(0);
//     //obj.getMat()->getTexture().display();
//     // for (auto face : obj.getVertexIndices())
//     // {
//     //     // if (face[0] > v.size() || face[1] > v.size() || face[2] > v.size())
//     //     // std::cout << v.size() << " " << face[0] << " " << face[1] << " " << face[2] << std::endl;
//     //     //its 1-indexed
//     //     temp.addTriangle(v[face[0] - 1], v[face[1] - 1], v[face[2] - 1]);
//     // }
//     return temp;
// }