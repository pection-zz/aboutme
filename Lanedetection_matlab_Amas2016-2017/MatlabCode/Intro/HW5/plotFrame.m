function plotFrame(H,len)
% H is a homogenous transformation matrix
% len is the length of each vector to be drawn (doesn't have to be 1)
R = H(1:3,1:3);
p = H(1:3,4);
hold on;
o_i = p;
x_i = [zeros(3,1) len*R(:,1)] + [o_i o_i];
y_i = [zeros(3,1) len*R(:,2)] + [o_i o_i];
z_i = [zeros(3,1) len*R(:,3)] + [o_i o_i];


plot3(x_i(1,:),x_i(2,:),x_i(3,:),'r','lineWidth',2);
plot3(y_i(1,:),y_i(2,:),y_i(3,:),'g','lineWidth',2);
plot3(z_i(1,:),z_i(2,:),z_i(3,:),'b','lineWidth',2);

axis equal
end