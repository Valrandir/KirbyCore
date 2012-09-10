#include "../../Model/World.h"
#include "../../Model/Field.h"
#include "DebugRender.h"

void DebugRender::Create()
{
}

void DebugRender::Activate()
{
	int width = 192;
	int height = 384;
	pWindowGDI = new WindowGDI(TEXT("Kirby Core - Debug Renderer"), width, height);
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
	RenderScore(pWorld->GetScore());
}

#include <tchar.h>
void DebugRender::RenderScore(int score)
{
	int len;
	TCHAR dest[128];

	len = _stprintf_s(dest, 128, TEXT("Score: %d"), score);
	pWindowGDI->Text(dest, len, 0, 0);
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

	pField->GetReadPtr(&gridPtr, 0, 0);

	for(y = j = 0; j < fieldSizeY; ++j)
	{
		for(x = i = 0; i < fieldSizeX; ++i)
		{
			color = *gridPtr;
			if(color)
				pWindowGDI->FillRect(x, y, squarePixelSizeX, squarePixelSizeY, color);
			x += squarePixelSizeX;
			++gridPtr;
		}
		y += squarePixelSizeY;
	}

	x = fieldSizeX * squarePixelSizeX;
	y = fieldSizeY * squarePixelSizeY;
	pWindowGDI->Line(0, y, x + 1, y);

	FieldItem const * vItem;
	int nItem;
	pField->GetFieldItems(&vItem, &nItem);
	for(i = 0; i < nItem; ++i)
	{
		x = vItem[i].x;
		y = vItem[i].y;
		color = vItem[i].color;
		if(color)
		{
			x *= squarePixelSizeX;
			y *= squarePixelSizeY;
			pWindowGDI->FillRect(x, y, squarePixelSizeX, squarePixelSizeY, color);
		}
	}
}
