#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;

template <typename InputIterator, typename valueType>
InputIterator findfirstinstance(InputIterator iterBegin, InputIterator iterEnd, const valueType &findEle)
{
	while (iterBegin != iterEnd && *iterBegin != findEle)
	{
		++iterBegin;
	}

	return iterBegin;
}

template <class InputIterator, class OutputIterator>
OutputIterator mergeSortedContainers(InputIterator lhsBegin, InputIterator lhsEnd, InputIterator rhsBegin, InputIterator rhsEnd, OutputIterator result)
{

	//Copy elements retaining order until end of one container.
	while (lhsBegin != lhsEnd && rhsBegin != rhsEnd)
	{
		if (*lhsBegin <= *rhsBegin)
		{
			*result = *lhsBegin;
			++lhsBegin;
		}
		else
		{
			*result = *rhsBegin;
			++rhsBegin;
		}
		++result;
	}

	//Copy remaining elements.
	while (lhsBegin != lhsEnd)
	{
		*result = *lhsBegin;
		++lhsBegin;
		++result;
	}

	while (rhsBegin != rhsEnd)
	{
		*result = *rhsBegin;
		++rhsBegin;
		++result;
	}

	return result;
}

template <class ForwardIterator, typename ElementType>
void findandreplace(ForwardIterator iterBegin, ForwardIterator iterEnd, const ElementType &oldEle, const ElementType &newEle)
{
	while (iterBegin != iterEnd)
	{
		if (*iterBegin == oldEle)
		{
			*iterBegin = newEle;
		}
		++iterBegin;
	}
}

template <class BidirectionalIterator, class OutputIterator>
OutputIterator reverseCopy(BidirectionalIterator iterBegin, BidirectionalIterator iterEnd, OutputIterator result)
{

	//Copy elements from iterEnd to results container.
	while (iterBegin != iterEnd)
	{
		*result++ = *--iterEnd;
	}

	return result;
}

template <class RandomAccessIterator>
void randomise(RandomAccessIterator iterBegin, RandomAccessIterator iterEnd)
{
	while (iterBegin < iterEnd)
	{
		iter_swap(iterBegin, iterBegin + rand() % (iterEnd - iterBegin)); //randomInteger(iterEnd - iterBegin));
		++iterBegin;
	}
}