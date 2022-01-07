
class stack
{
public:
	void push(int a);
	int pop();
	void clear();
	stack();//konstruktor musi miec nazwe jak nazwa klasy
	// explicit stack(int p) {}
	~stack();//destruktor musi miec nazwe jak nazwa klasy
	stack(const stack& src);//konstruktor kopiujac copy C-tor
	stack& operator=(const stack& src);

	//stack(const stack&& src);//konstruktor przenoszacy move C-tor
	//stack& operator=(const stack&& src);

	bool operator==(const stack& src) const;
	bool operator!=(const stack& src) const;

private:
	int m_top;
	size_t m_size;
	int* m_data;
	void allocation(size_t count);
};

