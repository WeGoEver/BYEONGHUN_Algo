#include<iostream>
#include<vector>
using namespace std;

int K;
int N;
vector<pair<int,int>> points [20];
int answer = 4000000;

void dfs(int k, int x_min, int x_max, int y_min, int y_max){
    if(k==K){
        int area = (x_max - x_min)*(y_max - y_min);
        if(answer > area){
            answer = area;
        }
        return;
    }

    for(int i=0;i<points[k].size();i++){
        pair<int,int> point = points[k][i];
        int x_min_next = x_min < point.first ? x_min : point.first;
        int x_max_next = x_max > point.first ? x_max : point.first;
        int y_min_next = y_min < point.second ? y_min : point.second;
        int y_max_next = y_max > point.second ? y_max : point.second;

        int next_area = (x_max_next - x_min_next)*(y_max_next - y_min_next);
        if(answer != 4000000 && next_area >= answer){
            continue;
        }else{
            dfs(k+1, x_min_next, x_max_next, y_min_next, y_max_next);
        }
    }
}


int main(int argc, char** argv)
{
    scanf("%d %d",&N,&K);

    for(int i=0;i<N;i++){
        int x, y, k;
        scanf("%d %d %d", &x, &y, &k);

        points[k-1].push_back({x,y});
    }

    dfs(0, 1001, -1001, 1001, -1001);
    cout << answer;
    return 0;
}

/*
dfs 로 탐색을 계속 한다고..?

*/