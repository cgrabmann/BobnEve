#include "GraphicsComponentAnimated.h"
#include "GameObject.h"
#include "Frame.h"

GraphicsComponentAnimated::GraphicsComponentAnimated(std::vector<Frame*> frames, bool mirror) : GraphicsComponent(frames.at(0)->sprite), frames_(frames), index_(0), msCount_(0), mirror_(mirror), mirroring_(false)
{
}

GraphicsComponentAnimated::~GraphicsComponentAnimated()
{
}

void GraphicsComponentAnimated::Update(GameObject& object, int16_t ms)
{
	msCount_ += ms;
	uint16_t msPerFrame = frames_.at(index_)->displayTime;

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
			if (index_ == frames_.size() - 1)
			{
				mirroring_ = true;
			}
		}
		else
		{
			index_ %= frames_.size();
		}
		sprite_ = frames_.at(index_)->sprite;
	}
}
