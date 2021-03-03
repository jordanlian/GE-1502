%voltage vs time after closing the switch in the circuit

t = 8; %time 
V = 36 * (1 - exp((0-t)*(10^6)/(2500*1600)));  %voltage function

disp('The voltage (volts) 8 seconds after the switch is closed is');
disp(V); %voltage at time t=8
i = V / 2500; % v = i*r, i = v / r

disp('The corresponding current in amps (2500 ohm resistance) is');
disp(i);
