#include "Timeline.hpp"
#include <iostream>
#include <cassert>
#include <algorithm>

int Timeline::frames = -1;
int Timeline::currentFrame = 0;
std::string Timeline::baseName = "default_";
std::map<std::string, Knob> Timeline::knobs;

Knob::Knob()
{
    assert(Timeline::getFrames() >= 0);
    // if (Timeline::getFrames() < 0) {
    //     std::cout << "Please set number of frames before declaring knobs!" << std::endl;
    //     exit(1);
    // }
    // if (endFrame_ < startFrame_) {
    //     std::cout << "End frame is before start frame!" << std::endl;
    //     exit(1);
    // }
    // if (endFrame_ >= Timeline::getFrames()) {
    //     std::cout << "End frame goes past num of frames!" << std::endl;
    //     exit(1);
    // }
}

void Knob::addRange(int startFrame_, int endFrame_, double startVal_, double endVal_)
{
    assert(endFrame_ >= startFrame_);
    for (auto keyframe : keyframes)
    {
        int f = keyframe.first;
        if (startFrame_ <= f && endFrame_ >= f)
        {
            std::cout << "Didn't add knob because an overlapping range was found!";
            return;
        }
    }
    keyframes.push_back({startFrame_, startVal_});
    keyframes.push_back({endFrame_, endVal_});
    std::sort(keyframes.begin(), keyframes.end());
}

double Knob::getValue(int frame) const
{
    assert(keyframes.size() != 0);
    for (unsigned int i = 0; i < keyframes.size() - 1; i++)
    {
        auto key1 = keyframes[i];
        auto key2 = keyframes[i + 1];
        if (key1.first <= frame && frame <= key2.first)
        {
            int totalFrames = key2.first - key1.first;
            int framesIn = frame - key1.first;
            double percent = framesIn / static_cast<double>(totalFrames);
            double diff = key2.second - key1.second;
            return diff * percent + key1.second;
            break;
        }
    }
    if (keyframes.size() > 0) {
        if (frame < keyframes.front().first) {
            return keyframes.front().second;
        } else if (frame > keyframes.back().first) {
            return keyframes.back().second;
        }
    }
    std::cout << "Knob had no keyframes?" << std::endl;
    exit(1);
    return 0;
}

std::ostream &operator<<(std::ostream &os, const Knob knob)
{
    for (auto range : knob.keyframes)
    {
        os << "{" << range.first << ", " << range.second << "}, ";
    }
    return os;
}

void Timeline::setFrames(int frames_)
{
    assert(frames_ >= 0);
    frames = frames_;
}

int Timeline::getFrames()
{
    return frames;
}

void Timeline::setFrame(int frame_)
{
    assert(frame_ >= 0 && frame_ < frames);
    currentFrame = frame_;
}

int Timeline::getFrame()
{
    return currentFrame;
}
void Timeline::setName(std::string name_)
{
    baseName = name_;
}
std::string Timeline::getName()
{
    return baseName;
}
void Timeline::addKnob(std::string name, int startFrame, int endFrame, double startVal, double endVal)
{
    if (knobs.count(name) == 0) {
        knobs.insert({name, {}});
    }
    
    knobs[name].addRange(startFrame, endFrame, startVal, endVal);
}

Knob const &Timeline::getKnob(std::string name)
{
    return knobs.at(name);
}

std::vector<std::pair<std::string, Knob>> Timeline::getKnobs()
{
    std::vector<std::pair<std::string, Knob>> temp;
    for (auto knob : knobs)
    {
        temp.push_back(knob);
    }
    return temp;
}