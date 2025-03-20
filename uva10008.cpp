#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>  // 缺少的標頭
#include <cctype>   // 用於 isalpha 和 toupper
#include <string>
using namespace std;

int main(){
    int lines;
    cin >> lines;
    cin.ignore();  // 忽略換行符
    string s;
    map<char, int> mp;  // map 用來存儲字母的出現次數
    
    for(int i = 0; i < lines; i++){
        getline(cin, s);
        stringstream sin(s);
        char c;
        
        while(sin >> c){
            if(isalpha(c)){  // 檢查是否是字母
                mp[toupper(c)]++;  // 轉為大寫並更新頻率
            }
        }
    }

    // 輸出所有字母的頻率
    for (auto& pair : mp) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
