#pragma once
#include <cinttypes>
#include <SFML/include/SFML/System/Vector2.hpp>

class PhysicsComponent;
class Renderer;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update(int16_t ms);
	virtual void Draw(Renderer& renderer) const;

	float GetLayer() const;
	sf::Vector2f GetPosition() const;

protected:
	//top-left corner
	//may be replaced by box2d::body
	sf::Vector2f position_;

	//z-buffer
	float layer_;
};

