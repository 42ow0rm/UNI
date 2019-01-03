//6. Schaubild Kugel

u = linspace(0, %pi, 40);
v = linspace(0, 2*%pi, 40);

[U, V] = meshgrid(u, v);

X = sin(U).*cos(V);
Y = sin(U).*sin(V);
Z = cos(U);

surf(X, Y, Z);

f = gcf();
f.color_map = coppercolormap(32)

//Achsenbeschriftung
xlabel('x-Achse', 'fontsize', 5)
ylabel('y-Achse', 'fontsize', 5)
zlabel('z-Achse', 'fontsize', 5)
