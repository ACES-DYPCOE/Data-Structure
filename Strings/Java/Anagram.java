import java.io.*;
import java.util.*;

public class Anagram
{
    public static void main(String[] args) throws IOException
    {
        InputStreamReader read = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(read);

        System.out.println("Enter the 2 strings: ");
        String s1 = in.readLine();
        String s2 = in.readLine();

        //ignoring cases of both strings
        s1 = s1.toLowerCase();
        s2 = s2.toLowerCase();

        Anagram a = new Anagram();
        boolean answer = a.checkAnagram(s1, s2);

        System.out.println(answer);
    }

    public boolean checkAnagram(String s1, String s2)
    {
        int len1 = s1.length();
        boolean answer = true;
        for(int i=0;i<len1;i++)
        {
            char toSearch = s1.charAt(i);
            int len2 = s2.length();
            boolean found = false;
            for(int j=0;j<len2;j++)
            {
                if(s2.charAt(j) == toSearch)
                {
                    found = true;
                    s2 = s2.substring(0,j) + s2.substring(j+1);
                    break;
                }
            }

            if(!found)
            {
                answer = false;
                break;
            }
        }
        return answer;
    }
}
