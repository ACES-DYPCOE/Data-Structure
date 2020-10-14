#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class ArrayADT
{
private:
    int cap;
    int lastindex;
    int *p;
public:
    ArrayADT()
    {
        cap=0;
        lastindex=-1;
        p=NULL;
    }
     ~ArrayADT()
    {
        delete[]p;
    }
void create_array(int k);
void set_item(int index,int value);
int get_item(int index);
void edit_item(int index,int value);
void remove_item(int index);
int count_item();
void sort_item();
void reverse_item();
};
void ArrayADT::create_array(int k)
{
    cap=k;
    lastindex=-1;
    p=new int[k];
}
void ArrayADT::set_item(int index,int value)
{
    if(index<0 || index>lastindex+1)
        cout<<"Invalid index: "<<endl;
    else if(lastindex==cap-1)
        cout<<"Overflow:"<<endl;
    else if (index<=lastindex)
    {
        int i;
        i=++lastindex;
        while(i!=index)
        {
            p[i]=p[i-1];
            i--;
        }
        p[index]=value;
    }
    else
    {
        lastindex++;
        p[index]=value;
    }
}
int ArrayADT::get_item(int index)
{
    if(lastindex==-1)
        return -1;
    else if(index<0 || index>lastindex)
        cout<<"invalid Index :"<<endl;
    else
        return(p[index]);
}
void ArrayADT::edit_item(int index,int value)
{
     if(lastindex==-1)
        cout<<"list is Empty:"<<endl;
    else if(index<0 || index>lastindex)
        cout<<"Invalid index: "<<endl;
    else
        p[index]=value;
}
void  ArrayADT::remove_item(int index)
{
     if(lastindex==-1)
        cout<<"list is Empty:"<<endl;
    else if(index<0 || index>lastindex)
        cout<<"Invalid index :"<<endl;
    else if(index<=lastindex)
    {
        int i;
        i=index;
        while(i!=lastindex)
        {
            p[i]=p[i+1];
            i++;
        }
        lastindex--;
    }
}
int  ArrayADT::count_item()
{
    return(lastindex+1);
}
void ArrayADT::sort_item()
{
    int i,n,r,t;
    n=count_item();
    if(n==0 || n==1)
        cout<<"Sorting is not possible:"<<endl;
    else
    {
        for(r=1;r<n;r++)
        {
            for(i=0;i<n-r;i++)
            {
                if(p[i]>p[i+1])
                {
                    t=p[i];
                    p[i]=p[i+1];
                    p[i+1]=t;
                }
            }
        }
    }
}
void ArrayADT::reverse_item()
{
    int i,n,t;
    n=count_item();
    if(n==0 || n==1)
        cout<<"Reverse is not possible:"<<endl;
    else
    {
        for(i=0;i<n/2;i++)
        {
            t=p[i];
            p[i]=p[n-i-1];
            p[n-i-1]=t;
        }
    }
}
int menu()
{
    int k;
    cout<<"1.Set the data in the list :"<<endl;
    cout<<"2.Get the data from the list :"<<endl;
    cout<<"3.Edit the data in the list :"<<endl;
    cout<<"4.Remove the data From the list :"<<endl;
    cout<<"5.Count the number of item in the list :"<<endl;
    cout<<"6.Sort the item :"<<endl;
    cout<<"7.Reverse the data :"<<endl;
    cout<<"8.Exit :"<<endl;
    cout<<"Enter any choice : "<<endl;
    cin>>k;
    return(k);
}
int main()
{
    int k,i,t,m;
    ArrayADT a;
    cout<<"Enter capacity of an array :"<<endl;
    cin>>k;
    if (k<=0)
        cout<<"invalid Capacity:"<<endl;
    else{
        a.create_array(k);
      while(1)
      {
        switch(menu())
            {

            case 1:
                cout<<"Enter any index: \n";
                cin>>t;
                cout<<"Enter any item : \n";
                cin>>m;
                a.set_item(t,m);
                break;
            case 2:
              for(i=0;i<a.count_item();i++)
                cout<<a.get_item(i)<<" ";
                cout<<endl;
              break;
            case 3:
                cout<<"Enter any index: \n";
                cin>>t;
                cout<<"Enter any item : \n";
                cin>>m;
                a.edit_item(t,m);
                break;
            case 4:
                cout<<"Enter any index: \n";
                cin>>t;
                a.remove_item(t);
                break;
            case 5:
                m=a.count_item();
                if(m==0)
                cout<<"No item is present :\n";
                else
                    cout<<"Number of item in the list is :"<<m<<endl;
                break;
            case 6:
                a.sort_item();
                break;
            case 7:
                a.reverse_item();
                break;
            case 8:
                exit(0);
            default:
                cout<<"Invalid choice : \n";
            }
      }
    }
}
