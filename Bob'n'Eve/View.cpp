#include "View.h"
#include <SFML/include/SFML/Window/Joystick.hpp>
#include "JoystickInputComponent.h"
#include <SFML/include/SFML/Graphics/Color.hpp>
#include "PhysicsComponent.h"
#include "GraphicsComponentStatic.h"

View::View() : platforms_(), enemys_(), assets_()
{
	InputComponent* inputPlayer1;
	if (sf::Joystick::isConnected(0))
	{
		inputPlayer1 = new JoystickInputComponent(1, 0);
	}
	else
	{
		inputPlayer1 = new InputComponent(1);
	}
	PhysicsComponent* physicsPlayer1 = new PhysicsComponent();
	GraphicsComponentBase* graphicsPlayer1 = new GraphicsComponentStatic(assets_.GetSpriteByName("Test.png",0));

	player1_ = new Player(inputPlayer1, physicsPlayer1, graphicsPlayer1);

	InputComponent* inputPlayer2;
	if (sf::Joystick::isConnected(1))
	{
		inputPlayer2 = new JoystickInputComponent(2, 1);
	}
	else
	{
		inputPlayer2 = new InputComponent(2);
	}
	PhysicsComponent* physicsPlayer2 = new PhysicsComponent();
	GraphicsComponentBase* graphicsPlayer2 = new GraphicsComponentStatic(assets_.GetSpriteByName("Test.png", 3));

	player2_ = new Player(inputPlayer2, physicsPlayer2, graphicsPlayer2);
}

View::~View()
{
	
}


void View::Update(int16_t ms)
{
	for (size_t i = 0; i < platforms_.size(); i++)
	{
		platforms_[i]->Update(ms);
	}

	for (size_t i = 0; i < enemys_.size(); i++)
	{
		enemys_[i]->Update(ms);
	}

	player1_->Update(ms);
	player2_->Update(ms);
}

void View::Draw(Renderer& renderer) const
{
	for (size_t i = 0; i < platforms_.size(); i++)
	{
		platforms_[i]->Draw(renderer);
	}

	for (size_t i = 0; i < enemys_.size(); i++)
	{
		enemys_[i]->Draw(renderer);
	}

	player1_->Draw(renderer);
	player2_->Draw(renderer);
}

