# Stack in C#

## A stack is a linear data structure that stores items in a Last-In/First-Out (LIFO) or First-In/Last-Out (FILO).

### Operations:

1. **Push**: Adds an item in the stack. If the stack is full, then it is said to be a stack Overflow condition.
2. **Pop**: Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be a stack Underflow condition.
3. **Peek**: Return the topmost element of stack.


## Stack class

Stack class comes under **System.Collections** namespace.

### Characteristics of Stack Class:

1. The capacity of a Stack is the number of elements the Stack can hold. As elements are added to a Stack, the capacity is automatically increased as required through reallocation.
2. If Count is less than the capacity of the stack, Push is an O(1) operation. If the capacity needs to be increased to accommodate the new element, Push becomes an O(n) operation, where n is Count. Pop is an O(1) operation.
3. Stack accepts null as a valid value and allows duplicate elements.