class Solution {
public:
    int numDifferentIntegers(string word) {
    unordered_set<string> data;
    for(int i=0; i<word.length();i++)
    {
       string tmp = "";
       if(isdigit(word[i]))
       {
         while(word[i]=='0')
             i++; 
         while(isdigit(word[i]))
             tmp+=word[i++];
         data.insert(tmp);
       }
    }
    
    return data.size();
    }
};