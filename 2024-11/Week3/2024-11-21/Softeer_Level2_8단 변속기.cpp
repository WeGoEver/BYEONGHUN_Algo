#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
    string currentState;
    int from;
    int to;
    scanf("%d %d", &from, &to);
    
    // 초기 상태 확인, ascending, descending 결정
    if(from < to){
        currentState = "ascending";
    }
    else{
        currentState = "descending";
    }
    from = to;

    // 다음 것들을 보면서,
    for(int i=0;i<6;i++){
        scanf("%d", &to);
        if(currentState == "ascending"){
            // 초기 상태와 다르다면, mixed 처리하고 return;
            if(from > to){
                currentState = "mixed";
                break;
            }
        }
        else if(currentState == "descending"){
            // 초기 상태와 다르다면, mixed 처리하고 return;
            if(from < to){
                currentState = "mixed";
                break;
            }
        }
        from = to;
    }
    
    cout << currentState;
    return 0;
}

/*
우선 두개 숫자를 보고
초기 상태 확인
ascending, descending
다음 것들을 보면서, 초기 상태와 동일하면 유지
초기 상태와 다르다면, mixed 처리하고 return;
*/