#pragma once
#include "View.h"
#include "Player.h"
#include "Coin.h"
#include "Enemy.h"
#include "Vector2f.h"
#include "PhysicManager.h"
#include "Finish.h"

View::View() : enemies_(std::vector<Enemy*>()), players_(std::vector<Player*>()), coins_(std::vector<Coin*>()), objects_(std::vector<GameObject*>()), score_(0), isActive_(true)
{
}

View::~View()
{	
}

View* View::instance_ = NULL;

View* View::Instance()
{
	static CGuard g;   // Speicherbereinigung
	if (!instance_)
		instance_ = new View();
	return instance_;
}

void View::Register(GameObject* object)
{
	objects_.push_back(object);
}

void View::Register(Enemy* enemy)
{
	enemies_.push_back(enemy);
}

void View::Register(Coin* coin)
{
	coins_.push_back(coin);
}

void View::Register(Player* player)
{
	players_.push_back(player);
}

void View::CleanUp()
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

	score_ = 0;
	isActive_ = true;
}

void View::Update(int16_t ms)
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

	DestroyAllKilledEnemies();
	DestroyAllCollectedCoins();

	PhysicManager::Instance()->Update(ms);
}

void View::Destroy(Enemy* enemy)
{
	int id = enemy->GetId();
	for (std::vector<Enemy*>::iterator it = enemies_.begin(); it != enemies_.end(); ++it)
	{
		if ((*it)->GetId() == id)
		{
			enemiesToDelete_.push_back(*it);
		}
	}

	score_ += 5;
}

void View::DestroyAllKilledEnemies()
{
	for (Enemy* enemy : enemiesToDelete_)
	{
		enemies_.erase(std::find(enemies_.begin(), enemies_.end(), enemy));
		delete enemy;
	}
	enemiesToDelete_.clear();
}

void View::Destroy(Player* player)
{
	isActive_ = false;
}

void View::Destroy(Finish* finish)
{
	isActive_ = false;

	score_ += 50;
}

void View::Destroy(Coin* coin)
{
	coinsToDelete_.push_back(coin);

	score_ += 10;
}

void View::DestroyAllCollectedCoins()
{
	for (Coin* coin : coinsToDelete_)
	{
		coins_.erase(std::find(coins_.begin(), coins_.end(), coin));
		delete coin;
	}
	coinsToDelete_.clear();
}

void View::Draw(Renderer& renderer) const
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
}

std::vector<const Vector2f> View::GetFocusPoints() const
{
	std::vector<const Vector2f> focusPoints;
	for (std::vector<Player*>::const_iterator it = players_.begin(); it != players_.end(); ++it)
	{
		focusPoints.push_back((*it)->GetRenderPosition());
	}
	return focusPoints;
}
