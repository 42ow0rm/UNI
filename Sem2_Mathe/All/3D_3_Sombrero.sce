//3. Schaubild Sombrero mit farbe

xy = linspace(-%pi, %pi, 40);

[X, Y] = meshgrid(xy)

F = sin(X.^2 + Y.^2)./(X.^2 + Y.^2);
mesh(X, Y, F)

//Achsenbeschriftung
a = gca();          //
a.font_size = 2;    //Schriftgröße für x,y,z scala

//Achsenbeschriftung
xlabel('x-Achse', 'fontsize', 5)
ylabel('y-Achse', 'fontsize', 5)
zlabel('z-Achse', 'fontsize', 5)
