#include "../../Model/World.h"
#include "../../Model/Field.h"
#include "DebugRender.h"

void DebugRender::Create()
{
}

void DebugRender::Activate()
{
	pWindowGDI = new WindowGDI(TEXT("Kirby Core - Debug Renderer"), 640, 480);
}

unsigned int DebugRender::Refresh()
{
	if(pWindowGDI)
		return pWindowGDI->Refresh();

	return 0;
}

DebugRender::~DebugRender()
{
	if(pWindowGDI)
	{
		delete pWindowGDI;
		pWindowGDI = NULL;
	}
}

void DebugRender::RenderWorld(World const * pWorld)
{
	Field const * pField = pWorld->GetField();
	RenderField(pField);
}

void DebugRender::RenderField(Field const * pField)
{
	pWindowGDI->FillRect(0, 0, 100, 100, RGB(255, 0, 40));
	pWindowGDI->Rectangle(200, 200, 100, 100, RGB(40, 128, 255));

	int const * gridPtr;
	int width = pWindowGDI->GetWidth();
	int height = pWindowGDI->GetHeight();
	int sqsx = width / pField->GetSizeX();
	int sqsy = height / pField->GetSizeY();
	int px, py;

	gridPtr = pField->GetReadPtr();

	for(py = 0; py < height; py += sqsy)
		for(px = 0; px < width; px += sqsx)
			pWindowGDI->Rectangle(px, py, px + sqsx, py + sqsy, *(gridPtr++));
}
