#pragma once

#include "button.hpp"
#include "config.hpp"

class window : noncopyable
{
private:

    sf::Vector2<int> size_;
    const char* name_;

    button** buttons_;
    int n_button_;

    sf::RenderWindow shell_;

public:

    window(int x, int y, const char* name) :
        n_button_(0),
        name_(name)
    {
        size_.x = x;
        size_.y = y;

        shell_.create(sf::VideoMode(x, y), name);
        shell_.clear(sf::Color(208, 242, 247, 255));

        buttons_ = new button* [MAX_BUTTONS_AMOUNT];
    }

    ~window()
    {
        size_.x = 0;
        size_.y = 0;
        name_ = nullptr;

        for (int i = 0; i < n_button_; ++i)
            delete buttons_[i];

        n_button_ = 0;
        delete[] buttons_;
    }

    void set_colour(sf::Color& colour)
    {
        shell_.clear(colour);
    }

    void set_colour(uint8_t red, uint8_t green, uint8_t blue)
    {
        shell_.clear(sf::Color(red, green, blue, 255));
    }

    void add_button(button* button)
    {
        buttons_[n_button_++] = button;
    }

    void draw()
    {
        for (int i = 0; i < n_button_; ++i)
        {
            (*(buttons_[i])).draw(shell_);
        }
    }

    int get_buttons()
    {
        return n_button_;
    }

    void run()
    {
        while (shell_.isOpen())
        {
            sf::Event event;

            while (shell_.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    shell_.close();
            }

            shell_.clear(sf::Color(208, 242, 247, 255));
            draw();
            shell_.display();
        }
    }
};