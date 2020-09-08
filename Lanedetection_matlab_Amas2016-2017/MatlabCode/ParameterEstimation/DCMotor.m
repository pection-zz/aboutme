function [dx, y] = DCMotor(t,x,u,tau,k,varargin)
%2.) Define a model for estimation

dx = [  x(2);
        (1/tau)*(-x(2)+k*u(1))];
r = 5;
y = 1/r*x(1);

end
