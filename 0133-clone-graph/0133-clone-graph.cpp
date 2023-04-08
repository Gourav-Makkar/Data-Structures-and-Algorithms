/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* helper(Node* node, unordered_map<Node*,Node*>&m)
    {
        vector<Node*>n;
        Node* temp=new Node(node->val);
        m[node]=temp;
        
        for(auto it:node->neighbors)
        {
            if(m.find(it)!=m.end())
                n.push_back(m[it]);
            else
                n.push_back(helper(it,m));
        }
        temp->neighbors=n;
        return temp;
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        unordered_map<Node*,Node*>m;
        
        return helper(node,m);
    }
};