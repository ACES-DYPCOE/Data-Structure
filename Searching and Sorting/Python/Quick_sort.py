#Quick sort is the widely used sorting algorithm that makes n log n comparisons in average case for sorting of an array of n elements.
#This algorithm follows divide and conquer approach. The algorithm processes the array in the following way.
#1. Set the first index of the array to left and loc variable. Set the last index of the array to right variable. i.e. left = 0, loc = 0, en d
#   = n - 1, where n is the length of the array.
# 2. Start from the right of the array and scan the complete array from right to beginning comparing each element of the array with the element pointed by loc.
#       Ensure that, a[loc] is less than a[right]
#       1.If this is the case, then continue with the comparison until right becomes equal to the loc.
#       2.If a[loc] > a[right], then swap the two values. And go to step 3.
#       3.Set, loc = right
# 3.start from element pointed by left and compare each element in its way with the element pointed by the variable loc. Ensure that a[loc] > a[left]
#       1.if this is the case, then continue with the comparison until loc becomes equal to left.
#       2.[loc] < a[right], then swap the two values and go to step 2.
#       3.Set, loc = left.

# Python program for implementation of Quicksort Sort

def partition(arr, low, high):
    i = (low - 1)  # index of smaller element
    pivot = arr[high]  # pivot

    for j in range(low, high):

        # If current element is smaller than or
        # equal to pivot
        if arr[j] <= pivot:
            # increment index of smaller element
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return (i + 1)


# The main function that implements QuickSort
# arr[] --> Array to be sorted,
# low  --> Starting index,
# high  --> Ending index

# Function to do Quick sort


def quickSort(arr, low, high):
    if len(arr) == 1:
        return arr
    if low < high:
        # pi is partitioning index, arr[p] is now
        # at right place
        pi = partition(arr, low, high)

        # Separately sort elements before
        # partition and after partition
        quickSort(arr, low, pi - 1)
        quickSort(arr, pi + 1, high)


# Driver code to test above
arr = [10, 7, 8, 9, 1, 5]
n = len(arr)
quickSort(arr, 0, n - 1)
print("Sorted array is:")
for i in range(n):
    print("%d" % arr[i])

#Time complexity : O(n log n)
#space complexity : O(log n)