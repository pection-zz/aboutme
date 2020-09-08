function dz = adaptiveLaw(t,x,z,x_d)
%{
Author:
Date:
Description:
%}

K_a = 50;

%% Modify this part
dz = -K_a*x(1)^2*(x_d(t)-x(1));
    
end