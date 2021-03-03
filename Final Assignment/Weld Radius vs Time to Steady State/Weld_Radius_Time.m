fid = fopen('weld_radius_time_60-40.txt', 'r');

formatSpec = '%f';
s = [2 Inf];

array = fscanf(fid, formatSpec, s);
length = max(size(array));

for i = 1 : length
    time1(i) = array(1, i);
    radius1(i) = array(2, i);
end 

plot(time1, radius1);
xlabel('Time (s)');
ylabel('Weld Radius (m)');
title('Weld Radius vs Time to Steady State Temperature');
hold on

fid = fopen('weld_radius_time_50-50.txt', 'r');

formatSpec = '%f';
s = [2 Inf];

array = fscanf(fid, formatSpec, s);
length = max(size(array));

for i = 1 : length
    time2(i) = array(1, i);
    radius2(i) = array(2, i);
end 

plot(time2, radius2);
hold off
