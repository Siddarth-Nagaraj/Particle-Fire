/*
 * swarm.h
 *
 *  Created on: Jan 25, 2020
 *      Author: sidkl
 */

#ifndef SWARM_H_
#define SWARM_H_
#include "Particle.h"

namespace Particlefire {

class swarm {
public:
	const static int NPARTICLES=10000;

private:
	Particle *m_pParticle;
	int lasttime;
public:
	swarm();
	const Particle * const getparticle(){return m_pParticle;};
	virtual ~swarm();
	void update(int elapsed);
};

} /* namespace Particlefire */

#endif /* SWARM_H_ */
