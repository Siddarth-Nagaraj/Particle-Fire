/*
 * Screen.cpp
 *
 *  Created on: Jan 25, 2020
 *      Author: sidkl
 */
#include<string.h>
#include "Screen.h"

namespace Particlefire {

Screen::Screen() :
		window(NULL), renderer(NULL), texture(NULL), buffer1(NULL), buffer2(NULL) {
	// TODO Auto-generated constructor stub

}

bool Screen::init() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {

		return false;
	}

	window = SDL_CreateWindow("Particle fire",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_w, screen_h,
			SDL_WINDOW_SHOWN);

	if (window == NULL) {

		SDL_Quit();
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, screen_w, screen_h);

	if (renderer == NULL) {

		SDL_DestroyWindow(window);
		SDL_Quit();
		return false;
	}
	if (texture == NULL) {

		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return false;
	}

	buffer1 = new Uint32[screen_w * screen_h];
	buffer2 = new Uint32[screen_w * screen_h];

	memset(buffer1, 0, screen_w * screen_h * sizeof(Uint32));
	memset(buffer2, 0, screen_w * screen_h * sizeof(Uint32));



	return true;
}
bool Screen::processevents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}
void Screen::setpixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

	if (x<0 ||x>=screen_w ||y<0 ||y>=screen_h){
		return;
	}
	Uint32 colour = 0;

	colour += red;
	colour <<= 8;
	colour += green;
	colour <<= 8;
	colour += blue;
	colour <<= 8;
	colour += 0xFF;

	buffer1[(y*screen_w)+x]=colour;

}
void Screen::update(){
	SDL_UpdateTexture(texture, NULL, buffer1, screen_w * sizeof(Uint32));
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);

}

void Screen::boxBlur(){
	Uint32 *temp = buffer1;
	buffer1=buffer2;
	buffer2=temp;

	for (int y=0;y<screen_h;y++){
		for (int x=0;x<screen_w;x++){

			int redtotal=0;
			int bluetotal=0;
			int greentotal=0;

			for(int row=-1;row<=1;row++){
				for(int col=-1;col<=1;col++){

					int currentx=x+col;
					int currenty=y+row;

					if (currentx>=0 && currentx<screen_w && currenty>=0 && currenty<screen_h){
						Uint32 colour = buffer2[currenty*screen_w + currentx];

						Uint8 red = colour>>24;
						Uint8 green = colour>>16;
						Uint8 blue = colour>>8;

						redtotal+=red;
						greentotal+=green;
						bluetotal+=blue;
					}

				}


			}

			Uint8 red=redtotal/9;
			Uint8 green=greentotal/9;
			Uint8 blue=bluetotal/9;

			setpixel(x,y,red, green, blue);
		}
	}

}

void Screen::close() {
	delete[] buffer1;
	delete[] buffer2;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);

	SDL_DestroyWindow(window);
	SDL_Quit();
}

} /* namespace Particlefire */
