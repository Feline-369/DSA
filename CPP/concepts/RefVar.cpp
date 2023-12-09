#include <iostream>
using namespace std;

void update(int &l)
{
    l = l + 3;
}

int main()
{
    int i = 3;
    int &j = i;
    cout << i << endl;
    cout << j << endl;
    int k = 6;
    update(k);
    cout << k << endl;
    int a = 9;
    // error(a);
};
/* int& error(int& b){
    int num = 369;
    int &s = num;
    return s;
    //could not send as s is local variable as well as num
}*/
