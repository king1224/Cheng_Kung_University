% Create an input array from -2*pi to 2*pi
t = -2*pi:pi/10:2*pi;

% Calculate |sin(t)|
x = abs(sin(t));

% Plot result
plot(t,x);

%跳出圖形視窗
%得到四條凹向下的曲線，四座山
%t從-2pi到2pi
%x介在0~1之間