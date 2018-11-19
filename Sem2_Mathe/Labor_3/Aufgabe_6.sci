function [Z] = Aufgabe_6(x1, y1, x2, y2, x3, y3)

  X = [x1^2 x1 1; x2^2 x2 1; x3^2 x3 1];
  y = [y1; y2; y3];
  
  //LGS lösen
  Z = X\y;  

endfunction
