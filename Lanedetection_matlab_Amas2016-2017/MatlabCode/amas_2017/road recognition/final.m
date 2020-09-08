function road
% a=imread('vasanth80.jpeg');
arrow1=imread('arrow1.jpg');arrow1=imresize(arrow1,[50 50]);
arrow2=imread('arrow2.jpg');arrow2=imresize(arrow2,[50 50]);
arrow3=imread('arrow3.jpg');arrow3=imresize(arrow3,[50 50]);
arrow4=imread('arrow4.jpg');arrow4=imresize(arrow4,[50 50]);
arrow5=imread('arrow5.jpg');arrow5=imresize(arrow5,[50 50]);
cross=imread('cross.jpg');cross=imresize(cross,[50 50]);
readerobj = mmreader('roadtest.avi');
Frames = read(readerobj);
vidFrames = read(readerobj);
numFrames = get(readerobj, 'numberOfFrames');

r = readerobj.Height;
c = readerobj.Width;

for k = 1 : numFrames-1
   
mov(k).cdata = vidFrames(:,:,:,k);
a=mov(k).cdata;
z=mov(k).cdata;
    for i=1:r
        for j=1:c        
            if(a(i,j,1)>100&&a(i,j,2)>120&&a(i,j,3)>110&&a(i,j,1)<255&&a(i,j,2)<255&&a(i,j,3)<255)
                if(a(i,j,1)>120&&a(i,j,2)>190&&a(i,j,3)>120&&a(i,j,1)<160&&a(i,j,2)<255&&a(i,j,3)<150)
                z(i,j,1)=255;                z(i,j,2)=255;                z(i,j,3)=255;
                else
                z(i,j,1)=0;                z(i,j,2)=0;                z(i,j,3)=0;
                end
                else
                z(i,j,1)=255;                z(i,j,2)=255;                z(i,j,3)=255;
                end
                           
            end
            
            
    end

z=z(:,:,1);

 check=0;
         if(z(r,c/2)==0&&z(r-2,c/2)==0)

         for i=1:1:r-10
             if(z(i,1)&&z(i+1,1)&&z(i+2,1)&&z(i+4,1)&&z(i+5,1)==255&&z(i+10,1)==255)
                x=i;
             end
             if(z(i,c)&&z(i+1,c)&&z(i+2,c)&&z(i+4,c)&&z(i+5,c)==255&&z(i+10,c)==255)
                y=i;
             end
         end
         if(x>=160&&y>=160)
             if(x==y||x==y+2)
                a(120:169,120:169,:)=arrow3;
                check=1;
             elseif(x<y)
                a(120:169,120:169,:)=arrow4;
                check=1;
            elseif(x>y)
                a(120:169,120:169,:)=arrow2;
                check=1;
         end
        
         end
    if(check==0)
                a(120:169,120:169,:)=arrow5;
    end
         else
             a(120:169,120:169,:)=cross;
         end
         mov(k).cdata=a;
vidFrames(:,:,:,k)=mov(k).cdata;
% imagename=strcat(int2str(k), '.jpeg');
% imwrite(vidFrames(:,:,:,k), strcat('kewl',imagename));
end
implay(Frames);
implay(vidFrames);