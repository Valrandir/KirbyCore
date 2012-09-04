#include "KirbyCore.h"
#include "Model/Field.h"
#include "Render/IRender.h"

#define DeletePtr(p)if(p){delete (p); (p) = NULL;}

Field* g_pField = NULL;
IRender* g_pIRender = NULL;

void GameStart()
{
	unsigned int isActive = 1;

	g_pField = new Field();

	g_pIRender = IRender::Create();
	g_pIRender->Activate();

	while(isActive)
	{
		g_pIRender->RenderField(g_pField);
		isActive = g_pIRender->Refresh();
	}
}

void GameStop()
{
	DeletePtr(g_pIRender);
	DeletePtr(g_pField);
}
