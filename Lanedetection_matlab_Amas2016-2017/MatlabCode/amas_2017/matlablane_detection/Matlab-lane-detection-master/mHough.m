function [P, T, H] = mHough(BW)
[Ro, Co] = size(BW);
rhoLimit = ceil(sqrt(Ro*Ro + Co*Co));
P = (-rhoLimit:1:rhoLimit);
T = (45:1:135);

numTheta = numel(T);
numRho = numel(P);
H = zeros(numRho, numTheta);

for i = 1:Ro
    for j = 1:Co
        if BW(i,j) == 1
            for tIndex = 1:numTheta
                theta = T(tIndex);
                rho = i*cosd(theta) + j*sind(theta);
                rhoIndex = round(rho + numRho/2);
                H(rhoIndex, tIndex) = H(rhoIndex, tIndex) + 1;
            end
        end
    end
end