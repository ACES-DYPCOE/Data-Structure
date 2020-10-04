#The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.
#1) The subarray which is already sorted.
#2) Remaining subarray which is unsorted.
#In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

#Bubble Sort Algorithm is the simplest sorting algorithm in which each element is compared to its adjacent element
#and if first elememt is greater than second element ,then the swapping occurs.
#The swapping occurs till the array is sorted.

def selectionsort(array, size):         #initialize the class definition
    for step in range(size):
        min_indx = step                #initialize min_indx to step
        for i in range(step + 1, size):      #inner for loop
            if array[i] < array[min_indx]:      #Checking if the element is larger than the next element
                min_indx = i

        (array[step], array[min_indx]) = (array[min_indx], array[step]);
    return array


def bubblesort(arr, n):
    for i in range(n - 1):
        for j in range(n - i - 1):        #inner for loop
            if arr[j] > arr[j + 1]:           #Checking if the element is less than the next element
                (arr[j], arr[j + 1]) = (arr[j + 1], arr[j])
    return arr


def display(arr, cnt):
    size = len(arr)
    while cnt > 0:              #while loop for printing out the array after sorting
        print(arr[size - 1]);
        size = size - 1;
        cnt = cnt - 1;


data = list();
num = input("Enter the number of elements:");            #input
for i in range(int(num)):
    n = input("num:");
    data.append(float(n));
choice = 1;
while choice != 3:                 #while loop for making a choice between selection sort and bubble sort
    print("1. selection sort:");
    print("2. Bubble  sort:");
    print("3. Exit");
    choice = int(input("choice:"));
    if choice == 1:
        arr = selectionsort(data[:], len(data));      #calling class definition
        print(arr);
        display(arr, 5);
    if choice == 2:
        arr = bubblesort(data, len(data));             #calling class definition
        print(arr);
        display(arr, 5);

#Time complexities:
         # 1)selection sort:  О(n2)
         # 2)bubble sort:  O(n2)

#space complexities:
        # 1)selection sort: O(1)
        # 2)bubble sort:   O(1)