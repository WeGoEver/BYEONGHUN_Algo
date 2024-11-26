#include<iostream>
using namespace std;

int N;
int T;
int lightSet[100][100][4];
bool visit[100][100];

bool checkBound(pair<int,int> pos){
    return pos.first >= 0 && pos.first < N && pos.second >= 0 && pos.second < N;
}

void drive(pair<int,int> position, int direction, int state, int currentT);

void moveUp(pair<int,int> position, int direction, int state, int currentT){
    if(checkBound({position.first-1, position.second})){
        drive({position.first-1, position.second}, 0, (state+1)%4, currentT+1);
    }
}
void moveRight(pair<int,int> position, int direction, int state, int currentT){
    if(checkBound({position.first, position.second+1})){
        drive({position.first, position.second+1}, 1, (state+1)%4, currentT+1);
    }
}
void moveDown(pair<int,int> position, int direction, int state, int currentT){
    if(checkBound({position.first+1, position.second})){
        drive({position.first+1, position.second}, 2, (state+1)%4, currentT+1);
    }
}
void moveLeft(pair<int,int> position, int direction, int state, int currentT){
    if(checkBound({position.first, position.second-1})){
        drive({position.first, position.second-1}, 3, (state+1)%4, currentT+1);
    }
}

// direction : 위, 오, 아, 왼
//              0,  1, 2,  3
void drive(pair<int,int> position, int direction, int state, int currentT){
    // 일단 교차로에 도착
    if(visit[position.first][position.second] == false){
        visit[position.first][position.second] = true;
    }

    // 시간이 다 되면 끝
    if(currentT == T){
        return;  
    }

    // 현재 위치의 lightSet 의 신호 번호
    int lightNumber = lightSet[position.first][position.second][state];
    
    // 차가 위 방향을 보고 있을 때,
    if(direction == 0){
        if(lightNumber == 2){
            // 좌회전
            moveLeft(position, direction, state, currentT);
            // 직진
            moveUp(position, direction, state, currentT);
            // 우회전
            moveRight(position, direction, state, currentT);
        }
        else if(lightNumber == 6){
            // 좌회전
            moveLeft(position, direction, state, currentT);
            // 직진
            moveUp(position, direction, state, currentT);
        }
        else if(lightNumber == 10){
            // 직진
            moveUp(position, direction, state, currentT);
            // 우회전
            moveRight(position, direction, state, currentT);
        }
    }
    // 차가 오늘쪽 방향을 보고 있을 때,
    if(direction == 1){
        if(lightNumber == 1){
            // 좌회전
            moveUp(position, direction, state, currentT);
            // 직진
            moveRight(position, direction, state, currentT);
            // 우회전
            moveDown(position, direction, state, currentT);
        }
        else if(lightNumber == 5){
            // 좌회전
            moveUp(position, direction, state, currentT);
            // 직진
            moveRight(position, direction, state, currentT);
        }
        else if(lightNumber == 9){
            // 직진
            moveRight(position, direction, state, currentT);
            // 우회전
            moveDown(position, direction, state, currentT);
        }
    }
    // 차가 아래 방향을 보고 있을 때,
    if(direction == 2){
        if(lightNumber == 4){
            // 좌회전
            moveRight(position, direction, state, currentT);
            // 직진
            moveDown(position, direction, state, currentT);
            // 우회전
            moveLeft(position, direction, state, currentT);
        }
        else if(lightNumber == 8){
            // 좌회전
            moveRight(position, direction, state, currentT);
            // 직진
            moveDown(position, direction, state, currentT);
        }
        else if(lightNumber == 12){
            // 직진
            moveDown(position, direction, state, currentT);
            // 우회전
            moveLeft(position, direction, state, currentT);
        }
    }
    // 차가 왼쪽 방향을 보고 있을 때,
    if(direction == 3){
        if(lightNumber == 3){
            // 좌회전
            moveDown(position, direction, state, currentT);
            // 직진
            moveLeft(position, direction, state, currentT);
            // 우회전
            moveUp(position, direction, state, currentT);
        }
        else if(lightNumber == 7){
            // 좌회전
            moveDown(position, direction, state, currentT);
            // 직진
            moveLeft(position, direction, state, currentT);
        }
        else if(lightNumber == 11){
            // 직진
            moveLeft(position, direction, state, currentT);
            // 우회전
            moveUp(position, direction, state, currentT);
        }
    }

    return; 
}


int main(int argc, char** argv)
{
    cin >> N >> T;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            visit[i][j] = false;
            for(int k=0;k<4;k++){
                scanf("%d",&lightSet[i][j][k]);
            }
        }
    }
    
    drive(make_pair(0,0), 0, 0, 0);

    int answer = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visit[i][j] == true){
                answer++;
            }
        }
    }
    
    cout << answer;
    return 0;
}

/*

12가지 상태? 
- 우회전, 자회전, 가능 : 4
- 우회전만 가능 : 4
- 좌회전만 가능 : 4

*/