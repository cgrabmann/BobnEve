#pragma once
#include <cinttypes>
#include "Vector2f.h"

class GraphicsComponent;
class PhysicsComponentBase;
class InputComponent;
class Renderer;

class GameObject
{
public:
	GameObject(InputComponent* input,	PhysicsComponentBase* physics,	GraphicsComponent* graphics);
	virtual ~GameObject();

	virtual void Update(int16_t ms);
	virtual void Draw(Renderer& renderer) const;

	float GetLayer() const;
	Vector2f GetPosition() const;
	Vector2f GetRenderPosition() const;
	Vector2f GetVelocity() const;
	Vector2f GetOrientation() const;

	void SetVelocity(Vector2f const & vec);
	void SetVelocity(float x, float y);

	void Left();
	void Right();
	void Up();
	void Kill();

	bool isActive() const { return isActive_; }
	void isActive(const bool isActive) { isActive_ = isActive; }

protected:
	//z-buffer
	float layer_;

	bool isActive_;

	InputComponent* input_;
	PhysicsComponentBase* physics_;
	GraphicsComponent* graphics_;
};

