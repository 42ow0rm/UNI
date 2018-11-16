

class ObjectCounter {
	// Private section
	public:
		// Public Declarations
		ObjectCounter();
		ObjectCounter(const ObjectCounter& oc);
		~ObjectCounter();
		
		int getCount();
		
	protected:
		// Protected Declarations
		static int count;
};


