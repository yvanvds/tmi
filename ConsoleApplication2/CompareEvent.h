#pragma once
#include "Event.h"
class CompareEvent
{
public:
	bool operator()(Event e1, Event e2);
};

