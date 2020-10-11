#Radix sort processes the elements the same way in which the names of the students are sorted according to their alphabetical order.
#There are 26 radix in that case due to the fact that, there are 26 alphabets in English. In the first pass, the names are grouped
#according to the ascending order of the first letter of names.
#In the second pass, the names are grouped according to the ascending order of the second letter. The same process continues until we
#find the sorted list of names. The bucket are used to store the names produced in each pass. The number of passes depends upon the
#length of the name with the maximum letter.
#In the case of integers, radix sort sorts the numbers according to their digits.
#The comparisons are made among the digits of the number from LSB to MSB.
#The number of passes depend upon the length of the number with the most number of digits.


# Python program for implementation of Radix Sort

def countingSort(arr, exp1):
    n = len(arr)

    # The output array elements that will have sorted arr
    output = [0] * (n)

    # initialize count array as 0
    count = [0] * (10)

    # Store count of occurrences in count[]
    for i in range(0, n):
        index = (arr[i] / exp1)
        count[int((index) % 10)] += 1

    # Change count[i] so that count[i] now contains actual
    #  position of this digit in output array
    for i in range(1, 10):
        count[i] += count[i - 1]

        # Build the output array
    i = n - 1
    while i >= 0:
        index = (arr[i] / exp1)
        output[count[int((index) % 10)] - 1] = arr[i]
        count[int((index) % 10)] -= 1
        i -= 1

    # Copying the output array to arr[],
    # so that arr now contains sorted numbers
    i = 0
    for i in range(0, len(arr)):
        arr[i] = output[i]

    # Method to do Radix Sort


def radixSort(arr):
    # Find the maximum number to know number of digits
    max1 = max(arr)

    # Do counting sort for every digit. Note that instead
    # of passing digit number, exp is passed. exp is 10^i
    # where i is current digit number
    exp = 1
    while max1 / exp > 0:
        countingSort(arr, exp)
        exp *= 10


# Driver code to test above
arr = [170, 45, 75, 90, 802, 24, 2, 66]
radixSort(arr)

for i in range(len(arr)):
    print(arr[i])


#Time complexity : 	θ(nk)
#space complexity : O(n+k)