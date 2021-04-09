#pragma once

#include "config.hpp"

class vidget
{
public:

    sf::Vector2<float> point_;
    sf::Vector2<float> size_;

public:

    vidget() :
        point_(0, 0),
        size_(10, 10)
    {}

    vidget(sf::Vector2<float>& point, sf::Vector2<float>& size) :
        point_(point),
        size_(size)
    {}

    vidget(float x, float y, float x_size, float y_size) :
        point_(x, y),
        size_(x_size, y_size)
    {}

    ~vidget() = default;

    vidget(const vidget& source)
    {
        point_ = source.point_;
        size_  = source.size_;
    }

    virtual void operator=(const vidget& source)
    {
        point_ = source.point_;
        size_  = source.size_;
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

    virtual bool is_pressed(sf::Vector2<int> mouse_pos)
    {
        if (mouse_pos.x > point_.x && mouse_pos.x < point_.x + size_.x &&
            mouse_pos.y > point_.y && mouse_pos.y < point_.y + size_.y)
            return true;

        return false;
    }

    virtual void draw(sf::RenderWindow& shell_) const
    {
        printf("I can't be drawn!\n");
    }

    virtual void action(draw_state& state) const
    {
        printf("Wow, I don't know what to do!\n");
    }

};