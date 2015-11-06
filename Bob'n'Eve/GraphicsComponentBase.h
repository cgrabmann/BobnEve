#pragma once
#include <cinttypes>

namespace sf{
	class Sprite;
}

class Renderer;
class GameObject;

class GraphicsComponentBase
{
public:
	GraphicsComponentBase();
	GraphicsComponentBase(sf::Sprite* sprite);
	virtual ~GraphicsComponentBase();

	virtual void Update(GameObject& object, int16_t ms) = 0;
	virtual void Draw(const GameObject& object, Renderer& renderer) = 0;
	
protected:
	void UpdateSprite(const GameObject& object, Renderer& renderer, sf::Sprite& sprite);

	sf::Sprite* sprite_;
};

