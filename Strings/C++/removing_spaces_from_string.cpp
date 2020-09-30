#include<bits/stdc++.h>
using namespace std; 
  
// Function to remove all spaces from a given string 
void removeSpaces(char *str) 
{ 
    // To keep track of non-space character count 
    int count = 0; 
  
    // Traverse the given string. If current character 
    // is not space, then place it at index 'count++' 
    for (int i = 0; str[i]; i++) 
        if (str[i] != ' ') 
            str[count++] = str[i]; 
    str[count] = '\0'; 
} 
  

int main() 
{ 
    char str[] = "AC ES  -D   YP   CO  E  "; 
    removeSpaces(str); 
    cout << str<<endl; 
    return 0; 
} 