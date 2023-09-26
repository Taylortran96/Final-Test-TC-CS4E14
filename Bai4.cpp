#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool is_prime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

vector<int> find_super_primes(int n)
{
    vector<int> super_primes;
    queue<int> q;

    // Thêm các số từ 2 đến 9 vào queue ban đầu
    for (int i = 2; i <= 9; i++)
    {
        q.push(i);
    }

    // Sử dụng queue để tìm tất cả các số siêu nguyên tố nhỏ hơn hoặc bằng n
    while (!q.empty())
    {
        int current_num = q.front();
        q.pop();

        // Kiểm tra xem số hiện tại là số siêu nguyên tố
        if (is_prime(current_num))
        {
            string current_str = to_string(current_num);
            if (current_str.length() == 1 || current_num <= n)
            {
                super_primes.push_back(current_num);
            }

            // Thêm các số mới được tạo ra vào queue
            for (int i = 0; i <= 9; i++)
            {
                int new_num = current_num * 10 + i;
                if (new_num <= n)
                {
                    q.push(new_num);
                }
            }

            for (int i = 1; i < current_str.length(); i++)
            {
                int new_num = stoi(current_str.substr(0, i));
                if (new_num <= n)
                {
                    q.push(new_num);
                }
            }
        }
    }

    return super_primes;
}

int main()
{
    int n;
    cout << "Nhap mot so nguyen n: ";
    cin >> n;

    vector<int> super_primes = find_super_primes(n);
    cout << "Cac so sieu nguyen to nho hon hoac bang " << n << " la: ";
    for (int i = 0; i < super_primes.size(); i++)
    {
        cout << super_primes[i] << " ";
    }
    cout << endl;

    return 0;
}
