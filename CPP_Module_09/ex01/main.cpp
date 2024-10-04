#include "RPN.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./rpn \"expression\"" << std::endl;
		return 1;
	}

	RPN rpn;

	std::string expression = argv[1];
	rpn.calculate(expression);

	return 0;
}

/*

2 2 +

2 2 2 +

Example for newApproach:

4 2 5 * + 1 3 2 * + /
make sub_expression:
4 2 5 * +
Is it valid? Yes
Calculate result:
Pop from front and back each time
4
+
2
*
5
Calculate:
2 * 5 = 10
4 + 10 = 14
sub_expression over
Insert result back to main expression:
14 1 3 2 * + /
back to main expression:
make sub_expression:
14 1 3 2 * + /
Is it valid? Yes
Calculate result:
Pop from front and back each time
14
/
1
+
3
*
2
Calculate:
3 * 2 = 6
1 + 6 = 7
14 / 7 = 2
sub_expression over
Insert result back to main expression:
2
back to main expression:
end of expression


Example:
4 2 5 * + 1 3 2 * + / 8 5 + + 2 1 * *
make sub_expression:
4 2 5 * +
4 + 2 * 5
5 * 2 + 4


*/
