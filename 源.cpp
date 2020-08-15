#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        vector<string> text_vec;
        for (int i = 0; i < text.size(); i++){
            if (text[i] == ' ')continue;
            if (i == text.size() - 1) {
                string temp = text.substr(i, 1);
                text_vec.push_back(temp);
                break;
            }
            for (int j = i + 1; j < text.size(); j++) {
                if (j == text.size() - 1) {
                    string temp = text.substr(i, j - i + 1);
                    text_vec.push_back(temp);
                    i = text.size();
                    break;
                }
                else if (text[j] == ' ') {
                    string temp = text.substr(i, j - i);
                    text_vec.push_back(temp);
                    i = j;
                    break;
                }
            }
        }
        for (string i : text_vec)cout << i << endl;
        int length = text_vec.size();
        if (length < 3)return ans;
        for (int i = 0; i < length - 2; i++)
            if (text_vec[i] == first && text_vec[i + 1] == second) {
                ans.push_back(text_vec[i + 2]);
               
            }
        return ans;
    }
};
int main (){
    Solution sol;
    string text = "a good a good b";
    string first = "a";
    string second = "good";
    vector<string>ans = sol.findOcurrences(text, first, second);
    for (string i : ans)cout << i << endl;
    return 0;
}
