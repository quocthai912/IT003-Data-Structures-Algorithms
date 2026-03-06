#include <iostream>
#include <vector>
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
    bool isPalindrome(ListNode *head)
    {
        // Mảng rỗng hoặc mảng một phần tử
        if (head->next == nullptr && head != nullptr || head == nullptr)
            return true;
        vector<int> mangData;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            mangData.push_back(curr->val);
            curr = curr->next;
        }
        for (int i = mangData.size() - 1; i >= 0; i--)
        {
            if (head->val != mangData[i])
                return false;
            head = head->next;
        }
        return true;
    }
};