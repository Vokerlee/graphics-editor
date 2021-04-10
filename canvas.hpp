#pragma once

#include "config.hpp"
#include "vidget.hpp"

class canvas : public vidget
{
private:

    sf::RectangleShape rectangle_;
    sf::Color colour_;

    uint32_t n_object_;
    sf::Drawable** objects_;

public:

    canvas() :
        vidget(),
        colour_(255, 255, 255),
        rectangle_(size_),
        n_object_(0)
    {
        objects_ = new sf::Drawable* [MAX_OBJECTS_AMOUNT];
    }

    canvas(sf::Vector2<float>& point, sf::Vector2<float>& size, uint32_t& colour) :
        vidget(point, size),
        colour_(colour),
        rectangle_(size_),
        n_object_(0)
    {
        rectangle_.move(point_);
        rectangle_.setOutlineThickness(2.f);
        rectangle_.setOutlineColor(sf::Color(0, 0, 0));
        rectangle_.setFillColor(colour_);

        objects_ = new sf::Drawable* [MAX_OBJECTS_AMOUNT];
    }

    canvas(sf::Vector2<float>& point, sf::Vector2<float>& size, uint8_t red, uint8_t green, uint8_t blue) :
        vidget(point, size),
        colour_(red, green, blue),
        rectangle_(size_),
        n_object_(0)
    {
        rectangle_.move(point_);
        rectangle_.setOutlineThickness(2.f);
        rectangle_.setOutlineColor(sf::Color(0, 0, 0));
        rectangle_.setFillColor(colour_);

        objects_ = new sf::Drawable * [MAX_OBJECTS_AMOUNT];
    }

    canvas(float x, float y, float x_size, float y_size, uint32_t& colour) :
        vidget(x, y, x_size, y_size),
        colour_(colour),
        rectangle_(size_),
        n_object_(0)
    {
        rectangle_.move(point_);
        rectangle_.setOutlineThickness(2.f);
        rectangle_.setOutlineColor(sf::Color(0, 0, 0));
        rectangle_.setFillColor(colour_);

        objects_ = new sf::Drawable * [MAX_OBJECTS_AMOUNT];
    }

    canvas(float x, float y, float x_size, float y_size, uint8_t red, uint8_t green, uint8_t blue) :
        vidget(x, y, x_size, y_size),
        colour_(red, green, blue),
        rectangle_(size_),
        n_object_(0)
    {
        rectangle_.move(point_);
        rectangle_.setOutlineThickness(2.f);
        rectangle_.setOutlineColor(sf::Color(0, 0, 0));
        rectangle_.setFillColor(colour_);

        objects_ = new sf::Drawable * [MAX_OBJECTS_AMOUNT];
    }

    ~canvas()
    {
        for (int i = 0; i < n_object_; ++i)
        {
            delete objects_[i];
        }

        delete objects_;
    }

    canvas(const canvas& source)
    {
        point_     = source.point_;
        size_      = source.size_;
        colour_    = source.colour_;
        rectangle_ = source.rectangle_;
    }

    virtual void operator=(const canvas& source)
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

        for (int i = 0; i < n_object_; ++i)
        {
            shell_.draw((*objects_[i]));
        }
    }

    virtual void action(draw_state& state)
    {
        switch (state.current_tool)
        {
            case ELLIPSE:
            {
                sf::EllipseShape* ellipse = new sf::EllipseShape(state.current_size / 2.f);
                ellipse->setOutlineThickness(state.current_thikness);
                ellipse->setOutlineColor(sf::Color(0, 0, 0));
                ellipse->setFillColor(state.current_colour);
                ellipse->setOrigin(state.current_size.x / 2, state.current_size.y / 2);
                ellipse->rotate(state.current_angle);

                ellipse->move(state.click_pos);

                objects_[n_object_++] = ellipse;

                break;
            }

            case RECTANGLE:
            {
                sf::RectangleShape* rectangle = new sf::RectangleShape(state.current_size);
                rectangle->setOutlineThickness(state.current_thikness);
                rectangle->setOutlineColor(sf::Color(0, 0, 0));
                rectangle->setFillColor(state.current_colour);
                rectangle->setOrigin(state.current_size.x / 2, state.current_size.y / 2);
                rectangle->rotate(state.current_angle);

                rectangle->move(state.click_pos);

                objects_[n_object_++] = rectangle;

                break;
            }

            case TRIANGLE:
            {
                sf::TriangleShape* triangle = new sf::TriangleShape(state.current_size);
                triangle->setOutlineThickness(state.current_thikness);
                triangle->setOutlineColor(sf::Color(0, 0, 0));
                triangle->setFillColor(state.current_colour);
                triangle->setOrigin(state.current_size.x * 1.22, state.current_size.y * 1.1);
                triangle->rotate(state.current_angle);

                triangle->move(state.click_pos);

                objects_[n_object_++] = triangle;

                break;
            }
        }
    }

};