#include <iostream>
#include <vector>
#include <stdint.h>

//8 + 8 => 16

class Expression
{
	private:
		std::vector<int64_t> operands;
		std::string operation;
	
	public:
		Expression(int64_t op1, int64_t op2, std::string&& optr)
		{
			operands.push_back(op1);
			operands.push_back(op2);
			operation = optr;
		}
		void print_t()
		{
			for (int64_t i: operands)
				std::cout << i << '\n';
			std::cout << operation << std::endl;
		}
};

int main()
{
	Expression my_expr(3, 4, "+");
	my_expr.print_t();
	return 0;
}
