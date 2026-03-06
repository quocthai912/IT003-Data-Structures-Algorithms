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
    int MaxIndexListNode(ListNode *head)
    {
        int count = -1;
        while (head != nullptr)
        {
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == nullptr)
            return nullptr;
        int middleIndex;
        int maxIndex = MaxIndexListNode(head);
        if (maxIndex % 2 == 0)
        {
            middleIndex = maxIndex / 2;
        }
        else
        {
            middleIndex = (maxIndex / 2) + 1;
        }
        int count = -1;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            count++;
            if ((count + 1) == middleIndex)
            {
                ListNode *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                return head;
            }
            curr = curr->next;
        }
        return head;
    }
};