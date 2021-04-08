#pragma once
#include "vector2.hpp"

union colour
{
    int value;
    char parts[4];
};

class button 
{
public:
    vector2_t point_;
    vector2_t size_;
    colour colour_;

    button() :
        colour_{ 0 }
    {}

    button(const vector2_t& point, const vector2_t& size, const int& colour) :
        point_(point),
        size_(size),
        colour_({ colour })
    {}

    button(const vector2_t& point, const vector2_t& size, const char& red, const char& green, const char& blue) :
        point_(point),
        size_(size)
    {
        colour_.parts[0] = red;
        colour_.parts[1] = green;
        colour_.parts[2] = blue;
    }

    ~button() = default;

    button(const button& source)
    {
        point_ = source.point_;
        size_ = source.size_;
        colour_ = source.colour_;
    }

    void set_position(int x, int y)
    {
        point_.x_ = x;
        point_.y_ = y;
    }

    void set_size(int x, int y)
    {
        size_.x_ = x;
        size_.y_ = y;
    }

    void set_colour(int rgba_value)
    {
        colour_.value = rgba_value;
    }

    void set_colour(char red, char green, char blue)
    {
        colour_.parts[0] = red;
        colour_.parts[1] = green;
        colour_.parts[2] = blue;
    }

    void draw() const
    {
        ///
    }

    bool is_pressed() const
    {
        ///
    }

    void action() const
    {
        printf("I am working now!!\n");
    }


};