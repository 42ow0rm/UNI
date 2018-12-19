#pragma once

class ObjectCounter {
	const int id;
	static unsigned int maxId;
	static unsigned int number;
public:
	ObjectCounter();
	~ObjectCounter();
	int getId() const;
	static int getMaxId();
	static int getNumber();
};
