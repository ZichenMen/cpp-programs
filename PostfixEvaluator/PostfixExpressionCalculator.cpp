#include "PostfixExpressionCalculator.h"
#include <sstream>
#include <iostream>
#include <string>

/**
 * The source file of PostfixExpressionCalculator
 * PostfixExpressionCalculator is a class for evaluating postfix expressions.
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 10/18/2023
 * @version 1.0
 */

/**
 * Initializes the calculator with the provided stack.
 *
 * @param _stack The stack used for expression evaluation.
 */
PostfixExpressionCalculator::PostfixExpressionCalculator(Stack<double> &_stack) : rStack(_stack) {}

/**
 * Evaluates a given postfix expression, the evaluated result is returned
 *
 * @param expression The postfix expression string.
 * @return The result of the postfix expression.
 * @throws std::runtime_error if the expression is invalid.
 */
double PostfixExpressionCalculator::evaluate(const std::string &expression)
{
    double operand1, operand2, result;

    for (char ch : expression)
    {
        if (isdigit(ch)) // Operand detected
        {
            rStack.push(static_cast<double>(ch - '0')); // Convert char to double
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') // Operator detected
        {
            // Validate and pop operands from stack
            if (!rStack.isEmpty())
            {
                operand2 = rStack.peek();
                rStack.pop();
            }
            else
            {
                throw std::runtime_error("Invalid expression: insufficient operands.");
            }

            if (!rStack.isEmpty())
            {
                operand1 = rStack.peek();
                rStack.pop();
            }
            else
            {
                throw std::runtime_error("Invalid expression: insufficient operands.");
            }

            // Perform operation and push result back to stack
            switch (ch)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            }

            rStack.push(result);
        }
    }

    return rStack.peek();
}
