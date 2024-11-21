#include<iostream>
using namespace std;

int a,b;
int d;
int totalTime;

int main(int argc, char** argv)
{
    cin >> a >> b >> d;

    int beforeTouch;
    if (d%a != 0){
        beforeTouch = (d/a)*a + (d%a) + (d/a)*b;    
    }
    else{
        beforeTouch = (d/a)*a + ((d/a)-1)*b;       
    }

    int afterTouch;
    if(d%b != 0){
        afterTouch = (d/b)*b + (d%b) + (d/b)*a;
    }
    else{
        afterTouch = (d/b)*b + ((d/b)-1)*a;
    }

    totalTime = beforeTouch + afterTouch;
    cout << totalTime;
    return 0;
}

/*
술래를 터치하는데 걸리는 시간
(d/a)번 이동이 필요함.

10/7 = 1 ... 3
그러면 (10/7)*7 + 3 + (10/7)*3 =

(d/a)*a + (d%a) + (d/a)*b

1/1*1 + 0 + 1

술래를 터치한 후 걸리는 시간
(d/b)*b + (d%b) + (d/b)*a

*/