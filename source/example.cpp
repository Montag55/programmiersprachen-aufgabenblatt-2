#include "window.hpp"
#include <utility>
#include <cmath>
#include <iostream>
#include <vector>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  //Kreise
  std::vector<Circle>MeinWunderschoenenKreise;
  MeinWunderschoenenKreise.push_back(Circle(Vec2(0.5f, 0.5f), 0.3f, Color(0.0f, 0.0f, 0.0f)));
  MeinWunderschoenenKreise.push_back(Circle(Vec2(0.5f, 0.5f), 0.28f, Color(0.0f, 0.0f, 0.0f)));

  //Knechtecke
  std::vector<Rectangle>Knechtecke;
  Knechtecke.push_back(Rectangle(0.6f, 0.6f, Color(0.0f, 0.0f, 0.0f), Vec2(0.2f, 0.2f))); 

  while (!win.should_close()) {
    if (win.is_key_pressed(GLFW_KEY_ESCAPE)) {
      win.close();
    }
    auto t = win.get_time();
    Vec2 mouse_pos = Vec2(win.mouse_position().first, win.mouse_position().second);
    
    if(MeinWunderschoenenKreise[0].is_inside(mouse_pos)){
      MeinWunderschoenenKreise[0].draw(win, Color{0, 1, 0.9});
      float x1{0.5f + 0.35f * std::sin(5.f*t)};
      float y1{0.5f + 0.35f * std::cos(5.f*t)};
      win.draw_point(x1, y1, 0.0f, 1.0f, 0.9f);
    }
    else{MeinWunderschoenenKreise[0].draw(win, Color{1,0,0});
      float x1{0.5f + 0.35f * std::sin(t)};
      float y1{0.5f + 0.35f * std::cos(t)};
      win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    }

    if(MeinWunderschoenenKreise[1].is_inside(mouse_pos)){
      MeinWunderschoenenKreise[1].moire(win, Color{0, 1, 0.9});
      float x2{0.25f + 0.04f * std::sin(15.0f*t)};
      float y2{0.25f + 0.04f * std::cos(15.0f*t)};
      float x3{0.25f + 0.04f * std::sin(15.0f*t)};
      float y3{0.75f + 0.04f * std::cos(15.0f*t)};
      float x4{0.75f + 0.04f * std::sin(15.0f*t)};
      float y4{0.75f + 0.04f * std::cos(15.0f*t)};
      float x5{0.75f + 0.04f * std::sin(15.0f*t)};
      float y5{0.25f + 0.04f * std::cos(15.0f*t)};
      win.draw_point(x2, y2, 0.0f, 1.0f, 0.9f);
      win.draw_point(x3, y3, 0.0f, 1.0f, 0.9f);
      win.draw_point(x4, y4, 0.0f, 1.0f, 0.9f);
      win.draw_point(x5, y5, 0.0f, 1.0f, 0.9f);
    }
    else{MeinWunderschoenenKreise[1].moire(win, Color{});}

    if (Knechtecke[0].is_inside(mouse_pos)){
      Knechtecke[0].draw(win, Color{0, 1, 0.9});
    }
    else{Knechtecke[0].draw(win, Color{1,0,0});}

   



    /*auto t = win.get_time();
    float x1{0.5f + 0.35f * std::sin(t)};
    float y1{0.5f + 0.35f * std::cos(t)};
    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);

    float x2{0.5f + 0.5f * std::sin(5.0f*t)};
    float y2{0.5f + 0.5f * std::cos(5.0f*t)};
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);

    float x3{0.5f + 0.5f * std::sin(5.0f*t)};
    float y3{0.5f + 0.5f * std::cos(5.0f*t)};
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto m = win.mouse_position();
    win.draw_line(0.1f, 0.1f, 0.8f,0.1f, 1.0,0.0,0.0);

    win.draw_line(0.0f, m.second, 0.01f, m.second, 0.0, 0.0, 0.0);
    win.draw_line(0.99f, m.second,1.0f, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0.0f, m.first, 0.01f, 0.0, 0.0, 0.0);
    win.draw_line(m.first, 0.99f,m.first, 1.0f, 0.0, 0.0, 0.0);*/

    win.update();
  }

  return 0;
}
