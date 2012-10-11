#pragma once
#include <Core.h>
#include "Model/World.h"
#include "Input/IInput.h"
#include "Render/IRender.h"

class KirbyCore
{
	Core::Time::TickRate* _pTickRate;
	World* _pWorld;
	IInput* _pIInput;
	IRender* _pIRender;

	public:
	KirbyCore();
	~KirbyCore();
	void Initialise();
	void UpdateLoop();
	void Shutdown();

	private:
	void ApplyInput();
};
