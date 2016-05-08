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
	Circle uhr{Circle(Vec2(0.5, 0.5), 0.49, Color{1,0,0})};

	while (!win.should_close()) {
    if (win.is_key_pressed(GLFW_KEY_ESCAPE)) {
   		win.close();
    }
    auto t = win.get_time();
	  uhr.draw(win, Color{1,0,0});
	    
	  Vec2 sec = Vec2(uhr.center().x+0.48f*std::sin(2*M_PI*t/60), uhr.center().y+0.48f*std::cos(2*M_PI*t/60));
	  Vec2 min = Vec2(uhr.center().x+0.42f*std::sin(2*M_PI*t/3600), uhr.center().y+0.42f*std::cos(2*M_PI*t/3600));
	  Vec2 stu = Vec2(uhr.center().x+0.28f*std::sin(2*M_PI*t/21600), uhr.center().y+0.28f*std::cos(2*M_PI*t/21600));

	  win.draw_line(uhr.center().x, uhr.center().y, sec.x, sec.y, 1.0, 0, 0);
	  win.draw_line(uhr.center().x, uhr.center().y, min.x, min.y, 1.0, 0, 0);
	  win.draw_line(uhr.center().x, uhr.center().y, stu.x, stu.y, 1.0, 0, 0);
	  win.update();
	}
  return 0;
}