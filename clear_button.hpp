#pragma once

#include "config.hpp"
#include "vidget.hpp"

class clear_button : public vidget, public noncopyable
{
private:

    sf::RectangleShape rectangle_;
    sf::Color colour_;

    char* section_name_;
    sf::Font font_;
    sf::Text text_;

public:

    clear_button() :
        vidget(),
        colour_(255, 255, 255),
        rectangle_(size_)
    {
        section_name_ = new char[MAX_SECTION_LENGTH];
        strcpy(section_name_, "Clear");

        font_.loadFromFile("Fonts/Samson.ttf");
        text_.setFont(font_);
        text_.setString(section_name_);
        text_.setCharacterSize(CHARACTER_SIZE);
        text_.setColor(sf::Color::Black);
        text_.setStyle(sf::Text::Regular);
        text_.move(sf::Vector2<float>(point_.x + (size_.x - strlen(section_name_) * (CHARACTER_SIZE + 1) / 2) / 2, point_.y));

        rectangle_.setOutlineThickness(2.f);
        rectangle_.setOutlineColor(sf::Color(0, 0, 0));
    }

    clear_button(sf::Vector2<float>& point, sf::Vector2<float>& size, uint8_t red = 255, uint8_t green = 255, uint8_t blue = 255) :
        vidget(point, size),
        colour_(red, green, blue),
        rectangle_(size_)
    {
        section_name_ = new char[MAX_SECTION_LENGTH];
        strcpy(section_name_, "Clear");

        font_.loadFromFile("Fonts/Samson.ttf");
        text_.setFont(font_);
        text_.setString(section_name_);
        text_.setCharacterSize(CHARACTER_SIZE);
        text_.setColor(sf::Color::Black);
        text_.setStyle(sf::Text::Regular);
        text_.move(sf::Vector2<float>(point_.x + (size_.x - strlen(section_name_) * (CHARACTER_SIZE + 1) / 2) / 2, point_.y));

        rectangle_.move(point_);
        rectangle_.setOutlineThickness(2.f);
        rectangle_.setOutlineColor(sf::Color(0, 0, 0));
        rectangle_.setFillColor(colour_);
    }

    clear_button(float x, float y, float x_size, float y_size, uint8_t red = 255, uint8_t green = 255, uint8_t blue = 255) :
        vidget(x, y, x_size, y_size),
        colour_(red, green, blue),
        rectangle_(size_)
    {
        section_name_ = new char[MAX_SECTION_LENGTH];
        strcpy(section_name_, "Clear");

        font_.loadFromFile("Fonts/Samson.ttf");
        text_.setFont(font_);
        text_.setString(section_name_);
        text_.setCharacterSize(CHARACTER_SIZE);
        text_.setColor(sf::Color::Black);
        text_.setStyle(sf::Text::Regular);
        text_.move(sf::Vector2<float>(point_.x + (size_.x - strlen(section_name_) * (CHARACTER_SIZE + 1) / 2) / 2, point_.y));

        rectangle_.move(point_);
        rectangle_.setOutlineThickness(2.f);
        rectangle_.setOutlineColor(sf::Color(0, 0, 0));
        rectangle_.setFillColor(colour_);
    }

    ~clear_button()
    {
        delete section_name_;
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
        shell_.draw(text_);
    }

    virtual void action(canvas& canvas)
    {

    }
};