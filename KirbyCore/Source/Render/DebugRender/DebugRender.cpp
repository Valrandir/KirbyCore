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

	pWindowGDI->ClearBackBuffer();
	RenderField(pField);
}

void DebugRender::RenderField(Field const * pField)
{
	int const * gridPtr;
	int fieldSizeX = pField->GetSizeX();
	int fieldSizeY = pField->GetSizeY();
	int squarePixelSizeX = pWindowGDI->GetWidth() / fieldSizeX;
	int squarePixelSizeY = pWindowGDI->GetHeight() / fieldSizeY;
	int j, i;
	int x, y, color;

	gridPtr = pField->GetReadPtr();
	x = 0;
	y = 0;

	for(j = 0; j < fieldSizeY; ++j)
	{
		for(i = 0; i < fieldSizeX; ++i)
		{
			color = *gridPtr;
			if(color)
				pWindowGDI->FillRect(x, y, x + squarePixelSizeX, y + squarePixelSizeY, color);
			x += squarePixelSizeX;
			++gridPtr;
		}
		y += squarePixelSizeY;
	}

	x = fieldSizeX * squarePixelSizeX;
	y = fieldSizeY * squarePixelSizeY;
	pWindowGDI->Line(0, y, x, y);

	pField->GetFallingInfo(x, y, color);
	if(color)
	{
		x *= squarePixelSizeX;
		y *= squarePixelSizeY;
		pWindowGDI->Rectangle(x, y, x + squarePixelSizeX, y + squarePixelSizeY, color);
	}
}
