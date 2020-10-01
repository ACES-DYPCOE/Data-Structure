
	// Sieve of Eratosthenes is one of the most efficient algorithms to find all prime
	// numbers less than a given 'n'

	// #ALgorithm:
	// 	1. Create a list of n+1 elements and initialize them to True.
	// 	2. Initialize a variable, lets say 'p' to 2, the first prime number.
	// 	3. Starting from 'p' check every element until 'n',if it is 'True' in list, modify the element at positions of multiples of'p' to 'False'

	// #Time Complexity:
	// 	O(nloglogn)

	// #Space Complexity: 
	// 	O(n)
	// 

#include<bits/stdc++.h>
using namespace std;

//Sieve Of Eratosthenes Function:
void soe(int n)
{
	bool isprime[n+1];
	memset(isprime, true, sizeof(isprime)); //Memset is used to assign values to a list

	for(int p=2;p*p<=n;++p)
	{
		if(isprime[p]==true)
		{
			//Update all multiples of p to False
			for(int i=p*p;i<=n;i+=p)
				isprime[i]=false;
		}
	}

	//Print all Prime Numbers
	for(int p=2;p<=n;++p)
	{
		if(isprime[p]==true)
			cout<<p<<" ";
	}
}

int main()
{
	int n;
	cout<<"Enter Number: ";
	cin>>n;

	cout<<"\n Prime Numbers less than "<<n<<" are: \n";
	soe(n);
	cout<<"\n";
}