q = [0;0;0;0;0;0];
DH_table = [0 335 75 (-pi/2);(-pi/2) 0 365 0;0 0 90 (pi/2);0 -405 0 (-pi/2);0 0 0 (pi/2);0 -80 0 pi];
type = [1;1;1;1;1;1];
forwardKinematics(q,DH_table,type);
