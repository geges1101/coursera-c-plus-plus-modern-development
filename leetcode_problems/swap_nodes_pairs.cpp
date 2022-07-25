#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
             return head;
        }
            ListNode* dummy_head = head->next;
            head->next = swapPairs(dummy_head->next);
            dummy_head->next = head;

        return dummy_head;
    }
};