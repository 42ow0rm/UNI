function [m,b] = gerade(x, y)

    m = (y(2)-y(1))/(x(2)-x(1));
    b = y(1) - m*x(1);

endfunction
