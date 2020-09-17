%{
Author:
Date:
Description:
%}

t_max = 10;                                 % maximum simulation time
x_0 = 0;                                    % initial state
k_0 = 5;                                    % nominal parameter 'k'
x_d = @(t)cos(pi*t);                        % desired position trajectory
dx_d = @(t)-pi*sin(pi*t);                   % desired velocity trajectory
k = k_0 + 5*(rand-0.5);                     % actual parameter value 

%% Modify this part
f = @(t,x,u)nonlinearDyn(t,x,u,k);                            % state equation
u = @(t,x,z)trajTracking(t,x,z,x_d,dx_d);                            % control law
f_z = @(t,x,z)adaptiveLaw(t,x,z,x_d);                          % integration law (adaptive law)
closedLoop = @(t,x,z)[f(t,x,u(t,x,z));f_z(t,x,z)];                   % closed loop dynamics

[t,s] = ode45(@(t,s)closedLoop(t,s(1),s(2)),[0 t_max],[x_0;k_0]);

%% Plot (DO NOT modify this part)

x = s(:,1);
k_est = s(:,2);

subplot(2,1,1)
hold on;
plot(t,x)
plot(t,x_d(t),'k--')
xlabel('t')
ylabel('x,x_d')
grid on;
axis([0 10 -2 2])
subplot(2,1,2)
hold on;
grid on;
plot(t,x_d(t)-x,'b')
xlabel('t')
ylabel('error between trajectory')