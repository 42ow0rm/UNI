#

class Labyrinth{
	
	// Größe des Labyrinths
	const int kZeilen1;
	const int kSpalten;

	// Zeichen, die im Labyrinth vorkommen können,
	// NL = new line, EOS = end of string
	enum Symbole;

	// Das Labyrinth als char-Array
	// Die vorletzte Spalte speichert ein Zeilenendezeichen \n
	// und die letzte ein \0-Zeichen, damit die Ausgabe leichter wird.
	char labyrinth[kZeilen][kSpalten + 2];

public:
	// Konstruktor	
	Labyrinth();
	
	void initialisieren();
	
	void drucken();
		
};
