#include <iostream>
#include <queue>
using namespace std;

// Queue implementation in C++ using std::queue
int main()
{
	queue<string> q;

	// Insert operation
	q.push("A");	
	q.push("B");	
	q.push("C");	
	q.push("D");	

	// Returns the number of elements present in the queue
	cout << "Queue size is " << q.size() << endl;

	// Prints the front of the queue ("A")
	cout << "Front element is: " << q.front() << endl;

	// Prints the rear of the queue ("D")
	cout << "Rear element is: " << q.back() << endl;

	q.pop();	
	q.pop();	

	cout << "Queue size is " << q.size() << endl;

	// check if queue is empty
	if (q.empty())
		cout << "Queue is Empty\n";
	else
		cout << "Queue is not Empty\n";

	return 0;
}