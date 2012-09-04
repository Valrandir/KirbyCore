#pragma once

class Field;

class IRender
{
	public:
	static IRender* Create();
	virtual void Activate() = 0;
	virtual unsigned int Refresh() = 0;
	virtual ~IRender() = 0;
	virtual void RenderField(Field const * pField) = 0;
};
