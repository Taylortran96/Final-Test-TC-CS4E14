#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

bool is_prime(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

vector<int> super_primes(int n)
{
    vector<int> result;
    queue<int> q;

    while (!q.empty())
    {
        int num = q.front();
        q.pop();
        if (num <= n)
        {
            if (is_prime(num))
            {
                result.push_back(num);
            }
            for (int i = 1; i <= 9; i += 2)
            {
                int new_num = num * 10 + i;
                if (is_prime(new_num))
                {
                    q.push(new_num);
                }
            }
        }
    }

    return result;
}

int main()
{
    int n;
    cout << "Nhập một số nguyên dương: ";
    cin >> n;

    vector<int> super_primes_list = super_primes(n);

    cout << "Các số siêu nguyên tố nhỏ hơn hoặc bằng " << n << " là: ";
    for (int i = 0; i < super_primes_list.size(); i++)
    {
        cout << super_primes_list[i] << " ";
    }

    return 0;
}
