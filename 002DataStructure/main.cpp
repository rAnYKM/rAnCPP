
#include "RanQueue.h"
#include <iostream>

using namespace std;

int main()
{
    RanQueue<int> ran(3);
    ran.push(1);
    ran.push(2);
    ran.push(3);
    RanQueue<int> ya(ran);
    RanDSBase<int> *jason = &ya;
    ran.push(4);
    cout << ran.pop() << endl;
    cout << ran.pop() << endl;
    cout << ran.pop() << endl;
    cout << ran.pop() << endl;
    ya.display();
    ran.display();
    jason->display();
    return 0;
}
