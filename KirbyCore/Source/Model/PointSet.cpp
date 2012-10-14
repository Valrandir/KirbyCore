#define nothing

class PointSet
{
	public:
	struct Point
	{
		int x, y;
		unsigned int c;

		Point(){}
		Point(int x, int y, unsigned int c) : x(x), y(y), c(c){}
	};

	private:
	static const int ListMaxSize = 25;
	int vLength;
	Point vBegin[ListMaxSize], *vEnd;

	int x1, y1, x2, y2;
	int cx, cy;
	bool cxyIsDirty;

	void UpdateCenter()
	{
		for(auto it = vBegin; it < vEnd; ++it)
		{
			if(it->x < x1) x1 = it->x;
			if(it->x > x2) x2 = it->x;
			if(it->y < y1) y1 = it->y;
			if(it->y > y2) y2 = it->y;
		}

		cx = x1 + ((x2 - x1) >> 1);
		cy = y1 + ((y2 - y1) >> 1);
		cxyIsDirty = false;
	}

	void RotateZero(bool clockwise)
	{
		int swap;

		for(auto it = vBegin; it < vEnd; ++it)
		{
			swap = it->x;
			it->x = it->y;
			it->y = swap;

			int& rf = clockwise ? it->x : it->y;
			rf = -rf;
		}
	}

	public:
	PointSet()
	{
		Clear();
	}

	void Clear()
	{
		vLength = 0;
		vEnd = vBegin + 1;

		x1 = 0;
		y1 = 0;
		x2 = 0;
		y2 = 0;
		cx = 0;
		cy = 0;
		cxyIsDirty = false;
	}

	void Add(Point const &p)
	{
		if(vLength >= ListMaxSize)
			return;

		*vEnd = p;
		++vLength;
		++vEnd;

		if(p.x < x1 || p.x > x2 || p.y < y1 || p.y > y2)
			cxyIsDirty = true;
	}

	void RemoveAt(int ndx)
	{
		if(ndx < 0 || ndx >= vLength)
			return;

		auto it = vBegin + ndx + 1;

		if(it->x == x1 || it->x == x2 || it->y == y1 || it->y == y2)
			cxyIsDirty = true;

		for(; it < vEnd; ++it)
			*(it - 1) = *it;

		--vLength;
		--vEnd;
	}

	void Offset(int x, int y)
	{
		for(auto it = vBegin; it < vEnd; ++it)
		{
			it->x += x;
			it->y += y;
		}
	}

	void Rotate(bool clockwise)
	{
		if(cxyIsDirty)
			UpdateCenter();

		Offset(-cx, -cy);
		RotateZero(clockwise);
		Offset(cx, cy);
	}

	Point const *GetByIndex(int ndx) const
	{
		if(ndx >= 0 && ndx < vLength)
			return vBegin + ndx;

		return 0;
	}

	Point const *GetByXY(int x, int y) const
	{
		for(auto it = vBegin; it < vEnd; ++it)
			if(x == it->x && y == it->y)
				return it;
		return 0;
	}

	int GetIterator(Point const **begin, Point const **end) const
	{
		if(begin) *begin = vBegin;
		if(end) *end = vEnd;
		return vLength;
	}
};
