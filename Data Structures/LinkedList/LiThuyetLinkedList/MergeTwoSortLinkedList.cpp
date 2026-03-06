// Cách 1: Cách của người bế tắc :))
#include <iostream>
#include <vector>
#include <algorithm>
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // Hai danh sách rỗng
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;
        // Danh sách này 1 nút nhưng danh sách còn lại rỗng
        if (list1 == nullptr && list2 != nullptr)
        {
            return list2;
        }
        if (list1 != nullptr && list2 == nullptr)
        {
            return list1;
        }
        // Hai danh sách 1 nút
        if (list1->next == nullptr && list2->next == nullptr)
        {
            if (list1->val > list2->val)
            {
                list2->next = list1;
                return list2;
            }
            else
            {
                list1->next = list2;
                return list1;
            }
        }
        vector<int> val;
        while (list1 != nullptr)
        {
            val.push_back(list1->val);
            list1 = list1->next;
        }
        while (list2 != nullptr)
        {
            val.push_back(list2->val);
            list2 = list2->next;
        }
        sort(val.begin(), val.end());
        ListNode *newHead = new ListNode(val[0]);
        ListNode *temp = newHead;
        for (int i = 1; i < val.size(); i++)
        {
            temp->next = new ListNode(val[i]);
            temp = temp->next;
        }
        return newHead;
    }
};
// Cách giải chuẩn
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // Hai danh sách rỗng
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;
        // Danh sách này 1 nút nhưng danh sách còn lại rỗng
        if (list1 == nullptr && list2 != nullptr)
        {
            return list2;
        }
        if (list1 != nullptr && list2 == nullptr)
        {
            return list1;
        }
        // Hai danh sách 1 nút
        if (list1->next == nullptr && list2->next == nullptr)
        {
            if (list1->val > list2->val)
            {
                list2->next = list1;
                return list2;
            }
            else
            {
                list1->next = list2;
                return list1;
            }
        }
        // Các trường hợp còn lại
        ListNode dummyNode(0);
        ListNode *temp = &dummyNode;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if (list1 != nullptr)
            temp->next = list1;
        else
            temp->next = list2;
        return dummyNode.next;
    }
};