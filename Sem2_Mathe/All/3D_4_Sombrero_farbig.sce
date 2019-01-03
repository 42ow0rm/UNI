//3. Schaubild Sombrero mit farbe

xy = linspace(-%pi, %pi, 40);

[X, Y] = meshgrid(xy)

F = sin(X.^2 + Y.^2)./(X.^2 + Y.^2);
surf(X, Y, F);

f = gcf();
f.color_map = coolcolormap(32);

//Achsenbeschriftung
xlabel('x-Achse', 'fontsize', 5)
ylabel('y-Achse', 'fontsize', 5)
zlabel('z-Achse', 'fontsize', 5)
