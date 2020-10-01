#include<bits/stdc++.h>
using namespace std;

int main() {

    //Declaring String
    string name1 = "ACES "; 
    string name2 = "DYPCOE";

    // Direct Concatenation
    cout<<"Direct Concatenation : "<< name1 + name2 <<endl; 

    // Concatenation and storing in another string
    string fullName1 = name1 + name2; 
    cout<<"Concatenation using another string : "<<fullName1 << endl; 

    // Concatenation using append function
    string fullName2 = name1.append(name2); 
    cout<<"Concatenation using append function : "<<fullName2 << endl;

    return 0;
}