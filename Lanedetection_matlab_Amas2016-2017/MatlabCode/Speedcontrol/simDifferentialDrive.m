%{
Author:
Date:
Description:
%}
    
t_max = 10;                             % maximum simulation time
x_0 = [0;0;0];                          % initial states
p_g = [-1;1];                           % desired location

%% Modify this part

f = @(t,x,u)differentialDrive(t,x,u);                        % state equation
u = @(t,x,p_g)goToGoal(t,x,p_g);                      % control law

[t,x] = ode45(@(t,x)f(t,x,u(t,x,p_g)),[0 t_max],x_0);                     % simulating using ode45

% end here
%% Animation (DO NOT modify this part)

step = 2;
hold on;
for i = 1:step:numel(t)-step
    h = plot(x(i,1),x(i,2),'ro','linewidth',5);
    h1 = plot([x(i,1) x(i,1)+0.5*cos(x(i,3))],[x(i,2) x(i,2)+0.5*sin(x(i,3))],'k');
    plot([x(i,1) x(i+step,1)],[x(i,2) x(i+step,2)],'b--');
    
    axis equal
    axis([-2 2 -2 2])
    grid on;
    pause(t(i+step)-t(i));
    
    if i<=numel(t)-step
    delete(h);
    delete(h1);
    end
    
end