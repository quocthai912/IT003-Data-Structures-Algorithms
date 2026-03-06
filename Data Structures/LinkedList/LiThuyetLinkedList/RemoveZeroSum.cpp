#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode dummyNode(0);
        dummyNode.next = head;
        // Tổng tiền tố
        int prefixSum = 0;
        // Set map lưu tổng tiền tố của từng Node
        unordered_map<int, ListNode *> set_map;
        for (ListNode *curr = &dummyNode; curr != nullptr; curr = curr->next)
        {
            prefixSum += curr->val;
            set_map[prefixSum] = curr;
        }
        prefixSum = 0;
        for (ListNode *curr = &dummyNode; curr != nullptr; curr = curr->next)
        {
            prefixSum += curr->val;
            curr->next = set_map[prefixSum]->next;
        }
        return dummyNode.next;
    }
};