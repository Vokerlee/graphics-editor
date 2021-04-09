#pragma once

#include "config.hpp"
#include "vidget.hpp"

class colour_button : public vidget
{
private:

    sf::RectangleShape rectangle_;
    sf::Color colour_;

public:
    
    colour_button() :
        vidget(),
        colour_(255, 255, 255),
        rectangle_(size_)
    {}

    colour_button(sf::Vector2<float>& point, sf::Vector2<float>& size, uint32_t& colour) :
        vidget(point, size),
        colour_(colour),
        rectangle_(size_)
    {
        rectangle_.move(point_);
        rectangle_.setOutlineThickness(2.f);
        rectangle_.setOutlineColor(sf::Color(0, 0, 0));
        rectangle_.setFillColor(colour_);
    }

    colour_button(sf::Vector2<float>& point, sf::Vector2<float>& size, uint8_t red, uint8_t green, uint8_t blue) :
        vidget(point, size),
        colour_(red, green, blue),
        rectangle_(size_)
    {
        rectangle_.move(point_);
        rectangle_.setOutlineThickness(2.f);
        rectangle_.setOutlineColor(sf::Color(0, 0, 0));
        rectangle_.setFillColor(colour_);
    }

    colour_button(float x, float y, float x_size, float y_size, uint32_t& colour) :
        vidget(x, y, x_size, y_size),
        colour_(colour),
        rectangle_(size_)
    {
        rectangle_.move(point_);
        rectangle_.setOutlineThickness(2.f);
        rectangle_.setOutlineColor(sf::Color(0, 0, 0));
        rectangle_.setFillColor(colour_);
    }

    colour_button(float x, float y, float x_size, float y_size, uint8_t red, uint8_t green, uint8_t blue) :
        vidget(x, y, x_size, y_size),
        colour_(red, green, blue),
        rectangle_(size_)
    {
        rectangle_.move(point_);
        rectangle_.setOutlineThickness(2.f);
        rectangle_.setOutlineColor(sf::Color(0, 0, 0));
        rectangle_.setFillColor(colour_);
    }

    ~colour_button() = default;

    colour_button(const colour_button& source)
    {
        point_     = source.point_;
        size_      = source.size_;
        colour_    = source.colour_;
        rectangle_ = source.rectangle_;
    }

    virtual void operator=(const colour_button& source)
    {
        point_     = source.point_;
        size_      = source.size_;
        colour_    = source.colour_;
        rectangle_ = source.rectangle_;
    }

    void set_colour(uint8_t red, uint8_t green, uint8_t blue)
    {
        colour_.r = red;
        colour_.g = green;
        colour_.b = blue;
    }

    virtual void draw(sf::RenderWindow& shell_) const
    {
        shell_.draw(rectangle_);
    }

    virtual void action(draw_state& state) const
    {
        state.current_colour = colour_;
    }

};