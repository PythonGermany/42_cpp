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
  std::list<t_element> data = loadExpression(expr);
  std::list<t_element> stack;
  while (data.size() > 0) {
    if (data.front().type == OPERAND)
      stack.push_front(data.front());
    else if (data.front().type == OPERATOR) {
      if (stack.size() < 2) handleError("Processing: Invalid expression", 1);
      if (data.front().value == '+')
        (*(++stack.begin())).value += stack.front().value;
      else if (data.front().value == '-')
        (*(++stack.begin())).value -= stack.front().value;
      else if (data.front().value == '*')
        (*(++stack.begin())).value *= stack.front().value;
      else if (data.front().value == '/')
        (*(++stack.begin())).value /= stack.front().value;
      stack.pop_front();
    }
    data.pop_front();
  }
  if (stack.size() != 1)
    handleError("Processing: Invalid/Incomplete expression", 1);
  return (stack.front().value);
}

void RPN::handleError(std::string msg, int exitCode) {
  std::cout << "Error: " << msg << "!" << std::endl;
  std::exit(exitCode);
}

std::list<t_element> RPN::loadExpression(std::string& expr) {
  if (expr.empty()) handleError("Loading: Empty input expression", 1);
  std::list<t_element> data;
  while (expr.length() > 0) {
    std::string value = expr.substr(0, expr.find(' '));
    if (value.size() == 1 && std::strchr("+-/*", expr[0]) != NULL)
      data.push_back(createElement(OPERATOR, expr[0]));
    else {
      if (verifyValue(value))
        handleError("Loading: Invalid input expression", 1);
      data.push_back(createElement(OPERAND, std::atof(value.c_str())));
    }
    expr.erase(0, value.size() + 1);
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
    if (i == 0 && (value[i] == '-' || value[i] == '+'))
      continue;
    else if (!precisionFound && value[i] == '.')
      precisionFound = true;
    else if (!std::isdigit(value[i]))
      return (1);
  }
  return (0);
}