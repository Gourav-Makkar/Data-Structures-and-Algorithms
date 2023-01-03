//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beg, string end, vector<string>& list) {
        // code here
        vector<vector<string>>ans;
        unordered_set<string>s;
        for(auto it:list)
            s.insert(it);
        queue<vector<string>>q;
        q.push({beg});
        s.erase(beg);
        while(!q.empty())
        {
            int n=q.size();
            vector<string>to_erase;
            for(int i=0;i<n;i++)
            {
                vector<string>temp=q.front();
                q.pop();
                
                string word=temp.back();
                if(word==end)
                {
                    ans.push_back(temp);
                    continue;
                }
                for(int idx=0;idx<word.size();idx++)
                {
                    string t=word;
                    for(int i=97;i<=122;i++)
                    {
                        t[idx]=i;
                        if(s.find(t)!=s.end())
                        {
                            temp.push_back(t);
                            to_erase.push_back(t);
                            q.push(temp);
                            temp.pop_back();
                        }
                    }
                }
            }
            for(auto it:to_erase)
                s.erase(it);
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends