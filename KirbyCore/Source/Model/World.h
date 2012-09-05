#pragma once

class Field;

class World
{
	Field* pField;
	int score;

	public:
	World();
	~World();
	void Update();
	Field const * GetField() const;
	int GetScore() const;
};
