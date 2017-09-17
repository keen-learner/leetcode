/*

A linked list is given such that each node contains an additional random 
pointer which could point to any node in the list or null.

Return a deep copy of the list.

*/

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
        if(!head) return NULL;
        for(RandomListNode *l1 = head; l1; l1 = l1->next->next ) {
            RandomListNode* n = new RandomListNode(l1->label);
            n->next = l1->next;
            l1->next = n;
        }
        RandomListNode* newhead = head->next; 
        for(RandomListNode *l1 = head; l1; l1 = l1->next->next ) {
            if(l1->random) {
                l1->next->random = l1->random->next;
            }  
        }
        RandomListNode* l2 = NULL;
        for(RandomListNode* l1 = head; l1; l1 = l1->next ) {
            l2 = l1->next;
            l1->next = l2->next;
            if(l2->next) l2->next = l2->next->next; 
        }
        return newhead;
    }   
        
};

class Solution1 {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        map<RandomListNode*, RandomListNode*> m;
        for(RandomListNode* curr = head; curr; curr = curr->next) {
            RandomListNode* temp = new RandomListNode(curr->label);
            // m.insert(curr, temp); //insert takes a pair, use make_pair(curr, temp)
            m[curr] = temp;
        }
        for(RandomListNode* curr = head; curr; curr = curr->next) {
            m[curr]->next = m[curr->next];
            m[curr]->random = m[curr->random];
        }
        return m[head];
        
    }
};
