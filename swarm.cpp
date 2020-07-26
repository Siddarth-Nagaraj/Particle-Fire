/*
 * swarm.cpp
 *
 *  Created on: Jan 25, 2020
 *      Author: sidkl
 */

#include "swarm.h"


namespace Particlefire {

swarm::swarm():lasttime(0) {
	m_pParticle=new Particle[NPARTICLES];

}

void swarm::update(int elapsed){
	int interval = elapsed- lasttime;
	for (int i = 0; i < swarm::NPARTICLES; i++) {
				m_pParticle[i].update(interval);

			}
	lasttime=elapsed;
}

swarm::~swarm() {
	delete [] m_pParticle;
}

} /* namespace Particlefire */
