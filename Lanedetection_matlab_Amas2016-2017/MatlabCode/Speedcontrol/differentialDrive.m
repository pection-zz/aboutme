function dx = differentialDrive(t,x,u)
%{
Author:
Date:
Description:
%}

%% Modify this part
y_g=1;
x_g=-1;
v0=1;
E=0.01;
kp=10;
equa=(((x_g-x(1))^2)+ (y_g-x(2))^2);
v =v0*(sqrt(equa)>=E);
e=atan2(y_g-x(2),x_g-x(1))-x(3);
w=kp*atan2(sin(e),cos(e));
dx = [v*cos(x(3));v*sin(x(3));w];
    
end