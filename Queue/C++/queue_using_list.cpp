#include <iostream>
#include <list>
using namespace std;

// Queue implementation in C++ using std::list
int main()
{
	list<string> q;
    
    // Insert operation
	q.push_back("A");	
	q.push_back("B");	
	q.push_back("C");	
	q.push_back("D");	

	// Returns the number of elements present in the queue
	cout << "Queue size is " << q.size() << endl;

	// Prints the front of the queue ("A")
	cout << "Front element is: " << q.front() << endl;

	// Prints the rear of the queue ("D")
	cout << "Rear element is: " << q.back() << endl;

    // delete operation
	q.pop_front();	
	q.pop_front();	

	cout << "Queue size is " << q.size() << endl;

	// check if queue is empty
	if (q.empty())
		cout << "Queue is Empty\n";
	else
		cout << "Queue is not Empty\n";

	return 0;
}