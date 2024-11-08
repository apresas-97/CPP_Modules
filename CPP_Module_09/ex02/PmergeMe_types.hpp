#ifndef PMERGEME_TYPES_HPP
#define PMERGEME_TYPES_HPP

#include <stdint.h>
#include <vector>
#include <list>

typedef uint_fast64_t				integer;
typedef std::list<integer>			list;
typedef std::vector<integer>		vector;
typedef std::pair<integer, integer>	pair;
typedef std::vector<pair>			pair_vector;

# endif // PMERGEME_TYPES_HPP