#Python Program to create a heapsort, pushing all values onto a heap and
#then popping off the smallest values one at a time

import heapq             #importing heapq file
def heapsort(h):         #initialize the class definition
    heap = []
    for value in h:
        heapq.heappush(heap, value)        #push function to push all values onto a heap
    return [heapq.heappop(heap) for i in range(len(heap))]    #inner for loop to return the sortted values

x=input('Enter the values: ').split()      #split function to take input from user
#note : Use spacebar while writing input

print(heapsort(x))

#Time complexity : O(nLogn)
#space complexity : O(1)