#include<iostream>
#include<cmath>
using namespace std;

long long K; // 처음 바이러스의 수
long long P; // 증가율
long long N; // 총 시간
long long answer;

int main(int argc, char** argv)
{
    cin >> K >> P >> N;
    answer = K;
    
    for(int i=0;i<N;i++){
        answer = (answer * P) % 1000000007;
    }

    cout << answer;
    return 0;
}

/*
a = a * p % k
a * p = 10*k + r

10*k*p + r*p
= 10*k*p + ?*k + r2

10*k*p*p + ?*k*p + r2*p
*/