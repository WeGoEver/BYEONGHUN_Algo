#include<iostream>
#include<cstring>
using namespace std;

int n, m;
int map[100][100];
int answer;

int main(int argc, char** argv)
{
    scanf("%d %d", &n, &m);
    answer=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &map[i][j]);
            if(map[i][j]==1){
                answer++;
            }
        }
    }

    for(int attack=0;attack<2;attack++){
        // 공격을 수행하는 row 의 index
        int attackIndexFrom, attackIndexEnd;
        scanf("%d %d", &attackIndexFrom, &attackIndexEnd);
        // index 맞춰주기
        attackIndexFrom --;
        attackIndexEnd --;

        for(int i = attackIndexFrom; i <= attackIndexEnd ; i++){
            for(int j=0;j<m;j++){
                if(map[i][j] == 1){
                    map[i][j] = 0;
                    answer--;
                    break;
                }
            }
        }
    }
    
    printf("%d",answer);
    return 0;
}