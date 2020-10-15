#include <iostream>
#include <stack>

using namespace std;

//function to dispay stack
void dispStack(stack <int> st){
    //declare temp. statck
    stack <int> s = st;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

//Main function for stack program
int main()
{
   //declare stack variable
   stack <int> st;
   
   //insert elements
   st.push(10);
   st.push(20);
   st.push(30);
   st.push(40);
   st.push(50);
   
   //display stack coun, top element and stack elements
   cout<<"Total stack elements are: "<<st.size()<<endl;
   cout<<"Top elements is: "<<st.top()<<endl;
   cout<<"All stack elements are: "<<endl;
   dispStack(st);
   
   //removing two stack elements
   st.pop();
   st.pop();
   
   cout<<"\nAfter removing two elements...\n";
    
   //display stack coun, top element and stack elements
   cout<<"Total stack elements are: "<<st.size()<<endl;
   cout<<"Top elements is: "<<st.top()<<endl;
   cout<<"All stack elements are: "<<endl;
   dispStack(st);   
   
   return 0;
}

/*
OUTPUT:
Total stack elements are: 5
Top elements is: 50
All stack elements are:
50 40 30 20 10

After removing two elements...
Total stack elements are: 3
Top elements is: 30
All stack elements are:
30 20 10
*/