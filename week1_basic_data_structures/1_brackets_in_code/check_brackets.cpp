#include <iostream>
#include <stack>
#include <string>
#include <bits/stdc++.h>

using namespace std;

struct Bracket {
    Bracket(char type, int position):
            type(type),
            position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    int ans;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
        Bracket b(next, position);

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(b);
        }
	else if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if (opening_brackets_stack.empty()) {
		cout << position + 1 << endl;
                return 0;
            }
	    if (opening_brackets_stack.top().Matchc(next)) {
		opening_brackets_stack.pop();
	    } else {
		cout << position + 1 << endl;
		return 0;
	    }
        }
    }

    // Printing answer, write your code here
    if (!opening_brackets_stack.empty()) {
        cout << opening_brackets_stack.top().position + 1 << endl;
    } else {
	cout << "Success" << endl;
    }

    return 0;
}
