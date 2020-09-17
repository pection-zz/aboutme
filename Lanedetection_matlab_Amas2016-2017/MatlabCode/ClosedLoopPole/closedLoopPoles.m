function [sigma,omega] = closedLoopPoles(z,p,spec,value,guess)

if strcmp(spec,'OS') % percent overshoot
    OS = value;
    zeta = -log(OS)/sqrt(pi^2+log(OS)^2);
    fun = @(w_n)cos(sumAngle(-zeta*w_n,w_n*sqrt(1-zeta^2),z,p))+1;
    options = optimoptions('fsolve');
    options.FunctionTolerance = 1e-12;
    options.OptimalityTolerance = 1e-12;
    w_n = fsolve(fun,guess,options);
    sigma = -zeta*w_n;
    omega = w_n*sqrt(1-zeta^2);
    
elseif strcmp(spec,'Ts')% settling time
    Ts = value;

    fun = @(omega)cos(sumAngle(-4/Ts,omega,z,p))+1;
    options = optimoptions('fsolve');
    options.FunctionTolerance = 1e-12;
    options.OptimalityTolerance = 1e-12;
    omega = fsolve(fun,guess,options);
    sigma = -4/Ts;
   
    
   
elseif strcmp(spec,'Tp') % peak time
    Tp = value;

    fun = @(w)cos(sumAngle(w,pi/Tp,z,p))+1;
    options = optimoptions('fsolve');
    options.FunctionTolerance = 1e-12;
    options.OptimalityTolerance = 1e-12;
    w = fsolve(fun,guess,options);
    sigma = fsolve(fun,guess,options);
    omega = pi/Tp;
    
else
    error('undefined specification')
end



end
%Natthiphong Yaidi 58340500061 secB