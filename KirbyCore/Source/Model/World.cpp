#include "World.h"
#include "Field.h"

World::World() : state(InGame)
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

void World::CmdMoveLeft()
{
	if(state == InGame)
		pField->PieceLeft();
}

void World::CmdMoveRight()
{
	if(state == InGame)
		pField->PieceRight();
}

void World::Update()
{
	pField->Update();
	score = pField->GetScoreTotal();
}

Field const * World::GetField() const
{
	return pField;
}

int World::GetScore() const
{
	return score;
}
