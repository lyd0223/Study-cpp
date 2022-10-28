#include <bits/stdc++.h>
#include <random>

using namespace std;

std::random_device g_rd;
std::mt19937 g_gen = mt19937(g_rd());

int NDRandomInt(int num)
{
    int standardDeviation = num / 10;
    std::normal_distribution<double> dist(/* 평균 = */ num/2, /* 표준 편차 = */ standardDeviation);

    return round(dist(g_gen));
}
int NDRandomInt(int startNum, int endNum)
{
    int avg = (startNum + endNum) / 2;
    int standardDeviation = (endNum - startNum) / 10;
    std::normal_distribution<double> dist(/* 평균 = */ avg, /* 표준 편차 = */ standardDeviation);

    return round(dist(g_gen));
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    std::map<int, int> m{};
    for (int n = 0; n < 10000; ++n) {
        ++m[NDRandomInt(50,100)];
    }
    for (auto p : m) {
        std::cout << std::setw(2) << p.first << ' '
            << std::string(p.second / 100, '*') << " " << p.second << '\n';
    }

    
    return 0;
    
}
