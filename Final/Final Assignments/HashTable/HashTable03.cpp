/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <string>

#define LOAD 0.7
#define EMPTY 0
#define DELETE -1
using namespace std;

struct Hocsinh
{
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Hashtable
{
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    Hocsinh *table;
};

void CreateHashtable(Hashtable &, int);
int Insert(Hashtable &, Hocsinh);
void PrintHashtable(Hashtable);
void DeleteHashtable(Hashtable &);

void Input(Hocsinh &x)
{
    cin >> x.Maso;
    getline(cin >> ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
int main()
{
    Hashtable hashtable;

    int m, n;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Input(hs);
        Insert(hashtable, hs);
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}

void CreateHashtable(Hashtable &ht, int m)
{
    ht.table = new Hocsinh[m];
    if (ht.table == NULL)
        exit(1);
    for (int i = 0; i < m; i++)
    {
        ht.table[i].Maso = EMPTY;
    }
    ht.M = m;
    ht.n = 0;
}

void PrintHashtable(Hashtable ht)
{
    for (int i = 0; i < ht.M; i++)
    {
        Hocsinh hs = ht.table[i];
        if (hs.Maso > 0)
            cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh << ", " << hs.Namsinh << ", " << hs.TBK << "]\n";
        else
            cout << "[" << hs.Maso << ",  " << "  , " << ", " << ", " << "]\n";
    }
}
void DeleteHashtable(Hashtable &ht)
{
    delete[] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int Insert(Hashtable &ht, Hocsinh x)
{
    // Luôn tăng phần tử lên trước nếu bảng băm có hệ số tải
    ht.n++;
    // Nếu vượt quá kích thước (>= LOAD)
    // Thêm thất bại ngay lập tức
    if (ht.n >= ht.M * LOAD)
        return 0;
    // Bắt đầu băm
    int index = x.Maso % ht.M;
    int nprob = 0;
    // Nếu vòng lặp này chạy, tức là đã xảy ra đụng độ
    while (ht.table[index].Maso != EMPTY && ht.table[index].Maso != DELETE && nprob < ht.M)
    {
        nprob++;
        index = ((x.Maso % ht.M) + nprob) % ht.M;
    }
    // Số lần thăm dò vượt quá kích thước của bảng băm
    // Không có vị trí nào có thể thêm được
    if (nprob >= ht.M)
        return 0;
    // Thêm thành công, tìm thấy vị trí thích hợp
    // Có thể không xảy ra đụng độ nào (Vị trí trống)
    // Có thể đã xảy ra đụng độ nhưng thăm dò thành công (< M)
    ht.table[index] = x;
    return 1;
}
