#include <stdlib.h>
#include <time.h>
#include "winsys.h"
#include "snake.h"

int main()
{
	srand((unsigned int)time(NULL));

	CDesktop desktop;

	desktop.insert(new CInputLine(CRect(CPoint(5, 7), CPoint(15, 15)), '$'));
	

	desktop.insert(new CWindow(CRect(CPoint(2, 3), CPoint(20, 10)), '#'));
	

	desktop.insert(new CSnake(CRect(CPoint(5, 5), CPoint(45, 20))));

	desktop.run();


	return 0;
}
