//1. Gitternetz

//mesh aufstellen
A = [0 2 3 2 2;
     2 4 5 4 2;
     3 5 6 5 3;
     2 4 5 4 2;
     1 2 3 2 0];
//anzeigen
mesh(A)


//Achsenbeschriftung
a = gca();          //
a.font_size = 2;    //Schriftgröße für x,y,z scala

xlabel('x-Achse', 'fontsize', 5)
ylabel('y-Achse', 'fontsize', 5)
zlabel('z-Achse', 'fontsize', 5)

//ab hier bringt nix
ticks = a.x_ticks;
ticks.labels = ['1'; '2'; '3'; '4'; '5']
ticks.location = [1 2 3 4 5]
a.x_ticks = ticks; 
