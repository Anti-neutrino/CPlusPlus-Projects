#ifndef POLYGON
#define POLYGON
struct Point
{
	float x, y;
};
struct Segment
{
	Point first, last;
	static float Line(Point, Point);
};
struct PolygonalLine
{
	Segment arr[20];
	int count;
	float polygonLength();
};
	
#endif