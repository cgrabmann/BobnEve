#pragma once
#include <string>

class LeaderBoard
{
public:
	LeaderBoard();
	LeaderBoard(std::string fileName);
	~LeaderBoard();

	void AddEntry(int points);
	int* GetEntries() const
	{
		return entries_;
	}
	void LoadEntires(std::string fileName);
	int GetSize() const 
	{
		return size_;
	}
protected:
	const int size_;
	int* entries_;
};

