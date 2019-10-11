#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>

class MaurerRose : public ci::app::App
{

private:
	double n;
  double d;

public:
	void setup() override;
	void update() override;
	void draw() override;
	void keyDown(ci::app::KeyEvent event) override;


};

void prepareSettings(MaurerRose::Settings* settings);
