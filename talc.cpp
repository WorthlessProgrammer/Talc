#include <iostream>
#include <vector>

//8 + 8 => 16
// Expression -> Operand, Operator
// Operands -> Numbers, Expressions[(), f()]
// Operator -> Binary, Unary

enum Op {
  Add = '+',
  Sub = '-',
  Mul = '*',
  Div = '/'
};

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
	Expression my_expr(359, 489, '*');
	my_expr.evalExpr();
	return 0;
}
