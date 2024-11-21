#include<iostream>
#include<queue>
using namespace std;

int n; // 칸 크기
int m; // 친구 수
int maxSum;
int map[20][20]; // 칸마다 열매 수확량
pair<int,int> pos[3]; // 친구들의 처음 위치
pair<int,int> currentPos[3];

int adj[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void calculateMaxSum(int currentSum) {
    
    for(int i=0;i<m;i++){
        currentSum += map[currentPos[i].first][currentPos[i].second];
        map[currentPos[i].first][currentPos[i].second] = 0;

        for(int i=0;i<4;i++){
            
        }
        
    }
}

int main(int argc, char** argv)
{
    // 입력 받기
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&map[i][j]);
        }
    }

    // pos 입력 받기
    for(int i=0;i<m;i++){
        scanf("%d %d", &pos[i].first, &pos[i].second);
        // 입력 -> index 로 맞추기
        pos[i].first--;
        pos[i].second--;
    }

    calculateMaxSum();

    cout << maxSum;
    return 0;
}