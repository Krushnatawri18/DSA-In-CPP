# DSA_in_cpp

/*

Reverse Words in a String III

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:

Input: s = "God Ding"
Output: "doG gniD"

Runtime 13 ms  Memory 13.5 MB

*/

class Solution {
public:
    string reverseWords(string s) {

        string result = "", t = "";
        int n = s.size();

        for(int i = 0; i <= n; i++) 
        {
            if(i == n){
                reverse(t.begin(), t.end());
                result += t;
            }
            else if(s[i] == ' ' )
            {
                reverse(t.begin(), t.end());
                result += t + " ";
                
                t = "";
            }
            else 
            {
                t += s[i];
            }

        }
        return result;
    }
};
Console
