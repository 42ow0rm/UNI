//Aufgabe 2

u = linspace(0, 2*%pi, 40);
v = linspace(0, 2*%pi, 40);

[U, V] = meshgrid(u, v);

X = (2 + cos(U)).*cos(V);
Y = (2 + cos(U)).*sin(V);
Z = sin(U);

surf(X, Y, Z);

f = gcf();
f.color_map = coppercolormap(32)

//Achsenbeschriftung
xlabel('x-Achse', 'fontsize', 5)
ylabel('y-Achse', 'fontsize', 5)
zlabel('z-Achse', 'fontsize', 5)
