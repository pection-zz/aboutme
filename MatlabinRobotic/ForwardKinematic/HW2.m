% Author : Naphat Nithisopha 58340500060
%        : Nattipong Yaidi   58340500061
%Date :30/01/2018
%Desciption :  homogeneous transformation matrix that represents
%transformation from the end-effector’s frame to the workspace’s frame

function [R,p,state] = HW2(matrix);
    q1 = matrix(1);
    q2 = matrix(2);

    H_1 =   trans(1.5,'x')*trans(1.25,'y')*trans(0.25,'z')
    H_2 =   rot(q1,'z')*trans(1,'x')
    H_3 =   rot(q2,'z')*trans(1.25,'x');
    
    H_new = H_1*H_2*H_3
    R =  H_new(1:3,1:3)
    p =  H_new(1:3,4)
    if 0<= p(1,1) && p(1,1) <=3 &&0<=p(2,1)&& p(2,1)<=2.5
        state = 'Yes'
    else 
        state = 'No'
    end
    
end