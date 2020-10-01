#include<iostream>
int pass = 0;

using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

Node* swapping(Node* p1, Node* p2){
    int temp = p1->data;
    p1->data = p2->data;
    p2->data = temp;
}

Node* display(Node* head, int n){
   for(int i=0;i<n;i++){
       cout<<head->data<<" ";
       head = head->next;

   }
}

void sort(Node *head, int n){
   int swaps = 0;
    Node *ptr1 = head;
    Node *ptr2 = ptr1->next;

    for(int i = 0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
        if(ptr1->data > ptr2->data) {     
                swapping(ptr1, ptr2);
                swaps = 1;  

            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;

        }
      ptr1 = head;
      ptr2 = ptr1->next;
      if(!swaps)
         break;      
         pass = pass+1;
   }
 }

Node* insert(Node *head, int n){
    Node *ptr = head;
    for(int i = 0;i<n;i++){
        cout<<"Enter the value "<<i+1<<" : ";
        cin>>ptr->data;
        if(i==n-1){
            break;
        }
        ptr->next = new Node();
        ptr = ptr->next;
    }
    ptr->next = NULL;

}
int main(){
    int n, val;
    Node* head = NULL;
    head = new Node();
    cout<<"Enter the no of elements: ";
    cin>>n;
    insert(head, n);
    cout<<"Linkedlist before sorting : ";
    display(head, n);
   
    cout<<"\nLinkedlist after sorting : ";
    sort(head, n);
    display(head, n);
    cout<<"\nNo. of passes : "<<pass;
   
}
