/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
  
Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
  
Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
  
Runtime 5 ms
Memory 6.4 MB
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int count = 0;
        for(int i=n-1; i>=0; i--)
        {
            //if we successfully traversed last word then break
            if (isspace(s.at(i)) && count >0){
                break;
            }

            // else we just started traversing last word
            else
            {
                if (isspace(s.at(i)) && count == 0){
                    continue;
                } 

                else{
                    count++;
                } 
            }
        }
        return count;
    }
};
