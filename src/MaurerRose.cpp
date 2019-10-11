#include "MaurerRose.h"

void MaurerRose::setup()
{ 

}

void MaurerRose::update()
{ 

}

void MaurerRose::draw()
{
	ci::gl::clear(ci::Color::gray(0.0f));
  ci::gl::drawSolidCircle(glm::vec2(100, 100), 100, 10);
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
