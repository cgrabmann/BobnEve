#pragma once
#include <cinttypes>
#include <SFML/include/SFML/System/Vector2.hpp>
#include <Box2D/Box2D.h>
#include "Vector2f.h"

class GraphicsComponentBase;
class PhysicsComponentBase;
class InputComponentBase;
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
	Vector2f GetVelocity() const;
	
	void SetOrientation(Vector2f const vec);
	//parameter = 0 gets ignored
	void SetOrientation(float x, float y);
	void SetVelocity(Vector2f const vec) const;
	void SetVelocity(float x, float y) const;

protected:
	//center of object
	sf::Vector2f position_;

	b2Body* physicsBody_;

	b2Vec2 orientation_;

	//z-buffer
	float layer_;

	InputComponentBase* input_;
	PhysicsComponentBase* physics_;
	GraphicsComponentBase* graphics_;
};

