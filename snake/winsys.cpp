#include "winsys.h"
#include "cpoint.h"
#include "screen.h"

#include <list>
#include <string>
#include <cctype>
#include <cstdarg>

using namespace std;


void CView::move(const CPoint& delta)
{
	geom.topleft += delta;
}



void CWindow::paint()
{
	for (int y = geom.topleft.y; y < geom.topleft.y + geom.size.y; y++)
		for (int x = geom.topleft.x; x < geom.topleft.x + geom.size.x; x++)
		{
			gotoyx(y, x);
			printl("%c", c);
		}
}

bool CWindow::handleEvent(int key)
{
	switch (key)
	{
		case KEY_UP:
			move(CPoint(0, -1));
		return true;

		case KEY_DOWN:
			move(CPoint(0, 1));
		return true;

		case KEY_RIGHT:
			move(CPoint(1, 0));
		return true;

		case KEY_LEFT:
			move(CPoint(-1, 0));
		return true;
	};

	return false;
}



void CFramedWindow::paint()
{
	int height = geom.topleft.y + geom.size.y;
	int width = geom.topleft.x + geom.size.x;

	for (int y = geom.topleft.y; y < height; y++)
	{
		if ((y == geom.topleft.y) || (y == height - 1))
		{
			for (int x = geom.topleft.x; x < width; x++)
			{
				gotoyx(y, x);
				if ((x == geom.topleft.x) || (x == width - 1))
					printl("+");
				else
					printl("-");
			}
		}
		else
		{
			for (int x = geom.topleft.x; x < width; x++)
			{
				gotoyx(y, x);
				if ((x == geom.topleft.x) || (x == width - 1))
					printl("|");
				else
					printl("%c", c);
			}
		}
	}
}



void CInputLine::paint()
{
	CFramedWindow::paint();

	unsigned int row = 0;

	for (int y = geom.topleft.y + 1; y < geom.topleft.y + geom.size.y - 1; y++, row++)
	{
		unsigned int letter = row * (geom.size.x - 2);

		for (int x = geom.topleft.x + 1; x < geom.topleft.x + geom.size.x - 1; x++, letter++)
		{
			gotoyx(y, x);
			printl("%c", letter < text.size() ? text[letter] : c);
		}
	}
}

bool CInputLine::handleEvent(int key)
{
	if (CFramedWindow::handleEvent(key))
		return true;

	if ((key == KEY_DC) || (key == KEY_BACKSPACE))
	{
		if (text.length() > 0)
		{
			text.erase(text.length() - 1);
			return true;
		};
	}
	if ((key > 255) || (key < 0))
		return false;

	if (!isalnum(key) && (key != ' '))
		return false;

	text.push_back(key);

	return true;
}



void CGroup::paint()
{
	for (int y = geom.topleft.y; y < geom.topleft.y + geom.size.y; y++)
	{
		gotoyx(y, geom.topleft.x);

		for (int x = 0; x < geom.size.x; x++)
			printl(".");
	}

	for (list< CView* >::iterator i = children.begin(); i != children.end(); i++)
		(*i)->paint();


}

bool CGroup::handleEvent(int key)
{
	if (!children.empty() && children.back()->handleEvent(key))
		return true;

	if (key == '\t')
	{
		if (!children.empty())
		{
			children.push_front(children.back());
			children.pop_back();
		};
		return true;
	}

	return false;
}

void CGroup::insert(CView* v)
{
	children.push_back(v);
}

CGroup::~CGroup()
{
	for (list< CView* >::iterator i = children.begin(); i != children.end(); i++)
		delete(*i);


}



CDesktop::CDesktop()
	: CGroup(CRect())
{
	init_screen();
	update_screen();
}

CDesktop::~CDesktop()
{
	done_screen();
}

void CDesktop::paint()
{
	getscreensize(geom.size.y, geom.size.x);

	for (int y = geom.topleft.y; y < geom.topleft.y + geom.size.y; y++)
	{
		gotoyx(y, geom.topleft.x);
		for (int x = 0; x < geom.size.x; x++)
			printl(".");
	}

	CGroup::paint();
}

int CDesktop::getEvent()
{
	return ngetch();
}

void CDesktop::run()
{
	update_screen();
	paint();
	refresh();

	while (TRUE)
	{
		int c = getEvent();

		if (c == 'q' || c == 'Q')
			break;

		if (c == KEY_RESIZE || handleEvent(c))
		{
			update_screen();
			paint();
			refresh();
		}
	}
}
