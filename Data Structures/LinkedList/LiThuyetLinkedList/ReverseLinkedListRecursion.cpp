// Ưu điểm: cách ngắn gọn, dễ đọc
// Nhược điểm chí mạng: Tràn bộ nhớ khi gọi stack liên tục, bộ nhớ chiếm lên tới O(n)
// Cách vòng lặp tuy dài dòng và thao tác với 3 con trỏ, nhưng chỉ chiếm bộ nhớ có O(1)
// Kết luận: không nên xài cách này cho Linked List, kham khảo thôi
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *newHead = reverseList(head->next); // Trả về nút đầu mới, ví dụ 1->2 sẽ thành 2->1
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};