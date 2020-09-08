function edgeImage = edgeLinking(edgePoints, Ro)
oldX = [];
x = find(edgePoints == 1);
while (size(oldX,1) ~= size(x,1))
    oldX = x;
    relatePixels = [x+Ro+1, x+Ro, x+Ro-1, x-1, x-Ro-1, x-Ro, x-Ro+1, x+1];
    edgePoints(relatePixels) = 0.5 + edgePoints(relatePixels);
    y = find(edgePoints == 0.5);
    edgePoints(y) = 0;
    yy = find(edgePoints >= 1);
    edgePoints(yy) = 1;
    x = find(edgePoints == 1);
end

edgeImage = edgePoints;