#include <vector>

using namespace std;



class CContainer
{
protected:
    vector<int> Data;

public:
    CContainer() {}
    virtual ~CContainer() {}
    virtual bool push(int) = 0;
    virtual int pop() = 0;

    virtual size_t getSizeLimit() = 0;
};



class CLimitedStack : virtual public CContainer
{
public:
    ~CLimitedStack() {}

    bool push(int) {
        return true;
    }

    int pop() {
        return 0;
    }

    size_t getSizeLimit() {
        return SizeLimit;
    }

private:
    static size_t SizeLimit;
};