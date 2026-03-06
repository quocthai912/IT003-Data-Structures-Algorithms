#include <iostream>
using namespace std;
class MyLinkedList
{
private:
    struct Node
    {
        int data;
        Node *pNext;
    };
    struct LinkedList
    {
        Node *pHead;
        Node *pTail;
    };
    LinkedList l;

public:
    Node *initNode(int data)
    {
        Node *p = new Node;
        p->data = data;
        p->pNext = nullptr;
        return p;
    }
    MyLinkedList()
    {
        l.pHead = nullptr;
        l.pTail = nullptr;
    }
    int MaxIndexLinkedList()
    {
        if (l.pHead == nullptr)
            return -1;
        if (l.pHead->pNext == nullptr)
            return 0;
        int count = 0;
        Node *p = l.pHead;
        while (p != nullptr)
        {
            p = p->pNext;
            count++;
        }
        return count - 1;
    }
    int get(int index)
    {
        int maxIndex = MaxIndexLinkedList();
        // Danh sách rỗng và index không hợp lệ
        if (l.pHead == nullptr || index < 0 || index > maxIndex)
            return -1;
        int count = -1;
        Node *p = l.pHead;
        while (p != nullptr)
        {
            count++;
            if (count == index)
                return p->data;
            p = p->pNext;
        }
        return -1;
    }

    void addAtHead(int val)
    {
        // Danh sách rỗng
        if (l.pHead == nullptr)
        {
            l.pHead = initNode(val);
            l.pTail = l.pHead;
        }
        else
        {
            Node *p = initNode(val);
            p->pNext = l.pHead;
            l.pHead = p;
        }
    }
    void printLinkedList()
    {
        if (l.pHead == nullptr)
        {
            cout << "Danh sach rong" << endl;
            return;
        }
        Node *p = l.pHead;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->pNext;
        }
        cout << endl;
    }
    void addAtTail(int val)
    {
        // Danh sách rỗng
        if (l.pHead == nullptr)
        {
            l.pHead = initNode(val);
            l.pTail = l.pHead;
        }
        else
        {
            Node *p = initNode(val);
            l.pTail->pNext = p;
            l.pTail = p;
        }
    }
    Node *returnNodeIndex(int index)
    {
        int maxIndex = MaxIndexLinkedList();
        // Danh sách rỗng và index không hợp lệ
        if (l.pHead == nullptr || index < 0 || index > maxIndex)
            return nullptr;
        if (index == 0)
            return l.pHead;
        if (index == maxIndex)
            return l.pTail;
        int count = -1;
        Node *p = l.pHead;
        while (p != nullptr)
        {
            count++;
            if (count == index)
                return p;
            p = p->pNext;
        }
        return nullptr;
    }
    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > MaxIndexLinkedList() + 1)
            return;
        if (index == 0)
        {
            addAtHead(val);
        }
        else if (index == MaxIndexLinkedList() + 1)
        {
            addAtTail(val);
        }
        else
        {
            Node *prevNode = returnNodeIndex(index - 1);
            Node *addNode = initNode(val);
            addNode->pNext = prevNode->pNext;
            prevNode->pNext = addNode;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index > MaxIndexLinkedList())
            return;
        if (l.pHead == nullptr)
            return;
        // Index = 0
        if (index == 0)
        {
            if (l.pHead == l.pTail)
            {
                delete l.pHead;
                l.pHead = nullptr;
                l.pTail = nullptr;
                return;
            }
            Node *deleteNode = l.pHead;
            l.pHead = l.pHead->pNext;
            delete deleteNode;
        }
        else if (index == MaxIndexLinkedList())
        {
            if (l.pHead == l.pTail)
            {
                delete l.pTail;
                l.pHead = nullptr;
                l.pTail = nullptr;
                return;
            }
            Node *p = l.pHead;
            while (p->pNext != l.pTail)
            {
                p = p->pNext;
            }
            delete l.pTail;
            p->pNext = nullptr;
            l.pTail = p;
        }
        else
        {
            Node *prev = returnNodeIndex(index - 1);
            Node *deleteNode = prev->pNext;
            prev->pNext = deleteNode->pNext;
            delete deleteNode;
        }
    }
};