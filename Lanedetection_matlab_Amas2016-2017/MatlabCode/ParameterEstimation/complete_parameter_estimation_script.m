%1.)  Load logged data & create Data for System Identification
data = csvread('logged_data');
t = data(:,1);
u = data(:,2);
y = data(:,3);

dt = t(2)-t(1); % sampling time

z = iddata(y, u, dt, 'Name', 'DC-motor');

%3.) generate a model for optimization
FileName      = 'DCMotor';       % File describing the model structure.
n_y = 1;
n_u = 1;
n_x = 2;
n_p = 2;
Order         = [n_y n_u n_x];     % Model orders [ny nu nx].
Parameters    = [10; 10];         % Initial parameters. Np = 3.
InitialStates = [0; 0];            % Initial initial states.

nlgr = idnlgrey(FileName, Order, Parameters, InitialStates, 0, ...
                'Name', 'DCMotor');

setpar(nlgr,'Minimum',[0;0])

opt = nlgreyestOptions('Display','on');
opt.SearchOption.MaxIter = 100;

%4.) Run parameter estimation
tic;
nlgr = nlgreyest(z, nlgr, opt);
toc


%5.) verify with the model
param = zeros(2,1);
param(1)= nlgr.Parameter(1).Value;
param(2)= nlgr.Parameter(2).Value;

sim('DC_motor_verified');
t_v = y_verified.Time;
y_v = y_verified.Data;
figure

hold on;
plot(t_v,y_v)
plot(t,y,'*')
grid on ;
xlabel('t')
ylabel('y_1')

display(param);