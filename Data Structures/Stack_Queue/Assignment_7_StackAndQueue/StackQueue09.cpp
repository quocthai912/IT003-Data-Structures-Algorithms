/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
using namespace std;

struct NODE
{
    int info;
    NODE *pNext;
};
struct queue
{
    NODE *front;
    NODE *back;
};
NODE *CreatNode(int x)
{
    NODE *p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}
bool isEmpty(const queue &q)
{
    return q.front == nullptr;
}
void enQueue(queue &q, NODE *p)
{
    if (isEmpty(q))
    {
        q.front = q.back = p;
        return;
    }
    q.back->pNext = p;
    q.back = p;
}
bool deQueue(queue &q)
{
    if (isEmpty(q))
        return false;
    NODE *p = q.front;
    q.front = q.front->pNext;
    delete p;
    if (q.front == nullptr)
        q.front = q.back = nullptr;
    return true;
}
int front(const queue &q)
{
    return q.front->info;
}
int back(const queue &q)
{
    return q.back->info;
}
void createQueue(queue &q)
{
    int mangLuuPhanTuDeQueue[10001];
    int dem = 0;
    q.front = q.back = nullptr;
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        if (temp != 0)
        {
            enQueue(q, CreatNode(temp));
        }
        else if (temp == 0)
        {
            if (!isEmpty(q))
            {
                mangLuuPhanTuDeQueue[dem++] = front(q);
                deQueue(q);
            }
        }
        cin >> temp;
    }
    if (dem > 0)
    {
        cout << "output: ";
        for (int i = 0; i < dem; i++)
            cout << mangLuuPhanTuDeQueue[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "output: " << endl;
    }
    if (!isEmpty(q))
    {
        cout << "front: " << front(q) << endl;
        cout << "back: " << back(q) << endl;
    }
    else
    {
        cout << "front: " << endl;
        cout << "back: " << endl;
    }
}
int main()
{
    queue q;
    createQueue(q);
    return 0;
}
