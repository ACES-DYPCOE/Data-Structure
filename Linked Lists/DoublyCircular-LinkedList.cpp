///////////////////////////////////////////////////////////////////////////////////
//Name     :Manasi Mohan Wader                                                   //
//Program  :Doubly Circular Linked List                                            //
//Language :C++  (Object Oriented Approach)                                      //
//Functions:To perform Create, Insert, Delete operations on Doubly Circular      //
//                Linked List                                                    //
///////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////
// Slightly different approach ,with 'void' return type                          //
// Doubly Circular linked list is maintained using two pointers (head and tail)  //
// Due to which it is possible to traverse in reverse as well as forward direction.//
// There no as such termination ,because last node does not contain NULL value   //
///////////////////////////////////////////////////////////////////////////////////

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}NODE,*PNODE;
///////////////////////////////////////////////////////////////////////////////////

class DoublyCircularLL
{
    PNODE head,tail;                     //maintaining two pointers
    //there is no as such termination in CLL unlike linear linkedlist
    int ct;
    public:
            DoublyCircularLL();          //constructor
            ~DoublyCircularLL();         //To deallocate the used memory

            void InsertFirst(int);
            void InsertLast(int);
            void InsertAtPos(int,int);

            void DeleteFirst();
            void DeleteLast();
            void DeleteAtPos(int);

            void DisplayCLL();           //to Display the Linked List
            int Count();                //Display total number of nodes present in Linked List
};
///////////////////////////////////////////////////////////////////////////////////
//Initializing memory
DoublyCircularLL::DoublyCircularLL()
{
    head=tail=NULL;
    ct=0;
}
///////////////////////////////////////////////////////////////////////////////////
//To get total number of nodes/elements present in the Linked List
int DoublyCircularLL::Count()
{
    //do-while loop can also be used here
    ct=0;
    PNODE temp=head;
    while(temp->next!=head)
    {
        ct++;
        temp=temp->next;
    }
    ct++;
    return ct;
}
///////////////////////////////////////////////////////////////////////////////////
//Display entire Linked List
void DoublyCircularLL::DisplayCLL()
{
    PNODE temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<" ";
}
///////////////////////////////////////////////////////////////////////////////////
//Inserting element at the beginning of Linked List
void DoublyCircularLL::InsertFirst(int n)
{
    PNODE temp=head;
    PNODE newn=new node;
    newn->data=n;
    newn->next=NULL;
    newn->prev=NULL;

    //Empty linked list
    if(head==NULL && tail==NULL)
    {
        head=newn;
        tail=newn;
    }
    //multiple nodes
    else
    {
        newn->next=head;
        newn->prev=tail;
        head->prev=newn;
        head=newn;
    }
        tail->next=head;
}
///////////////////////////////////////////////////////////////////////////////////
//Inserting element at the end of Linked List
void DoublyCircularLL::InsertLast(int n)
{
    PNODE temp=head;
    PNODE newn=new node;
    newn->data=n;
    newn->next=NULL;
    if(head==NULL && tail==NULL)
    {
        head=newn;
        tail=newn;
    }
    else
    {
        newn->prev=tail;
        tail->next=newn;
        tail=newn;
    }
     tail->next=head;  
}
///////////////////////////////////////////////////////////////////////////////////
//Inserting element at desired Position in the Linked List
void DoublyCircularLL::InsertAtPos(int pos,int n)
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
void DoublyCircularLL::DeleteFirst()
{
    //Empty Linked list
    if(head==NULL && tail==NULL)
    {
        cout<<"\nNothing to delete";
        return;
    }

    //Linked list containing only one element
    else if(head==tail)         
    {
        delete head;
        head=tail=NULL;
    }
    //Multiple nodes
    else
    {
        head=head->next;
        delete tail->next;
        tail->next=head;
        head->prev=tail;
    }
}
///////////////////////////////////////////////////////////////////////////////////
//Delete last element from the Linked List
void DoublyCircularLL::DeleteLast()
{
    //Empty Linked list
    if(head==NULL && tail==NULL)
    {
        cout<<"\nNothing to delete";
        return;
    }

    //Linked list containing only one element
    else if(head==tail)         
    {
        delete tail;
        head=tail=NULL;
    }
    //Multiple nodes
    else
    {
        PNODE temp=head;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        temp->next=head;
        tail=temp;
        head->prev=tail;     
    }
}
///////////////////////////////////////////////////////////////////////////////////
//Delete element from desired position in the Linked List
void DoublyCircularLL::DeleteAtPos(int pos)
{
    int tot=Count();
    if(head==NULL && tail==NULL)
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
DoublyCircularLL::~DoublyCircularLL()
{
    PNODE temp=head;
    if(head==NULL && tail==NULL)
        return;
    else
    {
        while(head!=tail)
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
    DoublyCircularLL obj;

    //Here one can opt for menu driven approach also!
    obj.InsertFirst(30);
    obj.DisplayCLL();cout<<"\n";
    obj.InsertFirst(20);
    obj.DisplayCLL();cout<<"\n";
    obj.InsertFirst(10);
    obj.DisplayCLL();
    cout<<"\nSuccessfully inserted element from beginning";
    cout<<"Total number of elements "<<obj.Count()<<"\n\n";

    obj.InsertLast(40);
    obj.DisplayCLL();cout<<"\n";
    obj.InsertLast(70);
    obj.DisplayCLL();
    cout<<"\nSuccessfully inserted element at end";
    cout<<"\nTotal number of elements "<<obj.Count()<<"\n\n";

    obj.InsertAtPos(5,100);
    obj.DisplayCLL();cout<<"\n";
    obj.InsertAtPos(1,200);
    obj.DisplayCLL();
    cout<<"\nSuccessfully inserted element at desired position";
    cout<<"\nTotal number of elements "<<obj.Count()<<"\n\n";

    obj.DeleteFirst();
    obj.DisplayCLL();cout<<"\n"; 
    obj.DeleteFirst();
    obj.DisplayCLL();cout<<"\n"; 
    cout<<"Successfully deleted 2 elements from beginning\n";
    obj.DisplayCLL();
    cout<<"\nTotal number of elements "<<obj.Count()<<"\n\n";

    obj.DeleteLast();    
    cout<<"Successfully deleted 1 element from end\n";
    obj.DisplayCLL();
    cout<<"\nTotal number of elements "<<obj.Count()<<"\n\n";

    obj.DeleteAtPos(2);
    obj.DisplayCLL();cout<<"\n";
    obj.DeleteAtPos(1);
    obj.DisplayCLL();cout<<"\n";
    cout<<"Successfully deleted element from desired position (1 and 2)\n";
    obj.DisplayCLL();cout<<"\n";
    cout<<"\nTotal number of elements "<<obj.Count()<<"\n";
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////
//End of program                                                                 //
///////////////////////////////////////////////////////////////////////////////////