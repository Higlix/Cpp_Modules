#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <vector>
# include <deque>
# include <chrono>
# include <algorithm>

# define DEBUG


class PmergeMe
{
	public:
	
		std::vector<int> vec;
		std::deque<int> deq;
	
		size_t	length;

		PmergeMe(int argc, char **argv);

		void	giveInfo( void );

		void	mergeDeque(void);
		void	mergeInsSort(std::deque<int>& dq);
		void	merge(std::deque<int>& left, std::deque<int>& right, std::deque<int>& result);

		void	mergeVector(void);
		void	mergeInsSort(std::vector<int>& vt, std::vector<int>& temp, int left,  int right);
		void	mergeInsSort(std::vector<int>& vt);
		void	merge(std::vector<int>& vt, std::vector<int>& temp, int left, int middle, int right);
};

#endif