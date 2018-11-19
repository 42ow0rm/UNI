function [V] = Aufgabe_7(r, L, h)

    V = r^2 * L (acos(r-h/r) - (r-h)sqrt(2*r*h-h^2)/r^2)

endfunction
