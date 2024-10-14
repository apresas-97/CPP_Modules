#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};  // Example array a1, a2, a3, b1, b2

    // Get iterators to specific elements
	std::vector<int>::iterator It = vec.begin() + 7;  // Iterator to a1

	size_t	vsize = vec.size();

    // Print the entire vector
	std::cout << "Vector: ";
    for (int i : vec) {
        std::cout << i << " ";
    }
	std::cout << std::endl;

	std::cout << "Element It = " << *It << std::endl;

	vec.insert(vec.begin() + 7, 123);

	// Print the entire vector
	std::cout << "Vector: ";
	for (int i : vec) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::cout << "Element It = " << *It << std::endl;

    return 0;
}