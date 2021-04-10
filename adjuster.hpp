#pragma once

#include "config.hpp"
#include "vidget.hpp"

class adjuster : public vidget
{
public:

    sf::Image image_;
    sf::Texture texture_;
    sf::Sprite sprite_;

    adjuster() :
        vidget()
    {
        image_.loadFromFile("Textures/adjuster.png");
        texture_.loadFromImage(image_);

        sf::Vector2u image_size = image_.getSize();
        size_.x = image_size.x;
        size_.y = image_size.y;

        sprite_.setTexture(texture_);
        sprite_.setPosition(sf::Vector2<float>(size_.x, size_.y));
    }

    adjuster(sf::Vector2<float>& point) :
        vidget(point, sf::Vector2<float>(0, 0))
    {
        image_.loadFromFile("Textures/adjuster.png");
        texture_.loadFromImage(image_);

        sf::Vector2u image_size = image_.getSize();
        size_.x = image_size.x;
        size_.y = image_size.y;

        sprite_.setTexture(texture_);
        sprite_.setPosition(point);
    }

    adjuster(float x, float y) :
        vidget(sf::Vector2<float>(x, y), sf::Vector2<float>(0, 0))
    {
        image_.loadFromFile("Textures/adjuster.png");
        texture_.loadFromImage(image_);

        sf::Vector2u image_size = image_.getSize();
        size_.x = image_size.x;
        size_.y = image_size.y;

        sprite_.setTexture(texture_);
        sprite_.setPosition(sf::Vector2<float>(x, y));
    }

    ~adjuster() = default;

    adjuster(const adjuster& source)
    {
        point_   = source.point_;
        size_    = source.size_;
        image_   = source.image_;
        texture_ = source.texture_;
    }

    virtual void operator=(const adjuster& source)
    {
        point_   = source.point_;
        size_    = source.size_;
        image_   = source.image_;
        texture_ = source.texture_;
    }

    virtual void draw(sf::RenderWindow& shell_) const
    {
        shell_.draw(sprite_);
    }

    virtual void action(draw_state& state)
    {
        printf("I am adjuster and I still can't do anything...\n");
    }

};


class thikness_adjuster : public adjuster
{
public:

    thikness_adjuster() :
        adjuster()
    {}

    thikness_adjuster(sf::Vector2<float>& point) :
        adjuster(point)
    {}

    thikness_adjuster(float x, float y) :
        adjuster(x, y)
    {}

    ~thikness_adjuster() = default;

    thikness_adjuster(const thikness_adjuster& source)
    {
        point_   = source.point_;
        size_    = source.size_;
        image_   = source.image_;
        texture_ = source.texture_;
    }

    virtual void action(draw_state& state)
    {
        if ((state.click_pos.x > point_.x) && (state.click_pos.x < point_.x + size_.x / 2))
        {
            printf("--\n");

            if (state.current_thikness > 0)
                state.current_thikness--;
        }
        else
        {
            printf("++\n");
            state.current_thikness++;
        }
    }
};

class xsize_adjuster : public adjuster
{
public:

    xsize_adjuster() :
        adjuster()
    {}

    xsize_adjuster(sf::Vector2<float>& point) :
        adjuster(point)
    {}

    xsize_adjuster(float x, float y) :
        adjuster(x, y)
    {}

    ~xsize_adjuster() = default;

    xsize_adjuster(const xsize_adjuster& source)
    {
        point_   = source.point_;
        size_    = source.size_;
        image_   = source.image_;
        texture_ = source.texture_;
    }

    virtual void action(draw_state& state)
    {
        if ((state.click_pos.x > point_.x) && (state.click_pos.x < point_.x + size_.x / 2))
        {
            printf("x--\n");

            if (state.current_size.x > 0)
                state.current_size.x--;
        }
        else
        {
            printf("x++\n");
            state.current_size.x++;
        }
    }
};

class ysize_adjuster : public adjuster
{
public:

    ysize_adjuster() :
        adjuster()
    {}

    ysize_adjuster(sf::Vector2<float>& point) :
        adjuster(point)
    {}

    ysize_adjuster(float x, float y) :
        adjuster(x, y)
    {}

    ~ysize_adjuster() = default;

    ysize_adjuster(const ysize_adjuster& source)
    {
        point_ = source.point_;
        size_ = source.size_;
        image_ = source.image_;
        texture_ = source.texture_;
    }

    virtual void action(draw_state& state)
    {
        if ((state.click_pos.x > point_.x) && (state.click_pos.x < point_.x + size_.x / 2))
        {
            printf("y--\n");

            if (state.current_size.y > 0)
                state.current_size.y--;
        }
        else
        {
            printf("y++\n");
            state.current_size.y++;
        }
    }
};

class scale_size_adjuster : public adjuster
{
public:

    scale_size_adjuster() :
        adjuster()
    {}

    scale_size_adjuster(sf::Vector2<float>& point) :
        adjuster(point)
    {}

    scale_size_adjuster(float x, float y) :
        adjuster(x, y)
    {}

    ~scale_size_adjuster() = default;

    scale_size_adjuster(const scale_size_adjuster& source)
    {
        point_   = source.point_;
        size_    = source.size_;
        image_   = source.image_;
        texture_ = source.texture_;
    }

    virtual void action(draw_state& state)
    {
        if ((state.click_pos.x > point_.x) && (state.click_pos.x < point_.x + size_.x / 2))
        {
            printf("all--\n");

            if (state.current_size.x > 0)
            {
                state.current_size.y -= state.current_size.y / (state.current_size.x--);
            }
        }
        else
        {
            printf("all++\n");
            state.current_size.y += state.current_size.y / (state.current_size.x++);
        }
    }
};

class angle_adjuster : public adjuster
{
public:

    angle_adjuster() :
        adjuster()
    {}

    angle_adjuster(sf::Vector2<float>& point) :
        adjuster(point)
    {}

    angle_adjuster(float x, float y) :
        adjuster(x, y)
    {}

    ~angle_adjuster() = default;

    angle_adjuster(const angle_adjuster& source)
    {
        point_   = source.point_;
        size_    = source.size_;
        image_   = source.image_;
        texture_ = source.texture_;
    }

    virtual void action(draw_state& state)
    {
        if ((state.click_pos.x > point_.x) && (state.click_pos.x < point_.x + size_.x / 2))
        {
            printf("angle--\n");

            state.current_angle--;
        }
        else
        {
            printf("angle++\n");

            state.current_angle++;
        }
    }
};