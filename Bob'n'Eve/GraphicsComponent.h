#pragma once
#include <cinttypes>

namespace sf{
	class Sprite;
}

class Renderer;
class GameObject;

class GraphicsComponent
{
public:
	GraphicsComponent();
	GraphicsComponent(sf::Sprite* sprite);
	virtual ~GraphicsComponent();

	virtual void Update(GameObject& object, int16_t ms);
	virtual void Draw(const GameObject& object, Renderer& renderer);
	
protected:
	void UpdateSprite(const GameObject& object, Renderer& renderer, sf::Sprite& sprite);

	sf::Sprite* sprite_;
};

