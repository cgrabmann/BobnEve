#include "View.h"
#include <SFML/include/SFML/Window/Joystick.hpp>
#include "JoystickInputComponent.h"
#include <SFML/include/SFML/Graphics/Color.hpp>
#include "PhysicsComponent.h"
#include "GraphicsComponentStatic.h"
#include "Player.h"

View::View(Player* bob, Player* eve, std::vector<Platform*>* platforms, std::vector<Enemy*>* enemies):
bob_(bob), eve_(eve), platforms_(platforms), enemys_(enemies), assets_()
{
}

View::~View()
{
	delete bob_;
	delete eve_;
	for (size_t i = 0; i < platforms_->size(); i++)
	{
		delete platforms_->at(i);
	}
	delete platforms_;
	for (size_t i = 0; i < enemys_->size(); i++)
	{
		delete enemys_->at(i);
	}
	delete enemys_;
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

