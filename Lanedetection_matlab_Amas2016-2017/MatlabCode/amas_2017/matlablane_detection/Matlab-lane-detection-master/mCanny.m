function edgeImage = mCanny(I)
[Ro, Co] = size(I);
I = double(I);

% Mask
Gx = [-1 0 1; -2 0 2; -1 0 1];
Gy = [-1 -2 -1; 0 0 0; 1 2 1];

% Convolution
fy = conv2(I, Gy, 'same');
fx = conv2(I, Gx, 'same');

% Gradient Magnitude
Gmag = sqrt(fx.^2 + fy.^2);

% Gphase
Gphase = atan2(fy, fx)*(180.0/pi);
% Convert Gphase to be positive
for iii = 1:Ro
    for jjj = 1:Co
        if Gphase(iii,jjj) < 0
            Gphase = Gphase + 180;
        end
    end
end

% Label Gphase direction by 4 parts
labelAngle = zeros(Ro,Co);
for iii = 1:Ro
    for jjj = 1:Co
        if Gphase(iii,jjj) < 45 % 0-45 --> 1
            labelAngle(iii,jjj) = 1;
        elseif Gphase(iii,jjj) < 90 % 45-90 --> 2
            labelAngle(iii,jjj) = 2;
        elseif Gphase(iii,jjj) < 135 % 90-135 --> 3
            labelAngle(iii,jjj) = 3;
        else %135-180 --> 4
            labelAngle(iii,jjj) = 4;
        end
    end
end
% Set boundary to be 0 so later don't need to worry about boundary
labelAngle(1,:) = 0;
labelAngle(end,:) = 0;
labelAngle(:,1) = 0;
labelAngle(:,end) = 0;

slope = abs(fy./fx);
%figure, imshow(gradient);
edgePoints = nonMaximalSuppression(labelAngle, slope, Gmag, Ro, Co);

% Set low and high threshold
grad = reshape(Gmag, [Ro*Co, 1]);
grad = sort(grad);
% Slide 40 -- Lecture 08 - Edge Detection -- alpha = 10, beta = 0.2
subscri = floor(0.9*Ro*Co);
highT = grad(subscri);
lowT = floor(0.2*highT);

% Set up for Edge Linking
edgePoints = edgePoints*0.5;
% Less than low threshold --> set to 0
xx = find(edgePoints > 0 & Gmag < lowT);
edgePoints(xx) = 0;
% Greater than high threshold --> set to 1
xx = find(edgePoints > 0 & Gmag >= highT);
edgePoints(xx) = 1;
% highT > gradient(pixel) > lowT --> edgePoints(pixel) > 0
edgeImage = edgeLinking(edgePoints, Ro);

%figure, imshow(edgeImage);