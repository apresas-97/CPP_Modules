#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
	vec.reserve(10);

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

    // Print the entire vector
	std::cout << "Vector: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
	std::cout << std::endl;

    // Get an iterator to an element
	std::vector<int>::iterator It = vec.begin() + 1;  // Iterator pointing to value 2

	size_t	vsize = vec.size();

	// Print the value of the element pointed by the iterator
	std::cout << "Element It = " << *It << std::endl;

	// Insert new elements into the vector
	vec.insert(vec.begin(), 234);
	vec.insert(vec.begin() + 2, 123);

	// Print the entire vector
	std::cout << "Vector: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
	std::cout << std::endl;

	// Print the value of the element pointed by the iterator
	std::cout << "Element It = " << *It << std::endl;

    return 0;
}
