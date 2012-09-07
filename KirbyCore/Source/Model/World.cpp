#include "World.h"
#include "Field.h"

World::World()
{
	pField = new Field();
	score = 0;
}

World::~World()
{
	if(pField)
	{
		delete pField;
		pField = 0;
	}
}

void World::Update()
{
	int updateScore;
	pField->Update(0, &updateScore);
	score += updateScore;
}

Field const * World::GetField() const
{
	return pField;
}

int World::GetScore() const
{
	return score;
}
