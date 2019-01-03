//Aufgabe 1

x = -3:3;
y = -3:3;

[X, Y] = meshgrid(x, y)

X_2 = X.* (-4)

//F = exp(-(X.^2 + Y.^2));
F = X_2.* exp(-(X.^2 + Y.^2));
//F = X.* (-4) * exp(-(X.^2 + Y.^2));
mesh(X, Y, F);


//Achsenbeschriftung
a = gca();          //
a.font_size = 2;    //Schriftgröße für x,y,z scala

xlabel('x-Achse', 'fontsize', 5)
ylabel('y-Achse', 'fontsize', 5)
zlabel('z-Achse', 'fontsize', 5)
