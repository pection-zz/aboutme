function u = trajTracking(t,x,z,x_d,dx_d)
%{
Author:
Date:
Description:
%}

K_p = 1;

%% Modify this part
u = (dx_d(t)+K_p*x_d(t)-x(1))-z*x(1)^2;
    
end