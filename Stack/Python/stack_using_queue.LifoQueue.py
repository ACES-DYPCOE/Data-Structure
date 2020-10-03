from queue import LifoQueue 
  
# Initializing a stack 
stack = LifoQueue(maxsize = 3) 
  
# qsize() show the number of elements in the stack 
print(stack.qsize()) 
   
# put() function to push element in the stack 
stack.put('a') 
stack.put('b') 
stack.put('c') 
  
print("Full: ", stack.full())  
print("Size: ", stack.qsize())  
  
# get() fucntion to pop element from stack  

print('\nElements poped from the stack') 
print(stack.get()) 
print(stack.get()) 
print(stack.get()) 
  
print("\nEmpty: ", stack.empty()) 