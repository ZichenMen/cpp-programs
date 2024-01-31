#ifndef POSTFIX_EXPRESSION_CALCULATOR_H
#define POSTFIX_EXPRESSION_CALCULATOR_H

#include "Stack.h"
#include "LinkedStack.h"
#include "DynamicArrayStack.h"
#include <string>

/**
 * The header file of PostfixExpressionCalculator.
 * PostfixExpressionCalculator is a class for evaluating postfix expressions.
 * Uses a reference to a Stack of type double for storing values.
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 10/18/2023
 * @version 1.0
 */
class PostfixExpressionCalculator
{
private:
    // Reference to a Stack object
    Stack<double> &rStack;

public:
    /**
     * Constructor that initializes the stack reference.
     * @param _stack The stack used for expression evaluation.
     */
    PostfixExpressionCalculator(Stack<double> &_stack);
    /**
     * Evaluates a postfix expression.
     * @param expression The postfix expression string.
     * @return The result of the postfix expression.
     */
    double evaluate(const std::string &expression);
};
#include "PostfixExpressionCalculator.cpp"
#endif
