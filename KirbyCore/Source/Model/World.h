#pragma once

class Field;

class World
{
	Field* pField;

	public:
	World();
	~World();
	void Update();
	Field const * GetField() const;
};
