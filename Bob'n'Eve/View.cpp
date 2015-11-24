#pragma once
#include "View.h"
#include "Player.h"
#include "Platform.h"
#include "Enemy.h"
#include "Vector2f.h"
#include "PhysicManager.h"

View::View() : bob_(nullptr), eve_(nullptr), platforms_(new std::vector<Platform*>), enemys_(new std::vector<Enemy*>)
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

void View::Register(Player* bob, Player* eve, std::vector<Platform*>* platforms, std::vector<Enemy*>* enemies)
{
	bob_ = bob;
	eve_ = eve;
	platforms_ = platforms;
	enemys_ = enemies;
}

void View::CleanUp()
{
	delete bob_;
	bob_ = nullptr;
	delete eve_;
	eve_ = nullptr;
	platforms_->clear();
	enemys_->clear();
}

void View::Update(int16_t ms)
{
	for (size_t i = 0; i < platforms_->size(); i++)
	{
		platforms_->at(i)->Update(ms);
	}

	for (size_t i = 0; i < enemys_->size(); i++)
	{
		enemys_->at(i)->Update(ms);
	}

	bob_->Update(ms);
	eve_->Update(ms);

	PhysicManager::Instance()->Update(ms / 1000.f);
}

void View::Draw(Renderer& renderer) const
{
	for (size_t i = 0; i < platforms_->size(); i++)
	{
		platforms_->at(i)->Draw(renderer);
	}

	for (size_t i = 0; i < enemys_->size(); i++)
	{
		enemys_->at(i)->Draw(renderer);
	}

	bob_->Draw(renderer);
	eve_->Draw(renderer);
}

const Vector2f View::GetCenterPoint() const
{
	return (bob_->GetRenderPosition() + eve_->GetRenderPosition()) / 2;
}
