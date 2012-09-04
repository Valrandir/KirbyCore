#include "KirbyCore.h"
#include "Model/World.h"
#include "Render/IRender.h"

#define DeletePtr(p)if(p){delete (p); (p) = 0;}

World* g_pWorld = 0;
IRender* g_pIRender = 0;

void GameStart()
{
	unsigned int isActive = 1;

	g_pWorld = new World();

	g_pIRender = IRender::Create();
	g_pIRender->Activate();

	while(isActive)
	{
		g_pIRender->RenderWorld(g_pWorld);
		isActive = g_pIRender->Refresh();
	}
}

void GameStop()
{
	DeletePtr(g_pIRender);
	DeletePtr(g_pWorld);
}
