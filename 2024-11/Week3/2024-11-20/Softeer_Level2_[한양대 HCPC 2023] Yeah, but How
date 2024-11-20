#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
    string T;
    
    string S;
    cin >> S;

    char c1, c2;
    c1 = S[0];
    T.push_back(c1);
    for(int i=1;i<S.size();i++){
        c2 = S[i];
        if(c1 == '(' && c2 == '('){
            T.push_back('(');
        }
        else if(c1 == '(' && c2 == ')'){
            T.push_back('1');
            T.push_back(')');
        }
        else if(c1 == ')' && c2 == '('){
            T.push_back('+');
            T.push_back('(');
        }
        else if(c1 == ')' && c2 == ')'){
            T.push_back(')');
        }

        c1 = c2;
    }

    cout << T;
   return 0;
}

/*
() -> 1 넣기 -> (1)
(( -> 아무것도 안 넣기 ((
(() -> 1 넣기 -> ((1)
)( -> + 넣기 -> ((1)+(
() -> 1 넣기 -> ((1)+(1)
)) -> 아무것도 안 넣기 -> ((1)+(1))
(()(())()(()))
((1)+((1))+(1)+((1)))
*/