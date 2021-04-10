#pragma once

#include "config.hpp"
#include "vidget.hpp"

namespace sf
{
    class TriangleShape : public sf::Shape
    {
    private:

        sf::Vector2f radius_;

    public:

        explicit TriangleShape(const sf::Vector2f& size = sf::Vector2f(0, 0)) :
            radius_(size.x * 1.2, size.y * 1.36)
        {
            update();
        }

        void setRadius(const sf::Vector2f& radius)
        {
            radius_ = radius;
            update();
        }

        const sf::Vector2f& getRadius() const
        {
            return radius_;
        }

        virtual unsigned int getPointCount() const
        {
            return 3;
        }

        virtual sf::Vector2f getPoint(unsigned int index) const
        {
            static const float pi = 3.141592654f;

            float angle = index * 2 * pi / getPointCount() - pi / 2;
            float x = std::cos(angle) * radius_.x;
            float y = std::sin(angle) * radius_.y;

            return sf::Vector2f(radius_.x + x, radius_.y + y);
        }

    };
}

class triangle : public vidget
{
private:

    sf::TriangleShape triangle_;
    sf::Color colour_;

public:

    triangle() :
        vidget(),
        colour_(255, 255, 255),
        triangle_(sf::Vector2<float>(size_.x / 2, size_.y / 2))
    {}

    triangle(sf::Vector2<float>& point, sf::Vector2<float>& size, uint32_t& colour) :
        vidget(point, size),
        colour_(colour),
        triangle_(sf::Vector2<float>(size_.x / 2, size_.y / 2))
    {
        triangle_.move(point_);
        triangle_.setOutlineThickness(2.f);
        triangle_.setOutlineColor(sf::Color(0, 0, 0));
        triangle_.setFillColor(colour_);
    }

    triangle(sf::Vector2<float>& point, sf::Vector2<float>& size, uint8_t red, uint8_t green, uint8_t blue) :
        vidget(point, size),
        colour_(red, green, blue),
        triangle_(sf::Vector2<float>(size_.x / 2, size_.y / 2))
    {
        triangle_.move(point_);
        triangle_.setOutlineThickness(2.f);
        triangle_.setOutlineColor(sf::Color(0, 0, 0));
        triangle_.setFillColor(colour_);
    }

    triangle(float x, float y, float x_size, float y_size, uint32_t& colour) :
        vidget(x, y, x_size, y_size),
        colour_(colour),
        triangle_(sf::Vector2<float>(size_.x / 2, size_.y / 2))
    {
        triangle_.move(point_);
        triangle_.setOutlineThickness(2.f);
        triangle_.setOutlineColor(sf::Color(0, 0, 0));
        triangle_.setFillColor(colour_);
    }

    triangle(float x, float y, float x_size, float y_size, uint8_t red, uint8_t green, uint8_t blue) :
        vidget(x, y, x_size, y_size),
        colour_(red, green, blue),
        triangle_(sf::Vector2<float>(size_.x / 2, size_.y / 2))
    {
        triangle_.move(point_);
        triangle_.setOutlineThickness(2.f);
        triangle_.setOutlineColor(sf::Color(0, 0, 0));
        triangle_.setFillColor(colour_);
    }

    ~triangle() = default;

    triangle(const triangle& source)
    {
        point_    = source.point_;
        size_     = source.size_;
        colour_   = source.colour_;
        triangle_ = source.triangle_;
    }

    virtual void operator=(const triangle& source)
    {
        point_    = source.point_;
        size_     = source.size_;
        colour_   = source.colour_;
        triangle_ = source.triangle_;
    }

    void set_colour(uint8_t red, uint8_t green, uint8_t blue)
    {
        colour_.r = red;
        colour_.g = green;
        colour_.b = blue;
    }

    virtual bool is_pressed(sf::Vector2<int> mouse_pos)
    {
        if ((mouse_pos.x > point_.x) && (mouse_pos.x < point_.x + 2 * size_.x) &&
            (mouse_pos.y > point_.y) && (mouse_pos.y < point_.y + 2 * size_.y))
            return true;

        return false;
    }

    virtual void draw(sf::RenderWindow& shell_) const
    {
        shell_.draw(triangle_);
    }

    virtual void action(draw_state& state)
    {
        state.current_tool = TRIANGLE;
    }
};