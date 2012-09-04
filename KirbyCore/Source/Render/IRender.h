#pragma once

class World;

class IRender
{
	public:
	static IRender* Create();
	virtual void Activate() = 0;
	virtual unsigned int Refresh() = 0;
	virtual ~IRender() = 0;
	virtual void RenderWorld(World const * pWorld) = 0;
};
