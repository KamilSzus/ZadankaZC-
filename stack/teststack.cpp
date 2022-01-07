#include <cstdio>
#include "stack.h"

void print(stack s)
{
	printf("%d\n", s.pop());
}
int main()
{
	{
		stack s1;
		stack s2;
		s1.push(1);
		s1.push(2);
		s1.push(3);
		s2.push(5);
		s2.push(6);
		printf("%d %d\n", s1.pop(), s1.pop());
		printf("%d\n", s1.pop());
		//printf("%d\n", s1.pop());
		{
			stack s3(s2);
			//stack s3 = s2;
			print(s2);
			printf("usuwanie kopi s2\n");

			s3 = s1; // s3.operator=(s1);
		}
		printf("usuwanie s3\n");
	}
	printf("przed zamknieciem");

	return 0;
}
