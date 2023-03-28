/*

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

Runtime 4 ms
Memory 6.6 MB
TC O(3 raised to n)
SC O(n)
  
*/  

#include<bits/stdc++.h>
class Solution {
public:

    void helper(int i, string& temp, string& digits,vector<string>& ans,unordered_map<char,string>& m){

        // base case
        if(i == digits.size()){
            ans.push_back(temp);
            return ;
        }

        string str = m[digits[i]];

        for(int j=0; j<str.size(); j++){
            temp.push_back(str[j]);
            helper(i+1,temp,digits,ans,m);
            temp.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty()){
            return {};
        }

        unordered_map <char,string> m;
        m['2']= "abc";
        m['3']= "def";
        m['4']= "ghi";
        m['5']= "jkl";
        m['6']= "mno";
        m['7']= "pqrs";
        m['8']= "tuv";
        m['9']= "wxyz";

        string temp="";
        vector<string> ans;
        helper(0,temp,digits,ans,m);
        return ans;

    }
};
