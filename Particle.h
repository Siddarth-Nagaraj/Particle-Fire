/*
 * Particle.h
 *
 *  Created on: Jan 25, 2020
 *      Author: sidkl
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace Particlefire {

struct Particle {

	double m_x;
	double m_y;
	//double xspeed;
	//double yspeed;
	double m_speed;
	double m_direction;


	Particle();
	virtual ~Particle();
	void update(int interval);
private:
	void init();
};

} /* namespace Particlefire */

#endif /* PARTICLE_H_ */
