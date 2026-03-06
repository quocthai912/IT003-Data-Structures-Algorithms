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
    ListNode *oddEvenList(ListNode *head)
    {
        // Danh sách rỗng
        if (head == nullptr)
            return nullptr;
        // Danh sách chỉ có một nút
        if (head->next == nullptr)
            return head;
        ListNode dummyNode(0);
        ListNode *newHead = nullptr;
        ListNode *currFirst = head;
        ListNode *currSecond = head;
        bool found = false;
        int count = 0;
        while (currFirst != nullptr)
        {
            if (count % 2 == 0)
            {
                if (!found)
                {
                    newHead = new ListNode(currFirst->val);
                    dummyNode.next = newHead;
                    found = true;
                }
                else
                {
                    newHead->next = new ListNode(currFirst->val);
                    newHead = newHead->next;
                }
            }
            currFirst = currFirst->next;
            count++;
        }
        count = 0;
        while (currSecond != nullptr)
        {
            if (count % 2 != 0)
            {
                if (!found)
                {
                    newHead = new ListNode(currSecond->val);
                    dummyNode.next = newHead;
                    found = true;
                }
                else
                {
                    newHead->next = new ListNode(currSecond->val);
                    newHead = newHead->next;
                }
            }
            currSecond = currSecond->next;
            count++;
        }
        return dummyNode.next;
    }
};