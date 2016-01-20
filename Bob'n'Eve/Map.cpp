#pragma once
#include "Map.h"
#include "Player.h"
#include "Coin.h"
#include "Enemy.h"
#include "Vector2f.h"
#include "PhysicManager.h"
#include "Finish.h"

Map::Map() : enemies_(std::vector<Enemy*>()), players_(std::vector<Player*>()), coins_(std::vector<Coin*>()), objects_(std::vector<GameObject*>()), time_(sf::Time::Zero), status_(Active)
{
}

Map::~Map()
{	
}

Map* Map::instance_ = NULL;

Map* Map::Instance()
{
	static CGuard g;   // Speicherbereinigung
	if (!instance_)
		instance_ = new Map();
	return instance_;
}

void Map::Register(GameObject* object)
{
	objects_.push_back(object);
}

void Map::Register(Finish* finish)
{
	finish_ = finish;
}

void Map::Register(Enemy* enemy)
{
	enemies_.push_back(enemy);
}

void Map::Register(Coin* coin)
{
	coins_.push_back(coin);
}

void Map::Register(Player* player)
{
	players_.push_back(player);
}

void Map::CleanUp()
{
	for (std::vector<GameObject*>::iterator it = objects_.begin(); it != objects_.end(); ++it)
	{
		delete(*it);
	}
	objects_.clear();

	for (std::vector<Enemy*>::iterator it = enemies_.begin(); it != enemies_.end(); ++it)
	{
		delete(*it);
	}
	enemies_.clear();

	for (std::vector<Player*>::iterator it = players_.begin(); it != players_.end(); ++it)
	{
		delete(*it);
	}
	players_.clear();

	for (std::vector<Coin*>::iterator it = coins_.begin(); it != coins_.end(); ++it)
	{
		delete(*it);
	}
	coins_.clear();

	//delete finish_;

	time_ = sf::Time::Zero;
	status_ = Active;
}

void Map::Update(int16_t ms)
{
	for (std::vector<GameObject*>::iterator it = objects_.begin(); it != objects_.end(); ++it)
	{
		(*it)->Update(ms);
	}

	for (std::vector<Enemy*>::iterator it = enemies_.begin(); it != enemies_.end(); ++it)
	{
		(*it)->Update(ms);
	}

	for (std::vector<Player*>::iterator it = players_.begin(); it != players_.end(); ++it)
	{
		(*it)->Update(ms);
	}

	for (std::vector<Coin*>::iterator it = coins_.begin(); it != coins_.end(); ++it)
	{
		(*it)->Update(ms);
	}

	if (finish_)
	finish_->Update(ms);

	DestroyAllKilledEnemies();
	DestroyAllCollectedCoins();

	PhysicManager::Instance()->Update(ms);

	time_ += sf::milliseconds(ms);
}

void Map::Destroy(Enemy* enemy)
{
	int id = enemy->GetId();
	for (std::vector<Enemy*>::iterator it = enemies_.begin(); it != enemies_.end(); ++it)
	{
		if ((*it)->GetId() == id)
		{
			enemiesToDelete_.push_back(*it);
		}
	}
}

void Map::DestroyAllKilledEnemies()
{
	for (Enemy* enemy : enemiesToDelete_)
	{
		enemies_.erase(std::find(enemies_.begin(), enemies_.end(), enemy));
		delete enemy;
	}
	enemiesToDelete_.clear();
}

void Map::Destroy(Player* player)
{
	status_ = GameOver;
}

void Map::Destroy(Finish* finish)
{
	status_ = Victory;
}

void Map::Destroy(Coin* coin)
{
	coinsToDelete_.push_back(coin);

	time_ -= sf::seconds(10); 
	if (time_.asMicroseconds() < 0)
	{
		time_ = sf::seconds(0);
	}
}

void Map::DestroyAllCollectedCoins()
{
	for (Coin* coin : coinsToDelete_)
	{
		coins_.erase(std::find(coins_.begin(), coins_.end(), coin));
		delete coin;
	}
	coinsToDelete_.clear();
}

void Map::Draw(Renderer& renderer) const
{
	for (std::vector<GameObject*>::const_iterator it = objects_.begin(); it != objects_.end(); ++it)
	{
		(*it)->Draw(renderer);
	}

	for (std::vector<Enemy*>::const_iterator it = enemies_.begin(); it != enemies_.end(); ++it)
	{
		(*it)->Draw(renderer);
	}

	for (std::vector<Player*>::const_iterator it = players_.begin(); it != players_.end(); ++it)
	{
		(*it)->Draw(renderer);
	}

	for (std::vector<Coin*>::const_iterator it = coins_.begin(); it != coins_.end(); ++it)
	{
		(*it)->Draw(renderer);
	}

	if (finish_)
	finish_->Draw(renderer);
}

std::vector<const Vector2f> Map::GetFocusPoints() const
{
	std::vector<const Vector2f> focusPoints;
	for (std::vector<Player*>::const_iterator it = players_.begin(); it != players_.end(); ++it)
	{
		focusPoints.push_back((*it)->GetRenderPosition());
	}
	return focusPoints;
}
