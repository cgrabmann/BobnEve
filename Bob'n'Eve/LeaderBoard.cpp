#include "LeaderBoard.h"
#include <algorithm> 
#include <functional>
#include <fstream>
#include <sstream>

LeaderBoard::LeaderBoard() : size_(3), entries_(new sf::Time[size_])
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

void LeaderBoard::AddEntry(sf::Time time)
{
	if (time.asSeconds() < entries_[size_ - 1].asSeconds() || entries_[size_ - 1].asMicroseconds() == 0)
	{
		entries_[size_ - 1] = time;

		struct {
			bool operator()(sf::Time a, sf::Time b)
			{
				return a < b;
			}
		} customGreater;

		std::sort(entries_, entries_ + size_, customGreater);
	}
}

bool LeaderBoard::LoadEntires(std::string fileName)
{
	std::string buffer;
	std::ifstream  myfile;
	myfile.open(fileName);
	if (!myfile.good())
	{
		size_ = 3;
		entries_ = new sf::Time[3]{ sf::Time::Zero,sf::Time::Zero, sf::Time::Zero };
		myfile.close();
		return false;
	}

	myfile >> buffer;
	myfile.close();

	size_ = std::count(buffer.begin(), buffer.end(), ';') + 1;
	entries_ = new sf::Time[size_];

	size_t pos = 0;
	for (int i = 0; i < size_ - 1; i++)
	{
		pos = buffer.find(';');
		entries_[i] = sf::seconds(atof(buffer.substr(0, pos).c_str()));
		buffer.erase(0, pos + 1);
	}
	entries_[size_ - 1] = sf::seconds(atof(buffer.c_str()));

	return true;
}

bool LeaderBoard::SaveEntires(std::string fileName) const
{
	std::ofstream  myfile;
	myfile.open(fileName);
	if (!myfile.good())
	{
		return false;
	}

	for (int i = 0; i < size_; i++)
	{
		myfile << std::to_string(entries_[i].asSeconds());

		if (i != size_ - 1)
		{
			myfile << ";";
		}
	}

	myfile.close();
	return true;
}
