//Aufgabe 4
A = [3 3; 3 -5];
B = [4 1; 3 2];
C = [-1 1 1; 1 -1 1; 1 1 1];

[V_a, L_a] = spec(A); //Eigenvektor
lambda_a = spec(A); //Eigenwert

[V_b, L_b] = spec(B);
lambda_b = spec(B);

[V_c, L_c] = spec(C);
lambda_c = spec(C);

//Aufgabe 5
x_k = [0 1 2];
y_k = [-1 0 3];

//Interpolationspolynom
//LGS in Matrixform
X_1 = [x_k .^0 x_k .^1 x_k .^2 ];

//LGS lösen
a = X_1\y_k;

// Ausgleichsgerade
//LSG Matrix
X_2 = [x_k .^0 x_k];

//LGS lösen
b = X_2\y_k
