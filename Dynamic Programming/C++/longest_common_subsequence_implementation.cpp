//a simple longest common subsequence(lcs) implementation has been explained using dynamic programming
//the problem statement for the same can be found on leetcode Problem #1143


//create a global matrix that will keep on getting updated with each iteration of the loop
//row number represents the length of 1st string
//column number represents the length of 2nd string
//each cell of matrix represents the lcs corresponding to string_1_length_till_row_number, string_2_length_till_column_number


int static t[1001][1001];


//this is the solution class that contains the implementation of lcs
//call it in int main to find lcs: int answer = Solution.longestCommonSubsequence(abcdef, bdf)

class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
    
        //finding the length of two string
        int n= text1.size(); //as per our example n = 6
        int m= text2.size(); //m = 3
        
        //initialise the base condition
        //it means that if length of either of the string is zero, then the lcs corresponding to that input will be zero
        for(int i=0; i<n+1; i++) t[i][0]=0;
        for(int i=0; i<m+1; i++) t[0][i]=0;
        
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(text1[i-1]==text2[j-1]) t[i][j] = 1 + t[i-1][j-1]; //if the element matches, then add one to the previous lcs 
                else t[i][j] = max(t[i-1][j], t[i][j-1]); //if elements don't match, keep one string the same and move to next element in the other string
                //check for lcs for those two cases and choose the greatest among the two
            }
        }
        return t[n][m]; 
        //lcs when n=6 and m=3, this is what was asked to us in the question

    }
};

//This algorithm is used in various other questions like Longest Palindromic Subsequence, Longest Common Substring, Shortest Common Super sequence, etc. 
