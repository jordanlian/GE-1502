Prod14 = [120000 235000 65000 82500];
Prod15 = [134000 262000 52800 78200];
Prod16 = [128600 245000 67300 80500];
Prod17 = [131600 253900 61550 83400];

disp('The product vectors from 2014, 2015, 2016, and 2017 are');
disp(Prod14);
disp(Prod15);
disp(Prod16);
disp(Prod17);

Total_Product = Prod14 + Prod15 + Prod16 + Prod17;

disp('The sum of these vectors is');
disp(Total_Product);

Average_Product =  Total_Product([1:4]) / 4;

disp('The average product is');
disp(Average_Product);

Total_Production = [sum(Prod14); sum(Prod15); sum(Prod16); sum(Prod17)];

disp('The total production from each year is');
disp(Total_Production);

Total_Profit = sum(Total_Production) / 5;

disp('The total profit is');
disp(Total_Profit);
