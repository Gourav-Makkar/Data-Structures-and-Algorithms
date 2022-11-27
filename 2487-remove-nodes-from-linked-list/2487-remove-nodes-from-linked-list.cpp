class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* curr=head;
        ListNode* head1=NULL,*tail=NULL;
        vector<int>v;
        while(curr!=NULL)
        {
            v.push_back(curr->val);
            curr=curr->next;
        }
        int n=v.size();
        unordered_map<int,bool>m;
        
        int mx=v[n-1];
        m[n-1]=true;
        for(int i=n-2;i>=0;i--)
        {
            if(v[i]<mx)
            {
                m[i]=false; 
            }
            else
            {
                m[i]=true;
                mx=v[i];
            }
        }
        curr=head;
        for(int i=0;i<n;i++)
        {
            if(m[i]==true)
            {
                ListNode* temp=new ListNode(v[i]);
                if(head1==NULL)
                {
                    head1=temp;
                    tail=temp;
                }
                else
                {
                    tail->next=temp;
                    tail=tail->next;
                }
                
            }
        }
        return head1;
    }
};