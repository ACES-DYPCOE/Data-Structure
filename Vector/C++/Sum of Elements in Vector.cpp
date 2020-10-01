#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    int n;
    cout<<"Enter no. of Elements : ";
    cin>>n;
    
    vector<int> v; 
    int a;
    
    cout<<"Enter the Elements : ";
    for(int  i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    
    cout << "\nVector: "; 
    for (int i = 0; i < n ;i++) 
        cout << v[i] << " "; 
    cout << endl; 
  
    cout << "\nSum = "
         << accumulate(v.begin(), v.end(), 0); 
    return 0; 
} 