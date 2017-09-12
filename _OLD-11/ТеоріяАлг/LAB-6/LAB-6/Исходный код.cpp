#include <windows.h>
#include <iostream>
using namespace std;

struct pt {
	int x, y;
};

inline int area (pt a, pt b, pt c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool intersect_1(int a, int b, int c, int d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}

bool intersect(pt a, pt b, pt c, pt d) {
	return intersect_1 (a.x, b.x, c.x, d.x)
		&& intersect_1 (a.y, b.y, c.y, d.y)
		&& area(a,b,c) * area(a,b,d) <= 0
		&& area(c,d,a) * area(c,d,b) <= 0;
}
void drawLine(pt o, pt a, pt b, bool t){
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);
	int cr = (!t)*255,
		cg = ( t)*255, 
		cb = (!t)*255;

	HPEN pen = CreatePen(PS_SOLID, 3, RGB(cr, cg, cb));
	SelectObject(device_context, pen);

	MoveToEx(device_context, o.x+a.x, o.y+a.y, NULL);
	LineTo(device_context, o.x+b.x, o.y+b.y);

	ReleaseDC(console_handle, device_context);
}

int main(){
	setlocale(LC_ALL, "Ukrainian");
	pt a, b, c, d;
	cout << "   | X | Y |\r\n";
	cout << " A | ";
	cin >> a.x >> a.y;
	cout << " B | ";
	cin >> b.x >> b.y;
	cout << " C | ";
	cin >> c.x >> c.y;

	cout << " D | ";
	cin >> d.x >> d.y;
	cout << "---|-------|\r\n";

	cout << (intersect(a, b, c, d) ? "П" : "Не п") << "еретинаються";
	pt offset = {200, 0};
	drawLine(offset, a, b, 0);
	drawLine(offset, c, d, 1);


	system("pause>>NUL");
	return 0;
}

