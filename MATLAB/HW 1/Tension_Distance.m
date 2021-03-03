%tension vs distance

x = [10, 30, 50, 70, 90, 110]; %domain (array)
T = [0, 0, 0, 0, 0, 0]; %initialize
i = 1; %counter loop

while i < 7 %calculate desired values
    T(i) = ((500*110) * sqrt(2500 + (x(i)*x(i)))) / (50*x(i)); %function 
    i = i+1;
end

disp('The tension values in pounds are');
disp(T); %display output values

plot(x,T); %plot function
xlabel('distance (in)');
ylabel('tension (lb)');
title('tension vs distance');
