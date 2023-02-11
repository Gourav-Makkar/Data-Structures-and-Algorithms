//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:

    bool isPrime(int n)
    {
        if(n==1)
          return false;
          
        if(n==2 || n==3)
          return true;
          
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
              return false;
        }
        return true;
    }

    int findNearest(int n)
    {
        int prev=n-1,nxt=n+1;
        while(true)
        {
            if(prev>0 && isPrime(prev))
             return prev;
            
            if(isPrime(nxt))
              return nxt;
            
            prev--;
            nxt++;
        }
    }
    
    Node *primeList(Node *head){
        Node* curr=head;
        
        while(curr!=NULL)
        {
            if(!isPrime(curr->val))
            {
                int val=findNearest(curr->val);
                curr->val=val;
            }
            curr=curr->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends