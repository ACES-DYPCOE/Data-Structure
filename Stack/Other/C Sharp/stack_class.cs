using System; 
using System.Collections; 
class stackclass { 
  
    // Driver code 
    public static void Main() 
    { 
  
        // Creating a Stack 
        Stack myStack = new Stack(); 
  
        // Inserting the elements into the Stack 
        myStack.Push("1st Element"); 
        myStack.Push("2nd Element"); 
        myStack.Push("3rd Element"); 
        myStack.Push("4th Element"); 
        myStack.Push("5th Element"); 
        myStack.Push("6th Element"); 
  
        // Displaying the count of elements contained in the Stack 
        Console.Write("Total number of elements in the Stack are : "); 
  
        Console.WriteLine(myStack.Count); 
  
        // Displaying the top element of Stack without removing it from the Stack 
        Console.WriteLine("Element at the top is : " + myStack.Peek()); 
  
        // Displaying the top element of Stack without removing it from the Stack 
        Console.WriteLine("Element at the top is : " + myStack.Peek()); 
  
        // Displaying the count of elements contained in the Stack 
        Console.Write("Total number of elements in the Stack are : "); 
  
        Console.WriteLine(myStack.Count); 
    } 
} 