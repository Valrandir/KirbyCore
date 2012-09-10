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

Field const * World::GetField() const
{
	return pField;
}

int World::GetScore() const
{
	return score;
}

void World::Update()
{
	pField->Update();
	score = pField->GetScoreTotal();
}

void World::CmdMoveLeft()
{
	if(state == InGame)
		pField->PieceMoveLeft();
}

void World::CmdMoveRight()
{
	if(state == InGame)
		pField->PieceMoveRight();
}

void World::CmdMoveDown()
{
	if(state == InGame)
		pField->PieceMoveDown();
}

void World::CmdActionB()
{
	if(state == InGame)
		pField->PieceRotateLeft();
}

void World::CmdActionA()
{
	if(state == InGame)
		pField->PieceRotateRight();
}

void World::CmdActionX()
{
	if(state == InGame)
		pField->PieceDropDown();
}
