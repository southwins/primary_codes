#include<bits/stdc++.h>
using namespace std;

unsigned fn(int i){
    if (i == 1)
        return 1;
    if (i == 2)
        return 2;
    else
        return fn(i - 1) + fn (i - 2);
}

int main(){
    cout << fn(15);
    return 0;
}
