

#include <SFML/include/SFML/Graphics/Sprite.hpp>
#include <cstdint>

class Frame
{
public:
	inline Frame(sf::Sprite* sprite, int16_t displayTime) : sprite(sprite), displayTime(displayTime)
	{}
	inline ~Frame()
	{
		delete sprite;
	}

	sf::Sprite* sprite;
	int16_t displayTime;
};
