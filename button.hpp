#pragma once

#include "config.hpp"
#include "base_button.hpp"

class button : public base_button
{
private:

    sf::Color colour_;

public:
    
    button() :
        base_button(),
        colour_(255, 255, 255)
    {}

    button(sf::Vector2<float>& point, sf::Vector2<float>& size, uint32_t& colour) :
        base_button(point, size),
        colour_(colour)
    {
        rectangle_.setFillColor(colour_);
    }

    button(sf::Vector2<float>& point, sf::Vector2<float>& size, uint8_t red, uint8_t green, uint8_t blue) :
        base_button(point, size),
        colour_(red, green, blue)
    {
        rectangle_.setFillColor(colour_);
    }

    button(float x, float y, float x_size, float y_size, uint32_t& colour) :
        base_button(x, y, x_size, y_size),
        colour_(colour)
    {
        rectangle_.setFillColor(colour_);
    }

    button(float x, float y, float x_size, float y_size, uint8_t red, uint8_t green, uint8_t blue) :
        base_button(x, y, x_size, y_size),
        colour_(red, green, blue)
    {
        rectangle_.setFillColor(colour_);
    }

    ~button() = default;

    button(const button& source)
    {
        point_     = source.point_;
        size_      = source.size_;
        colour_    = source.colour_;
        rectangle_ = source.rectangle_;
    }

    virtual void operator=(const button& source)
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

    virtual void action() const
    {
        printf("I am working now!!\n");
    }


};