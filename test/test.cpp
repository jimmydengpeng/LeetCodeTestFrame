#include <iostream>
#include "test.h"
using namespace std;

void hw()
{
    cout << "hello world!" << endl;
}

void swap2(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}
