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

	Field const * GetField() const;
	int GetScore() const;

	void Update();
	void CmdMoveLeft();
	void CmdMoveRight();
	void CmdMoveDown();
	void CmdActionB();
	void CmdActionA();
	void CmdActionX();
};
