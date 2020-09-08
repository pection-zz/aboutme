function detecface(img)
faceDetector = vision.CascadeObjectDetector;
bboxes=step(faceDetector,img);
Ifaces = insertObjectAnnotation(img,'rectangle',bboxes,'Face');
imagesc(Ifaces),title('Detected faces'),drawnow;
end