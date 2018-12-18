#pragma once
#include "ObjectCounter.hpp"

extern bool debugConstructor;

class DrawingObject: public ObjectCounter
{
	public:
		DrawingObject();
		~DrawingObject();
};
