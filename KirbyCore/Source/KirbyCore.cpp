#include <Core.h>
#include "KirbyCore.h"
#include "Model/World.h"
#include "Render/IRender.h"

#define DeletePtr(p)if(p){delete (p); (p) = 0;}

Core::Time::TickRate* g_pTickRate = 0;
World* g_pWorld = 0;
IRender* g_pIRender = 0;

void GameInitialise()
{
	g_pTickRate = new Core::Time::TickRate(60);
	g_pWorld = new World();
	g_pIRender = IRender::Create();
	g_pIRender->Activate();
}

void GameLoop()
{
	unsigned int nTick, iTick;
	unsigned int isActive = 1;

	g_pTickRate->Reset();

	while(isActive)
	{
		nTick = g_pTickRate->TickUpdate();
		for(iTick = 0; iTick < nTick; ++iTick)
			g_pWorld->Update();

		g_pIRender->RenderWorld(g_pWorld);

		isActive = g_pIRender->Refresh();

		Sleep(1);
	}
}

void GameShutdown()
{
	DeletePtr(g_pIRender);
	DeletePtr(g_pWorld);
	DeletePtr(g_pTickRate);
}
