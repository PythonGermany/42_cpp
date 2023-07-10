/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:55:04 by rburgsta          #+#    #+#             */
/*   Updated: 2023/05/30 16:55:04 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const& rhs) { *this = rhs; }

RPN& RPN::operator=(RPN const& rhs) {
  if (this == &rhs) return (*this);
  return (*this);
}

RPN::~RPN() {}

float RPN::processExpression(std::string expr) {
  std::stack<t_element> data = loadExpression(expr);
  std::stack<t_element> stack;
  while (data.size() > 0) {
    if (data.top().type == OPERAND)
      stack.push(data.top());
    else if (data.top().type == OPERATOR) {
      if (stack.size() < 2) handleError("Processing: Invalid expression", 1);
      t_element temp = stack.top();
      stack.pop();
      if (data.top().value == '+')
        stack.top().value += temp.value;
      else if (data.top().value == '-')
        stack.top().value -= temp.value;
      else if (data.top().value == '*')
        stack.top().value *= temp.value;
      else if (data.top().value == '/') {
        if (temp.value == 0) handleError("Processing: Division by zero", 1);
        stack.top().value /= temp.value;
      }
    }
    data.pop();
  }
  if (stack.size() != 1)
    handleError("Processing: Invalid/Incomplete expression", 1);
  return (stack.top().value);
}

void RPN::handleError(std::string msg, int exitCode) {
  std::cout << "Error: " << msg << "!" << std::endl;
  std::exit(exitCode);
}

std::stack<t_element> RPN::loadExpression(std::string& expr) {
  if (expr.empty()) handleError("Loading: Empty input expression", 1);
  std::stack<t_element> data;
  while (expr.length() > 0) {
    size_t start = expr.find_last_of(' ');
    std::string value;
    if (start != std::string::npos)
      value = expr.substr(start + 1);
    else {
      value = expr;
      start = 0;
    }
    if (value.size() == 1 && std::strchr("+-/*", value[0]) != NULL)
      data.push(createElement(OPERATOR, value[0]));
    else {
      if (verifyValue(value))
        handleError("Loading: Invalid input expression", 1);
      data.push(createElement(OPERAND, std::atof(value.c_str())));
    }
    expr.erase(start);
  }
  return (data);
}

t_element RPN::createElement(int type, float value) {
  t_element el;

  el.type = type;
  el.value = value;
  return (el);
}

int RPN::verifyValue(std::string& value) {
  bool precisionFound = false;
  if (value.empty()) return (1);
  for (size_t i = 0; i < value.length(); i++) {
    if (i == 0 && (value[i] == '-' || value[i] == '+') && value.length() > 1)
      continue;
    else if (!precisionFound && value[i] == '.')
      precisionFound = true;
    else if (!std::isdigit(value[i]))
      return (1);
  }
  return (0);
}