#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
      int data;
      struct Node*next;
}Node;

Node* insert(Node*head ,int x )  //function to insert node in ll
{ 
     //New node to be inserted
       Node * p = new Node;
        p->data = x;
        p->next = NULL;
    //if it's first node 
       if(head == NULL)
       {
              head = p;
       }
       
      //if head node is there 
       
     else{
        Node*temp = head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
         }
         temp->next = p;
         }
     return head;
}

Node* reverse(Node*head)     //function to reverse
    { 
        // Initialize current, previous and 
        // next pointers 
        Node* current = head; 
        Node *prev = NULL, *next = NULL; 
  
        while (current != NULL) { 
            // Store next 
            next = current->next; 
  
            // Reverse current node's pointer 
            current->next = prev; 
  
            // Move pointers one position ahead. 
            prev = current; 
            current = next; 
        } 
        head = prev;
        return head; 
    } 

void print(Node*head)
{
     Node*temp = head;
     while(temp!=NULL)
     {
          cout<<temp->data<<" ";
          temp=temp->next;
      }
      
}

int main()
{

     Node * head = NULL;  //initilaise head to NULL
     head = insert(head,1);     
     head = insert(head,2);
     head = insert(head,3);
     print(head);
     head = reverse(head);    //reverse linked list
     print(head);
     
return 0;

}

// Time Complexity: O(n)

