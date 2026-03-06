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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode *prev = &dummyNode; // Node đứng trước cặp đang swap
        while (head != nullptr && head->next != nullptr)
        {
            ListNode *first = head;
            ListNode *second = head->next;
            // Swap
            prev->next = second;
            first->next = second->next;
            second->next = first;
            prev = first;
            head = first->next;
        }
        return dummyNode.next;
    }
};