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

	bool IsRunning() const { return isRunning_; }
	void IsRunning(const bool isRunning) { isRunning_ = isRunning; }

	bool IsVisible() const { return isVisible_; }
	void IsVisible(const bool isVisible) { isVisible_ = isVisible; }
	
protected:
	void UpdateSprite(const GameObject& object, const Renderer& renderer, sf::Sprite& sprite);

	sf::Sprite* sprite_;
	bool isRunning_, isVisible_;
};

