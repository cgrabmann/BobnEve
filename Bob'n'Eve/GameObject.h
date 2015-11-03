#pragma once
#include <cinttypes>
#include <SFML/include/SFML/System/Vector2.hpp>
#include <Box2D/Box2D.h>
#include "InputComponentBase.h"
#include "PhysicsComponentBase.h"
#include "GraphicsComponentBase.h"
#include "Vector2f.h"

class Renderer;

class GameObject
{
public:
	GameObject(InputComponentBase* input,	PhysicsComponentBase* physics,	GraphicsComponentBase* graphics);
	GameObject(b2Body* physicsBody, b2Vec2 orientation, InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics);
	virtual ~GameObject();

	virtual void Update(int16_t ms);
	virtual void Draw(Renderer& renderer) const;

	float GetLayer() const;
	Vector2f GetPosition() const;		
	b2Body* GetPhysicsBody() const;
	Vector2f GetOrientation() const;

protected:
	//top-left corner
	sf::Vector2f position_;

	b2Body* physicsBody_;

	b2Vec2 orientation_;

	//z-buffer
	float layer_;

	InputComponentBase* input_;
	PhysicsComponentBase* physics_;
	GraphicsComponentBase* graphics_;
};

