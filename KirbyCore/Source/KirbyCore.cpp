#include "KirbyCore.h"

#define DeletePtr(p)if(p){delete (p); (p) = 0;}

KirbyCore::KirbyCore() : _pTickRate(0), _pWorld(0), _pIInput(0), _pIRender(0)
{
}

KirbyCore::~KirbyCore()
{
	Shutdown();
}

void KirbyCore::Initialise()
{
	_pTickRate = new Core::Time::TickRate(10);
	_pWorld = new World();
	_pIInput = IInput::Create();
	_pIRender = IRender::Create();
	_pIRender->Create();
	_pIRender->Activate();
}

void KirbyCore::UpdateLoop()
{
	unsigned int nTick, iTick;
	unsigned int isActive = 1;

	_pTickRate->Reset();

	while(isActive)
	{
		nTick = _pTickRate->TickUpdate();
		for(iTick = 0; iTick < nTick; ++iTick)
		{
			ApplyInput();
			_pWorld->Update();
		}

		_pIRender->RenderWorld(_pWorld);

		isActive = _pIRender->Refresh();

		Sleep(1);
	}
}

void KirbyCore::Shutdown()
{
	DeletePtr(_pIRender);
	DeletePtr(_pIInput);
	DeletePtr(_pWorld);
	DeletePtr(_pTickRate);
}

void KirbyCore::ApplyInput()
{
	_pIInput->Read(0);

	if(_pIInput->Peek(CmdMoveLeft))
		_pWorld->CmdMoveLeft();

	if(_pIInput->Peek(CmdMoveRight))
		_pWorld->CmdMoveRight();

	if(_pIInput->Peek(CmdMoveDown))
		_pWorld->CmdMoveDown();

	if(_pIInput->Peek(CmdActionB))
		_pWorld->CmdActionB();

	if(_pIInput->Peek(CmdActionA))
		_pWorld->CmdActionA();

	if(_pIInput->Peek(CmdActionX))
		_pWorld->CmdActionX();
}
