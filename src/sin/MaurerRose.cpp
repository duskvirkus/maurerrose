#include "MaurerRose.h"

inline double map(double value, double in_start, double in_end, double out_start, double out_end)
{
  return out_start +  ((out_end - out_start) / (in_end - in_start)) * value - in_start;
}

inline double to_degrees(double radians)
{
  return map(radians, 0, M_PI * 2, 0, 360);
}

inline double to_radians(double degrees)
{
  return map(degrees, 0, 360, 0, M_PI * 2);
}

void MaurerRose::setup()
{

}

void MaurerRose::update()
{
  getWindow()->setTitle("FPS: " + std::to_string(static_cast<int>(getFrameRate())));

  double amt = getElapsedFrames() * 0.000005;
  n = map(sin(amt), -1.0, 1.0, 1.0, 7.0);
  d = map(cos(amt), -1.0, 1.0, 20.0, 100.0);
}

void MaurerRose::draw()
{
	ci::gl::clear(ci::Color::gray(0.0f));
  //ci::gl::clear(ci::Color(1, 0, 0));

  ci::gl::pushModelMatrix();
  ci::gl::translate(getWindowWidth() / 2, getWindowHeight() / 2);

  for (int i = 0; i < 360; i += 2)
  {
    ci::gl::color(ci::Color(i / 360.0, 0.5, 0.5));

    double k1 = i * d;
    double r1 = sin(to_radians(n * k1)) * getWindowWidth() / 4;
    double x1 = r1 * cos(to_radians(k1));
    double y1 = r1 * sin(to_radians(k1));

    double k2 = (i + 1) * d;
    double r2 = sin(to_radians(n * k2)) * getWindowWidth() / 4;
    double x2 = r2 * cos(to_radians(k2));
    double y2 = r2 * sin(to_radians(k2));

    ci::gl::drawLine(glm::vec2(x1, y1), glm::vec2(x2, y2));
  }

  ci::gl::popModelMatrix();
}

void MaurerRose::keyDown(ci::app::KeyEvent event)
{
	if(event.getChar() == 'f')
	{
		setFullScreen(!isFullScreen());
	}
	else if(event.getCode() == ci::app::KeyEvent::KEY_ESCAPE)
	{
		if(isFullScreen())
		{
			setFullScreen(false);
		}
		else
		{
			quit();
		}
	}
}

void prepareSettings(MaurerRose::Settings* settings)
{
	settings->setMultiTouchEnabled(false);
}

CINDER_APP(MaurerRose, ci::app::RendererGl, prepareSettings);
