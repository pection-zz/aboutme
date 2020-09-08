% Author : Naphat Nithisopha 58340500060
%        : Nattipong Yaidi   58340500061
%Date :7/02/2018
%Desciption :  fuction for find series of homogeneous transformation
%,homogeneous transformation matrix,homogeneous rotation matrix of the
%end-effecto,position vector of the end-effector with respect
function [H, H_e, R_e, p_e] = forwardKinematics(q,DH_table,type)

% H := [4 x 4 x n] matrix
% H_e := [4 x 4] matrix
% R_e := [3 x 3] rotation matrix (not homogeneous matrix)
% p_e := column vector [3 x 1]


% q := [n x 1] column vector. can be either numeric or symbolic
% type := [n x 1] column vector. can only be numeric [0 or 1]
% DH_table := [n x 4] matrix. can be either numeric or symbolic

n = size(DH_table,1);

for i = 1:n 
    if type(i) == 1 
        DH_table(i,1) = DH_table(i,1) + q(i);
   
    elseif type(i) == 0 
        DH_table(i,2) = DH_table(i,2) + q(i);
    else
        error('Invalid type')
    end
end
if ~strcmp(class(q),'sym')
    H = zeros(4,4,n);
else
    H = sym(zeros(4,4,n));
end

Hi = [];
H = [];
H_e = eye(4);
for i = 1:n
    Hi = cat(3, Hi, DHTrans(DH_table(i,:)));
end

for i = 1:n
    H_e = H_e*Hi(:,:,i);
    H = cat(3, H, H_e);
end

R_e = H_e(1:3,1:3);
p_e = H_e(1:3,4);

%% visualization 
%
%if ~strcmp(class(q),'sym')
%         plotFrame(eye(4,4),1)
%         for i = 1:n
%             plotFrame(H(:,:,i),100)
%         end
%else
%    H = simplify(H);
%    H_e = simplify(H_e);
%    R_e = simplify(R_e);
%    p_e = simplify(p_e);
%end
end