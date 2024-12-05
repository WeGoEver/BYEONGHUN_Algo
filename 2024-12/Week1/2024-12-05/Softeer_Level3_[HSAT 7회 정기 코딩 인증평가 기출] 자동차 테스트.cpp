#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> f; // 자동차의 연비
int q;


int binarySearch(int target){
    int left = 0;
    int right = n-1;
    while(left <= right){
        int mid = left + (right - left) / 2;

        if(target == f[mid]){
            // 찾았다
            return mid;
        }
        else if(target > f[mid]){
            left = mid+1;
        }
        else{// target < f[mid]
            right = mid-1;
        }
    }

    // 만약 target 값을 찾지 못하면
    return -1;
}


int main(int argc, char** argv)
{
    // n, q 입력
    cin >> n >> q;
    // f 입력
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        f.push_back(temp);
    }

    // 연비를 정렬
    sort(f.begin(), f.end());

    for(int i=0;i<q;i++){
        int m;
        cin >> m;
        
        int index = binarySearch(m);
        // 기대하는 중앙값이 존재하지 않음
        if(index == -1){
            cout << 0 << "\n";
            continue;
        }

        // 일단 기대하는 중앙값이 존재해
        // 그럼 중앙값의 가지 수는
        cout << index * (n-1-index) << "\n";
    }

    
    // for(int i=0;i<n;i++){
    //     cout << f[i] << " ";
    // }
    
    return 0;
}

/*

n 대의 자동차의 연비 값이 주어졌을 때
일단 int로 가도 되나? 20억까지 되는 거 같고,
1억이 1초

5, 2, 3, 1, 6

정렬해서
0, 1, 2, 3, 4
1, 2, 3, 5, 6


이분탐색으로 찾는다. 1의 index를 찾기

중앙값이 1이 나오려면 -> 0*4
중앙값이 3이 나오려면 -> 2*2
중앙값이 6이 나오려면 -> 4*0

우선 정렬 -> Nlog(N) = 50000 * 5 = 250000
쿼리 처리 -> q*log(N) = 200,000 * 5 = 1,000,000


*/