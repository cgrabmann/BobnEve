#include "LeaderBoard.h"
#include <algorithm> 
#include <functional>

LeaderBoard::LeaderBoard() : size_(3), entries_(new int[size_]{0, 0, 0})
{
}

LeaderBoard::LeaderBoard(std::string fileName) : size_(3)
{
	LoadEntires(fileName);
}

LeaderBoard::~LeaderBoard()
{
	delete[] entries_;
}

void LeaderBoard::AddEntry(int points)
{
	if (points > entries_[size_ - 1])
	{
		entries_[size_ - 1] = points;
		std::sort(entries_, entries_ + size_, std::greater<int>());
	}
}

void LeaderBoard::LoadEntires(std::string fileName)
{
	entries_ = new int[size_]{0, 0, 0};
}
