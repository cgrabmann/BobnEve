#pragma once
#include <cinttypes>
#include "Vector2f.h"

class GraphicsComponent;
class PhysicsComponent;
class InputComponent;
class Renderer;

class GameObject
{
public:
	GameObject(InputComponent* input,	PhysicsComponent* physics,	GraphicsComponent* graphics);
	virtual ~GameObject();

	void Update(int16_t ms);
	void Draw(Renderer& renderer) const;

	float GetLayer() const;
	Vector2f GetPosition() const;
	Vector2f GetRenderPosition() const;
	Vector2f GetVelocity() const;
	Vector2f GetOrientation() const;

	void SetVelocity(Vector2f const & vec);
	void SetVelocity(float x, float y);

protected:
	//z-buffer
	float layer_;

	InputComponent* input_;
	PhysicsComponent* physics_;
	GraphicsComponent* graphics_;
};

