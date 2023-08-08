#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		int val = atoi(argv[i]);

		if (val < 0)
		{
			std::cerr << "Negative number found exitting...." << std::endl;
			exit(EXIT_FAILURE);
		}
		vec.push_back(val);
	}
	length = argc;
}

void	PmergeMe::giveInfo()
{
	std::cout << "Before: ";
	int count = 0;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << " ";
		count++;
		if (count == 5)
		{
			std::cout << " [...] " << std::endl;
			break ;
		}
	}
	std::cout << std::endl;

	std::vector<int> sortedVec = vec;
	std::sort(sortedVec.begin(), sortedVec.end());
	std::cout << "After: ";
	for (std::vector<int>::iterator it = sortedVec.begin(); it != sortedVec.end(); it++)
	{
		std::cout << *it << " ";
		count--;
		if (count == 0)
		{
			std::cout << " [...] " << std::endl;
			break ;
		}
	}
	std::cout << std::endl;
	std::copy(vec.begin(), vec.end(), std::inserter(deq, deq.end()));
}

void	PmergeMe::merge(std::deque<int>& left, std::deque<int>& right, std::deque<int>& result)
{
	while (!left.empty() && !right.empty())
	{
		if (left.front() < right.front())
		{
			result.push_back(left.front());
			left.pop_front();
		}
		else
		{
			result.push_back(right.front());
			right.pop_front();
		}
	}
	while (!left.empty())
	{
		result.push_back(left.front());
		left.pop_front();
	}
	while (!right.empty())
	{
		result.push_back(right.front());
		right.pop_front();
	}
}

void	PmergeMe::mergeInsSort(std::deque<int>& dq)
{
	if (dq.size() < 2)
		return ;
	
	std::deque<int> left, right, result;
	int middle = dq.size() / 2;

	for (int i = 0; i < middle; ++i)
		left.push_back(dq[i]);
	for (unsigned i = middle; i < dq.size(); ++i)
		right.push_back(dq[i]);

	mergeInsSort(left);
	mergeInsSort(right);
	merge(left, right, result);

	std::copy(result.begin(), result.end(), dq.begin());
}

void	PmergeMe::mergeDeque(void)
{
	std::clock_t start = std::clock();
	mergeInsSort(deq);
	std::clock_t end = std::clock();
	
	double sortTime = double(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to sort " << length << " numbers with std::deque : " << sortTime << " us" << std::endl;

#ifdef DEBUG
	for (std::deque<int>::iterator i = deq.begin(); i != deq.end(); i++)
	{
		std::cout << *i << std::endl;
	}
#endif
}

void	PmergeMe::merge(std::vector<int>& vt, std::vector<int>& temp, int left, int middle, int right)
{
	int i = left, j = middle + 1, k = left;

	while (i <= middle && j <= right)
	{
		if (vt[i] <  vt[j])
			temp[k++] = vt[i++];
		else
			temp[k++] = vt[j++];
	}

	while (i <= middle)
	 	temp[k++] = vt[i++];
	while (i <= right)
		temp[k++] = vt[j++];
	for (k = left; k <= right; k++)
		vt[k] = temp[k];
}

void	PmergeMe::mergeInsSort(std::vector<int>& vt, std::vector<int>& temp, int left, int right)
{
	if (left < right)
	{
		if (right - left < 10)
		{
			for (int i = left + 1; i <= right; i++)
			{
				int key = vt[i];
				int j = i - 1;
				while (j >= left && vt[j] > key)
				{
					vt[j + 1] = vt[j];
					j--;
				}
				vt[j + 1] = key;
			}

		}
		else
		{
			int middle = (left + right) / 2;
			mergeInsSort(vt, temp, left, middle);
			mergeInsSort(vt, temp, middle + 1, right);
			merge(vt, temp, left, middle, right);
		}
	}
}

void	PmergeMe::mergeInsSort(std::vector<int>& vt)
{
	std::vector<int> temp(vt.size());
	mergeInsSort(vt, temp, 0, vt.size() - 1);
}

void	PmergeMe::mergeVector(void)
{
	std::clock_t start = std::clock();
	mergeInsSort(vec);
	std::clock_t end = std::clock();

	double sortTime = double(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to sort " << length << " numbers with std::vector : " << sortTime << " us" << std::endl;
#ifdef DEBUG
	for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
	{
		std::cout << *i << std::endl;
	}
#endif
}