function dx = nonlinearDyn(t,x,u,k)
%{
Author:
Date:   
Description:
%}

%% Modify this part
dx = k*x(1)^2+u(1);
end