#Insertion sort

class Point:
    def __init__(self, a):   #initialize the class definition
        self.a = a


def insertion_sort(alist):
    for i in range(1, len(alist)):
        temp = alist[i]       #initialize temp to alist
        j = i - 1
        while (j >= 0 and temp < alist[j]):
            alist[j + 1] = alist[j]
            j = j - 1
        alist[j + 1] = temp


alist = input('Enter the list of numbers: ').split()
alist = [int(x) for x in alist]
insertion_sort(alist)   #calling class definition
for point in alist:
    print('Sorted list: ', end='')
    print(alist)

#Time Complexity: O(n2)
