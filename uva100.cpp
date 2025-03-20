#include <iostream>
using namespace std;

int cycle(int k){
    int result = 1;
    while(true){
        if(k == 1){
            return result;
        }
        if(k % 2 == 0){
            k /= 2;
            result++;
        }
        else{
            k = 3 * k + 1;
            result++;
        }
    }
}

int main(){
    int a, b;
    while(cin >> a >> b){
        int a1 = a;
        int b1 = b;
        if(a > b)swap(a1,b1);
        int result = cycle(a1);
        for(int i = a1; i < b1; i++){
            result = max(result, cycle(i));
        }
        cout << a << ' ' << b << ' ' << result << endl;
    }
}