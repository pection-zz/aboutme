% Author : Naphat Nithisopha 58340500060
%        : Nattipong Yaidi   58340500061
%Date :30/01/2018
%Desciption :   fuction for find Homogenous transformation

function Homo = trans(position,axis_tran);
    if(axis_tran == 'x')
        Homo  = [1 0 0 position;0 1 0 0;0 0 1 0;0 0 0 1]
    elseif(axis_tran == 'y')
        Homo  = [1 0 0 0;0 1 0 position;0 0 1 0;0 0 0 1]
    elseif(axis_tran == 'z')
        Homo  = [1 0 0 0;0 1 0 0;0 0 1 position;0 0 0 1]
    end
    
end
    

    
    