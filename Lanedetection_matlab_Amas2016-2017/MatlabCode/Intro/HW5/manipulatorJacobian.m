% Author : Naphat Nithisopha 58340500060
%        : Nattipong Yaidi   58340500061
%Date :21/02/2018
function [J,Jv,Jw] = manipulatorJacobian(q,type,DH_table)
[H,H_e,R_e,p_e] = forwardKinematics(q,type, DH_table);

z_im1 = [0;0;1];
o_im1 = [0;0;0];
o_n = p_e ;

for i = 1 : n
    J_v_i = cross(type(i)*z_im1 , (o_n-o_im1)) + (1 - type(i))*z_im1;
    J_w_i = type(i)*z_im1;
    J(:,i) = [J_v_i ; J_w_i];
    
    z_im1 = H(1:3,3,i);
    o_im1 = H(1:3,4,i);
    
end
Jv = J(1:3,1:3);
Jw = J(4:6,1:3);
end
