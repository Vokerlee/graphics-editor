#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include <iostream>
#include <cstdio>
#include <cstdlib>

const int MAX_TOOLS_AMOUNT = 20;

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
};

class draw_state
{
public:
    sf::Color current_colour;
    uint32_t current_tool;

    draw_state() :
        current_colour(),
        current_tool(NOTHING)
    {}

    draw_state(sf::Color colour, uint32_t tool) :
        current_colour(colour),
        current_tool(tool)
    {}

    ~draw_state() = default;
};