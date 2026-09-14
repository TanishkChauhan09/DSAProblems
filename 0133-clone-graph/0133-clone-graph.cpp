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
   
    void dfs(Node *node,Node *cloneNode,unordered_map<Node*,Node*>&mp)
    {
        for(Node *neigh : node->neighbors)
        {
            if(mp.find(neigh)==mp.end())
            {
                Node *clone = new Node(neigh->val);
                mp[neigh] = clone;

                cloneNode->neighbors.push_back(clone);

                dfs(neigh,clone,mp);
            }
            else
            {
                cloneNode->neighbors.push_back(mp[neigh]);
            }
        }
    }

    Node* cloneGraph(Node* node) {

        if(!node)
        return NULL;

        unordered_map<Node*,Node*>mp;
        Node *cloneNode = new Node(node->val);
        mp[node] =  cloneNode;

        dfs(node,cloneNode,mp);
        
        return cloneNode;
    }
};