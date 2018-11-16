#include "MyString.hpp"

class Fahrzeug {
	// Private section
	public:
		// Public Declarations
		Fahrzeug();
		Fahrzeug(const Fahrzeug& f);
		Fahrzeug(MyString& kenz);
		Fahrzeug(char *str);
		~Fahrzeug();
		
		int getCount();
		void setKenz(MyString &kenz);
		const char* getKenz();
		void fahren(double d);
		double getKm();
		void setVIN();
		unsigned int getVIN();
		
	protected:
		// Protected Declarations
		static int count;
		MyString kz;
		unsigned int vin;
		double km;
		
		
};


ostream & operator << (ostream & out, Fahrzeug & f);


