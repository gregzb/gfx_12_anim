#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
#include <limits>

#include <random>
#include <unordered_map>
#include <chrono>

#include <utility>

#include <cmath>

#include "Utils.hpp"
#include "PixelGrid.hpp"
#include "Screen.hpp"
#include "Mat4.hpp"
#include "Vec4.hpp"

#include "OBJLoader.hpp"
#include "Light.hpp"

#include "MDLDriver.hpp"

std::vector<Light> WORLD_LIGHTS;

void parse(std::vector<Operation> const &operations, Screen &screen, Mat4 &edges, Mat4 &triangles, std::vector<Mat4> &coordSystems)
{
    Material defaultMat;
    defaultMat.ambient = {0.5, 0.5, 0.5};
    defaultMat.diffuse = {0.5, 0.5, 0.5};
    defaultMat.specular = {0.5, 0.5, 0.5};
    for (auto op : operations)
    {
        auto name = op.op;
        //std::cout << name << std::endl;
        if (name == "SPHERE")
        {
            triangles.addSphere(op.vecs[0], op.vals[0], 30, 15);

            if (op.cs1.has_value())
            {
                triangles.multiplyMutate(MDLDriver::coordTable[op.cs1.value()]);
            }
            else
            {
                triangles.multiplyMutate(coordSystems.back());
            }
            Material const &mat = op.mat.has_value() ? MDLDriver::matTable[op.mat.value()] : defaultMat;
            //std::cout << op.vecs[0] << op.vals[0] << std::endl;
            //std::cout << triangles.toString() << std::endl;
            screen.drawTriangles(triangles, mat);
            triangles.clear();
        }
        else if (name == "TORUS")
        {
            triangles.addTorus(op.vecs[0], op.vals[0], op.vals[1], 20, 12);

            if (op.cs1.has_value())
            {
                triangles.multiplyMutate(MDLDriver::coordTable[op.cs1.value()]);
            }
            else
            {
                triangles.multiplyMutate(coordSystems.back());
            }
            Material const &mat = op.mat.has_value() ? MDLDriver::matTable[op.mat.value()] : defaultMat;
            screen.drawTriangles(triangles, mat);
            //std::cout << triangles.toString() << std::endl;
            triangles.clear();
        }
        else if (name == "BOX")
        {
            //std::cout << op.vecs[0] << op.vecs[1] << std::endl;
            triangles.addBox(op.vecs[0], op.vecs[1]);

            if (op.cs1.has_value())
            {
                triangles.multiplyMutate(MDLDriver::coordTable[op.cs1.value()]);
            }
            else
            {
                triangles.multiplyMutate(coordSystems.back());
            }
            Material const &mat = op.mat.has_value() ? MDLDriver::matTable[op.mat.value()] : defaultMat;
            screen.drawTriangles(triangles, mat);
            triangles.clear();
        }
        else if (name == "LINE")
        {
            Mat4 t1 = {};
            t1.addPoint(op.vecs[0]);

            if (op.cs1.has_value())
            {
                t1.multiplyMutate(MDLDriver::coordTable[op.cs1.value()]);
            }
            else
            {
                t1.multiplyMutate(coordSystems.back());
            }

            Mat4 t2 = {};
            t2.addPoint(op.vecs[1]);

            if (op.cs2.has_value())
            {
                t2.multiplyMutate(MDLDriver::coordTable[op.cs2.value()]);
            }
            else
            {
                t2.multiplyMutate(coordSystems.back());
            }

            edges.addEdge(t1.getPoint(0), t2.getPoint(0));
            Material const &mat = op.mat.has_value() ? MDLDriver::matTable[op.mat.value()] : defaultMat;
            screen.drawEdges(edges, mat.diffuse.toColor());
            edges.clear();
            // edges.addEdge(op.vecs[0], op.vecs[1]);
            // triangles.addBox(op.vecs[0], op.vecs[1]);

            // if (op.cs1.has_value()) {
            //     triangles.multiplyMutate(MDLDriver::coordTable[op.cs1.value()]);
            // } else {
            //     triangles.multiplyMutate(coordSystems.back());
            // }
            // Material const &mat = op.mat.has_value() ? MDLDriver::matTable[op.mat.value()] : defaultMat;
            // screen.drawTriangles(triangles, mat);
            // triangles.clear();
        }
        else if (name == "MESH")
        {
            std::string filename = op.data.value_or("filename wasnt given??");
            //std::cout << "trying to load obj file: " << filename << std::endl;
            OBJLoader obj(filename);

            obj.addAllToMatrix(triangles);
            if (op.cs1.has_value())
            {
                triangles.multiplyMutate(MDLDriver::coordTable[op.cs1.value()]);
            }
            else
            {
                triangles.multiplyMutate(coordSystems.back());
            }

            Material const &mat = op.mat.has_value() ? MDLDriver::matTable[op.mat.value()] : defaultMat;
            screen.drawTriangles(triangles, mat);
            triangles.clear();
        }
        else if (name == "MOVE")
        {
            Vec4 transformVec = op.vecs[0];
            if (op.knob.has_value())
            {
                transformVec = transformVec * Timeline::getKnob(op.knob.value()).getValue(Timeline::getFrame());
            }
            Mat4 const &temp = Mat4::translate(transformVec);
            coordSystems.back() = coordSystems.back().multiply(temp);
        }
        else if (name == "SCALE")
        {
            Vec4 transformVec = op.vecs[0];
            if (op.knob.has_value())
            {
                transformVec = transformVec * Timeline::getKnob(op.knob.value()).getValue(Timeline::getFrame());
            }
            Mat4 const &temp = Mat4::scale(transformVec);
            coordSystems.back() = coordSystems.back().multiply(temp);
        }
        else if (name == "ROTATE")
        {
            double PI = std::atan(1) * 4;
            double angle = op.vals[0] * PI / 180;
            if (op.knob.has_value())
            {
                angle *= Timeline::getKnob(op.knob.value()).getValue(Timeline::getFrame());
            }
            std::string axis = op.data.value_or(" ");
            Mat4 temp(0);
            temp.identity();
            if (axis == "x" || axis == "X") {
                temp = Mat4::rotX(angle);
            } else if (axis == "y" || axis == "Y") {
                temp = Mat4::rotY(angle);
            } else if (axis == "z" || axis == "Z") {
                temp = Mat4::rotZ(angle);
            }
            coordSystems.back() = coordSystems.back().multiply(temp);
        }
        else if (name == "PUSH")
        {
            coordSystems.push_back(coordSystems.back());
        }
        else if (name == "POP")
        {
            coordSystems.pop_back();
        }
        else if (name == "DISPLAY")
        {
            screen.display();
        }
        else if (name == "SAVE")
        {
            std::string filename = op.data.value_or("filename missing?");
            screen.toFileExtension(filename);
        }
        else if (name == "DIRECTIONAL_LIGHT")
        {
            //std::cout << op.vecs[0] << op.vecs[1] << std::endl;
            WORLD_LIGHTS.push_back({LightType::Directional, {}, op.vecs[0], op.vecs[0], op.vecs[1]});
        }
        else if (name == "CONSTANTS")
        {
            std::cout << "constants should never be here" << std::endl;
        }
        else if (name == "SAVE_COORDS")
        {
            std::cout << "saving coords? " << op.data.has_value() << std::endl;
            if (op.data.has_value()) {
                std::string t = op.data.value();
                MDLDriver::coordTable.insert({t, coordSystems.back()});
            }
        }
        else if (name == "SET")
        {
            std::cout << name << ": how about no" << std::endl;
        }
        else if (name == "SAVE_KNOBS")
        {
            std::cout << name << ": how about no" << std::endl;
        }
        else if (name == "TWEEN")
        {
            std::cout << name << ": how about no" << std::endl;
        }
        else if (name == "SHADING")
        {
            std::cout << name << ": how about no" << std::endl;
        }
        else if (name == "SET_KNOBS")
        {
            std::cout << name << ": how about no" << std::endl;
        }
        else if (name == "FOCAL")
        {
            std::cout << name << ": how about no" << std::endl;
        }
        else if (name == "WEB")
        {
            std::cout << name << ": how about no" << std::endl;
        }
        else if (name == "AMBIENT_LIGHT")
        {
            WORLD_LIGHTS.push_back({LightType::Ambient, op.vecs[0]});
        }
        else if (name == "GENERATE_RAYFILES")
        {
            std::cout << name << ": how about no" << std::endl;
        }
    }
}

