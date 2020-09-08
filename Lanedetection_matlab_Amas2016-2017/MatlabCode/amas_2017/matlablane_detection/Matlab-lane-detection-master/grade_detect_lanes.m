setN = [1 2]; % Number of sets in train
totalFramesInSets = [250 232]; % Total number of frames in set1 and set2
points = 0;

for i = setN
    % load the gt file. order of values in gt: rho1,theta1,rho2,theta2
    gt_filename = sprintf('set%d_gt.csv',i);
    gt = csvread(gt_filename);
    
    % loop through all the frames in each set
    for j = 1:totalFramesInSets(i)
        % load each frame in the set
        image_name = sprintf('set%d_f%05d.png',i,j-1);
        img = imread(image_name);
        
        t = cputime; % start timer

        % call the algorithm
        [alg_rho1, alg_theta1, alg_rho2, alg_theta2] = detect_lanes(img);
        
        execution_time = cputime - t;
        if execution_time > 60 % only 60 seconds per image
            fprintf ( 'Set %d - frame %d.  Took > 60 seconds [%d]. Point [%d], Total Points [%d]\n', ...
            i, (j-1), execution_time, ...
            new_point, points );
            
            continue
        end

        % calculate x-values for y=1 and y=480 for 
        % lane1 (with rho1 and theta1) and lane2 from the algorithm
        
        al_x(1,1) = compute_x_rad ( 1, alg_rho1, alg_theta1 );
        al_x(1,2) = compute_x_rad ( 1, alg_rho2, alg_theta2 );        
        al_x(2,1) = compute_x_rad ( 480, alg_rho1, alg_theta1 );
        al_x(2,2) = compute_x_rad ( 480, alg_rho2, alg_theta2 );


        gt_rho1 = gt(j,1);
        gt_theta1 = gt(j,2);
        gt_rho2 = gt(j,3);
        gt_theta2 = gt(j,4);
        
        gt_x(1,1) = compute_x_rad ( 1, gt_rho1, gt_theta1 );
        gt_x(1,2) = compute_x_rad ( 1, gt_rho2, gt_theta2 );
        gt_x(2,1) = compute_x_rad ( 480, gt_rho1, gt_theta1 );
        gt_x(2,2) = compute_x_rad ( 480, gt_rho2, gt_theta2 );
        

        % visualization.  Remove when fixed
        fn = sprintf ( 'set%d_f%05d.png', i, j-1 );   % 4/7/2016 - bug fixed: j changed to j-1
        f = imread ( fn ); 
        imshow ( f );
        hold on;
        plot ( [gt_x(1,1) gt_x(2,1)], [1, 480], '-g' );
        plot ( [gt_x(1,2) gt_x(2,2)], [1, 480], '-g' );
        
        plot ( [al_x(1,1) al_x(2,1)], [1, 480], '-r' );
        plot ( [al_x(1,2) al_x(2,2)], [1, 480], '-r' );
        
                
        
        % now compute the differences
        for k = 1:2
            
            % top row
            ds1 = abs(gt_x(k,1) - al_x(k,1));
            ds2 = abs(gt_x(k,1) - al_x(k,2));

            if ( ds1 < ds2 ) % matched (*,1) -> (*,1)
                dist_v(1 + (k-1)*2) = ds1;
                dist_v(2 + (k-1)*2) = abs ( gt_x(k,2) - al_x(k,2) );

            else             % matched (*,1) -> (*,2)
                dist_v(1 + (k-1)*2) = ds2;
                dist_v(2 + (k-1)*2) = abs ( gt_x(k,2) - al_x(k,1) );
            end
        end

        
        % compute score
        distT = [110 90 70 50]; %distT = [100 75 50 25];
        
        points_checked = false;
        new_point = 0;
        
        for k = 1:4
            for m = 1:4
                if ( dist_v(m) > distT(k) )
                    new_point = k-1;
                    points = points + new_point; 
                    points_checked = true;
                    break;
                end
            end
            
            if ( points_checked == true )
                break;
            end
        end
            
        if ( points_checked == false )
            new_point = 4;
            points = points + new_point;
        end
        
        str_output = sprintf ( 'Distance [%.0f, %.0f, %.0f, %.0f] = points [%d, %d]', ...
            dist_v(1), dist_v(2), dist_v(3), dist_v(4), ...
            new_point, points );
        
        title ( str_output );

        fprintf ( 'Set %d - frame %d.  Distance [%.0f, %.0f, %.0f, %.0f]. Point [%d], Total Points [%d]\n', ...
            i, (j-1), dist_v(1), dist_v(2), dist_v(3), dist_v(4), ...
            new_point, points );
        
    end
end