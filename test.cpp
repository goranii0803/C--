#include<iostream>

using namespace std;
int main(){
    int k,c;
    cin>>k>>c;

    for (int i=0;i<c;i++){
        int a, b;
        cin>>a>>b;

        int restRound=k-max(a,b);
        if((a >= b && a - restRound - b>2) || (a < b && b - restRound - a > 1)){
            cout<<"0\n";
        }
        else{
            cout<<"1\n";
        }
    }
}