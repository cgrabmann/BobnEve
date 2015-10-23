#pragma once
#include <SFML/include/SFML/Window/Joystick.hpp>
#include "InputComponent.h"

class JoystickInputComponent : public InputComponent
{
public:
	JoystickInputComponent(unsigned player, unsigned joystickId);
	virtual ~JoystickInputComponent();

	virtual void Update(Player& player, int16_t ms) override;

protected:
	const float threshold = 0.15f;

	unsigned joystickId_;
	sf::Joystick::Axis xAxis_;
	sf::Joystick::Axis yAxis_;
};

