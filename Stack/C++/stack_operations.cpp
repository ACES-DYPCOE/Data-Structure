/*Stack is a linear data structure which follows a particular order in which the operations are performed.
The order may be LIFO(Last In First Out) or FILO(First In Last Out).

Mainly the following three basic operations are performed in the stack:

1. Push: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.
2. Pop: Removes an item from the stack. The items are popped in the reversed order in which they are pushed. 
     If the stack is empty, then it is said to be an Underflow condition.
3. Peek or Top: Returns top element of stack.
isEmpty: Returns true if stack is empty, else false.
*/



/* C++ program to implement basic stack 
   operations */
#include <bits/stdc++.h> 
  
using namespace std; 
  
#define MAX 1000 
  
class Stack { 
    int top; 
  
public: 
    int a[MAX]; // Maximum size of Stack 
  
    Stack() { top = -1; } 
    bool push(int x); 
    int pop(); 
    int peek(); 
    bool isEmpty(); 
}; 
  
bool Stack::push(int x) 
{ 
    if (top >= (MAX - 1)) { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else { 
        a[++top] = x; 
        cout << x << " pushed into stack\n"; 
        return true; 
    } 
} 
  
int Stack::pop() 
{ 
    if (top < 0) { 
        cout << "Stack Underflow"; 
        return 0; 
    } 
    else { 
        int x = a[top--]; 
        return x; 
    } 
} 
int Stack::peek() 
{ 
    if (top < 0) { 
        cout << "Stack is Empty"; 
        return 0; 
    } 
    else { 
        int x = a[top]; 
        return x; 
    } 
} 
  
bool Stack::isEmpty() 
{ 
    return (top < 0); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    class Stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout << s.pop() << " Popped from stack\n"; 
  
    return 0; 
}




/*
Output :

10 pushed into stack
20 pushed into stack
30 pushed into stack
30 popped from stack
*/



/*
Time Complexity:
push(), pop(), isEmpty() and peek() all take O(1) time. 
We do not run any loop in any of these operations.
*/