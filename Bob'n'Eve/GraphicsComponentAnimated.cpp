#include "GraphicsComponentAnimated.h"
#include "GameObject.h"


GraphicsComponentAnimated::GraphicsComponentAnimated(std::vector<sf::Sprite*> sprites, std::vector<int16_t> msPerFrame) : GraphicsComponentStatic(sprites.at(0)), sprites_(sprites), index_(0), msCount_(0), msPerFrame_(msPerFrame)
{
}

GraphicsComponentAnimated::GraphicsComponentAnimated(std::vector<sf::Sprite*> sprites, int16_t msPerFrame) : GraphicsComponentStatic(sprites.at(0)), sprites_(sprites), index_(0), msCount_(0), msPerFrame_(std::vector<int16_t>(sprites.size(), msPerFrame))
{
}

GraphicsComponentAnimated::~GraphicsComponentAnimated()
{
}

void GraphicsComponentAnimated::Update(GameObject& object, int16_t ms)
{
	msCount_ += ms;
	if (msCount_ >= msPerFrame_.at(index_))
	{
		msCount_ -= msPerFrame_.at(index_);
		index_++;
		index_ %= sprites_.size();
	}

	sprite_ = sprites_.at(index_);
}
