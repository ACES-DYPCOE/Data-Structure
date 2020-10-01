import java.io.*;
import java.util.*;

public class Searching
{
    public static void main(String[] args)throws IOException
    {
        InputStreamReader read = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(read);
        Scanner sc = new Scanner(System.in);

        System.out.print("Length of Array: ");
        int n = sc.nextInt();

        int arr[] = new int[n];
        System.out.println("Enter elements: ");
        for(int i=0;i<n;i++)
            arr[i] = sc.nextInt();

        System.out.print("Element to be searched: ");
        int s = sc.nextInt();

        Searching obj = new Searching();
        int linear = obj.Linear(arr.clone(), s);

        int[] sortedArr = Arrays.copyOf(arr, n);
        Arrays.sort(sortedArr);
        int binary = obj.Binary(sortedArr, 0,n-1,s);

        System.out.println("Linear Search element found at: " + linear);
        System.out.println("Binary Search element found it: " + binary);

    }

    public int Linear(int [] arr, int s)
    {
        int loc = -1;
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i] == s)
            {
                loc = i;
            }
        }
        return loc;
    }

    public int Binary(int [] arr, int l, int r, int x)
    {
        if(r >= l)
        {
            int mid = (l + r)/2;

            if(arr[mid] == x)
                return mid;

            else if(arr[mid] > x)
            {
                return Binary(arr, l, mid - 1, x);
            }
            else
            {
                return Binary(arr, mid+1, r,x);
            }
        }
        return -1;
    }
}
