// Merge Sort (Sắp xếp trộn) Độ phức tạp O(nlogn)
// Đây là cách tốt nhất để sắp xếp một danh sách liên kết
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
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = nullptr;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        ListNode *mid = slow;
        prev->next = nullptr;
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return mergeSort(left, right);
    }

private:
    ListNode *mergeSort(ListNode *list1, ListNode *list2)
    {
        ListNode dummyNode(0);
        ListNode *temp = &dummyNode;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
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