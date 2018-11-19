//Aufgabe 1
//Ein Skript wird einmal ausgeführt, Fkten werden eingebunden und mehrfach verwendet


//Aufgabe 2
//Umgebung =  Global Scope
//Lokal = local Scope


//Aufgabe 3
//um eine Datei auszuführen (.sce) oder eine Funktion einzubinden (.sci). 

//Aufgabe 4
A = [1 4 2; 5 3 6; 4 5 6];
B = [1 4 0; 2 5 0 ; 3 6 0];
if (abs(A - B) ~= 1)
    a = 1
    //YO
end

//Aufgabe 5
//exec('C:\Users\W1nd0ws\Desktop\Mathe Labor\Labor_3\Aufgabe_5.sci', -1)
exec Aufgabe_5.sci

x1 = 1;
y1 = 1;
x2 = -1;
y2 = 1;
x3 = 0;
y3 = 0;

Z = Aufgabe_5(x1, y1, x2, y2, x3, y3)


//Aufgabe 6
exec Aufgabe_6.sci

x1 = 1;
y1 = 1;
x2 = -1;
y2 = 1;
x3 = 0;
y3 = 0;

Z = Aufgabe_6(x1, y1, x2, y2, x3, y3)


//Aufgabe 7
exec Aufgabe_7.sci

x1 = 1;
y1 = 1;
x2 = -1;
y2 = 1;
x3 = 0;
y3 = 0;

Z = Aufgabe_5(x1, y1, x2, y2, x3, y3)
