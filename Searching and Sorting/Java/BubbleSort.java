import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class BubbleSort
{
    public void bubblerSort(int[] arr, int n)
    {
        int temp = 0;
        for(int i=0; i < n; i++)
        {
            for(int j=1; j < (n-i); j++)
            {
                if(arr[j-1] > arr[j])
                {
                    //swap elements
                    temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                }

            }
        }
    }

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

        BubbleSort obj = new BubbleSort();
        obj.bubblerSort(arr, n);

        System.out.println("Sorted Array: " + Arrays.toString(arr));


    }
}
