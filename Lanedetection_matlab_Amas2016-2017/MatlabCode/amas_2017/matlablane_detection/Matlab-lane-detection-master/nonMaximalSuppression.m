function edgePoints = nonMaximalSuppression(labelAngle, slope, Gmag, Ro, Co)
edgePoints = zeros(Ro,Co);

% Gradient direction 0-45
indx = find(labelAngle == 1); % Index as 1 dimension for 0-45
slop = slope(indx);
% (1,1) and (1,0)
d1 = slop.*(Gmag(indx)-Gmag(indx+Ro+1)) + (1-slop).*(Gmag(indx)-Gmag(indx+1));
% (-1,-1) and (-1,0)
d2 = slop.*(Gmag(indx)-Gmag(indx-Ro-1)) + (1-slop).*(Gmag(indx)-Gmag(indx-1));
pickIndx = indx(d1>=0 & d2>=0);
edgePoints(pickIndx) = 1;

% Gradient direction 45-90
indx = find(labelAngle == 2); % Index as 1 dimension for 45-90
slop = 1./slope(indx); % Need inverse slope for this case and 90-135
% (1,1) and (0,1)
d1 = slop.*(Gmag(indx)-Gmag(indx+Ro+1)) + (1-slop).*(Gmag(indx)-Gmag(indx+Ro));
% (-1,-1) and (0,-1)
d2 = slop.*(Gmag(indx)-Gmag(indx-Ro-1)) + (1-slop).*(Gmag(indx)-Gmag(indx-Ro));
pickIndx = indx(d1>=0 & d2>=0);
edgePoints(pickIndx) = 1;

% Gradient direction 90-135
indx = find(labelAngle == 3); % Index as 1 dimension for 90-135
slop = 1./slope(indx); % Inverse slope
% (-1,1) and (0,1)
d1 = slop.*(Gmag(indx)-Gmag(indx+Ro-1)) + (1-slop).*(Gmag(indx)-Gmag(indx+Ro));
% (1,-1) and (0,-1)
d2 = slop.*(Gmag(indx)-Gmag(indx-Ro+1)) + (1-slop).*(Gmag(indx)-Gmag(indx-Ro));
pickIndx = indx(d1>=0 & d2>=0);
edgePoints(pickIndx) = 1;

% Gradient direction 135-180
indx = find(labelAngle == 4); % Index as 1 dimesion for 135-180
slop = slope(indx);
% (-1,1) and (-1,0)
d1 = slop.*(Gmag(indx)-Gmag(indx+Ro-1)) + (1-slop).*(Gmag(indx)-Gmag(indx-1));
% (1,-1) and (1,0)
d2 = slop.*(Gmag(indx)-Gmag(indx-Ro+1)) + (1-slop).*(Gmag(indx)-Gmag(indx+1));
pickIndx = indx(d1>=0 & d2>=0);
edgePoints(pickIndx) = 1;

%figure, imshow(edgePoints);