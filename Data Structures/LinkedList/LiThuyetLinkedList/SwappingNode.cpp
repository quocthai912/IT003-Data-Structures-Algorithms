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
    int LengthList(ListNode *head)
    {
        if (head == nullptr)
            return 0;
        ListNode *curr = head;
        int count = 0;
        while (curr != nullptr)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }
    ListNode *swapNodes(ListNode *head, int k)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;
        int lengthLinkedList = LengthList(head);
        int count = 1;
        ListNode *pos = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            if (count == k)
            {
                pos = curr;
            }
            curr = curr->next;
            count++;
        }
        curr = head;
        while (curr != nullptr)
        {
            if (lengthLinkedList == k)
            {
                int value = curr->val;
                curr->val = pos->val;
                pos->val = value;
            }
            curr = curr->next;
            lengthLinkedList--;
        }
        return head;
    }
};