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
	GraphicsComponent(sf::Sprite* sprite, bool running = true);
	virtual ~GraphicsComponent();

	virtual void Update(GameObject& object, int16_t ms);
	virtual void Draw(const GameObject& object, Renderer& renderer);

	virtual void Start() { isRunning_ = true; }
	virtual void Pause() { isRunning_ = false; }
	virtual void Stop() { isRunning_ = false; }
	virtual void ReStart() { isRunning_ = true; }
	virtual void Reset() {}

	virtual bool IsRunning() const { return isRunning_; }
	virtual void SetRun(const bool isRunning) { isRunning_ = isRunning; }
	
protected:
	void UpdateSprite(const GameObject& object, Renderer& renderer, sf::Sprite& sprite);

	sf::Sprite* sprite_;
	bool isRunning_;
};

