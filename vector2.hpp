#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>

class vector2_t
{
public:

    int x_;
    int y_;

    vector2_t() :
        x_(0),
        y_(0)
    {}

    vector2_t(int x, int y) :
        x_(x),
        y_(y)
    {}
    
    ~vector2_t() = default;

    vector2_t(const vector2_t& copy_vector2_t)
    {
        x_ = copy_vector2_t.x_;
        y_ = copy_vector2_t.y_;
    }

    void operator=(const vector2_t& copy_vector2_t)
    {
        x_ = copy_vector2_t.x_;
        y_ = copy_vector2_t.y_;
    }

    vector2_t operator+(const vector2_t& copy_vector2_t)
    {
        vector2_t result = { x_ + copy_vector2_t.x_, y_ + copy_vector2_t.y_ };

        return result;
    }

    vector2_t operator-(const vector2_t& copy_vector2_t)
    {
        vector2_t result = { x_ - copy_vector2_t.x_, y_ - copy_vector2_t.y_ };

        return result;
    }

    vector2_t operator*(const vector2_t& copy_vector2_t)
    {
        vector2_t result = { x_ * copy_vector2_t.x_, y_ * copy_vector2_t.y_ };

        return result;
    }

    vector2_t operator/(const vector2_t& copy_vector2_t)
    {
        vector2_t result = { x_ / copy_vector2_t.x_, y_ / copy_vector2_t.y_ };

        return result;
    }

    void print()
    {
        printf("x = %d, y = %d\n", x_, y_);
    }

    int get_x(const vector2_t& vector)
    {
        return vector.x_;
    }

    int get_y(const vector2_t& vector)
    {
        return vector.y_;
    }

};
