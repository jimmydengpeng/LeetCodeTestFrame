#include <iostream>
#include "test.h"
using namespace std;

int main(int argc, char const *argv[])
{
    hw();
    int a, b;
    a = 5;
    b = 8;
    cout << a << b << endl;
    swap2(a, b);
    cout << a << b << endl;
    swap(a, b);
    cout << a << b << endl;
    return 0;
}
