#include<bits/stdc++.h>
using namespace std;

int main() {

    //Declaring String
    string name1 = "ACES-DYPCOE"; 
    char myString[] = "ACES-DYPCOE";

    //calculating length using length() function
    cout<<"using Length() : "<<name1.length()<<endl;

    //calculating length using size() function
    cout<<"using size() : "<<name1.size()<<endl;

    //calculating length using strlen() function
    cout<<"using strlen() : "<<strlen(myString)<<endl;
    
    //calculating length using for loop
    int count =0;
    for(int i = 0; myString[i] != '\0'; i++){
      count++;
   }
    cout<<"using for loop : "<<count<<endl;

    return 0;
}