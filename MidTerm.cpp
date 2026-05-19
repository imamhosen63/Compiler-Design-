#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream file("input.txt");

    if (!file) {
        cout << "Cannot open file!";
        return 0;
    }

    char ch;

    int keyword = 0, identifier = 0, number = 0;
    int op = 0, sep = 0, str = 0;

    while (file.get(ch)) {

        if (ch == ' ' || ch == '\n' || ch == '\t')
            continue;


        if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ';') {
            cout << ch << " --> Separator\n";
            sep++;
        }


        else if (ch == '=') {
            cout << ch << " --> Operator\n";
            op++;
        }


        else if (ch == '"') {
            string s = "\"";
            while (file.get(ch) && ch != '"')
                s += ch;
            s += "\"";

            cout << s << " --> String\n";
            str++;
        }


        else if (ch >= '0' && ch <= '9') {
            string num = "";
            num += ch;

            while (file.peek() >= '0' && file.peek() <= '9')
                num += file.get();

            cout << num << " --> Number\n";
            number++;
        }

        else {
            string word = "";
            word += ch;

            while (file.peek() != EOF &&
                  ((file.peek() >= 'a' && file.peek() <= 'z') ||
                   (file.peek() >= 'A' && file.peek() <= 'Z'))) {
                word += file.get();
            }

            if (word == "int" || word == "return") {
                cout << word << " --> Keyword\n";
                keyword++;
            }
            else {
                cout << word << " --> Identifier\n";
                identifier++;
            }
        }
    }

    cout << "\n--- Summary ---\n";
    cout << "Keywords: " << keyword << endl;
    cout << "Identifiers: " << identifier << endl;
    cout << "Operators: " << op << endl;
    cout << "Separators: " << sep << endl;
    cout << "Numbers: " << number << endl;
    cout << "Strings: " << str << endl;

    return 0;
}
