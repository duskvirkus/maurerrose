#include "MaurerRose.h"

static constexpr int n = 2;
static constexpr int d = 29;

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

}

void MaurerRose::draw()
{
	ci::gl::clear(ci::Color::gray(0.0f));

  ci::gl::pushModelMatrix();
  ci::gl::translate(getWindowWidth() / 2, getWindowHeight() / 2);

  ci::gl::begin(GL_LINE_STRIP);
  for (int i = 0; i <= 360; i++)
  {
    double k = i * d;
    double r = sin(to_radians(n * k)) * getWindowWidth() / 3;
    double x = r * cos(to_radians(k));
    double y = r * sin(to_radians(k));
    ci::gl::vertex(glm::vec2(x, y));
  }
  ci::gl::end();

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
