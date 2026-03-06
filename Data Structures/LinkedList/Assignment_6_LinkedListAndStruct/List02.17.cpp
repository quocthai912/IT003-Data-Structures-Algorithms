/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

struct DONTHUC
{
    float HeSo;
    int SoMu;
};
struct NODE
{
    DONTHUC info;
    NODE *pNext;
};
struct DATHUC
{
    NODE *pHead;
    NODE *pTail;
};
NODE *initNode(DONTHUC value)
{
    NODE *p = new NODE;
    p->info.HeSo = value.HeSo;
    p->info.SoMu = value.SoMu;
    p->pNext = nullptr;
    return p;
}
void addTail(DATHUC &L, NODE *addNode)
{
    if (L.pHead == nullptr)
    {
        L.pHead = L.pTail = addNode;
    }
    else
    {
        L.pTail->pNext = addNode;
        L.pTail = addNode;
    }
}
void CreateEmptyDATHUC(DATHUC &dt)
{
    dt.pHead = nullptr;
    dt.pTail = nullptr;
}
void selectionSort(DATHUC &dt)
{
    if (dt.pHead == nullptr)
        return;
    if (dt.pHead == dt.pTail)
        return;
    NODE *i = dt.pHead;
    while (i)
    {
        NODE *minSoMu = i;
        NODE *j = i->pNext;
        while (j)
        {
            if (j->info.SoMu < minSoMu->info.SoMu)
                minSoMu = j;
            j = j->pNext;
        }
        float HeSo = i->info.HeSo;
        int SoMu = i->info.SoMu;
        i->info.HeSo = minSoMu->info.HeSo;
        i->info.SoMu = minSoMu->info.SoMu;
        minSoMu->info.HeSo = HeSo;
        minSoMu->info.SoMu = SoMu;
        i = i->pNext;
    }
}
void rutGonDaThuc(DATHUC &dt)
{
    if (dt.pHead == nullptr)
        return;
    selectionSort(dt);
    DATHUC rutGon;
    CreateEmptyDATHUC(rutGon);
    DONTHUC giaTriMoi;
    NODE dummyNode;
    dummyNode.pNext = dt.pHead;
    NODE *curr = &dummyNode;
    float tongHeSo = 0.0;
    int soMuHienTai = dt.pHead->info.SoMu;
    while (curr->pNext != nullptr)
    {
        if (curr->pNext->info.SoMu == soMuHienTai)
        {
            tongHeSo += curr->pNext->info.HeSo;
            curr = curr->pNext;
        }
        else
        {
            if (tongHeSo != 0)
            {
                giaTriMoi.HeSo = tongHeSo;
                giaTriMoi.SoMu = soMuHienTai;
                addTail(rutGon, initNode(giaTriMoi));
            }
            tongHeSo = 0.0;
            soMuHienTai = curr->pNext->info.SoMu;
        }
    }
    if (tongHeSo != 0)
    {
        giaTriMoi.HeSo = tongHeSo;
        giaTriMoi.SoMu = soMuHienTai;
        addTail(rutGon, initNode(giaTriMoi));
    }
    dt.pHead = rutGon.pHead;
}
void CreatePolynomial(DATHUC &dt)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        DONTHUC value;
        cin >> value.HeSo >> value.SoMu;
        addTail(dt, initNode(value));
    }
    rutGonDaThuc(dt);
}
void Output(DONTHUC a)
{
    if (a.HeSo == -1)
        cout << "-";
    else if (a.HeSo == 1)
        cout << "";
    else
        cout << a.HeSo;

    if (a.SoMu == 0)
        cout << "";
    else if (a.SoMu == 1)
        cout << "x";
    else if (a.SoMu < 1)
        cout << "-x";
    else // s.SoMu>1
        cout << "x^" << a.SoMu;
}

void Output(DATHUC L)
{
    NODE *p;

    if (L.pHead == NULL)
        cout << "Empty DATHUC.";
    else
    {
        p = L.pHead;
        Output(p->info);
        p = p->pNext;
        while (p)
        {
            cout << " + ";
            Output(p->info);
            p = p->pNext;
        }
    }
}

int main()
{
    DATHUC poly;
    CreateEmptyDATHUC(poly);
    CreatePolynomial(poly);
    Output(poly);
    return 0;
}
