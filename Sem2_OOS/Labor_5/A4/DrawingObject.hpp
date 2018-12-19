#pragma once
#include "ObjectCounter.hpp"

extern bool debugConstructor;

class DrawingObject: public ObjectCounter
{
	public:
		DrawingObject();
		~DrawingObject();
		virtual void print(bool=false) const = 0;
};
