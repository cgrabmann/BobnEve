#pragma once
#include <cinttypes>
#include "Vector2f.h"

class GraphicsComponentBase;
class PhysicsComponentBase;
class InputComponentBase;
class Renderer;

class GameObject
{
public:
	GameObject(InputComponentBase* input,	PhysicsComponentBase* physics,	GraphicsComponentBase* graphics);
	virtual ~GameObject();

	void Update(int16_t ms);
	void Draw(Renderer& renderer) const;

	float GetLayer() const;
	const Vector2f& GetPosition() const;
	const Vector2f& GetVelocity() const;

	Vector2f GetOrientation() const;

	virtual void Left();
	virtual void Right();
	virtual void Up();
	virtual void Down();

protected:
	//z-buffer
	float layer_;

	InputComponentBase* input_;
	PhysicsComponentBase* physics_;
	GraphicsComponentBase* graphics_;
};

