#pragma once
#include <string>
#include <SFML/include/SFML/System/Time.hpp>

class LeaderBoard
{
public:
	LeaderBoard();
	LeaderBoard(std::string fileName);
	~LeaderBoard();

	void AddEntry(sf::Time time);
	sf::Time* GetEntries() const
	{
		return entries_;
	}
	bool LoadEntires(std::string fileName);
	bool SaveEntires(std::string fileName) const;

	int GetSize() const 
	{
		return size_;
	}
protected:
	int size_;
	sf::Time* entries_;
};

