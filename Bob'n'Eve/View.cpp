#include "View.h"
#include <SFML/include/SFML/Window/Joystick.hpp>
#include "JoystickInputComponent.h"

View::View() : platforms_(), enemys_()
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
	GraphicsComponent* graphicsPlayer1 = new GraphicsComponent(sf::Color::Red);

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
	GraphicsComponent* graphicsPlayer2 = new GraphicsComponent(sf::Color::Blue);

	player2_ = new Player(inputPlayer2, physicsPlayer2, graphicsPlayer2);
}

View::~View()
{
	
}


void View::Update(int16_t ms)
{
	for (int i = 0; i < platforms_.size(); i++)
	{
		platforms_[i]->Update(ms);
	}

	for (int i = 0; i < enemys_.size(); i++)
	{
		enemys_[i]->Update(ms);
	}

	player1_->Update(ms);
	player2_->Update(ms);
}

void View::Draw(Renderer& renderer) const
{
	for (int i = 0; i < platforms_.size(); i++)
	{
		platforms_[i]->Draw(renderer);
	}

	for (int i = 0; i < enemys_.size(); i++)
	{
		enemys_[i]->Draw(renderer);
	}

	player1_->Draw(renderer);
	player2_->Draw(renderer);
}

