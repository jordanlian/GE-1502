%composition of parts

Cr = [0.68, 0.75 , 0, 0, 0];
Ni = [0.2, 0, 0.998, 0, 0];
Mn = [0.02, 0.001, 0.001, 0.001, 0];
C = [0.002, 0.02, 0, 0.001, 0.999];
Fe = [.098, 0.229, 0.001, 0.998, 0.001];

%a, d

a = [Cr; Ni; Mn; C; Fe]; %from equations
d = [0.175, 0.085, 0.005, 0.002, 0.733]'; %from equations
c = inv(a); %[a]^-1

%exercise 1

%solution, multiply by 100 to convert the percentages
j1a = (a\d*100);
j1b = (100* c*d); 

%print results
FID = fopen('matter.txt', 'w'); %create file pointer with permission write
fprintf(FID, 'Exercise 1\nMatrix [A]\n'); %create header
fprintf(FID, '%4.4f\t%4.4f\t%4.4f\t%4.4f\t%4.4f\n', a); %4 decmial places
fprintf(FID, '\nInverse Matrix [A]^-1\n'); %repeat process, and so on...
fprintf(FID, '%4.4f\t%4.4f\t%4.4f\t%4.4f\t%4.4f\n', c);
fprintf(FID, '\nSolution using [A] \\ [d] * 100\n');
fprintf(FID, '%4.4f\t%4.4f\t%4.4f\t%4.4f\t%4.4f\n', j1a);
fprintf(FID, '\nSolution using [A]^-1 * [d] * 100\n');
fprintf(FID, '%4.4f\t%4.4f\t%4.4f\t%4.4f\t%4.4f\n', j1b);

%exercise 2 -- label variables correspondingly

Cr2 = [0.665, 0.74 , 0, 0, 0];
Ni2 = [0.2, 0, 0.998, 0, 0];
Mn2 = [0.02, 0.001, 0.001, 0.001, 0];
C2 = [0.017, 0.03, 0, 0.001, 0.999];
Fe2 = [.098, 0.229, 0.001, 0.998, 0.001];

a2 = [Cr2; Ni2; Mn2; C2; Fe2];
c2 = inv(a2);

%solution
j2a = (a2\d*100);
j2b = (100*c2*d);

fprintf(FID, '\nExercise 2\nMatrix [A]\n');
fprintf(FID, '%4.4f\t%4.4f\t%4.4f\t%4.4f\t%4.4f\n', a2);
fprintf(FID, '\nInverse Matrix [A]^-1\n');
fprintf(FID, '%4.4f\t%4.4f\t%4.4f\t%4.4f\t%4.4f\n', c2);
fprintf(FID, '\nSolution using [A] \\ [d] * 100\n');
fprintf(FID, '%4.4f\t%4.4f\t%4.4f\t%4.4f\t%4.4f\n', j2a);
fprintf(FID, '\nSolution using [A]^-1 * [d] * 100\n');
fprintf(FID, '%4.4f\t%4.4f\t%4.4f\t%4.4f\t%4.4f\n', j2b);

%exercise 3

Cr3 = [0.681, 0.745 , 0, 0, 0];
Ni3 = [0.2, 0, 0.998, 0, 0];
Mn3 = [0.02, 0.001, 0.001, 0.001, 0];
C3 = [0.001, 0.025, 0, 0.001, 0.999];
Fe3 = [.098, 0.229, 0.001, 0.998, 0.001];

a3 = [Cr3; Ni3; Mn3; C3; Fe3];
c3 = inv(a3);

j3a = (a3\d*100);
j3b = (100*c3*d);

fprintf(FID, '\nExercise 3\nMatrix [A]\n');
fprintf(FID, '%4.4f\t%4.4f\t%4.4f\t%4.4f\t%4.4f\n', a3);
fprintf(FID, '\nInverse Matrix [A]^-1\n');
fprintf(FID, '%4.4f\t%4.4f\t%4.4f\t%4.4f\t%4.4f\n', c3);
fprintf(FID, '\nSolution using [A] \\ [d] * 100\n');
fprintf(FID, '%4.4f\t%4.4f\t%4.4f\t%4.4f\t%4.4f\n', j3a);
fprintf(FID, '\nSolution using [A]^-1 * [d] * 100\n');
fprintf(FID, '%4.4f\t%4.4f\t%4.4f\t%4.4f\t%4.4f\n', j3b);

%results and my conclusion
fprintf(FID, '\nBased on the results from Vendor A and Vendor B (Exercise 2 and 3 respectively, I would purchase from Vendor B.');
fprintf(FID, '\nThis is because Vendor Bs alloy scraps and ferrochrome composition create a solution that requires a negative amount');
fprintf(FID, '\nof iron. This implies that the total amount of other material excluding iron would exceed 100 kg, the desired amount.');
