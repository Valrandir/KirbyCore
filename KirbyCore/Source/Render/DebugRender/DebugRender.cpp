#include "../../Model/World.h"
#include "../../Model/Field.h"
#include "DebugRender.h"

void DebugRender::Activate()
{
	int width = 192;
	int height = 384;
	pWindow2D = Core::Window2D::Create(Core::CORESTR("Kirby Core - Debug Renderer"), width, height);
	pWindow2D->Show();
}

unsigned int DebugRender::Refresh()
{
	if(pWindow2D)
		return pWindow2D->Update();

	return 0;
}

DebugRender::~DebugRender()
{
	if(pWindow2D)
	{
		delete pWindow2D;
		pWindow2D = NULL;
	}
}

void DebugRender::RenderWorld(World const * pWorld)
{
	Field const * pField = pWorld->GetField();

	pWindow2D->Clear();
	RenderField(pField);
	RenderScore(pWorld->GetScore());
}

void DebugRender::RenderScore(int score)
{
	int len;
	Core::CORECHAR dest[128];

	Core::String::Format(dest, 128, CORETEXT("Score: %d"), score);
	pWindow2D->DrawString(dest, 0, 0);
}

void DebugRender::RenderField(Field const * pField)
{
	int const * gridPtr;
	int fieldSizeX = pField->GetSizeX();
	int fieldSizeY = pField->GetSizeY();
	int squarePixelSizeX;
	int squarePixelSizeY;
	int j, i, x, y;
	unsigned int color;

	pWindow2D->GetClientSize(x, y);
	squarePixelSizeX = x / fieldSizeX;
	squarePixelSizeY = y / fieldSizeY;

	pField->GetReadPtr(&gridPtr, 0, 0);

	for(y = j = 0; j < fieldSizeY; ++j)
	{
		for(x = i = 0; i < fieldSizeX; ++i)
		{
			color = *gridPtr;
			if(color)
				pWindow2D->DrawRect(x, y, squarePixelSizeX, squarePixelSizeY, color);
			x += squarePixelSizeX;
			++gridPtr;
		}
		y += squarePixelSizeY;
	}

	x = fieldSizeX * squarePixelSizeX;
	y = fieldSizeY * squarePixelSizeY;
	pWindow2D->DrawLine(0, y, x + 1, y);

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
			pWindow2D->DrawRect(x, y, squarePixelSizeX, squarePixelSizeY, color);
		}
	}
}
