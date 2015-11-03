#pragma once
#include <cinttypes>
#include <SFML/include/SFML/Graphics/Sprite.hpp>

class Renderer;
class GameObject;

class GraphicsComponentBase
{
public:
	GraphicsComponentBase();
	GraphicsComponentBase(sf::Sprite* sprite);
	virtual ~GraphicsComponentBase();

	virtual void Update(GameObject& object, int16_t ms) = 0;
	virtual void Draw(const GameObject& object, Renderer& renderer) const = 0;
	
protected:
	sf::Sprite* sprite_;
};

