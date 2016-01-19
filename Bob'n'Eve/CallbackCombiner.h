#pragma once
#include "UpdateableCollisionCallback.h"
#include <string>

class CallbackCombiner
{
public:
	CallbackCombiner();
	~CallbackCombiner();

	UpdateableCollisionCallback* GetCallback(std::string& type);
	void ClearCallback()
	{
		lastType = "Empty";
		lastCallback = nullptr;
	}

private:
	UpdateableCollisionCallback* lastCallback;
	std::string lastType;
};

