//Aufgabe 1
A = [1 4; 2 5; 3 6];
B = [1 4 0 0; 2 5 0 0; 3 6 0 0];
C = [1 4 1 2 3; 2 5 4 5 6; 3 6 0 0 0];

//Aufgabe 2
D = zeros(5, 10);
j = 1;
k = 1;

for i = 1 : 50
    D(j, k) = i;
    k = k + 1;
    
    if (i == 10)
       j = 2;
       k = 1; 
    end
    if (i == 20)
       j = 3;
       k = 1; 
    end
    if (i == 30)
       j = 4;
       k = 1; 
    end
    if (i == 40)
       j = 5;
       k = 1; 
    end
end
//oder
Z = [1:10; 11:20; 21:30; 31:40; 41:50];

//Aufgabe 3
//lgs:
// 7x + 4y = -1
// 5x + 3y = 2
// A * x = b
// -> x = A\b

E = [7 4; 5 3];
F = [(-1); 2];
G = E\F;



