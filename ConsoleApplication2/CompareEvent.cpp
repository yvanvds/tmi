#include "stdafx.h"
#include "CompareEvent.h"
#include "Event.h"


bool CompareEvent::operator()(Event e1, Event e2)
{
	if (e1.getX() > e2.getX()) return true;
	return false;
}