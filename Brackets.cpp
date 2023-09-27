#include <iostream>
#include <queue>
#include <string>


unsigned findMismatchedBracket(const std::string &input) {
    std::queue<unsigned> c1;
    std::queue<unsigned> c2;
    std::queue<unsigned> c3;
    unsigned ret = 0;
    for (unsigned i = 0; i < input.length(); i++) {
        if (input[i] == '[') c1.push(i + 1);
        if (input[i] == '(') c2.push(i + 1);
        if (input[i] == '{') c3.push(i + 1);


        if (input[i] == '}') {
            if (c3.empty()) {
                return i + 1;
            }
            else c3.pop();
        }
        if (input[i] == ']') {
            if (c1.empty())
                return i + 1;
            else c1.pop();
        }
        if (input[i] == ')') {
            if (c2.empty())
                return i + 1;
            else c2.pop();
        }
    }

    if (!c1.empty())
        ret = c1.front();

    if (!c2.empty())
        ret = ret == 0 ? c2.front() : ret < c2.front() ? ret : c2.front();

    if (!c3.empty())
        ret = ret == 0 ? c3.front() : ret < c3.front() ? ret : c3.front();

    return ret;
}

int main() {
    std::string input_str;

    while (true) {
        std::getline(std::cin, input_str);

        if (input_str.empty()) {
            break;
        }

        unsigned result = findMismatchedBracket(input_str);
        if (result == 0) {
            std::cout << "Success" << std::endl;
        } else {
            std::cout << result << std::endl;
        }
    }

    return 0;
}
