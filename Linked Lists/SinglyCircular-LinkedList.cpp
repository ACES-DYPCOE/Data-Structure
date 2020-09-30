///////////////////////////////////////////////////////////////////////////////////
//Name     :Manasi Mohan Wader                                                   //
//Program  :Singly Circular Linked List                                          //
//Language :C++  (Object Oriented Approach)                                      //
//Functions:To perform Create, Insert, Delete operations on Circular Linked List          //
///////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////
// Slightly different approach ,with 'void' return type                          //
///////////////////////////////////////////////////////////////////////////////////

typedef struct node
{
    int data;
    struct node* next;
}NODE,*PNODE;
///////////////////////////////////////////////////////////////////////////////////

class SinglyCircularLL
{
    PNODE head,tail;                     //maintaining two pointers
    //there is no as such termination in CLL unlike linear linkedlist
    int ct;
    public:
            SinglyCircularLL();          //constructor
            ~SinglyCircularLL();         //To deallocate the used memory

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
SinglyCircularLL::SinglyCircularLL()
{
    head=tail=NULL;
    ct=0;
}
///////////////////////////////////////////////////////////////////////////////////
//To get total number of nodes/elements present in the Linked List
int SinglyCircularLL::Count()
{
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
void SinglyCircularLL::DisplayCLL()
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
void SinglyCircularLL::InsertFirst(int n)
{
    PNODE temp=head;
    PNODE newn=new node;
    newn->data=n;
    newn->next=NULL;

    //Empty linked list
    if(head==NULL && tail==NULL)
    {
        head=newn;
        tail=newn;
    }else
    {
        newn->next=head;
        head=newn;
    }
        tail->next=head;
}
///////////////////////////////////////////////////////////////////////////////////
//Inserting element at the end of Linked List
void SinglyCircularLL::InsertLast(int n)
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
        tail->next=newn;
        tail=tail->next;
    }
     tail->next=head;
   
}
///////////////////////////////////////////////////////////////////////////////////
//Inserting element at desired Position in the Linked List
void SinglyCircularLL::InsertAtPos(int pos,int n)
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
        for(int i=1;i<tot-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }  
}
///////////////////////////////////////////////////////////////////////////////////
//Delete first element of Linked List
void SinglyCircularLL::DeleteFirst()
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
    }
}
///////////////////////////////////////////////////////////////////////////////////
//Delete last element from the Linked List
void SinglyCircularLL::DeleteLast()
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
        delete tail;
        tail=temp;
        tail->next=head;
    }
}
///////////////////////////////////////////////////////////////////////////////////
//Delete element from desired position in the Linked List
void SinglyCircularLL::DeleteAtPos(int pos)
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
        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        curr=temp->next;
        temp->next=curr->next;
        delete curr;
    }  
}
///////////////////////////////////////////////////////////////////////////////////
//Destructor:  to deallocate the used memory 
SinglyCircularLL::~SinglyCircularLL()
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
    SinglyCircularLL obj;

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