#include <iostream>
using namespace std;

int main() {

    string index;

    string testCases[5] = {
        "ab",
        "aaab",
        "bbbb",
        "aaa",
        "ba"
    };

    for(int t = 0; t < 5; t++) {

        index = testCases[t];

        int i = 0;


        while(index[i] == 'a') {
            i++;
        }


        int b = 0;

        while(index[i] == 'b') {
            b++;
            i++;
        }


        if(b >= 1 && i == index.length()) {
            cout << index << " ->String Accepted" << endl;
        }
        else {
            cout << index << " ->String Rejected" << endl;
        }
    }

    return 0;
}
