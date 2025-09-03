#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<double> creditsTaken;
	vector<double> creditsEarned;
	ifstream infile;
	infile.open("test.txt");

	if (infile.fail())
	{
		cout << "Failed to open";
		return -1;
	}

	char grade;
	string line;

	int size = 0;

	while (!infile.eof())
	{
		getline(infile, line);
		size = line.length();

		string credit_hrs;
		double credits;
		string temp = line;

		int i = 0;
		while (temp[i] != ' ')
		{
			credit_hrs += temp[i];
			i++;
		}
		if (credit_hrs == "Honors" || credit_hrs == "Honours")
		{
			credits = 4.5;
		}
		else if (credit_hrs == "AP" || credit_hrs == "Ap")
		{
			credits = 5.0;
		}
		else
		{
			credits = 4.0;
		}
		//cout << "This is the credit hours for the course " << credits << endl;
		creditsTaken.push_back(credits);

		double creditTemp = credits;


		/*
		for (int i = 0; i < size; i++)
		{
			cout << i << ". " << line[i] << endl;
		}
		cout << "This is the grade for the class " << line[size - 1] << endl;
		*/

		grade = line[size - 1];
		if (grade == 'A')
		{
			credits = 4.0;
		}
		else if (grade == 'B')
		{
			credits = 3.0;
		}
		else if (grade == 'C')
		{
			credits = 2.0;
		}
		else if (grade == 'D')
		{
			credits = 1.0;
		}
		else
		{
			credits = 0.0;
		}

		if (creditTemp == 4.5)
		{
			credits += 0.5;
		}
		else if (creditTemp == 5.0)
		{
			credits += 1.0;
		}



		creditsEarned.push_back(credits);

	}

	infile.close();

	double cgpa = 0;

	for (size_t i = 0; i < creditsEarned.size(); i++)
	{
		cgpa += (creditsEarned[i] * creditsTaken[i]);
	}

	double totalCredits = 0;

	for (int i = 0; i < creditsTaken.size(); i++)
	{
		totalCredits += creditsTaken[i];
	}

	cgpa = cgpa / totalCredits;

	cout << "Your CGPA is " << cgpa << endl;





	return 0;
}