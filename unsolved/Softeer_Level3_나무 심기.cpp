#include<iostream>
using namespace std;

int n;
int sum[1000][1000];
int max[1000][1000];
int answer;
int map[1000][1000];

int main(int argc, char** argv)
{
    // n 입력 받기
    scanf("%d",&n);
    // map 입력 받기
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&map[i][j]);
        }
    }

    // [0][0]
    sum[0][0] = map[0][0];
    max[0][0] = map[0][0];
    
    // 가장자리에 대해서, sum[][] 과 max[][] 계산
    for(int i=1;i<n;i++){
        // 가로에 대해서
        sum[0][i] = sum[0][i-1] + map[0][i];
        max[0][i] = max[0][i-1] > map[0][i] ? max[0][i-1] : map[0][i];
        // 세로에 대해서
        sum[i][0] = sum[i-1][0] + map[i][0];
        max[i][0] = max[i-1][0] > map[i][0] ? max[i-1][0] > map[i][0];
    }
    
    // 나머지에 대해서, sum[][] 과 max[][] 계산
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            // 위에서 오늘 거랑, 아래서 오는 것 중, 큰 거 선택
            int beforeSum = sum[i-1][j] > sum[i][j-1] ? sum[i-1][j] : sum[i][j-1];
            // 큰 거랑 지금 거랑 합쳐서 sum 계산
            sum[i][j] = beforeSum + map[i][j];

              
        }
    }

    
    return 0;
}

/*
브루트포스로 풀 수 있지 않을까?

우선 모든 경로에 대해서
합을 구하고, 수로가 연결된 곳들 중에 max인 곳에다가 스프링클러 달기 -> localSum 을 구해

다 돌고 나면 max를 구했다.

DP 같은데
해당 지점까지의 sum 과, 가장 컸던 숫자 max 를 기억

// 정답의 범위
최대 : 1000 * 2000 = 2000000 int로 가능
*/