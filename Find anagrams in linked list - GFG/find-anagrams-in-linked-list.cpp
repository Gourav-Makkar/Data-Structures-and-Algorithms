//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        vector<Node*>ans;
        
        unordered_map<char,int>m1,m2;
        for(auto it:s)
          m1[it]++;
        
        Node* i=head,*j=head;
        int st=0,en=0;
        
        while(j!=NULL)
        {
            m2[j->data]++;
            
            if(en-st+1==s.size())
            {
                if(m1==m2)
                {
                   Node* temp=j->next;
                   j->next=NULL;
                   ans.push_back(i);
                   i=temp;
                   j=temp;
                   st=0;
                   en=0;
                   m2.clear();
                   continue;
                }
                else
                {
                    st++;
                    m2[i->data]--;
                    if(m2[i->data]==0)
                      m2.erase(i->data);
                    i=i->next;
                }
            }
            en++;
            j=j->next;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends