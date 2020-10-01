// To calculate the steps reequired in complaeting Tower of Hanoi challenge
#include <iostream>
using namespace std;

void TOH (int n, int A, int B, int C)
{
    if(n>0)
    {
        TOH(n-1, A, C, B);
        cout<<"("<<A<<" - "<<C<<")\n";
        TOH(n-1, B, A, C);
    }
}

int main ()
{   
    TOH(4, 1, 2, 3);

    return 0;
}