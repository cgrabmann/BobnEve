#pragma once
#include <SFML/include/SFML/Window/Joystick.hpp>
#include "InputComponent.h"

class InputComponentJoystick : public InputComponent
{
public:
	InputComponentJoystick(unsigned int player, unsigned int joystickId);
	virtual ~InputComponentJoystick();

	virtual void Update(GameObject& player, int16_t ms) override;

protected:
	const float threshold = 15.f;

	unsigned joystickId_;
	sf::Joystick::Axis xAxis_;
	sf::Joystick::Axis yAxis_;
};

