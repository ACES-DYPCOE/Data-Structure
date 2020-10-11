//Range Update trick
// The program allows you to update a range of array values.
//for eg. If we have an integer array of 10 elements and we want to update all the values from the 5th term to the 9th term by X(an integer) then we can use this programme
// the function takes in 3 arguments, the stating location, the ending location and the updatio value
// the following array takes in 10 numbers and updates the required values. Necessary changes can be made in the programme as per ypur suitability
// the time complexity of the follwing programme is constant time O(1)

#include<iostream>
using namespace std;

int a[11], b[11], c[11];
void updateval(int x, int y, int val)
{
    b[x-1] += val;
    b[y] -= val;
}

void buildfinalarray()
{
    for(int i=1; i<=10; i++)
    {
        c[i] = c[i-1]+b[i];
        a[i] += c[i];

    }
    for(int j=0; j<=10; j++)
    {
        cout<<a[j];
    }
}

int main()
{
    cout<<"enter the value for the array"<<endl;
    for (int i=0 ; i<10 ; i++)
    {
        cin>>a[i];
        b[i]=0;
        c[i]=0;
    }
    updateval(2,6,10);
    buildfinalarray();

    int n;
    cin>>n;
    return 0;


}
