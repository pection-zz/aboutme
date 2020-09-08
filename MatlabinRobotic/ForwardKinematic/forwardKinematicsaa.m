function [H, H_e, R_e, p_e] = forwardKinematics(q,DH_table,type)

% H := [4 x 4 x n] matrix
% H_e := [4 x 4] matrix
% R_e := [3 x 3] rotation matrix (not homogeneous matrix)
% p_e := column vector [3 x 1]


% q := [n x 1] column vector. can be either numeric or symbolic
% type := [n x 1] column vector. can only be numeric [0 or 1]
% DH_table := [n x 4] matrix. can be either numeric or symbolic

n = size(DH_table,1);

if ~strcmp(class(q),'sym')
    H = zeros(4,4,n);
else
    H = sym(zeros(4,4,n));
end



H_e = H(:,:,end);
R_e = H_e(1:3,1:3);
p_e = H_e(1:3,4);

%% visualization 
if ~strcmp(class(q),'sym')

end