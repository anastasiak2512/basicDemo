//- Extract Function (Ctrl+Alt+M on Windows/Linux, Cmd+Alt+M on macOS)
//- Inline (Ctrl+Alt+N on Windows/Linux, Cmd+Alt+N on macOS)
//- Extract parameter (Ctrl+Alt+P on Windows/Linux, Cmd+Alt+P on macOS)
//- Extract variable (Ctrl+Alt+V on Windows/Linux, Cmd+Alt+V on macOS)

#include <tkDecls.h>
#include "ExtractSmth.h"

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
    //Extract expression to a function
    //Inline: xp
    float xp = x * 100 + z * z;
    //Inline: EXTRA_MASS (good for debug)

    //Extract parameter: 0.5f
    //Extract variable: x * 2 + z
    particleArray[(x * 2 + z)].setMass(BASE_MASS + EXTRA_MASS * (1 - xp) * (1 - 0.5f));
    massDisplayPos.addScaledVector(
            particleArray[(x * 2 + z)].getPosition(), (1 - xp) * (1 - 0.5f)
    );

    if (xp > 0) {
        particleArray[x * 2 + z + 2].setMass(BASE_MASS + EXTRA_MASS * xp * (1 - 0.5f));
        massDisplayPos.addScaledVector(
                particleArray[x * 2 + z + 2].getPosition(), xp * (1 - 0.5f)
        );

        if (0.5f > 0) {
            particleArray[x * 2 + z + 3].setMass(BASE_MASS + EXTRA_MASS * xp * 0.5f);
            massDisplayPos.addScaledVector(
                    particleArray[x * 2 + z + 3].getPosition(), xp * 0.5f
            );
        }
    }
    if (0.5f > 0) {
        particleArray[x * 2 + z + 1].setMass(BASE_MASS + EXTRA_MASS * (1 - xp) * 0.5f);
        massDisplayPos.addScaledVector(
                particleArray[x * 2 + z + 1].getPosition(), (1 - xp) * 0.5f
        );
    }
}

void ExtractSmth::callCheck() {
    extractSample(5, 100);
}