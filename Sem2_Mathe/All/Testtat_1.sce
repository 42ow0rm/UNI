//Teststat

//Aufgabe 1
exec gerade.sci;
exec zeichne.sci;

s = 0:6
F = [3.53 3.71 3.85 4.27 4.38 4.73 4]

[m, b] = gerade(s, F);
zeichne(s, F, m ,b)
