#pragma once

class Field;

class World
{
	Field* pField;

	public:
	World();
	~World();
	Field const * GetField() const;
};
