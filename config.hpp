#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include <iostream>
#include <cstdio>
#include <cstdlib>

const int MAX_TOOLS_AMOUNT   = 1000;
const int MAX_OBJECTS_AMOUNT = 50000;
const int MAX_SECTION_LENGTH = 100;

const int CHARACTER_SIZE = 20;

class noncopyable
{
protected:
    noncopyable() {}
    ~noncopyable() {}
private:
    noncopyable(const noncopyable&);
    const noncopyable& operator=(const noncopyable&);
};

enum TOOL
{
    NOTHING,
    ELLIPSE,
    RECTANGLE,
    TRIANGLE
};

class draw_state
{
public:
    sf::Color current_colour;
    uint32_t current_tool;

    uint16_t current_angle;

    sf::Vector2<float> current_size;
    sf::Vector2f click_pos;

    float current_thikness;


    draw_state() :
        current_colour(),
        current_tool(NOTHING),
        current_size(10, 10),
        click_pos(10, 10),
        current_thikness(2.f),
        current_angle(0)
    {}

    draw_state(sf::Color colour, uint32_t tool, sf::Vector2<float> size) :
        current_colour(colour),
        current_tool(tool),
        current_size(size),
        click_pos(0, 0),
        current_thikness(2.f),
        current_angle(0)
    {}

    void set_size(sf::Vector2<float> size)
    {
        current_size = size;
    }

    void set_size(float x, float y)
    {
        current_size.x = x;
        current_size.y = y;
    }

    void set_tool(uint32_t tool)
    {
        current_tool = tool;
    }

    void set_colour(sf::Color colour)
    {
        current_colour = colour;
    }

    void set_thick(float thikness)
    {
        current_thikness = thikness;
    }

    void set_angle(float angle)
    {
        current_angle = angle;
    }

    void set_colour(uint8_t red, uint8_t green, uint8_t blue)
    {
        current_colour.r = red;
        current_colour.g = green;
        current_colour.b = blue;
    }

    ~draw_state() = default;
};