int main()
{
    Screen screen(500, 500);

    Mat4 edges(0);
    Mat4 triangles(0);
    std::vector<Mat4> coordSystems;
    coordSystems.push_back(Mat4::identity());

    MDLDriver drv;
    drv.parse("simple_anim.mdl");

    std::cout << "Materials: " << std::endl;
    for (auto mat : drv.matTable)
    {
        std::cout << mat.first << ": " << mat.second.ambient << mat.second.diffuse << mat.second.specular << mat.second.emissive << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Coordinate Systems: " << std::endl;
    for (auto mat : drv.coordTable)
    {
        std::cout << mat.first << ": " << std::endl;
        std::cout << mat.second.toString() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Timeline Frames: " << Timeline::getFrames() << std::endl;
    std::cout << "Timeline Basename: " << Timeline::getName() << std::endl;
    std::cout << "Knobs: " << std::endl;
    for (auto knob : Timeline::getKnobs())
    {
        std::cout << knob.first << ": " << knob.second << std::endl;
    }
    std::cout << std::endl;

    // std::cout << "Operations: " << std::endl;
    // for (auto op : drv.ops) {
    //     std::cout << op.op << " " << op.data.value_or("None") << std::endl;
    // }
    // WORLD_LIGHTS.push_back({LightType::Ambient, {.15, .15, .15}});
    // WORLD_LIGHTS.push_back({LightType::Directional, {}, {.6, .6, .6}, {.6, .6, .6}, {-1, -1, -1}});

    if (Timeline::getFrames() < 0)
    {
        parse(drv.ops, screen, edges, triangles, coordSystems);
    }
    else
    {
        system("mkdir -p ./animation/");
        system("rm ./animation/*");
        for (int i = 0; i < Timeline::getFrames(); i++)
        {
            Timeline::setFrame(i);
            parse(drv.ops, screen, edges, triangles, coordSystems);

            std::string s = std::to_string(i);
            s.insert(s.begin(), 5 - s.size(), '0');

            std::string savename = "./animation/" + Timeline::getName() + s + ".png";

            screen.toFileExtension(savename);
            std::cout << savename << std::endl;
            screen.clear({0, 0, 0, 255});
            screen.clearZbuf();

            WORLD_LIGHTS.clear();
            coordSystems.clear();
            coordSystems.push_back(Mat4::identity());
        }

        int delay = 4;
        std::string outputName = "animation.gif";

        system(("convert -delay " + std::to_string(delay) + " ./animation/* " + outputName).c_str());
        std::cout << "The animation was rendered into " << outputName << std::endl;
        system(("animate " + outputName).c_str());
    }

    return 0;
}
