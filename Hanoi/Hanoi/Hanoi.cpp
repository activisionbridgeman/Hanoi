// Hanoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Prints out the steps required to solve the "Tower of Hanoi"
// This program uses the iterative solution from https://en.wikipedia.org/wiki/Tower_of_Hanoi

#include <iostream>
#include <stack> 

// Run when either stack 1 or stack 2 has no discs
// Moves the disc from the stack containing one or more discs to the stack containing no discs
// For example, if stackA has no discs, stackB must contain one or more discs, so the top disc from stackB will move to stackA
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

// Run when both stack 1 and stack 2 contain one or more discs
// If both stacks contain one or more discs, then the smaller top disc must be moved to the stack with the larger top disc
// For example, if stackA has a top disc of 5 and stackB has a top disc of 2, then the top disc from stackB must be moved to the top of stackA
void bothStacksAreOccupied(std::stack<int>& stack1, std::stack<int>& stack2, std::string num1, std::string num2)
{
	if (stack1.top() > stack2.top())
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

int main()
{
	std::stack<int> tower1;
	std::stack<int> tower2;
	std::stack<int> tower3;

	// Populate tower 1 with 10 discs
	for (int i = 10; i > 0; i--)
	{
		tower1.push(i);
	}

	// Keep track of numbers of moves
	int moves = 0;

	while (true)
	{
		// Check for completion: tower 3 has 10 discs and top one is '1'
		if (tower3.size() == 10 && tower3.top() == 1)
		{
			// Print number of moves (should be 1023)
			std::cout << moves << " moves";
			return 0;
		}

		// Procedure for towers 1 and 2
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

		// Procedure for towers 1 and 3
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

		// Procedure for towers 2 and 3
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

	// Failure if this point is reached
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
