#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <string>
using namespace std;

int main() {
    int lines;
    cin >> lines;
    cin.ignore();  // 忽略換行符

    string s;
    map<char, int> mp;  // 用來存儲字母的出現次數
    
    for(int i = 0; i < lines; i++) {
        getline(cin, s);  // 讀取每行文字
        for(char c : s) {  // 遍歷每個字符
            if(isalpha(c)) {  // 只處理字母
                mp[toupper(c)]++;  // 轉為大寫並更新頻率
            }
        }
    }

    // 將 map 內容放入 vector 以便排序
    vector<pair<char, int> > freq_vec(mp.begin(), mp.end());

    // 根據頻率排序，從高到低，若頻率相同則按字母順序排序
    sort(freq_vec.begin(), freq_vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        if(a.second == b.second) {
            return a.first < b.first;  // 頻率相同時按字母順序排序
        }
        return a.second > b.second;  // 按頻率從高到低排序
    });

    // 輸出所有字母的頻率
    for (auto& pair : freq_vec) {
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}
