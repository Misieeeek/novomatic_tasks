#include "window.h"

Window::Window() {
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Novomatic Task 2",
                          sf::Style::Close | sf::Style::Resize);
  is_running(window);
}
Window::~Window() {}

void Window::Triangle::draw(sf::RenderTarget& target,
                            sf::RenderStates states) const {
  sf::VertexArray va(sf::Triangles, 3);
  for (size_t i = 0; i < 3; ++i) {
    va[i].position = {m_points[i].m_x, m_points[i].m_y};
    va[i].color = m_color;
  }
  target.draw(va, states);
}

bool Window::is_colliding(const Triangle& triangle1,
                          const Triangle& triangle2) {
  auto dot = [](const Vec2& v, const sf::Vector2f& axis) {
    return v.m_x * axis.x + v.m_y * axis.y;
  };

  std::vector<sf::Vector2f> axes;
  const Triangle* tris[2] = {&triangle1, &triangle2};
  for (int k = 0; k < 2; ++k) {
    const auto& tri = *tris[k];
    for (int i = 0; i < 3; ++i) {
      Vec2 p1 = tri.m_points[i];
      Vec2 p2 = tri.m_points[(i + 1) % 3];
      sf::Vector2f edge(p2.m_x - p1.m_x, p2.m_y - p1.m_y);
      axes.emplace_back(-edge.y, edge.x);
    }
  }

  for (const auto& axisRaw : axes) {
    sf::Vector2f axis = axisRaw;
    float len = std::sqrt(axis.x * axis.x + axis.y * axis.y);
    if (len > 0.f) {
      axis.x /= len;
      axis.y /= len;
    }

    float min1 = dot(triangle1.m_points[0], axis);
    float max1 = min1;
    for (int i = 1; i < 3; ++i) {
      float proj = dot(triangle1.m_points[i], axis);
      min1 = std::min(min1, proj);
      max1 = std::max(max1, proj);
    }
    float min2 = dot(triangle2.m_points[0], axis);
    float max2 = min2;
    for (int i = 1; i < 3; ++i) {
      float proj = dot(triangle2.m_points[i], axis);
      min2 = std::min(min2, proj);
      max2 = std::max(max2, proj);
    }

    if (max1 < min2 || max2 < min1)
      return false;
  }

  return true;
}

void Window::Triangle::move(int x, int y) {
  for (auto& p : m_points) {
    p.m_x += x;
    p.m_y += y;
  }
}

void Window::is_running(sf::RenderWindow& window) {
  std::array<Vec2, 3> pts1 = {Vec2{100, 380}, Vec2{150, 280}, Vec2{200, 380}};
  std::array<Vec2, 3> pts2 = {Vec2{900, 380}, Vec2{950, 280}, Vec2{1000, 380}};

  Triangle triangle1(pts1, sf::Color::Red);
  Triangle triangle2(pts2, sf::Color::Cyan);
  bool collision = false;
  sf::Clock clock;
  std::filesystem::current_path(
      std::filesystem::path(__FILE__).parent_path().parent_path());
  sf::Font font;
  if (!font.loadFromFile("assets/OpenSans-Regular.ttf")) {
    std::cerr << "Failed to load font" << std::endl;
  }
  sf::Text collision_mess;
  collision_mess.setFont(font);
  collision_mess.setCharacterSize(24);
  collision_mess.setFillColor(sf::Color::Yellow);
  collision_mess.setString("Collision!");
  collision_mess.setPosition(600, 20);

  while (window.isOpen()) {
    sf::Event evnt;
    while (window.pollEvent(evnt)) {
      switch (evnt.type) {
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::KeyPressed:
          switch (evnt.key.code) {
            case sf::Keyboard::Up:
              triangle2.move(0, -5);
              break;
            case sf::Keyboard::Down:
              triangle2.move(0, 5);
              break;
            case sf::Keyboard::Left:
              triangle2.move(-5, 0);
              break;
            case sf::Keyboard::Right:
              triangle2.move(5, 0);
              break;
          }
          if (is_colliding(triangle1, triangle2)) {
            collision = true;
            clock.restart();
          }
          break;
      }
    }
    window.clear();
    window.draw(triangle1);
    window.draw(triangle2);
    if (collision && clock.getElapsedTime().asSeconds() < 1.0f)
      window.draw(collision_mess);
    else if (collision)
      collision = false;
    window.display();
  }
}
