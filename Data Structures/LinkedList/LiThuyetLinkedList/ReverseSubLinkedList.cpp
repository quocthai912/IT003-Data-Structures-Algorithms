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
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;
        if (left == 1 && right == 1)
            return head;
        if (left == 1)
        {
            int count = 0;
            ListNode *curr = head;
            ListNode *nutRight = nullptr;
            ListNode *benPhaiChuoiCon = nullptr;
            while (curr != nullptr)
            {
                count++;
                if (count + 1 == right)
                {
                    benPhaiChuoiCon = curr->next->next;
                    nutRight = curr->next;
                }
                curr = curr->next;
            }
            nutRight->next = nullptr;
            ListNode *newHead = reverseLinkedList(head);
            head->next = benPhaiChuoiCon;
            return newHead;
        }
        else
        {
            int count = 0;
            ListNode *curr = head;
            ListNode *nutRight = nullptr;
            ListNode *nutLeft = nullptr;
            ListNode *benPhaiChuoiCon = nullptr;
            ListNode *benTraiChuoiCon = nullptr;
            while (curr != nullptr)
            {
                count++;
                if (count + 1 == right)
                {
                    benPhaiChuoiCon = curr->next->next;
                    nutRight = curr->next;
                }
                if (count + 1 == left)
                {
                    benTraiChuoiCon = curr;
                    nutLeft = curr->next;
                }
                curr = curr->next;
            }
            benTraiChuoiCon->next = nullptr;
            nutRight->next = nullptr;
            ListNode *newHead = reverseLinkedList(nutLeft);
            benTraiChuoiCon->next = newHead;
            nutLeft->next = benPhaiChuoiCon;
            return head;
        }
    }
};