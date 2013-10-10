/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        map<RandomListNode *,RandomListNode *> index;
        return copy(head,index);
    }

    RandomListNode *copy(RandomListNode *node,map<RandomListNode *,RandomListNode *> &index)
    {
    	if(!node) return NULL;
    	if(index.find(node) != index.end()) return index[node];
    	RandomListNode *newNode = new RandomListNode(node->label);
    	index[node] = newNode;
    	RandomListNode *newNext = copy(node->next,index);
    	RandomListNode *newRand = copy(node->random,index);
    	newNode->next = newNext;
    	newNode->random = newRand;
    	return newNode;
    }
};