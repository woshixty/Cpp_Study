#include <iostream>
#include <vector>

using namespace std;
int main() {
    char chars[3][4] = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    vector<vector<char>> container;
    for (int i = 0; i < 3; ++i) {
        vector<char> temp;
        for (int j = 0; j < 4; ++j) {
            temp.push_back(chars[i][j]);
        }
        container.push_back(temp);
    }
    return 0;
}
