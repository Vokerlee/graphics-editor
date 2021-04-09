#pragma once

#include "config.hpp"

class base_button
{
public:

    sf::Vector2<float> point_;
    sf::Vector2<float> size_;
    sf::RectangleShape rectangle_;

public:

    base_button() :
        point_(0, 0),
        size_(10, 10),
        rectangle_(size_)
    {}

    base_button(sf::Vector2<float>& point, sf::Vector2<float>& size) :
        point_(point),
        size_(size),
        rectangle_(size_)
    {
        rectangle_.move(point_);
        rectangle_.setOutlineThickness(2.f);
        rectangle_.setOutlineColor(sf::Color(0, 0, 0));
    }

    base_button(float x, float y, float x_size, float y_size) :
        point_(x, y),
        size_(x_size, y_size),
        rectangle_(size_)
    {
        rectangle_.move(point_);
        rectangle_.setOutlineThickness(2.f);
        rectangle_.setOutlineColor(sf::Color(0, 0, 0));
    }

    ~base_button() = default;

    base_button(const base_button& source)
    {
        point_     = source.point_;
        size_      = source.size_;
        rectangle_ = source.rectangle_;
    }

    virtual void operator=(const base_button& source)
    {
        point_     = source.point_;
        size_      = source.size_;
        rectangle_ = source.rectangle_;
    }

    void set_position(float x, float y)
    {
        point_.x = x;
        point_.y = y;
    }

    void set_size(float x, float y)
    {
        size_.x = x;
        size_.y = y;
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