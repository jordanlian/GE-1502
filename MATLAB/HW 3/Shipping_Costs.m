a = 'y'; %counter loop initializer

while(a == 'y') %counter loop where service occurs
    service = input('Please enter the type of service (G for ground, E for express, or O for overnight --> ', 's');
    weight = input('Please enter the weight of the package as [lb oz] --> ');
    converted_weight = (weight(1)*16) + weight(2); %oz
    
    FID = fopen('shipping.txt', 'w'); %create file pointer with permission write
    fprintf(FID, 'This is the weight of the package as [lb oz] -->');
    fprintf(FID, '%4.0f', weight);
    fprintf(FID, '\nThis equates to');
    fprintf(FID, '%4.0f', converted_weight);
    fprintf(FID, 'oz');
    
    if(service == 'G') %ground service
        fprintf(FID, '\nYou have chosen ground service\n');
        if(converted_weight < 8) %price calculationsq
            cost = 0.7 + (0.06*converted_weight);
        elseif ((converted_weight >= 8) && (converted_weight <= 80))
            cost = 1.18 + (0.25*converted_weight);
        else 
            cost = 4.96 + (0.45*converted_weight);
        end  
    elseif(service == 'E') %express service
        fprintf(FID, '\nYou have chosen express service\n');
        if(converted_weight < 8)
            cost = 2.40 + (0.25*converted_weight);
        elseif ((converted_weight >= 8) && (converted_weight <= 80))
            cost = 4.40 + (0.50*converted_weight);
        else 
            cost = 15.20 + (0.65*converted_weight);
        end 
    elseif(service == 'O') %overnight service 
        fprintf(FID, '\nYou have chosen overnight 1 day service\n');
        if(converted_weight < 8)
            cost = 12.20 + (0.80*converted_weight);
        elseif ((converted_weight >= 8) && (converted_weight <= 80))
            cost = 18.60 + (0.75*converted_weight);
        else 
            cost = 61.80 + (0.85*converted_weight);
        end 
    end 

    fprintf(FID, 'Your cost is $'); %print cost
    fprintf(FID, '%4.2f\n', cost);
    
    a = input('Please enter y to run another case or q to quit --> ' ,'s'); %counter loop
end 

fprintf(FID, 'Thank you for shipping with UPS'); 
