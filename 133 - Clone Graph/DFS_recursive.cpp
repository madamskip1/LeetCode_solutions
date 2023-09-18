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
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        auto val = node->val;
        auto clonedNode = new Node(val);
        nodeTraversed.emplace(val, clonedNode);

        for (auto neighbor : node->neighbors)
        {
            if (nodeTraversed.contains(neighbor->val))
            {
                clonedNode->neighbors.emplace_back(nodeTraversed[neighbor->val]);
            }
            else
            {
                Node* clonedNeighbor = cloneGraph(neighbor);
                clonedNode->neighbors.emplace_back(clonedNeighbor);
            }
        }

        return clonedNode;
    }

private:
    std::unordered_map<int, Node*> nodeTraversed;
};