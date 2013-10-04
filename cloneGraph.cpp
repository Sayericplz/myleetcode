/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        map<int,UndirectedGraphNode*> nodes;
        return clone(node,nodes);
    }

    UndirectedGraphNode *clone(UndirectedGraphNode *node,map<int,UndirectedGraphNode*> &nodes)
    {
    	if(!node) return NULL;
    	if(nodes.find(node->label) != nodes.end())
			return nodes[node->label];
		UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        nodes[node->label] = newNode;
		for(int i = 0;i < node->neighbors.size();i++)
		{
			UndirectedGraphNode *neighbor = clone(node->neighbors[i],nodes);
			newNode->neighbors.push_back(neighbor);
		}    
		return newNode;
    }
};