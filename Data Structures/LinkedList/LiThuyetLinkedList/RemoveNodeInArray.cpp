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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode *prev = &dummyNode;
        while (prev->next != nullptr)
        {
            if (st.count(prev->next->val))
                prev->next = prev->next->next;
            else
                prev = prev->next;
        }
        return dummyNode.next;
    }
};