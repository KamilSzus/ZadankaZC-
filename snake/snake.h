#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <vector>

#include "cpoint.h"
#include "winsys.h"

enum Dir
{
	None  = 0,
	Left  = 1, // (-1,0)
	Right = 2, // (1,0)
	Down  = 3, // (0,-1)
	Up    = 4  // (0,1)
};

class CSnake
	: public CFramedWindow
{
public:
	CSnake(CRect r, char _c = ' ');

	void paint();
	bool handleEvent(int key);

private:
	bool m_info;
	bool m_pause;

	size_t m_level;
	size_t m_score; 

	double m_speed;	
	Dir m_dir;
	CPoint m_foodPos;

	std::vector<CPoint> m_body;

	void Reset();

	void PrintInfo();
	void PrintSnake();

	void StartTimer();
	void NextMove();
};

#endif
