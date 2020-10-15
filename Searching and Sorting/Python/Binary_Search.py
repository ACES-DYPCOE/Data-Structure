'''
Binary Search: Search a sorted array by repeatedly dividing the search
interval in half. Begin with an interval covering the whole array.
If the value of the search key is less than the item in the middle of
the interval, narrow the interval to the lower half. Otherwise narrow it
to the upper half. Repeatedly check until the value is found or the
interval is empty.

The idea of binary search is to use the information that the array is
sorted and reduce the time complexity to O(Log n).

ALGORITHM
We basically ignore half of the elements just after one comparison.

1.Compare x with the middle element.
2.If x matches with middle element, we return the mid index.
3.Else If x is greater than the mid element, then x can only lie in
right half subarray after the mid element. So we recur for right half.
4.Else (x is smaller) recur for the left half.
'''

'''Recursive implementation of Binary Search'''


def binarySearch(arr, l, r, x):
    if r >= l:

        mid = l + (r - l) // 2

        # If element is present at the middle itself
        if arr[mid] == x:
            return mid

       # If element is smaller than mid, then it can only be present
        # in left subarray
        elif arr[mid] > x:
            return binarySearch(arr, l, mid - 1, x)

            # Else the element can only be present
        # in right subarray
        else:
            return binarySearch(arr, mid + 1, r, x)

    else:
        return -1


arr = [2, 3, 4, 10, 40]
x = 10

result = binarySearch(arr, 0, len(arr) - 1, x)

if result != -1:
    print("Element is present at index % d" % result)
else:
    print("Element is not present in array")

'''
OUTPUT: Element is present at index  3
'''

'''Iterative implementation of Binary Search'''


def binarySearch(arr, l, r, x):
    while l <= r:

        mid = l + (r - l) // 2;

        # Check if x is present at mid
        if arr[mid] == x:
            return mid

        # If x is greater, ignore left half
        elif arr[mid] < x:
            l = mid + 1

        # If x is smaller, ignore right half
        else:
            r = mid - 1

    return -1


arr = [2, 3, 4, 10, 40]
x = 4

result = binarySearch(arr, 0, len(arr) - 1, x)

if result != -1:
    print("Element is present at index % d" % result)
else:
    print("Element is not present in array")


'''
OUTPUT: Element is present at index  2
'''