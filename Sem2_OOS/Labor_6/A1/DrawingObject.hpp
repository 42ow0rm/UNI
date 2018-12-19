#pragma once
#include "ObjectCounter.hpp"

extern bool debugConstructor;

class DrawingObject: public ObjectCounter
{
	public:
		DrawingObject();
		~DrawingObject();
		virtual void print(bool=false) const = 0;
        void check() const;
    class GraphException{
        const int id;
        public:
            GraphException(int id);
            int getId() const;
    };

    class IdTooHigh : public GraphException {
        public:
            IdTooHigh(int id);
    };
};
