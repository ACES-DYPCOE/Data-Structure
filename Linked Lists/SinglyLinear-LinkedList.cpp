///////////////////////////////////////////////////////////////////////////////////
//Name     :Manasi Mohan Wader                                                   //
//Program  :Singly Linear Linked List                                            //
//Language :C++  (Object Oriented Approach)                                      //
//Functions:To perform Create, Insert, Delete operations on Linked List          //
///////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////
// Slightly different approach ,with 'void' return type                           //
///////////////////////////////////////////////////////////////////////////////////

typedef struct node
{
    int data;
    struct node* next;
}NODE,*PNODE;
///////////////////////////////////////////////////////////////////////////////////

class SinglyLinearLL
{
    PNODE head;
    int ct;
    public:
            SinglyLinearLL();          //constructor
            ~SinglyLinearLL();         //To deallocate the used memory

            void InsertFirst(int);
            void InsertLast(int);
            void InsertAtPos(int,int);

            void DeleteFirst();
            void DeleteLast();
            void DeleteAtPos(int);

            void DisplayLL();           //to Display the Linked List
            int Count();                //Display total number of nodes present in Linked List
};
///////////////////////////////////////////////////////////////////////////////////
//Initializing memory
SinglyLinearLL::SinglyLinearLL()
{
    head=NULL;
    ct=0;
}
///////////////////////////////////////////////////////////////////////////////////
//To get total number of nodes/elements present in the Linked List
int SinglyLinearLL::Count()
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
void SinglyLinearLL::DisplayLL()
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
void SinglyLinearLL::InsertFirst(int n)
{
    PNODE temp=head;
    PNODE newn=new node;
    newn->data=n;
    newn->next=NULL;
    if(temp==NULL)
    {
        head=newn;
    }else if(temp!=NULL)
    {
        newn->next=head;
        head=newn; 
    }
}
///////////////////////////////////////////////////////////////////////////////////
//Inserting element at the end of Linked List
void SinglyLinearLL::InsertLast(int n)
{
    PNODE temp=head;
    PNODE newn=new node;
    newn->data=n;
    newn->next=NULL;
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
    }
}
///////////////////////////////////////////////////////////////////////////////////
//Inserting element at desired Position in the Linked List
void SinglyLinearLL::InsertAtPos(int pos,int n)
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
void SinglyLinearLL::DeleteFirst()
{
    if(head==NULL)
    {
        cout<<"\nNothing to delete";
        return;
    }
    else
    {
        PNODE temp=head;
        head=head->next;
        delete temp;
    }
}
///////////////////////////////////////////////////////////////////////////////////
//Delete last element from the Linked List
void SinglyLinearLL::DeleteLast()
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
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
}
///////////////////////////////////////////////////////////////////////////////////
//Delete element from desired position in the Linked List
void SinglyLinearLL::DeleteAtPos(int pos)
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
        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        curr=temp->next;
        temp->next=temp->next->next;
        delete curr;
    }  
}
///////////////////////////////////////////////////////////////////////////////////
//Destructor:  to deallocate the used memory 
SinglyLinearLL::~SinglyLinearLL()
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
    SinglyLinearLL obj;

    //Here one can opt for menu driven approach also!
    obj.InsertFirst(30);
    obj.InsertFirst(20);
    obj.InsertFirst(10);

    cout<<"\nSuccessfully inserted element from beginning\n";

    obj.DisplayLL();
    cout<<"\nTotal number of elements "<<obj.Count()<<"\n";

    obj.InsertLast(40);
    obj.InsertLast(70);

    cout<<"\nSuccessfully inserted element at end\n";

    obj.DisplayLL();
    cout<<"\nTotal number of elements "<<obj.Count()<<"\n";

    obj.InsertAtPos(5,100);
    obj.InsertAtPos(7,200);

    cout<<"\nSuccessfully inserted element at desired position\n";

    obj.DisplayLL();
    cout<<"\nTotal number of elements "<<obj.Count()<<"\n";

    obj.DeleteFirst();
    obj.DeleteFirst(); 

    cout<<"\nSuccessfully deleted element from beginning\n";

    obj.DisplayLL();
    cout<<"\nTotal number of elements "<<obj.Count()<<"\n";

    obj.DeleteLast();   
    obj.DeleteLast();
    obj.DeleteLast(); 
    
    cout<<"\nSuccessfully deleted element from end\n";

    obj.DisplayLL();
    cout<<"\nTotal number of elements "<<obj.Count()<<"\n";

    obj.DeleteAtPos(2);
    obj.DeleteAtPos(1);

    cout<<"\nSuccessfully deleted element from desired position (1 and 2)\n";

    obj.DisplayLL();
    cout<<"\nTotal number of elements "<<obj.Count()<<"\n";
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////
//End of program                                                                 //
///////////////////////////////////////////////////////////////////////////////////