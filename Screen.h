/*
 * Screen.h
 *
 *  Created on: Jan 25, 2020
 *      Author: sidkl
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include<SDL.h>

namespace Particlefire {

class Screen {
public:
	const static int screen_w = 800;
	const static int screen_h = 600;

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	Uint32 *buffer1;
	Uint32 *buffer2;

public:
	Screen();
	bool init();
	bool processevents();
	void close();
	void setpixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void update();
	void boxBlur();


};

} /* namespace Particlefire */

#endif /* SCREEN_H_ */
