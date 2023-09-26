// * Xây dựng lớp `’Vemaybay’ gồm:
// - Thuộc tính: ‘tenchuyen’, ‘ngaybay’,  ‘giave’
// - Phương thức:
//     - Hàm tạo
//     - Hàm hủy
//     - Nhap
//     - Xuat
//     - ‘getgiave()’: hàm trả về giá vé

// * Xây dựng lớp Nguoi gồm:
// - Thuộc tính: ‘hoten’,  ‘gioitinh’, ‘tuoi’
// - Phương thức:
//       - Hàm tạo
//     - Hàm hủy
//     - Nhập
//     - Xuất

// * Xây dựng lớp `’hanhkhach’ (mỗi hành khách được mua nhiều vé) kế thừa lớp ‘nguoi’
// Bổ sung thêm:
// - Thuộc tính: `’Vemaybay * ve’; ‘int soluong’;
// - Phương thức:
//     - Hàm tạo
//     - Hàm hủy
//     - Nhập
//     - Xuất
//     - ‘tongtien()’: trả về Tổng số tiền phải trả của hành khách

// Chương trình chính: Nhập vào 1 danh sách n hành khách (n nhập từ bàn phím).
// Hiển thị danh sách hành khách và số tiền phải trả tương ứng của mỗi khách hàng.
// Sắp xếp danh sách hành khách theo chiều giảm dần của Tổng tiền.

//-- Lớp Vemaybay:
#include <iostream>
#include <string>
using namespace std;

class Vemaybay
{
public:
    string tenchuyen;
    string ngaybay;
    double giave;

    Vemaybay() {}
    ~Vemaybay() {}

    void Nhap()
    {
        cin.ignore();
        cout << "Nhap ten chuyen: ";
        getline(cin, tenchuyen);
        cout << "Nhap ngay bay: ";
        getline(cin, ngaybay);
        cout << "Nhap gia ve: ";
        cin >> giave;
    }

    void Xuat()
    {
        cout << "Ten chuyen: " << tenchuyen << endl;
        cout << "Ngay bay: " << ngaybay << endl;
        cout << "Gia ve: " << giave << endl;
    }

    double getgiave()
    {
        return giave;
    }
};

//-- Lớp Nguoi:
class Nguoi
{
public:
    string hoten;
    string gioitinh;
    int tuoi;

    Nguoi() {}
    ~Nguoi() {}

    void Nhap()
    {
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, hoten);
        cout << "Nhap gioi tinh: ";
        getline(cin, gioitinh);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
    }

    void Xuat()
    {
        cout << "Ho ten: " << hoten << endl;
        cout << "Gioi tinh: " << gioitinh << endl;
        cout << "Tuoi: " << tuoi << endl;
    }
};

//-- Lớp Hanhkhach:
class Hanhkhach : public Nguoi
{
public:
    Vemaybay *ve;
    int soluong;

    Hanhkhach() {}
    ~Hanhkhach() {}

    void Nhap()
    {
        Nguoi::Nhap();
        cout << "Nhap so luong ve: ";
        cin >> soluong;
        ve = new Vemaybay[soluong];
        for (int i = 0; i < soluong; i++)
        {
            cout << "Nhap thong tin ve may bay thu " << i + 1 << ":" << endl;
            ve[i].Nhap();
        }
    }

    void Xuat()
    {
        Nguoi::Xuat();
        cout << "So luong ve: " << soluong << endl;
        for (int i = 0; i < soluong; i++)
        {
            cout << "Thong tin ve may bay thu " << i + 1 << ":" << endl;
            ve[i].Xuat();
        }
        cout << "Tong tien phai tra: " << tongtien() << endl;
    }

    double tongtien()
    {
        double tong = 0;
        for (int i = 0; i < soluong; i++)
        {
            tong += ve[i].getgiave();
        }
        return tong;
    }
};

//-- Chương trình chính:
int main()
{
    int n;
    cout << "Nhap so luong hanh khach: ";
    cin >> n;
    Hanhkhach *dsHanhkhach = new Hanhkhach[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin cho hanh khach thu " << i + 1 << ":" << endl;
        dsHanhkhach[i].Nhap();
    }
    // Tính tổng tiền phải trả và hiển thị danh sách hành khách:
    double tongtien;
    for (int i = 0; i < n; i++)
    {
        tongtien = dsHanhkhach[i].tongtien();
        cout << "Thong tin hanh khach thu " << i + 1 << ":" << endl;
        dsHanhkhach[i].Xuat();
        cout << endl;
    }
    // Sắp xếp danh sách hành khách theo chiều giảm dần của tổng tiền:
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (dsHanhkhach[i].tongtien() < dsHanhkhach[j].tongtien())
            {
                Hanhkhach tmp = dsHanhkhach[i];
                dsHanhkhach[i] = dsHanhkhach[j];
                dsHanhkhach[j] = tmp;
            }
        }
    }
    // In ra danh sách hành khách đã được sắp xếp:
    cout << "Danh sach hanh khach da sap xep theo chieu giam dan cua tong tien:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Thong tin hanh khach thu " << i + 1 << ":" << endl;
        dsHanhkhach[i].Xuat();
        cout << endl;
    }
    delete[] dsHanhkhach;
    return 0;
}
