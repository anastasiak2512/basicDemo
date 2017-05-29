//
// Created by AK on 31/10/16.
//

#include "6_ExtractSmth.h"


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuninitialized"

#define BASE_MASS 100
#define EXTRA_MASS (BASE_MASS * 10)


class Particle {

public:
    void setMass(float d) {

    }

    float getPosition() {
        return 100.0;
    }
};

class Mass {
public:

    void addScaledVector(float d, float d1) {

    }
};

Mass massDisplayPos;
Particle particleArray[BASE_MASS];

void ExtractSmth::extractSample(int x, int z)
{
    //Inline / extract function
    float xp = getDouble(xp);
    float zp = getZp(zp);

    //Extract const (1-xp)
    //Extract parameter: x * 2 + z
    const auto delta = 1 - xp;
    particleArray[x * 2 + z].setMass(BASE_MASS + EXTRA_MASS * delta * (1 - zp));
    massDisplayPos.addScaledVector(
            particleArray[x * 2 + z].getPosition(), delta * (1 - zp)
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
        particleArray[x * 2 + z + 1].setMass(BASE_MASS + EXTRA_MASS * delta * zp);
        massDisplayPos.addScaledVector(
                particleArray[x * 2 + z + 1].getPosition(), delta * zp
        );
    }
}

float ExtractSmth::getDouble(float xp) const { return xp * 100 + xp * xp; }

#pragma clang diagnostic pop