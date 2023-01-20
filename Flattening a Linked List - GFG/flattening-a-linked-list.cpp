//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

class Solution {
public:

    Node* merge(Node* curr1,Node* curr2)
    {
        Node* head=NULL,*tail=NULL;
        
        while(curr1 && curr2)
        {
            if(curr1->data<=curr2->data)
            {
                if(head==NULL)
                {
                    head=curr1;
                    tail=curr1;
                }
                else
                {
                    tail->bottom=curr1;
                    tail=tail->bottom;
                }
                curr1=curr1->bottom;
            }
            else
            {
                 if(head==NULL)
                {
                    head=curr2;
                    tail=curr2;
                }
                else
                {
                    tail->bottom=curr2;
                    tail=tail->bottom;
                }
                curr2=curr2->bottom;
            }
        }
        if(curr1==NULL)
          {
              if(head==NULL)
              {
                  head=curr2;
                  tail=curr2;
              }
              else
              {
                  tail->bottom=curr2;
              }
          }
        else
          {
              if(head==NULL)
              {
                  head=curr1;
                  tail=curr1;
              }
              else
              {
                  tail->bottom=curr1;
              }
          }
          
        return head;
    }
    Node *flatten(Node *root)
    {
        Node* curr=root;
        if(curr==NULL)
          return NULL;
        
        Node* temp=flatten(curr->next);
        return merge(temp,curr);
    }
};


//{ Driver Code Starts.

int main(void) {

    int t;
    cin >> t;
    while (t--) {
        int n, m, flag = 1, flag1 = 1;
        struct Node * temp = NULL;
        struct Node * head = NULL;
        struct Node * pre = NULL;
        struct Node * tempB = NULL;
        struct Node * preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++) {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag) {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++) {

                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1) {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;

        Solution ob;
        Node* root = ob.flatten(head);
        printList(root);
        cout << endl;

    }
    return 0;
}

// } Driver Code Ends