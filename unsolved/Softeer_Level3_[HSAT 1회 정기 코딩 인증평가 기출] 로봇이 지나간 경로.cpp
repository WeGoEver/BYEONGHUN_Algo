#include<iostream>
#include<string>
using namespace std;

int H, W;
bool map[5][25];
bool visit[5][25];

pair<int,int> position = {-1,-1};
int direction;

int adj[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; // 상, 우, 하, 좌


bool inBound(pair<int,int> position){
    return position.first >= 0 && position.first < H && position.second >= 0 && position.second < W; 
}

int findDirection(pair<int,int> position){
    int i;
    for(i=0;i<4;i++){
        pair<int,int> next;
        next.first = position.first + adj[i][0];
        next.second = position.second + adj[i][1];

        // 범위 내에 있고,
        if(inBound(next)){
            // visit 이 아니고,
            if(visit[next.first][next.second] == false){
                // 가야 할 길 이라면,
                if(map[next.first][next.second] == true){
                    return i;
                }    
            }
        }
    }

    // 4 방향 다 둘러보았는데, 갈 수 있는 방향이 없으면
    if(i == 4){
        return -1;
    }
}

void move(){
    // 일단 방향 찾기
    int newDirection = findDirection(position);
    if(newDirection == -1){
        return;
    }

    // -3, (-2), -1, (0), +1, (+2), +3
    if(direction - newDirection == -3){
        cout << "L";
        direction = newDirection;
    }
    else if(direction - newDirection == -1){
        cout << "R";
        direction = newDirection;
    }
    else if(direction - newDirection == 1){
        cout << "L";
        direction = newDirection;
    }
    else if(direction - newDirection == 3){
        cout << "R";
        direction = newDirection;
    }
    // 갈 방향이랑 현재 방향이랑 같으면, 이동
    pair<int,int> next;
    next.first = position.first + adj[direction][0]*2;
    next.second = position.second + adj[direction][1]*2;

    cout << "A";
    // 이동
    position = next;
    // 지나온 길 방문 처리
    visit[next.first - adj[direction][0]][next.second - adj[direction][1]] = true;
    visit[next.first][next.second] = true;
    
    move();
}

int main(int argc, char** argv)
{
    cin >> H >> W;

    for(int i=0;i<H;i++){
        string s;
        cin >> s;
        for(int j=0;j<W;j++){
            if(s[j] == '#'){
                map[i][j] = true;
                // 1. 시작 위치 찾기
                if(position.first == -1){
                    position = {i,j};
                }
            }
            else{
                map[i][j] = false;
            }
            visit[i][j] = false;
        }
    }
    
    // 2. 시작 위치에서 방향 잡기
    direction = findDirection(position);
    visit[position.first][position.second] = true;

    // 시작 위치 출력
    cout << position.first+1 << " " << position.second+1 << "\n";

    // 처음 방향 출력
    if(direction == 0){
        cout << "^" << "\n";
    }else if(direction == 1){
        cout << ">" << "\n";
    }else if(direction == 2){
        cout << "v" << "\n";
    }else if(direction == 3){
        cout << "<" << "\n";
    }
    
    // 3. move
    move();
    
    return 0;
}

/*
1. 시작 위치 찾기
2. 시작 위치에서 방향 잡기
3. 잡은 방향으로 2칸 가기 A 명령
4. 다시 방향 잡기

*/