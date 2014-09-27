/*
 * Permutation.cpp
 *
 *  Created on: Aug 7, 2014
 *      Author: smart
 */

#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;


int nextChoice(const std::vector<bool>& v)
{
	std::vector<bool>::const_iterator iter = std::find(v.begin(), v.end(), false);
	if (iter==v.end())
		return -1;
	else
		return iter-v.begin();
}

/*
 * permutation(Result, ChoiceSet)
 * 	if no choices left
 * 		Result is a solution, save Result
 * 		return
 *  end
 *
 *  init all choices to be unprocessed
 *
 *  while (choices left)
 *     pull elem from ChoiceSet
 *     mark elem as processed, and add to Result,
 *
 *	   RemainingChoices = ChiceSet - elem;
 *
 *     permutation(Result, RemainingChoices)
 *
 *     pop elem from Result
 *  end
 */

void permutation(std::vector<int>& result, std::vector<int>& choiceSet)
{
	if (choiceSet.empty())
	{
		cout << "Solution found:";
		for (unsigned i = 0; i < result.size(); ++i)
			cout << " " << result[i];
		cout << endl;
		return;
	}

	std::vector<bool> processed(choiceSet.size(), false);

	int index = -1;
	while ( (index = nextChoice(processed)) != -1 )
	{
		result.push_back(choiceSet[index]);
		processed[index] = true;

		std::vector<int> remaningChoices(choiceSet.begin(), choiceSet.end());
		remaningChoices.erase(remaningChoices.begin()+index);

		permutation(result, remaningChoices);

		result.pop_back();
	}
}

void testPermutation()
{
	int iarray[] = { 1, 2, 3, 4 };

	std::vector<int> vec2(iarray, iarray + sizeof(iarray)/sizeof(*iarray));
	std::vector<int> vec1;

	permutation(vec1, vec2);
}
