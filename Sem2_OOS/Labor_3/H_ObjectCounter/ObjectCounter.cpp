#include <iostream>
#include "ObjectCounter.hpp"
using namespace std;

int ObjectCounter::count = 0;

ObjectCounter::ObjectCounter(){
	count++;
}

ObjectCounter::ObjectCounter(const ObjectCounter& oc){
	count++;
}

ObjectCounter::~ObjectCounter(){
	count--;
}
		
int ObjectCounter::getCount(){
	return count;
}
		
