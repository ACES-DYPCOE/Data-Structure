#include<bits/stdc++.h>
using namespace std;

void buildtree(int *tree,int *a, int index, int s, int e)
{

	//base case
	if(s > e)
		return;

	//base class leaf node
	if(s == e)
	{
		tree[index] = a[s];
		return;
	}
	
	//recursive case
	int mid = (s + e)/2;

	//build left sub tree
	buildtree(tree,a,2*index,s, mid);
	
	//build right sub tree
	buildtree(tree, a, 2*index+1, mid+1, e);
	
	//getting min value
	int left = tree[2*index];
	int right = tree[2*index + 1];

	tree[index] = min(left, right);
	
}

int query(int *tree,int index, int s, int e, int qs, int qe)
{
	//complete overlap condition
	if(qs <= s and qe >= e)
		return tree[index];

	//No overlap condition
	if(qe < s or qs > e)
		return INT_MAX;

	//Partial Overlap
	int mid = (s+e)/2;
	//getting results from left and right
	int left = query(tree, index*2, s, mid,qs,qe);
	int right = query(tree, index*2+1, mid+1, e,qs,qe);

	//returning the minimum one
	return min(left, right);
}

//to update a single node
void updatenode(int *tree, int index, int s, int e, int i, int val)
{
	//no overlap
	if(i < s or i > e)
		return;

	//reached leaf node
	if(s == e)
	{
		tree[index] = val;
		return;
	}

	//partial overlap (i.e.  i is lying between s and e)
	int mid = (s + e)/2;
	updatenode(tree, 2*index, s, mid, i, val);
	updatenode(tree, 2*index + 1, mid + 1, e, i, val);	

	//updating parent nodes
	tree[index] = min(tree[2*index], tree[2*index + 1]);

	return;
}

//incrementing a range with a particular value
void updaterange(int *tree, int index, int s, int e, int rs, int re, int inc)
{

	//no overlap
	if(re < s or rs > e)
		return;

	if(s==e)
	{
		tree[index] += inc;
		return;
	}

	int mid = (s + e)/2;
	updaterange(tree, 2*index, s, mid, rs, re, inc);
	updaterange(tree, 2*index + 1, mid + 1, e, rs, re, inc);	

	//updating parent nodes
	tree[index] = min(tree[2*index], tree[2*index + 1]);
	return;
}


int main()
{
	int n;
	cout<<"Enter the no. of elements: ";
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
	{
		cout<<"Enter "<<i+1<<" element: ";
		cin>>a[i];
	}
	//starting and ending values
	int s = 0;
	int e = n-1;


	//making a tree array of size(4*n + 1).[4*n + 1 is an upper bound]
	int tree[(4*n) + 1];

	//building the tree
	buildtree(tree, a, 1, s, e);

	int q;
	cout<<"Enter the number of queries: ";
	cin>>q;
    
    int l, r, i, val;
	
	while(q--)
	{
		int ch;
		cout<<"Press 1 to get the minimum value between a range"<<endl;
		cout<<"Press 2 to update a particular value"<<endl;
		cout<<"Press 3 to increment a range"<<endl;
		cout<<"Press 4 to exit"<<endl;
		cin>>ch;
       
		switch(ch)
		{
			case 1: cout<<"Range starts from (0 based indexing): ";
					cin>>l;
					cout<<"Range ends at (0 based indexing): ";
					cin>>r;
					cout<<"minimum number in range  "<<l<<" - "<<r<<"  is: "<<query(tree, 1, s, e, l, r)<<endl;
					break;

			case 2: cout<<"Enter the index to be changed(0 based indexing): ";
					cin>>i;
					cout<<"Enter the updated value: ";
					cin>>val;
					updatenode(tree, 1, s, e, i, val);
					cout<<"value updated successfully."<<endl;
					break;		

			case 3: cout<<"Range starts from (0 based indexing): ";
					cin>>l;
					cout<<"Range ends at (0 based indexing): ";
					cin>>r;
					cout<<"Range updated from  "<<l<<" - "<<r<<"  successfully."<<endl;
					break;

			case 4:	return 0;
			
			default: cout<<"Please enter a valid option"<<endl;		
		}
		
	}
		
	return 0;
}