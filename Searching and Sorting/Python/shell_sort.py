#Shell sort algorithm using python
#Shell sort algorithm is an improved form of insertion sort algorithm as it compares elements separated by a gap of several position.
#In Shell sort algorithm, the elements in an array are sorted in multiple passes and in each pass, data are taken with smaller and smaller gap sizes.
# However, the finale of shell sort algorithm is a plain insertion sort algorithm.

def shellsort(a):        #initialize the function definition
    gap=len(a)//2        #Return the number of items in a container
    while gap>0:
        for i in range(gap,len(a)):
            j=a[i]                                  ##initialize j to a[i]
            pos=i                                   #initialize pos to i
            while pos>=gap and j<a[pos-gap]:        #inner while loop
                a[pos]=a[pos-gap]
                pos=pos-gap
            a[pos]=j
        gap=gap//2

n=int(input("Enter length of array: "))
print("Enter values in array: ")                  #taking input from user
arr=[int(input()) for i in range(n)]
shellsort(arr)                                    #calling of function definition
print("sorted array: ",arr)

#Time complexity :   O(n*log n)
#space complexity :   O(1)

