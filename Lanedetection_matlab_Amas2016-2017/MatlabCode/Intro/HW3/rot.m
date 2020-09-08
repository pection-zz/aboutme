% Author : Naphat Nithisopha 58340500060
%        : Nattipong Yaidi   58340500061
%Date :30/01/2018
%Desciption :  fuction for find Homogenous rot

function Homo =rot(angle_rot,axis_rot);
    if(axis_rot == 'x')
        Homo  = [1 0 0 0;0 cos(angle_rot) -sin(angle_rot) 0;0 sin(angle_rot) cos(angle_rot) 0; 0 0 0 1]
    elseif(axis_rot == 'y')
        Homo  = [cos(angle_rot) 0 sin(angle_rot) 0;0 1 0 0;-sin(angle_rot) 0 cos(angle_rot) 0; 0 0 0 1]
    elseif(axis_rot == 'z')
        Homo  = [cos(angle_rot) -sin(angle_rot) 0 0;sin(angle_rot) cos(angle_rot) 0 0;0 0 1 0; 0 0 0 1]
end
    

    
    