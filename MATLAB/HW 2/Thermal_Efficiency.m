%tension vs distance
L = 10; %10 mm
t = 0.1; %0.1 mm
Lc = L + (2*t); %constant function
i = 1; %counter loop initializing variable

for n=0.1 : 0.1 : 1 %for loop for incrementation
    nfin(i) = tanh(n*Lc) / (n*Lc) ; %function
    m(i)=n; %make m a vector
    i = i+1;
end

%results
FID = fopen('fin_efficiency.txt', 'w'); %file pointer, permission write
fprintf(FID, 'thickness domain\n'); %header
fprintf(FID, '%4.4f\t', m); %values, and repeat process
fprintf(FID, '\n\nefficiency values\n');
fprintf(FID, '%4.4f\t', nfin);

%plot
plot(m, nfin, '*'); %plot function with points only
xlabel('fin parameter (mm)');
ylabel('fin efficiency');
title('fin efficiency vs fin parameter');
