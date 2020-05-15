# pragma once
# include <string>
# include <map>
# include <vector>

class Knob
{
private:
    std::vector<std::pair<int, double>> keyframes;
    // int startFrame, endFrame;
    // double startVal, endVal;
public:
    Knob();
    void addRange(int startFrame_, int endFrame_, double startVal_ = 0, double endVal_ = 1);
    double getValue(int frame) const;
    friend std::ostream &operator<<(std::ostream &os, const Knob knob);
};

class Timeline
{
private:
    static int frames;
    static int currentFrame;
    static std::string baseName;
    static std::map<std::string, Knob> knobs;
public:

    static void setFrames(int frames_);
    static int getFrames();
    static void setFrame(int frame_);
    static int getFrame();
    static void setName(std::string name_);
    static std::string getName();
    static void addKnob(std::string name, int startFrame, int endFrame, double startVal = 0, double endVal = 1);    
    static Knob const & getKnob(std::string name);
    static std::vector<std::pair<std::string, Knob>> getKnobs();
};