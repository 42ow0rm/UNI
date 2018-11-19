clf();
//Aufgabe 1
z = 2 - %i;
r = abs(z); //Betrag

re = real(z);
im = imag(z);
alpha = atan(im, re); //Winkel

//Aufgabe 2
exponent = 2 * %pi * %i * [0:5] / 6;
z = %e^(exponent);
re = real(z);
im = imag(z);
r = abs(z);

//phi = atan(im, re);
//polarplot(phi, r, -1);

subplot(3, 2, 1);
title('Aufgabe 2');
plot(re, im, '*o');
xgrid;
mtlb_axis([-2 2 -2 2]);

//Aufgabe 3
z = 1 + %i;
z_2 = [z z^2 z^3 z^4];

re = real(z_2);
im = imag(z_2);
r = abs(z_2);
subplot(3, 2, 2);
title('Aufgabe 3');
plot(re, im, '*y');
xgrid;
mtlb_axis([-5 5 -5 5]);


//Aufgabe 4
omega  = 0:0.1:100;
H = omega ./ ( 1 + omega^2 * %i);
subplot(3, 2, 3);
title('Nyquist-Diagramm');
plot(real(H), imag(H), '*g');   //Nyquist-Diagramm


subplot(3, 2, 4);
plot(omega, abs(H), '-r');
title('Ampltitudengang');
subplot(3, 2, 6);
title('Phasengang');
plot(omega, atan(imag(H), real(H)), '-b');
