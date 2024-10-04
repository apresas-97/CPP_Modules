#include <iostream>
#include <stack>
#include <sstream>

int evaluateRPN(const std::string& expression) {
    std::stack<int> stack;
    std::istringstream tokens(expression);
    std::string token;

    while (tokens >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {  // Handle numbers
            stack.push(std::stoi(token));
        } else {  // Handle operators
            int operand2 = stack.top(); stack.pop();
            int operand1 = stack.top(); stack.pop();

            if (token == "+") {
                stack.push(operand1 + operand2);
            } else if (token == "-") {
                stack.push(operand1 - operand2);
            } else if (token == "*") {
                stack.push(operand1 * operand2);
            } else if (token == "/") {
                stack.push(operand1 / operand2);
            }
        }
    }
    return stack.top();
}

int main() {
    std::string rpnExpression = "1 2 3 * 2 / 2 * 2 4 - +";
    std::cout << "Result: " << evaluateRPN(rpnExpression) << std::endl;
    return 0;
}
