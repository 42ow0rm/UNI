function zeichne(x, y, m, b)
    
    clf;
    plot(x, y, 'r*');
    xx = [min(x)-1, max(x)+1];
    yy = m*xx + b;
    plot(xx, yy, '-b');
endfunction
