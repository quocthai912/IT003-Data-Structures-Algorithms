// No Template.
// Xóa Tất Cả Khóa Key Trong Bảng Băm Có Giá Trị Là Số Nguyên Tố.
// Xử Lí Đụng Độ (Thăm Dò Bậc Hai).
#include <iostream>
#include <vector>
using namespace std;
vector<int> primeNumbers;
#define DELETE -2
#define EMPTY -1
struct HASHTABLE
{
    int M;
    int N;
    int *table;
};
bool isPrime(int number)
{
    if (number < 2)
        return false;
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}
int HF(int key, int M)
{
    return key % M;
}
int HF_QuadraticProbing(int key, int M, int i)
{
    return (HF(key, M) + i * i) % M;
}
void CreateEmptyHashTable(HASHTABLE &ht, int M)
{
    ht.table = new int[M];
    for (int i = 0; i < M; i++)
    {
        ht.table[i] = EMPTY;
    }
    ht.M = M;
    ht.N = 0;
}
void InsertHashTable(HASHTABLE &ht, int key)
{
    int i = 0;
    int index = HF(key, ht.M);
    // Xử lí trùng khóa
    if (ht.table[index] == key)
        return;
    while (ht.table[index] != EMPTY && i < ht.M)
    {
        if (ht.table[index] == key)
            return;
        i++;
        index = HF_QuadraticProbing(key, ht.M, i);
    }
    if (i >= ht.M)
        return;
    ht.table[index] = key;
    ht.N++;
}
void CreateHashTable(HASHTABLE &ht)
{
    int M;
    cin >> M;
    CreateEmptyHashTable(ht, M);
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        InsertHashTable(ht, temp);
        if (isPrime(temp))
            primeNumbers.push_back(temp);
        cin >> temp;
    }
}
bool DeleteKey(HASHTABLE &ht, int key)
{
    int i = 0;
    int index = HF(key, ht.M);
    while (ht.table[index] != EMPTY && i < ht.M)
    {
        if (ht.table[index] == key)
        {
            ht.table[index] = DELETE;
            return true;
        }
        i++;
        index = HF_QuadraticProbing(key, ht.M, i);
    }
    return false;
}
void DeletePrimeKey(HASHTABLE &ht, bool &deleteSuccesful)
{
    for (int i = 0; i < primeNumbers.size(); i++)
    {
        if (DeleteKey(ht, primeNumbers[i]))
        {
            deleteSuccesful = true;
        }
    }
}
void PrintHashTable(HASHTABLE ht)
{
    if (ht.N == 0)
    {
        cout << "Empty Hash Table." << endl;
        return;
    }
    for (int i = 0; i < ht.M; i++)
    {
        cout << i << "| ";
        if (ht.table[i] == EMPTY)
            cout << "EMPTY";
        else if (ht.table[i] == DELETE)
            cout << "DELETE";
        else
            cout << ht.table[i];
        cout << endl;
    }
}
int main()
{
    HASHTABLE ht;
    CreateHashTable(ht);
    cout << "HASH TABLE truoc khi xoa toan bo so nguyen to: ";
    cout << endl;
    PrintHashTable(ht);
    cout << "HASH TABLE sau khi xoa toan bo so nguyen to: ";
    cout << endl;
    bool deleteSuccesful = false;
    DeletePrimeKey(ht, deleteSuccesful);
    PrintHashTable(ht);
    if (deleteSuccesful)
    {
        cout << "Cac so nguyen to duoc xoa thanh cong";
    }
    else
    {
        cout << "Khong tim thay so nguyen to de xoa";
    }
    return 0;
}
