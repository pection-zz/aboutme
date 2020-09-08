% Author : Naphat Nithisopha 58340500060
%        : Nattipong Yaidi   58340500061
%Date :14/02/2018
%Desciption :plot angle
h4 =0.8;
l1 =0.5;
l2 = 1;
l3 = 1;
l4 =0.5;

for q1 =-pi:0.25:pi
    for q2 = -pi/2:0.25:pi/2
        for q3 = -3*pi/4:0.25:3*pi/4
            x = l1+l3*cos(q1+q2)+l2*cos(q1);
            y =l3*sin(q1+q2)+12*sin(q1);
            z=h1-h4*14-q3;
            plot3(x,y,z,'ro')
            hold on
        end
    end
end