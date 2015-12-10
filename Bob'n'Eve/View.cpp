#pragma once
#include "View.h"
#include "Player.h"
#include "Platform.h"
#include "Enemy.h"
#include "Vector2f.h"
#include "PhysicManager.h"

View::View() : objects_(std::vector<GameObject*>()), players_(std::vector<Player*>())
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

void View::Register(GameObject* platform)
{
	objects_.push_back(platform);
}

void View::Register(Enemy* enemy)
{
	enemies_.push_back(enemy);
}

void View::Register(Player* player)
{
	players_.push_back(player);
}

void View::CleanUp()
{
	objects_.clear();
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

	DeleteAllEnemiesToDelete();

	PhysicManager::Instance()->Update(ms);
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
}

void View::DeleteAllEnemiesToDelete()
{
	for (Enemy* enemy : enemiesToDelete_)
	{
		enemies_.erase(std::find(enemies_.begin(), enemies_.end(), enemy));
		delete enemy;
	}
	enemiesToDelete_.clear();
}

void View::DeleteEnemy(Enemy* enemy)
{
	enemiesToDelete_.push_back(enemy);
}

void View::DeleteEnemyById(size_t id)
{
	for (std::vector<Enemy*>::iterator it = enemies_.begin(); it != enemies_.end(); ++it)
	{
		if ((*it)->GetId() == id)
		{
			enemiesToDelete_.push_back(*it);
		}
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
