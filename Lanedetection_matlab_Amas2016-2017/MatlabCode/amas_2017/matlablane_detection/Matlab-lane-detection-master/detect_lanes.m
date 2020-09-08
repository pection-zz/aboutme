function [rho1, theta1, rho2, theta2] = detect_lanes (img)

img = rgb2gray(img);
[Ro, Co] = size(img);

% Divide image by 9 regions --> Take the middle one
interestRo = round(Ro/3);
interestCo = round(Co/3);
BW = imcrop(img,[interestCo interestRo interestCo interestRo]);
BW = mCanny(BW); % Canny

[rho, theta, H] = mHough(BW); % Hough

% For lines that haave positive slope (in normal x,y axis)
HLeft = zeros(size(H));
HLeft(:, 1:45) = H(:, 1:45);

% For lines that have negative slope (in normal x,y axis)
HRight = zeros(size(H));
HRight(:, 46:90) = H(:, 46:90);

% Find the right line (negative slope)
[p1, t1] = find(HRight == max(HRight(:)));
theta1 = 90 - theta(t1(1));
P1forCropImg = rho(p1(1));

% Find the left line (positive slope)
[p2, t2] = find(HLeft == max(HLeft(:)));
theta2 = 90 - theta(t2(1));
P2forCropImg = rho(p2(1));

% Convert rho back to original image
realToCropDist = sqrt(interestCo*interestCo + interestRo*interestRo);
angleFromRealToCrop = atand((double(interestRo)/interestCo));
% Right
diff_angle_bween_RealToCrop_vs_theta1 = angleFromRealToCrop - theta1;
rho1 = cosd(diff_angle_bween_RealToCrop_vs_theta1)*realToCropDist + P1forCropImg;
% Left
diff_angle_bween_RealToCrop_vs_theta2 = angleFromRealToCrop - theta2;
rho2 = cosd(diff_angle_bween_RealToCrop_vs_theta2)*realToCropDist + P2forCropImg;

% Convert theta to radian
theta1 = theta1*pi/180;
theta2 = theta2*pi/180;

end