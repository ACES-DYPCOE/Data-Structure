///////////////////////////////////////////////////////////////////////////////////
//Name     :Manasi Mohan Wader                                                   //
//Program  :Doubly Linear Linked List                                            //
//Language :C++  (Object Oriented Approach)                                      //
//Functions:To perform Create, Insert, Delete operations on Doubly Linear        //
//                Linked List                                                    //
///////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////
// Slightly different approach ,with 'void' return type                          //
// Doubly linear linked list is maintained using two pointers                    //
// Due to which it is possible to traverse in reverse as well as forward direction.//
///////////////////////////////////////////////////////////////////////////////////

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}NODE,*PNODE;
///////////////////////////////////////////////////////////////////////////////////

class DoublyLinearLL
{
    PNODE head;
    int ct;
    public:
            DoublyLinearLL();          //constructor
            ~DoublyLinearLL();         //To deallocate the used memory

            void InsertFirst(int);
            void InsertLast(int);
            void InsertAtPos(int,int);

            void DeleteFirst();
            void DeleteLast();
            void DeleteAtPos(int);

            void DisplayDLL();           //to Display the Linked List
            int Count();                //Display total number of nodes present in Linked List
};
///////////////////////////////////////////////////////////////////////////////////
//Initializing memory
DoublyLinearLL::DoublyLinearLL()
{
    head=NULL;
    ct=0;
}
///////////////////////////////////////////////////////////////////////////////////
//To get total number of nodes/elements present in the Linked List
int DoublyLinearLL::Count()
{
    ct=0;
    PNODE temp=head;
    while(temp!=NULL)
    {
        ct++;
        temp=temp->next;
    }
    return ct;
}
///////////////////////////////////////////////////////////////////////////////////
//Display entire Linked List
void DoublyLinearLL::DisplayDLL()
{
    PNODE temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
///////////////////////////////////////////////////////////////////////////////////
//Inserting element at the beginning of Linked List
void DoublyLinearLL::InsertFirst(int n)
{
    PNODE newn=new node;
    newn->data=n;
    newn->next=NULL;
    newn->prev=NULL;
    if(head==NULL)
    {
        head=newn;
    }
    else
    {
        newn->next=head;
        head->prev=newn;
        head=newn;
    }
}
///////////////////////////////////////////////////////////////////////////////////
//Inserting element at the end of Linked List
void DoublyLinearLL::InsertLast(int n)
{
    PNODE temp=head;
    PNODE newn=new node;
    newn->data=n;
    newn->next=NULL;
    newn->prev=NULL;

    if(head==NULL)
    {
        head=newn;
    }
    else
    {
        while(temp->next!=NULL)
        {
         temp=temp->next;
        }
        temp->next=newn;
        temp->next->prev=temp;
    }
}
///////////////////////////////////////////////////////////////////////////////////
//Inserting element at desired Position in the Linked List
void DoublyLinearLL::InsertAtPos(int pos,int n)
{
    int tot=Count();
    if(pos<1 || pos>tot+1)
    {
        cout<<"\nPosition invalid (element cannot be inserted";
        return;
    }
    else if(pos==1)
    {
        //To insert element at beginning
        InsertFirst(n);
    }
    else if(pos==tot+1)
    {
        //To insert element at end
        InsertLast(n);
    }
    else
    {
        PNODE temp=head;
        PNODE newn=new node;
        newn->next=NULL;
        newn->data=n;
        for(int i=1;i<tot;i++)
        {
            temp=temp->next;
        }
        newn->next=temp;
        newn->prev=temp->prev;
        temp->prev->next=newn;
        temp->prev=newn;
    }  
}
///////////////////////////////////////////////////////////////////////////////////
//Delete first element of Linked List
void DoublyLinearLL::DeleteFirst()
{
    if(head==NULL)
    {
        cout<<"\nNothing to delete";
        return;
    }
    else
    {
        PNODE temp=head;
        temp->next->prev=NULL;
        head=head->next;
        delete temp;
    }
}
///////////////////////////////////////////////////////////////////////////////////
//Delete last element from the Linked List
void DoublyLinearLL::DeleteLast()
{
    if(head==NULL)
    {
        cout<<"\nNothing to delete\n";
        return;
    }
    else if(head->next==NULL)
    {
        delete head;
        head=NULL;
    }
    else
    {
        PNODE temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=NULL;
        delete temp;
    }
}
///////////////////////////////////////////////////////////////////////////////////
//Delete element from desired position in the Linked List
void DoublyLinearLL::DeleteAtPos(int pos)
{
    int tot=Count();
    if(head==NULL)
    {
        cout<<"\nNothing to delete\n";
        return;
    }
    if(pos<1 || pos>tot)
    {
        cout<<"\nPosition invalid\n";
    }
    else if(pos==1)
    {
        DeleteFirst();
    }
    else if(pos==tot)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp=head;
        PNODE curr=NULL;
        for(int i=1;i<pos;i++)
        {
            temp=temp->next;
        }
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        delete temp;
    }  
}
///////////////////////////////////////////////////////////////////////////////////
//Destructor:  to deallocate the used memory 
DoublyLinearLL::~DoublyLinearLL()
{
    PNODE temp=head;
    if(head==NULL)
        return;
    else if(head!=NULL)
    {
        while(head!=NULL)
        {
            head=head->next;
            delete temp;
            temp=head;
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////
//main function of the program
///////////////////////////////////////////////////////////////////////////////////
int main()
{
    DoublyLinearLL obj;

   //Here one can opt for menu driven approach also!
    obj.InsertFirst(30);
    obj.DisplayDLL();cout<<"\n";
    obj.InsertFirst(20);
    obj.DisplayDLL();cout<<"\n";
    obj.InsertFirst(10);
    obj.DisplayDLL();
    cout<<"\nSuccessfully inserted element from beginning";
    cout<<"Total number of elements "<<obj.Count()<<"\n\n";

    obj.InsertLast(40);
    obj.DisplayDLL();cout<<"\n";
    obj.InsertLast(70);
    obj.DisplayDLL();
    cout<<"\nSuccessfully inserted element at end";
    cout<<"\nTotal number of elements "<<obj.Count()<<"\n\n";

    obj.InsertAtPos(5,100);
    obj.DisplayDLL();cout<<"\n";
    obj.InsertAtPos(1,200);
    obj.DisplayDLL();
    cout<<"\nSuccessfully inserted element at desired position";
    cout<<"\nTotal number of elements "<<obj.Count()<<"\n\n";

    obj.DeleteFirst();
    obj.DisplayDLL();cout<<"\n"; 
    obj.DeleteFirst();
    obj.DisplayDLL();cout<<"\n"; 
    cout<<"Successfully deleted 2 elements from beginning\n";
    obj.DisplayDLL();
    cout<<"\nTotal number of elements "<<obj.Count()<<"\n\n";

    obj.DeleteLast();    
    cout<<"Successfully deleted 1 element from end\n";
    obj.DisplayDLL();
    cout<<"\nTotal number of elements "<<obj.Count()<<"\n\n";

    obj.DeleteAtPos(2);
    obj.DisplayDLL();cout<<"\n";
    obj.DeleteAtPos(1);
    obj.DisplayDLL();cout<<"\n";
    cout<<"Successfully deleted element from desired position (1 and 2)\n";
    obj.DisplayDLL();cout<<"\n";
    cout<<"\nTotal number of elements "<<obj.Count()<<"\n";
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////
//End of program                                                                 //
///////////////////////////////////////////////////////////////////////////////////