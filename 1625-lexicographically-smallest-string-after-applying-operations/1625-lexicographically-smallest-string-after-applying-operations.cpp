class Solution {
public:
    string smallestStr;
    string addOper(string node, int a) {
        string temp = node;
        for(int i = 1; i < node.length(); i+=2) {
            temp[i] = ((temp[i] - '0' + a) % 10) + '0';
        }
        return temp;
    }

    string rotateOper(string node, int b) {
        string temp = node;
        reverse(temp.begin(), temp.end());
        reverse(temp.begin(), temp.begin()+b);
        reverse(temp.begin()+b, temp.end());
        return temp;
    }

    void dfs(string node, int &a, int &b, unordered_set<string> &visited) {
        visited.insert(node);

        // add 
        string addState = addOper(node, a);

        // rotate
        string rotateState = rotateOper(node, b);

        if(visited.find(addState) == visited.end()) {
            dfs(addState, a, b, visited);
            if(smallestStr > addState) smallestStr = addState;
        }

        if(visited.find(rotateState) == visited.end()) {
            dfs(rotateState, a, b, visited);
            if(smallestStr > rotateState) smallestStr = rotateState;
        }
    }

    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        smallestStr = s;
        dfs(s, a, b, visited);
        return smallestStr;
    }
};