// mind blowing algorithm I learned recently
// the follwing recursive funtion helps to calculate the exponent of a number.( even large numbers can be accomodated without memory overflow)
// time complexity O(logn)

#include <iostream>

using namespace std;

int fastexpor(int a, long long n, int mod)
{
    if(n==0)
        return 1;
    if(n%2==0)
        return fastexpor((1LL * a * a)%mod, n/2 , mod);
    return (1LL * a * fastexpor(a, n-1, mod))%mod;

}


int main()
{
    int base, exponent;
    cout<<"enter the base of the exponent you want to calculate"<<endl;
    cin>>base;
    cout<<"enter the exponent for the base"<<endl;
    cin>>exponent;
    cout<<base<<" raised to the power "<<exponent<<" is: "<<fastexpor(base,exponent,1000007)<<endl;
    return 0;
}
