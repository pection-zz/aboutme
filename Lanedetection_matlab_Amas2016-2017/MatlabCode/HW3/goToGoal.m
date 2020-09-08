function u = goToGoal(t,x,p_g)
%{
Author:
Date:
Description:
%}

%% Modify this part
yg =1;
xg = -1;
E=0.01;
v0=1;
kp =10;

equa=(((xg-x(1))^2)+(yg-x(2))^2);
v = v0*(sqrt(equa)>=E);
e = atan2(yg-x(2),xg-x(1))-x(3);
w = kp*atan2(sin(e),cos(e));
u = [v;w];
end