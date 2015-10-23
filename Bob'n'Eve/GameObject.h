#pragma once
#include <cinttypes>
#include <Box2D/Dynamics/b2Body.h>
#include "PhysicsComponent.h"
#include "InputComponent.h"
#include "GraphicsComponent.h"
#include <SFML/include/SFML/System/Vector2.hpp>

class Renderer;

class GameObject
{
	friend class PhysicManager;
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update(int16_t ms);
	virtual void Draw(Renderer& renderer) const;

	float GetLayer() const;
	sf::Vector2f GetPosition() const;

protected:
	sf::Vector2f position_;

	//z-buffer
	float layer_;

	//pysics
	b2Body* body_;
	void setPhysicBody(b2Body* body);
};

