#include <map>
#include <iostream>
#include <fstream>

using namespace std;

class  compare {
public:
    bool operator() (int a, int b) {
        return a / 10 < b / 10;
    }
};

int main() {
    map<int, double, compare> histogram;
    ifstream f("filename.txt");
    int count;
    while (f) {
        int val;
        f >> val;
        if (!f)
            break;
        histogram[val]++;
        count++;
    }
    for (int i = 0; i <= 100; i += 10) {
        cout << i << "s:";
        for (int j = 0; j < histogram[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}