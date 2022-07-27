// Hanoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack> 

void oneStackIsEmpty(std::stack<int>& stack1, std::stack<int>& stack2, std::string num1, std::string num2)
{
	if (stack1.size() == 0)
	{
		int disc = stack2.top();
		stack2.pop();
		stack1.push(disc);
		std::cout << "Moved " << disc << " from tower " << num2 << " to tower " << num1 << '\n';
	}
	else
	{
		int disc = stack1.top();
		stack1.pop();
		stack2.push(disc);
		std::cout << "Moved " << disc << " from tower " << num1 << " to tower " << num2 << '\n';
	}
}

void bothStacksAreOccupied(std::stack<int>& stack1, std::stack<int>& stack2, std::string num1, std::string num2)
{
	if (stack1.top() > stack2.top())
	{
		int disc = stack2.top();
		stack2.pop();
		stack1.push(disc);
		std::cout << "Moved " << disc << " from tower 2 to tower 1\n";
	}
	else
	{
		int disc = stack1.top();
		stack1.pop();
		stack2.push(disc);
		std::cout << "Moved " << disc << " from tower 1 to tower 2\n";
	}
}

int main()
{
	std::stack<int> tower1;
	std::stack<int> tower2;
	std::stack<int> tower3;
	for (int i = 10; i > 0; i--)
	{
		tower1.push(i);
	}
	int moves = 0;

	while (true)
	{
		if (tower3.size() == 10 && tower3.top() == 1)
		{
			std::cout << moves << " moves";
			return 0;
		}

		// 1 and 2
		if (tower1.size() == 0 || tower2.size() == 0)
		{
			oneStackIsEmpty(tower1, tower2, "1", "2");
			moves++;
		}
		else
		{
			bothStacksAreOccupied(tower1, tower2, "1", "2");
			moves++;
		}

		// 1 and 3
		if (tower1.size() == 0 || tower3.size() == 0)
		{
			oneStackIsEmpty(tower1, tower3, "1", "3");
			moves++;
		}
		else
		{
			bothStacksAreOccupied(tower1, tower3, "1", "3");
			moves++;
		}

		// 2 and 3
		if (tower2.size() == 0 || tower3.size() == 0)
		{
			oneStackIsEmpty(tower2, tower3, "2", "3");
			moves++;
		}
		else
		{
			bothStacksAreOccupied(tower2, tower3, "2", "3");
			moves++;
		}
	}

	return -1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
