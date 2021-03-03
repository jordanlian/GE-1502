%precipitation (inches) in Boston and Seattle

BOS = [2.67 1.00 1.21 3.09 3.43 4.71 3.88 3.08 4.10 2.62 1.01 5.93];
SEA = [6.83 3.63 7.20 2.68 2.05 2.96 1.04 0.00 0.03 6.71 8.28 6.85];

%precipitation for the year
tot_BOS = sum(BOS);
tot_SEA = sum(SEA);

FID = fopen('precipitation.txt', 'w'); %create file pointer with permission write

fprintf(FID, 'total precipitation in Boston during 2017\n');
fprintf(FID, '%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\n', tot_BOS);

fprintf(FID, '\n\ntotal precipitation in Seattle during 2017\n');
fprintf(FID, '%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\n', tot_SEA);

%monthly average precipitation
month_avg_BOS = tot_BOS/12;
month_avg_SEA = tot_SEA/12;

fprintf(FID, '\n\nmonthly average in Boston is\n');
fprintf(FID, '%4.2f\n', month_avg_BOS);

fprintf(FID, '\nmonthly average in Seattle is\n');
fprintf(FID, '%4.2f\n', month_avg_SEA);

b=0; %Boston variable
s=0; %Seattle variable

%check how many months was the precipitation above average
for i=1:12
    BOS(i);
    if (BOS(i) > month_avg_BOS)
        b=b+1;
    end 
end 

fprintf(FID, '\namount of times precipitation was above average in Boston\n');
fprintf(FID, '%4.0f\n', b);

for j=1:12

    if (SEA(j) > month_avg_SEA)
        s=s+1;
    end 
end

fprintf(FID, '\namount of times precipitation was above average in Seattle\n');
fprintf(FID, '%4.0f\n', s);

%how many months, and which months was precipitation in Boston lower than
%Seattle
precip = [0 0 0 0 0 0 0 0 0 0 0 0];
d=0;

fprintf(FID, '\nmonths where the precipitation in Boston was lower than the precipitation in Seattle\n');

for c=1:12
    if (BOS(c) < SEA(c))
       d=d+1;
       precip(c) = c;
       fprintf(FID, '%4.0f\n', c);
    end
end 
        
fprintf(FID, '\namount of times that the precipitation in Boston was lower than the precipitation in Seattle\n');
fprintf(FID, '%4.0f\n', d);  