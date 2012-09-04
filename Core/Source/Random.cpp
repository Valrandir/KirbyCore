#include <stdlib.h>
#include <time.h>
#include "Random.h"

using namespace Core;

void Random::Randomize()
{
	srand((unsigned int)time(NULL));
}

int Random::Rnd(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}
