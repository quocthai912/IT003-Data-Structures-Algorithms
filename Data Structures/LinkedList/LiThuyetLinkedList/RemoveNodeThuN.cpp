// Xóa node thứ N từ cuối
// Cách 1: Duyệt Fast-Slow, cho Fast chạy với n bước, Slow chạy 1 bước
// Khi Fast tiến tới cuối, Slow sẽ chạy tới trước node cần xóa.
// Nhược điểm: Khó hiểu với người mới, chưa có kĩ thuật áp dụng two-pointer và dummyNode
// Ưu điểm, code ngắn gọn, dễ đọc
// Cách này phải cài đặt nút ảo, vì nút đầu có thể sẽ bị xóa
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Edges Case: Danh sách 1 nút
        if (head->next == nullptr)
            return nullptr;
        ListNode dummyNode(0);
        int count = 0;
        dummyNode.next = head;
        ListNode *fast = &dummyNode;
        ListNode *slow = &dummyNode;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *deleteNode = slow->next;
        slow->next = deleteNode->next;
        delete deleteNode;
        return dummyNode.next;
    }
};
// Cách 2, duyệt vòng lặp thông thường, dễ hiểu, độ phức tạp thuật toán là như nhau
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
    int demNode(ListNode *head)
    {
        int count = 0;
        while (head != nullptr)
        {
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Edges Case: Danh sách 1 nút
        if (head->next == nullptr)
            return nullptr;
        int count = demNode(head);
        // Edges Case: Xóa nút đầu
        if (count == n)
            return head->next;
        ListNode *deleteNode = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            if (count - 1 == n)
            {
                deleteNode = curr->next;
                curr->next = deleteNode->next;
                delete deleteNode;
                return head;
            }
            curr = curr->next;
            count--;
        }
        return head;
    }
};