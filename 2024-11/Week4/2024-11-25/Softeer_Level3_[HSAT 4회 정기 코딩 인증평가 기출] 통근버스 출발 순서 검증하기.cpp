#include<iostream>
#include<algorithm>
using namespace std;

int N;
int busNumberList[5000];
long long answer;

int main(int argc, char** argv)
{
    answer=0;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &busNumberList[i]);
    }

    for(int i=0;i<N-2;i++){
        int currentBusNumber = busNumberList[i];
        int sum = 0;
        for(int j=i+1;j<N;j++){
            // 현재 버스 번호보다 크면, sum의 크기를 ++
            if(currentBusNumber < busNumberList[j]){
                sum++;
            }
            // 현재 버스 번호보다 작으면, answer = answer + sum;
            else{
                answer = answer + sum;
            }
        }
    }

    cout << answer;
    return 0;
}

/*

[4 입장]
나보다 큰 게 나오면, 더하는 수 ++
4보다 큰 이후로, 4보다 작은 게 있으면 + 더하는 수
N + N-1 + 

*/

/*
번호 순서대로 출발

출구, 임시 주차장(스택), 주차장

(i,j,k) 의 케이스를 몇 개나 찾을 수 있는지?
aj 가 ai 보다 크고, ak 보다는 작ㅇ

ai < aj && ai > ak

맨 앞의 애가, 뒤의 애 중에서는 작고, 맨 뒤의 애보다는 크면

맨 뒤의 애 때문에, 먼저 나갈 수는 없어,,
근데 뒤의 애 때문에 먼저 나가야 해

일단 뒤에 나보다 작은 애가 있네 -> 지금 나가면 안된다.
근데, 나보다 작은 애보다 앞쪽에 나보다 큰 애가 있다. -> 나보다 큰 애가 있으면, 내가 먼저 나가야 하는데, 나는 지금 못 나가..!


[4 입장]에서는
뒤에 나보다 작은애 : 2,3,1
2 앞에, 나보다 큰 애 -> x
3 앞에, 나보다 큰 애 : 5 -> +1
1 앞에, 나보다 큰 애 5 있네 -> +1

[2 입장]
뒤에 나보다 작은 애 : 1
1 앞에, 나보다 큰 애 : 5, 3 -> +2

[5 입장]
뒤에 나보다 작은 애 -> x

[3 입장]
뒤에 나보다 작은 애 -> x


i -> 뒤에 a[i] 보다 큰 애들의 index
i -> 앞에 a[i] 보다 작은 애들의 index

vector<int> smallIndexList[N];
vector<int> bigIndexList[N];

smallIndexList[0] = 1,3,4;
bigIndexList[0] = 2;

[0] 입장에서
smallIndexList 의 원소보다, bigIndexList 의 원소의 값이 작으면(앞에 있으면) ++

그러면,
vector<int> smallIndexList[N];
vector<int> bigIndexList[N];
얘네를 구성하는 데에 걸리는 시간을 줄여보자.
N + N-1 + N-2 + N-3 + ... + 1
n(n+1) = O(n^2)

5000*5000 = 25000000


(4,0) (2,1) (5,2) (3,3) (1,4)

(a,인덱스)
(1,4) (2,1) (3,3) (4,0) (5,2)

(2,1) 에 대해서
값이 작은애보다, 값이 큰 애 중에, 
값이 큰 애들 중에,
일단 1보다 크고
4보다 작은 -> 1,2,3 -> 3개
인덱스가 1보다 크고, 4보다 작은 2,3 에 대해서 -> a[2], a[3]을 봐서 2랑 비교

(3,3) 에 대해서
일단 3보다 크고
4보다 작은 -> 0, 2 -> 


정렬하는 거는 O(n log n)

map으로 하면, key값으로 정렬되니까

map<int,int> keyToIndex 

pair<int,int> [] -> sort compare

5000*log5000 + 1*5000 + 2


[4 입장]
나보다 큰 게 나올 때까지 일단 go
4보다 큰 이후로, 4보다 작은 게 있으면 ++
N + N-1 + 
*/
