function ang = sumAngle(sigma,omega,z,p)
ang = 0;   
for i = 1:numel(z)
    ang = ang + atan2(omega-imag(z(i)),sigma-real(z(i)));
end
for j = 1:numel(p)
    ang = ang - atan2(omega-imag(p(j)),sigma-real(p(j)));
end
end
%Natthiphong Yaidi 58340500061 secB