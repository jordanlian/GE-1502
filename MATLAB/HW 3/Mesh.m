%3-D mesh-plot

[x,y] = meshgrid(-5 : 0.01 : 5); %original domain/range
R = sqrt(x.^2 + y.^2); %function
z= -cos(2.*R) ./ exp(0.2.*R); %function of a function
mesh(x,y,z); %mesh it all