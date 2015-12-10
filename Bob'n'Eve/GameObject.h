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
	explicit GameObject(InputComponent* input,	PhysicsComponentBase* physics,	GraphicsComponent* graphics, Vector2f speed = Vector2f(0,0));
	virtual ~GameObject();

	virtual void Update(int16_t ms);
	virtual void Draw(Renderer& renderer) const;

	float GetLayer() const;
	Vector2f GetPosition() const;
	Vector2f GetRenderPosition() const;
	Vector2f GetVelocity() const;
	Vector2f GetOrientation() const;
	bool IsOnGround() const;

	void SetVelocity(Vector2f const & vec);
	void SetVelocity(float x, float y);
	void SetOnGround(bool onGround);

	virtual void Left();
	virtual void Right();
	virtual void Up();
	virtual void Kill();
protected:
	//z-buffer
	float layer_;
	bool onGround_;

	Vector2f speed_;

	InputComponent* input_;
	PhysicsComponentBase* physics_;
	GraphicsComponent* graphics_;
};

