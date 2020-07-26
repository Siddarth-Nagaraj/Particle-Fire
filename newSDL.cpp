//============================================================================
// Name        : newSDL.cpp
// Author      : Siddarth Nagaraj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<SDL.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include "Screen.h"
#include "swarm.h"

using namespace std;
using namespace Particlefire;
int main(int argc, char *argv[]) {

	srand(time(NULL));

	swarm s_swarm;

	Screen screen;

	if (screen.init() == false) {
		cout << "error initilaizing" << endl;
	}

	while (true) {
		int elapsed = SDL_GetTicks();

		//screen.clear();
		s_swarm.update(elapsed);

		unsigned char green = (unsigned char) ((1 + sin(elapsed * 0.001)) * 128);
		unsigned char red = (unsigned char) ((1 + cos(elapsed * 0.001)) * 128);
		unsigned char blue = (unsigned char) ((1 + sin(elapsed * 0.001)) * 128);

		const Particle *const pParticle = s_swarm.getparticle();

		for (int i = 0; i < swarm::NPARTICLES; i++) {
			Particle particle = pParticle[i];
			int x = (particle.m_x + 1) * Screen::screen_w / 2;
			int y = particle.m_y * Screen::screen_w/2 + Screen::screen_h/2;

			screen.setpixel(x, y, red, green, blue);

		}

		screen.boxBlur();

		screen.update();

		if (screen.processevents() == false) {
			break;
		}

	}

	return 0;
}
