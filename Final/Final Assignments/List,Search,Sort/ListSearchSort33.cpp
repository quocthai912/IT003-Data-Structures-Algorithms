/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

NODE *CreateNode(int data)
{
    NODE *p = new NODE;
    p->data = data;
    p->next = nullptr;
    return p;
}

struct LIST
{
    NODE *head;
    NODE *tail;
};

void CreateEmptyList(LIST &l)
{
    l.head = l.tail = nullptr;
}

void AddTail(LIST &l, int data)
{
    NODE *p = CreateNode(data);
    if (l.head == nullptr)
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void CreateList(LIST &l)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        AddTail(l, data);
        cin >> data;
    }
}

void add_after_middle(LIST &l, int Y)
{
    if (l.head == nullptr)
        return;
    NODE *slow = l.head;
    NODE *fast = l.head->next;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    NODE *p = CreateNode(Y);
    p->next = slow->next;
    slow->next = p;
}

void PrintList(LIST l)
{
    if (l.head == nullptr)
    {
        cout << "Empty List.";
        return;
    }
    NODE *p = l.head;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LIST L;
    int X, Y;

    CreateEmptyList(L);

    CreateList(L);

    std::cin >> Y;
    add_after_middle(L, Y);

    PrintList(L);

    return 0;
}
