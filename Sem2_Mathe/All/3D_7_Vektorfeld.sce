//7. Vektorfeld

x = -2:0.5:2;
y = -2:0.5:2;

[X, Y] = meshgrid(x, y);

Vx = -Y;
Vy = X;
champ(x, y, Vx' ,Vy');
