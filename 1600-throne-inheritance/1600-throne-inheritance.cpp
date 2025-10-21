class Node {
    public : 
        string name;
        vector<Node*> children;

        Node(string name) {
            this->name = name;
        }
};

class ThroneInheritance {
public:
    Node* root = NULL;
    unordered_set<string> deadSt;
    unordered_map<string, Node*> mp;

    void dfs(Node* node, vector<string> &ans) {
        if(node == NULL) return;
        if(deadSt.find(node->name) == deadSt.end()) ans.push_back(node->name);

        for(auto &child : node->children) {
            dfs(child, ans);
        }
    }

    Node* getParent(Node* root, string name) {
        if(root == NULL || name == root->name) return root;
        for(auto &child : root->children) {
            Node* res = getParent(child, name);
            if(res != NULL) return res; 
        }
        return NULL;
    }

    ThroneInheritance(string kingName) {
        Node* king = new Node(kingName);
        root = king;
        mp[kingName] = king;
    }
    
    void birth(string parentName, string childName) {
        // 1. Find Parent
        Node* parent = mp[parentName];

        // 2. Create new Node for child
        Node* child = new Node(childName);
        mp[childName] = child;

        //3. Parent ke children mai push kardo
        parent->children.push_back(child);
    }
    
    void death(string name) {
        deadSt.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        // simple dfs maaro on root
        vector<string> ans;
        dfs(root, ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */