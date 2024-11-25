#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> A;
long long B;

// k가 주어졌을 때, 달성 가능한지 확인하는 함수
bool canUpgrade(long long k){
    long long currentB = B;
    
    for(int i=0;i<N;i++){
        // 만약 A[i] 가 k보다 작으면, k까지 업그레이드하고, 비용 차감
        if(A[i] < k){
            currentB = currentB - (k-A[i])*(k-A[i]);
            // 비용이 - 가 되었다면, 업그레이드 실패
            if(currentB < 0){
                return false;
            }
        }
    }
    
    return true;
}

int main(int argc, char** argv)
{
    scanf("%d", &N);
    
    scanf("%lld", &B);

    int a;
    for(int i=0;i<N;i++){
        scanf("%d", &a);
        A.push_back(a);
    }


    long long answer = 0;
    long long left = 1;
    long long right = 2*1000000000;
    long long mid;
    
    while(left <= right){
        mid = (left + right) / 2;
        
        if(canUpgrade(mid) == true){
            answer = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    

    cout << answer;
    return 0;
}

/*
N 대의 컴퓨터 중, 각각의 성능 a[i]

성능을 d만큼 향상 비용 : d*d

한번에 두 번 이상 x

예산 B원.

성능이 가장 낮은 컴퓨터의 성능을 최대화

최선의 최저성능


우선 가장 낮을 성능의 컴퓨터를 찾아서
1. 최대로 업그레이드 해도, 가장 낮은 성능
2. 가장 낮은 성능은 탈출, 

가장 낮은 성능을 K 로 만들기
K 이하인 애들 데려와서 K로 만들기

K=3 으로 만들기 -> 성능이 3 미만인 애들 데려와서 3으로 만들어주기 -> 가능 ok
K=4 로 만들기 -> 성능이 4 미만인 애들 데려와서 4로 만들어주기 -> 하다가 초과,,

K 값을 이분탐색하여 가능한 최대값 찾기

일단 k 값이 주어지면, 달성 가능한지 판단하는 함수 만들기
-> O(n)

이분탐색 -> 최저의 최대값
다 N=1이고, A[0]가 10^9 야, 근데, 예산 B도 최대야 ->10^18
10^9 + 10^9 = > 2*10^9

이분탐색 -> log(2*10^9) * 10000 = 100000



*/