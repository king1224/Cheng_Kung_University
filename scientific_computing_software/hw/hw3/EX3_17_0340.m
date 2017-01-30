p=1000;
theta=0:pi/10:2*pi;
figure(1)   %分三個圖，用極座標畫出軌跡，near r軌道與地球最近距離，far r軌道與地球最遠距離
subplot(3,1,1)
E=0;        %第一個圖esplion=0
r=p./(1-E*cos(theta));
polar(theta,r,'r');
subplot(3,1,2)
fprintf('If esplion=0 , near r=%4.5f\n',p/1);
fprintf('If esplion=0 , far r=%4.5f\n',p/1);
E=0.25;     %第二個圖esplion=0.25
r=p./(1-E*cos(theta));
polar(theta,r,'r');
fprintf('If esplion=0.25 , near r=%4.5f\n',p./(1+0.25));
fprintf('If esplion=0.25 , far r=%4.5f\n',p./(1-0.25));
subplot(3,1,3)
E=0.5;      %第三個圖esplion=0.5
r=p./(1-E*cos(theta));
polar(theta,r,'r');
fprintf('If esplion=0.5 , near r=%4.5f\n',p./(1+0.5));
fprintf('If esplion=0.5 , far r=%4.5f\n',p./(1-0.5));
%P為theta=pi/2、3/2*pi時軌道與地球的距離，P越大，軌道越大