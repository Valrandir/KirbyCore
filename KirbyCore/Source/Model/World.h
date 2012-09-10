#pragma once

class Field;

enum WorldStateEnum
{
	InGame = 0
};

class World
{
	WorldStateEnum state;
	Field* pField;
	int score;

	public:
	World();
	~World();

	void CmdMoveLeft();
	void CmdMoveRight();
	void Update();

	Field const * GetField() const;
	int GetScore() const;
};
