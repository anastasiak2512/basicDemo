//
// Created by AK on 31/10/16.
//

#include "ExtractSmth.h"

#define BASE_MASS 100
#define EXTRA_MASS 1000

class Particle {

public:
    void setMass(float d) {

    }

    float getPosition() {

    }
};

class Mass {
public:

    void addScaledVector(float d, float d1) {

    }
};

Mass massDisplayPos;
Particle particleArray[100];

void ExtractSmth::extractSample(int x, int z)
{
    float xp = getXp();
    float zp = getZp();

    //Extract const (1-xp)
    //Extract parameter: x * 2 + z
    particleArray[(x * 2 + z)].setMass(BASE_MASS + EXTRA_MASS * (1 - xp) * (1 - zp));
    massDisplayPos.addScaledVector(
            particleArray[(x * 2 + z)].getPosition(), (1 - xp) * (1 - zp)
    );

    if (xp > 0) {
        particleArray[x * 2 + z + 2].setMass(BASE_MASS + EXTRA_MASS * xp * (1 - zp));
        massDisplayPos.addScaledVector(
                particleArray[x * 2 + z + 2].getPosition(), xp * (1 - zp)
        );

        if (zp > 0) {
            particleArray[x * 2 + z + 3].setMass(BASE_MASS + EXTRA_MASS * xp * zp);
            massDisplayPos.addScaledVector(
                    particleArray[x * 2 + z + 3].getPosition(), xp * zp
            );
        }
    }
    if (zp > 0) {
        particleArray[x * 2 + z + 1].setMass(BASE_MASS + EXTRA_MASS * (1 - xp) * zp);
        massDisplayPos.addScaledVector(
                particleArray[x * 2 + z + 1].getPosition(), (1 - xp) * zp
        );
    }
}