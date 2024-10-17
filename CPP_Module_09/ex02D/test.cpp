#include <iostream>
#include <string>

void	test_jacobsthalNumbers( void )
{
	size_t	jacobsthalNumbers[63];

	jacobsthalNumbers[0] = 0;
	jacobsthalNumbers[1] = 1;
	for (size_t i = 2; i < 63; i++)
		jacobsthalNumbers[i] = (jacobsthalNumbers[i - 1]) + (2 * jacobsthalNumbers[i - 2]);

	size_t	jacobsthalDiff[63];

	jacobsthalDiff[0] = 2;
	jacobsthalDiff[1] = 2;
	for (size_t i = 2; i < 63; i++)
		jacobsthalDiff[i] = jacobsthalDiff[i - 1] + 2 * jacobsthalDiff[i - 2];

	std::cout << "Printing Jacobsthal Numbers:" << std::endl;
	for (size_t i = 0; i < 63; i++)
		std::cout << jacobsthalNumbers[i] << " ";
	std::cout << std::endl;

	std::cout << "Printing Jacobsthal Differences:" << std::endl;
	for (size_t i = 0; i < 63; i++)
		std::cout << jacobsthalDiff[i] << " ";
	std::cout << std::endl;
}

int	main( void )
{
	test_jacobsthalNumbers();
	return 0;
}