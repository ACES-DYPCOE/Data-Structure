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

class CircularQueue
{
    PNODE head,tail;                     //maintaining two pointers
    //there is no as such termination in CLL unlike linear linkedlist
    int ct;
    public:
            CircularQueue();          //constructor
            ~CircularQueue();         //To deallocate the used memory

            void Insert(int);
 
            void Remove();
        
            void DisplayQueue();           //to Display the Queue
            int Count();                //Display total number of nodes present in Linked List
};
///////////////////////////////////////////////////////////////////////////////////
//Initializing memory
CircularQueue::CircularQueue()
{
    head=tail=NULL;
    ct=0;
}
///////////////////////////////////////////////////////////////////////////////////
//To get total number of nodes/elements present in the Linked List
int CircularQueue::Count()
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
void CircularQueue::DisplayQueue()
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
//Inserting element at the end of Linked List
void CircularQueue::Insert(int n)
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
//Delete first element of Linked List
void CircularQueue::Remove()
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
//Destructor:  to deallocate the used memory 
CircularQueue::~CircularQueue()
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
    CircularQueue obj;

    //Here one can opt for menu driven approach also!
    cout<<"\n";
    obj.Insert(40);
    obj.DisplayQueue();
    obj.Insert(70);cout<<"\n";
    obj.DisplayQueue();
    obj.Insert(100);cout<<"\n";
    obj.DisplayQueue();
    cout<<"\nSuccessfully inserted in queue";
    obj.DisplayQueue();cout<<"\n";
    cout<<"\nTotal number of elements "<<obj.Count()<<"\n\n";

    obj.Remove(); 
    obj.DisplayQueue();cout<<"\n";   
    obj.Remove();
    obj.DisplayQueue();cout<<"\n";
    cout<<"Successfully removed 2 element from queue\n";
    obj.DisplayQueue();cout<<"\n";
    cout<<"Total number of elements "<<obj.Count()<<"\n\n";

    obj.Insert(130);cout<<"\n";
    obj.DisplayQueue();
    obj.Insert(160);cout<<"\n";
    obj.DisplayQueue();
    cout<<"\nSuccessfully inserted in queue\n";
    obj.DisplayQueue();
    cout<<"\nTotal number of elements "<<obj.Count()<<"\n\n";
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////
//End of program                                                                 //
///////////////////////////////////////////////////////////////////////////////////
