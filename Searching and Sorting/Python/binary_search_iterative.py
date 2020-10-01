'''Binary Search is a searching method that requires array to be sorted in ascending
   order, it is faster than linear search
   Time Complexity - O(log2n)
   Space Complexity - O(1)'''
def binary_search_iterative(arr,x):
    #Terms used for spliting array in two divisions.
    low = 0
    high = len(arr) - 1
    mid = (high + low)//2

    #iterative loop over array.
    while high >= low:
        #updationg value of mid using current high and low.
        mid = (high + low)//2

        #if x is greater than middle element then x in latter half of array.
        if (x > arr[mid]):
            low = mid + 1

        #if x is smaller than middle element then x in former half of array.
        elif (x < arr[mid]):
            high = mid - 1

        #the only remaining condition is that middle element is x in that
        #case we return value of middle.
        else:
            return mid

    #if location of x is not found in above loop that suggests x is not
    #present in the array, so we return -1.
    return -1

arr = []
loc = binary_search_iterative(arr,23)
print(loc)

'''Great Video on Binary search- https://www.youtube.com/watch?v=KXJSjte_OAI'''
