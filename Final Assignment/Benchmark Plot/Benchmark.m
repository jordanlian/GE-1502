fid = fopen('benchmark_plot_60-40.txt', 'r');

formatSpec = '%f';
s = [2 Inf];

array = fscanf(fid, formatSpec, s);
length = max(size(array));

for i = 1 : length
    time1(i) = array(1, i);
    temp1(i) = array(2, i);
end 

plot(time1, temp1);
xlabel('time (s)');
ylabel('temperature (C)');
title('Benchmark Plot');
hold on

fid = fopen('benchmark_plot_50-50.txt', 'r');

formatSpec = '%f';
s = [2 Inf];

array = fscanf(fid, formatSpec, s);
length = max(size(array));

for i = 1 : length
    time2(i) = array(1, i);
    temp2(i) = array(2, i);
end 

plot(time2, temp2);
hold off
