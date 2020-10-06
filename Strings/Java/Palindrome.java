import java.io.*;
public class Palindrome
{
    public static void main(String[] args)throws IOException
    {
        InputStreamReader read = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(read);

        System.out.println("Enter the string:");
        String na = in.readLine();

        Palindrome p = new Palindrome();

        boolean answer = p.checkPalindrome(na);

        System.out.println(answer);
    }

    public boolean checkPalindrome(String na)
    {
        int len = na.length();
        boolean answer = true;
        for(int i=0,j=len-1 ; i<(len/2) ; i++,j--)
        {
            if(na.charAt(i) != na.charAt(j))
            {
                answer = false;
                break;
            }

        }
        return answer;
    }
}
