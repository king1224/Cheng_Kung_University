p=1000;
theta=0:pi/10:2*pi;
figure(1)   %���T�ӹϡA�η��y�еe�X�y��Anear r�y�D�P�a�y�̪�Z���Afar r�y�D�P�a�y�̻��Z��
subplot(3,1,1)
E=0;        %�Ĥ@�ӹ�esplion=0
r=p./(1-E*cos(theta));
polar(theta,r,'r');
subplot(3,1,2)
fprintf('If esplion=0 , near r=%4.5f\n',p/1);
fprintf('If esplion=0 , far r=%4.5f\n',p/1);
E=0.25;     %�ĤG�ӹ�esplion=0.25
r=p./(1-E*cos(theta));
polar(theta,r,'r');
fprintf('If esplion=0.25 , near r=%4.5f\n',p./(1+0.25));
fprintf('If esplion=0.25 , far r=%4.5f\n',p./(1-0.25));
subplot(3,1,3)
E=0.5;      %�ĤT�ӹ�esplion=0.5
r=p./(1-E*cos(theta));
polar(theta,r,'r');
fprintf('If esplion=0.5 , near r=%4.5f\n',p./(1+0.5));
fprintf('If esplion=0.5 , far r=%4.5f\n',p./(1-0.5));
%P��theta=pi/2�B3/2*pi�ɭy�D�P�a�y���Z���AP�V�j�A�y�D�V�j