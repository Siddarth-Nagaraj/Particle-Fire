/*
 * Particle.cpp
 *
 *  Created on: Jan 25, 2020
 *      Author: sidkl
 */

#include "Particle.h"
#include<stdlib.h>
#include<math.h>

namespace Particlefire {

Particle::Particle() {

init();
}
void Particle::init(){
	m_x = 0; //((2.0 * rand()) / RAND_MAX) - 1;
		m_y = 0; //((2.0 * rand()) / RAND_MAX) - 1;
		//xspeed = 0.01*(((2.0*rand())/RAND_MAX)-1);
		//yspeed = 0.01*(((2.0*rand())/RAND_MAX)-1);
		m_direction = (2.0 *M_PI* rand()) / RAND_MAX;
		m_speed = (0.04*rand()) / RAND_MAX;
		m_speed*=m_speed;
}
void Particle::update(int interval) {
	/*m_x += xspeed;
	m_y += yspeed;

	if (m_x<=-1.0||m_x>=1.0){
		xspeed=-xspeed;
	}
	if (m_y<=-1.0||m_y>=1.0){
			yspeed=-yspeed;
		}*/
	m_direction+=interval*0.0002;
	double xspeed = m_speed*cos(m_direction);
	double yspeed = m_speed*sin(m_direction);
	m_x+=xspeed*interval;
	m_y+=yspeed*interval;

	if (m_x<-1 || m_x>1 || m_y<-1 || m_y>1){
		init();
	}
}
Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

} /* namespace Particlefire */
