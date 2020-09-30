#include<iostream>
#include<cstring>
using namespace std;

int main() {

    // Declaring the Strings
    char name1[] = "ACES";
    char name2[] = "DYPCOE";
    char fullName[] = "ACES-DYPOCE";
    char copiedString[20];
    

    // Copying String 
    strcpy(copiedString, fullName);
    cout<<"Copied String: "<<copiedString<<endl;

    // Calculating the length of the String
    int length =strlen(name2);
    cout<<"length of DYPCOE: "<<length<<endl;
    
    // Comparing the Strings
    int compare = strcmp(name1,name2);
    cout<<"Compare the Strings: "<<compare<<endl;
    
     
      // Find first occurrence of name1 in fullName 
    char *p = strstr(fullName, name1); 
  
        if (p) { 
            cout<<"\"Aces\" String found in \"ACES-DYPOCE\""<<endl; 
        } 
        else {
            cout<<"String not found"<<endl; 
        }

    // Concatenation of two Strings
    strcat(name1, name2);
    cout<<"Concatenation: "<<name1<<endl;


    

    return 0;
}

