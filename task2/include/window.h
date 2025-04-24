#ifndef WINDOW_H
#define WINDOW_H
#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include <cmath>
#include <filesystem>
#include <iostream>
#include <limits>
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class Window {
 private:
  struct Vec2 {
    float m_x, m_y;
  };

  class Triangle : public sf::Drawable {
   public:
    Triangle(const std::array<Vec2, 3>& pts, sf::Color col = sf::Color::White)
        : m_points(pts), m_color(col) {}
    void move(int x, int y);
    virtual void draw(sf::RenderTarget& target,
                      sf::RenderStates states) const override;
    friend class Window;

   private:
    std::array<Vec2, 3> m_points;
    sf::Color m_color;
  };

 public:
  Window();
  ~Window();
  void is_running(sf::RenderWindow& window);
  bool is_colliding(const Triangle& triangle1, const Triangle& triangle2);
};

#endif
