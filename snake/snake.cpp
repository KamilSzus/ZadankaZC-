#include <stdlib.h>
#include "snake.h"
#include "screen.h"

namespace
{
const char FOOD = '@';
const char HEAD = '>';
const char TAIL = '-';
}

CSnake::CSnake(CRect r, char _c /*=' '*/)
	: CFramedWindow(r, _c)
	, m_info(true)
	, m_pause(false) 
	, m_level(1)
	, m_score(0) 
	, m_speed(1.0)
	, m_dir(Right)
{
	Reset();
}


void CSnake::paint()
{
	CFramedWindow::paint();

	int left = geom.topleft.x;
	int top = geom.topleft.y;

	gotoyx(top - 1, left);
	printl("| Level: %d |", m_level);

	gotoyx(top + m_foodPos.y, left + m_foodPos.x);
	printc(FOOD);

	PrintSnake();

	if (m_info)
	{
		PrintInfo();
	}
}


bool CSnake::handleEvent(int key)
{
	if (key == 'r' || key == 'R')
	{
		Reset();
		return true;
	}

	if (key == 'p' || key == 'P')
	{		
		m_pause = !m_pause;
		return true;
	}	

	if (key == 'h' || key == 'H')
	{
		m_info = !m_info;
		return true;
	}

	if (m_info || m_pause)
	{
		if (CFramedWindow::handleEvent(key))
			return true;
	}
	else // if (!m_info && !m_pause)
	{
		if (key == KEY_LEFT && m_dir != Right)
		{
			m_dir = Left;
		}
		else if (key == KEY_RIGHT && m_dir != Left)
		{
			m_dir = Right;
		}
		else if (key == KEY_DOWN && m_dir != Up)
		{
			m_dir = Down;
		}
		else if (key == KEY_UP && m_dir != Down)
		{
			m_dir = Up;
		}

		StartTimer();
		return true;
	}

	return false;
}

void CSnake::Reset()
{
	m_info = true;
	m_pause = false;

	m_level = 1;
	m_score = 0; 

	m_speed = 1.0;
	m_dir = Right;

	m_foodPos.x = geom.size.x / 2;
	m_foodPos.y = geom.size.y / 2;
	// m_foodPos = geom.topleft;
	// m_foodPos += CPoint(geom.size.x / 2, geom.size.y / 2);

	m_body.clear();
	m_body.reserve(50);

	m_body.push_back(CPoint(4, 2)); // m_body.push_back({3, 2});
	m_body.push_back(CPoint(3, 2));
	m_body.push_back(CPoint(2, 2));
}

void CSnake::PrintInfo()
{
	int left = geom.topleft.x;
	int top = geom.topleft.y;

	gotoyx(top + 4, left + 2);
	printl("h - toggle help information");	
		
	gotoyx(top + 5, left + 2);
	printl("p - toggle pause/play mode");

	gotoyx(top + 6, left + 2);
	printl("r - reset game");

	gotoyx(top + 7, left + 2);
	printl("arrows - move snake (in play mode) or");

	gotoyx(top + 8, left + 11);
	printl("move window (in pause mode)");
}

void CSnake::PrintSnake()
{
	int left = geom.topleft.x;
	int top = geom.topleft.y;

	// if (m_body.empty())
	{
		gotoyx(top + m_body.front().y, left + m_body.front().x);
		printc(HEAD);
	}

	for(size_t k = 1; k < m_body.size(); k++)
	{
		gotoyx(top + m_body[k].y, left + m_body[k].x);
		printc(TAIL);
	}
}

void CSnake::StartTimer()
{
	unsigned long long time = 50000000;

	while (m_speed * time > 1)
	{
		--time;
	}

	NextMove();
	paint();
}

void CSnake::NextMove()
{
	for(size_t k = m_body.size()-1; k > 0; k--)
	{
		m_body[k] = m_body[k-1]; 
	}

	switch (m_dir)
	{
		case Left:
		{
			m_body.front().x--;
			if (m_body.front().x < 1)
			{
				m_body.front().x = geom.size.x - 2;
			}
		}
		break;
	
		case Right:
		{
			m_body.front().x++;
			if (m_body.front().x > geom.size.x - 2)
			{
				m_body.front().x = 1;
			}
		}
		break;

		case Down:
		{
			m_body.front().y++;
			if (m_body.front().y > geom.size.y - 2)
			{
				m_body.front().y = 1;
			}
		}
		break;


		case Up:
		{
			m_body.front().y--;
			if (m_body.front().y < 1)
			{
				m_body.front().y = geom.size.y - 2;
			}
		}
		break;

		default:
		break;
	}

	if ((m_body.front().x == m_foodPos.x) && (m_body.front().y == m_foodPos.y))
	{
		m_score++;
		m_body.push_back(m_body.back());	

		m_foodPos.x = rand()%(geom.size.x-2)+1;		
		m_foodPos.y = rand()%(geom.size.y-2)+1;	

		// TO DO: verify if m_foodPos != m_body[1..N]	
	}

	m_level = m_score / 3;
	
	// TO DO: verify if 'head' != m_body[1..N]
	// TO DO: modify m_speed
}
