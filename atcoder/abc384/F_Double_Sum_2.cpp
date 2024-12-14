#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int f(int x)
{
    while (x % 2 == 0)
    {
        x /= 2;
    }
    return x;
}

long long solve(int N, const vector<int> &A)
{
    const int MAX_VAL = 20000000;
    vector<int> f_values(MAX_VAL + 1);
    for (int i = 1; i <= MAX_VAL; ++i)
    {
        f_values[i] = f(i);
    }
    unordered_map<int, long long> freq;
    for (int i = 0; i < N; ++i)
    {
        freq[A[i]]++;
    }
    long long result = 0;
    vector<int> unique_values;
    for (const auto &entry : freq)
    {
        unique_values.push_back(entry.first);
    }

    for (size_t i = 0; i < unique_values.size(); ++i)
    {
        for (size_t j = i; j < unique_values.size(); ++j)
        {
            int v1 = unique_values[i];
            int v2 = unique_values[j];
            int pair_sum = v1 + v2;
            long long count = 0;
            if (v1 == v2)
            {
                count = (freq[v1] * (freq[v1] - 1)) / 2 + freq[v1];
            }
            else
            {
                count = freq[v1] * freq[v2];
            }
            result += f_values[pair_sum] * count;
        }
    }

    return result;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    cout << solve(N, A) << endl;
    return 0;
}