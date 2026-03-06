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
    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode *next = nullptr;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
    ListNode *reorderList(ListNode *head)
    {
        // Danh sách rỗng
        if (head == nullptr)
            return nullptr;
        // Danh sách chỉ có 1 nút
        if (head->next == nullptr)
            return head;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *curr = head;
        ListNode *prev = nullptr;
        // Duyệt tìm nút giữa
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        // Cắt dãy làm 2 phần bằng nhau
        prev->next = nullptr;
        // Đảo ngược dãy bên phải
        ListNode *right = reverseLinkedList(slow);
        ListNode dummyNode(0);
        ListNode *temp = &dummyNode;
        // Tiến hành trỏ xen kẽ giữa hai dãy
        while (head != nullptr && right != nullptr)
        {
            temp->next = head;
            temp = temp->next;
            head = head->next;
            temp->next = right;
            right = right->next;
            temp = temp->next;
        }
        return dummyNode.next;
    }
};