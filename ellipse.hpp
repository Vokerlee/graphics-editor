#pragma once

#include "config.hpp"
#include "vidget.hpp"

namespace sf
{
    class EllipseShape : public sf::Shape
    {
    private:

        sf::Vector2f radius_;

    public:

        explicit EllipseShape(const sf::Vector2f& radius = sf::Vector2f(0, 0)) :
            radius_(radius)
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
            return 30;
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

class ellipse : public vidget
{
private:

    sf::EllipseShape ellipse_;
    sf::Color colour_;

public:

    ellipse() :
        vidget(),
        colour_(255, 255, 255),
        ellipse_(sf::Vector2<float>(size_.x / 2, size_.y / 2))
    {}

    ellipse(sf::Vector2<float>& point, sf::Vector2<float>& size, uint32_t& colour) :
        vidget(point, size),
        colour_(colour),
        ellipse_(sf::Vector2<float>(size_.x / 2, size_.y / 2))
    {
        ellipse_.move(point_);
        ellipse_.setOutlineThickness(2.f);
        ellipse_.setOutlineColor(sf::Color(0, 0, 0));
        ellipse_.setFillColor(colour_);
    }

    ellipse(sf::Vector2<float>& point, sf::Vector2<float>& size, uint8_t red, uint8_t green, uint8_t blue) :
        vidget(point, size),
        colour_(red, green, blue),
        ellipse_(sf::Vector2<float>(size_.x / 2, size_.y / 2))
    {
        ellipse_.move(point_);
        ellipse_.setOutlineThickness(2.f);
        ellipse_.setOutlineColor(sf::Color(0, 0, 0));
        ellipse_.setFillColor(colour_);
    }

    ellipse(float x, float y, float x_size, float y_size, uint32_t& colour) :
        vidget(x, y, x_size, y_size),
        colour_(colour),
        ellipse_(sf::Vector2<float>(size_.x / 2, size_.y / 2))
    {
        ellipse_.move(point_);
        ellipse_.setOutlineThickness(2.f);
        ellipse_.setOutlineColor(sf::Color(0, 0, 0));
        ellipse_.setFillColor(colour_);
    }

    ellipse(float x, float y, float x_size, float y_size, uint8_t red, uint8_t green, uint8_t blue) :
        vidget(x, y, x_size, y_size),
        colour_(red, green, blue),
        ellipse_(sf::Vector2<float>(size_.x / 2, size_.y / 2))
    {
        ellipse_.move(point_);
        ellipse_.setOutlineThickness(2.f);
        ellipse_.setOutlineColor(sf::Color(0, 0, 0));
        ellipse_.setFillColor(colour_);
    }

    ~ellipse() = default;

    ellipse(const ellipse& source)
    {
        point_   = source.point_;
        size_    = source.size_;
        colour_  = source.colour_;
        ellipse_ = source.ellipse_;
    }

    virtual void operator=(const ellipse& source)
    {
        point_   = source.point_;
        size_    = source.size_;
        colour_  = source.colour_;
        ellipse_ = source.ellipse_;
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
        shell_.draw(ellipse_);
    }

    virtual void action(draw_state& state)
    {
        state.current_tool = ELLIPSE;
    }
};