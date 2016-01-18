#include "CallbackCombiner.h"
#include "TrampolinCollisionCallback.h"
#include "PassThroughCollisionCallback.h"
#include "JumpPadCollisionCallback.h"


CallbackCombiner::CallbackCombiner() : lastType("Empty"), lastCallback(nullptr)
{
}


CallbackCombiner::~CallbackCombiner()
{
}

UpdateableCollisionCallback* CallbackCombiner::GetCallback(std::string& type)
{
	if (lastType == type)
	{
		return lastCallback;
	}
	lastType = type;

	if (type == "JumpPad")
	{
		return lastCallback = new JumpPadCollisionCallback();
	}
	if (type == "Trampoline")
	{
		return lastCallback = new TrampolinCollisionCallback();
	}
	if (type == "PassThrough")
	{
		return lastCallback = new PassThroughCollisionCallback();
	}
	return lastCallback = nullptr;
}
