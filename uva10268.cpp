//Q: 3x3+2x2+1x1+0 計算微分後的值，有給x
// 3 2 1 0
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
typedef long long int lli;

int main(){
    lli num, m;
    string s1;
    while(cin >> num){
        getline(cin, s1);
        getline(cin, s1);
        istringstream mains(s1);
        vector<lli>vec;
        while(mains >> m){
            vec.insert(vec.begin(), m);// 0 1 2 3
        }
        for(int i = 0; i < vec.size(); i++){
            vec[i] = vec[i] * i;//新的係數值建立
        }
        vec.erase(vec.begin());// 1 2 3
        lli initial = 1, ans = 0;
        for(int i = 0; i < vec.size(); i++){
            ans += vec[i] * initial;
            initial *= num;
        }
        cout << ans << endl;
    }
    return 0;
}
