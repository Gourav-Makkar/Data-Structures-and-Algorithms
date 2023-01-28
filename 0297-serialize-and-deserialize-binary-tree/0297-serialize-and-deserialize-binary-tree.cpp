/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    void create(TreeNode* root,string &s)
    {
        if(root==NULL)
        {
            s+='N';
            s+=',';
            return;
        }
        
        string temp=to_string(root->val);
        
        s+=temp;
        s+=',';
        
        create(root->left,s);
        create(root->right,s);
    }
    
    TreeNode* helper(queue<string>&q)
    {
        string temp=q.front();
        q.pop();
        
        if(temp=="N")
            return NULL;
        
        TreeNode* root=new TreeNode(stoi(temp));
        
        root->left=helper(q);
        root->right=helper(q);
        
        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string temp="";
        create(root,temp);
        
        for(int i=0;i<temp.size();i++)
            cout<<temp[i];
        cout<<endl;
        return temp;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       string num="";
       queue<string>q;
       
        for(int i=0;i<data.size();i++)
        {
            if(data[i]==',')
            {
                q.push(num);
                num="";
            }
            else
                num+=data[i];
        }
        return helper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));