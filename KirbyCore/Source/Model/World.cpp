#include "World.h"
#include "Field.h"

World::World() : pField(0)
{
	pField = new Field();
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
	pField->Update();
}

Field const * World::GetField() const
{
	return pField;
}
