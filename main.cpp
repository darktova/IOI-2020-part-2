#include <iostream>
#include <set>
#include <map>

// Operations
std::multimap< size_t, size_t> operation;

// Number
int n;

// Number of operations
size_t m;

int main()
{
	// Step: 1
	std::ios_base::sync_with_stdio(NULL);
	std::cin >> n >> m;

	// Reading operations
	for (size_t i = 0, a, b; i < m; ++i)
	{
		std::cin >> a >> b;
		operation.insert(std::make_pair(b, a));
	}

	// Step: 2
	//
	long long min_total = INT64_MAX;
	for (auto i = operation.begin(), 
		 end = operation.end(); 
		 i != end; ++i)
	{
		int tmp_n = n;
		size_t cnt = 0;
		long long total = 0;
		for (auto j = i; j != end; ++j)
		{
			// How much "a" in n
			cnt = (tmp_n / j->second);

			// Decrease n
			tmp_n -= (j->second * cnt);

			// Increase current minimum
			total += (j->first * cnt);

			// Found result
			if (tmp_n <= 0)
			{
				min_total = std::min(total, min_total);
				break;
			}
		}
	}

	// Result
	std::cout << min_total;
}
