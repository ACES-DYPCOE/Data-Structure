print("//*****BUBBLE SORT*****//")
'''Bubble Sort is the simplest sorting algorithm that works 
by repeatedly swapping the adjacent elements if they are in wrong order.'''


'''/////ALGORITHM////
1)Starting with the first element(index = 0), compare the current element 
with the next element of the array.

2)If the current element is greater than the next element of the array,swap them.

3)If the current element is less than the next element,move to the next element.'''

#implementation of Bubble sort

def bubbleSort(arr):
   n = len(arr)
   # Traverse through all array elements
   for i in range(n):
   # Last i elements are already in correct position
        for j in range(0, n-i-1):
      # Swap if the element found is greater than the next element
            if arr[j] > arr[j+1] :
                arr[j], arr[j+1] = arr[j+1], arr[j]


arr = [64,23,56,21,10,15]
print("Given Array is: ",arr)
bubbleSort(arr)
print ("Sorted array is:")
for i in range(len(arr)):
   print (arr[i])


'''
OUTPUT : 
//*****BUBBLE SORT*****//
Given Array is:  [64, 23, 56, 21, 10, 15]
Sorted array is:
10
15
21
23
56
64
'''

'''
Time Complexity :
1.Worst and Average Case Time Complexity: O(n*n) Worst case occurs when array
 is reverse sorted.

2.Best Case Time Complexity: O(n) Best case occurs when array is already sorted
'''