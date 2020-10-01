''' Merge Sort is a Divide and Conquer algorithm. It divides input
array in two halves, calls itself for the two halves and then merges the
two sorted halves.The merge() function is used for merging two halves.
The merge(arr, l, m, r) is key process that assumes that arr[l..m] and
arr[m+1..r] are sorted and merges the two sorted sub-arrays into one'''

'''////ALGORITHM////

#MergeSort(arr[], l,  r)
If r > l
     1. Find the middle point to divide the array into two halves:  
             middle m = (l+r)/2
     2. Call mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)'''


'''Python program for implementation of MergeSort'''


def mergeSort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2  # Finding the mid of the array
        left = arr[:mid]  # Dividing the array elements
        right = arr[mid:]  # into 2 halves

        mergeSort(left)  # Sorting the first half
        mergeSort(right)  # Sorting the second half

        i = j = k = 0

        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1

        # Checking if any element was left
        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1


# printing the list
def printList(arr):
    for i in range(len(arr)):
        print(arr[i], end=" ")
    print()


arr = [12, 11, 13, 5, 6, 7]
print("Given array is: ")
printList(arr)
mergeSort(arr)
print("Sorted array is: ")
printList(arr)


