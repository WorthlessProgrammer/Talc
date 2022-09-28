#include <iostream>
#include <bits/stdc++.h>
#include <vector>

// 8 + 8 => 16
// Expression -> Operand, Operator
// Operands -> Numbers, Expressions[(), f()]
// Operator -> Binary, Unary

//TODO: Parse multiple operations and define priority queue  

enum Op {
  Add = '+',
  Sub = '-',
  Mul = '*',
  Div = '/'
};

enum TokenKind {
  Operand,
  Operation
};

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
            s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

class Expression
{
  private:
    std::vector<int> operands;
    char operation;

  public:
    Expression(int op1, int op2, char optr)
    {
      operands.push_back(op1);
      operands.push_back(op2);
      operation = optr;
    }

    Expression(std::string& expr) 
    {
      std::string temp;
      std::vector<std::string> tokens;

      std::stringstream strm_expr(expr);

      while (getline(strm_expr, temp, ' ')) {
        tokens.push_back(temp);
      }

      for (std::string token: tokens) { 
        if (is_number(token)) {
          operands.push_back(std::atoi(token.c_str()));
          continue;
        }
        switch (token[0]) {
          case Add:
            operation = '+';
            break;
          case Sub:
            operation = '-';
            break;
          case Mul:
            operation = '*';
            break;
          case Div:
            operation = '/';
            break;  
          default:
            //TODO: Report Operand error
            perror("ERROR: Invalid operator");
            return;
        } 
      }
    } 

    void evalExpr()
    {
      int result;

      switch (operation) {
        case Add:
          result = operands[0] + operands[1];
          break;
        case Sub:
          result = operands[0] - operands[1];
          break;
        case Mul:
          result = operands[0] * operands[1];
          break;
        case Div:
          result = operands[0] / operands[1];
          break;  
        default:
          perror("ERROR: Invalid operator");
          return;
      }

      std::cout << operands[0] << ' ' << operation << ' ' << operands[1] 
      << " = " << result << std::endl; 
    }

    void print_t()
    {
      for (int i: operands)
        std::cout << i << '\n';
      std::cout << operation << std::endl;
    }
};

int main()
{
  std::string a = "98 + 8 + 5 - 5 / 8";
  std::string b = "98 - 8";
  std::string c = "98 / 8";
  
  Expression my_expr(c);
  my_expr.evalExpr();
}

int main2()
{
  Expression my_expr(359, 489, '*');
  my_expr.evalExpr();
  return 0;
}