#include <iostream>     // std::cout
#include <algorithm>    // std::transform
#include <vector>       // std::vector
#include <functional>   // std::plus
#include <cctype>
#include <iostream>
#include <string>


int op_increase(int i) { return ++i; }

int main() {
    //std::vector<int> foo;
    //std::vector<int> bar;

    //// set some values:
    //for (int i = 1; i < 6; i++)
    //    foo.push_back(i * 10);                         // foo: 10 20 30 40 50

    //bar.resize(foo.size());                         // allocate space

    //std::transform(foo.begin(), foo.end(), bar.begin(), op_increase);
    //// bar: 11 21 31 41 51

    //// std::plus adds together its two arguments:
    //std::transform(foo.begin(), foo.end(), bar.begin(), foo.begin(), std::plus<int>());
    //// foo: 21 41 61 81 101

    //std::cout << "foo contains:";
    //for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
    //    std::cout << ' ' << *it;
    //std::cout << '\n';


    std::string s("hello");
    std::transform(s.begin()+1, s.end(), s.begin(),
        [](unsigned char c) -> unsigned char { return std::toupper(c); });

    std::vector<std::size_t> ordinals;
    std::transform(s.begin(), s.end(), std::back_inserter(ordinals),
        [](unsigned char c) -> std::size_t { return c; });

    std::cout << s << ':';
    for (auto ord : ordinals) {
        std::cout << ' ' << ord;
    }

    std::transform(ordinals.cbegin(), ordinals.cend(), ordinals.cbegin(),
        ordinals.begin(), std::plus<>{});

    std::cout << '\n';
    for (auto ord : ordinals) {
        std::cout << ord << ' ';
    }
    std::cout << '\n';

    return 0;
}