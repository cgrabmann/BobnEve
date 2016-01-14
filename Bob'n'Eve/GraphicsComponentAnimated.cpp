#include "GraphicsComponentAnimated.h"
#include "GameObject.h"
#include "Frame.h"

GraphicsComponentAnimated::GraphicsComponentAnimated(std::vector<Frame*> frames, bool mirror, bool running) : GraphicsComponent(frames.at(0)->sprite, running), frames_(frames), index_(0), msCount_(0), displayTime_(frames.at(0)->displayTime), mirror_(mirror), mirroring_(false)
{
}

GraphicsComponentAnimated::~GraphicsComponentAnimated()
{
	//frames_.clear();
}

void GraphicsComponentAnimated::Update(GameObject& object, int16_t ms)
{
	if (!isRunning_)
		return;

	msCount_ += ms;

	if (msCount_ >= displayTime_)
	{
		msCount_ -= displayTime_;
		index_ += mirroring_ ? -1 : 1;
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
		displayTime_ = frames_.at(index_)->displayTime;
		sprite_ = frames_.at(index_)->sprite;
	}
}
