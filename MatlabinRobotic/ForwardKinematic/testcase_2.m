load testData.mat

N = 10;
q1 = linspace(0,2*pi*(1-1/N),N);
q2 = q1;
correct = true;
for i = 1:N
    for j = 1:N
        [R,p,state] = HW2([q1(i) q2(j)]);
        
        correct_R = all(all(R-R_test(:,:,i,j)<=eps));
        correct_p = all(all(p-p_test(:,i,j)<=eps));
        correct_state = isequal(state,state_test{i,j});
        
        correct = correct && (correct_R && correct_p && correct_state);
    end
end

correct

