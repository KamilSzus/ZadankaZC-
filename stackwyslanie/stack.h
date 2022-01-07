#pragma
#ifndef STACK_H
#define STACK_H


class stack
{
public:
	void push(int a);
	int pop();
	void clear();
	stack();
	~stack();
private:
	int m_top;
	size_t m_size;
	int* m_data;
	void allocation(size_t count);
};

#endif // STACK