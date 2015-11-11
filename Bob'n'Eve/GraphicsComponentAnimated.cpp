#include "GraphicsComponentAnimated.h"
#include "GameObject.h"


GraphicsComponentAnimated::GraphicsComponentAnimated(std::vector<sf::Sprite*> sprites, std::vector<int16_t> msPerFrame, bool mirror) : GraphicsComponent(sprites.at(0)), sprites_(sprites), index_(0), msCount_(0), msPerFrame_(msPerFrame), mirror_(mirror), mirroring_(false)
{
}

GraphicsComponentAnimated::GraphicsComponentAnimated(std::vector<sf::Sprite*> sprites, int16_t msPerFrame, bool mirror) : GraphicsComponentAnimated(sprites, std::vector<int16_t>(sprites.size(), msPerFrame), mirror)
{
}

GraphicsComponentAnimated::~GraphicsComponentAnimated()
{
}

void GraphicsComponentAnimated::Update(GameObject& object, int16_t ms)
{
	msCount_ += ms;
	uint16_t msPerFrame = msPerFrame_.at(index_);

	if (msCount_ >= msPerFrame)
	{
		msCount_ -= msPerFrame;
		index_ += mirroring_ ? -1 : +1;
		if (mirror_)
		{
			if (index_ == 0)
			{
				mirroring_ = false;
			}
			if (index_ == sprites_.size() - 1)
			{
				mirroring_ = true;

			}
		}
		else
		{
			index_ %= sprites_.size();
		}
		sprite_ = sprites_.at(index_);
	}
}
