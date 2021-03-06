clc;
clear;

%% CONFIG
SUBPLOT_ENABLED = true;


%% TASK 1
if(exist('SUBPLOT_ENABLED', 'var') > 0 && SUBPLOT_ENABLED)
    subplot(2,2,1);
else
    clc;
    clear;
end;
x = -5 : 0.1 : 3;
y = 2 ./ x;
plot(x,y), grid;
title('y = 3*sin(x)');
xlabel('x');
ylabel('y');


%% TASK 2
if(exist('SUBPLOT_ENABLED', 'var') > 0 && SUBPLOT_ENABLED)
    subplot(2,2,2);
else
    clc;
    clear;
end;
r = 0 : pi/100 : 5;
fi = r*0 + 3 .* pi ./ 2;
polar(r, fi), grid;
title('y = 3pi/2');
xlabel('x');
ylabel('y'); 


%% TASK 3
if(exist('SUBPLOT_ENABLED', 'var') > 0 && SUBPLOT_ENABLED)
    subplot(2,2,3);
else
    clc;
    clear;
end;
range_x = -1 : 1/50 : 1;
range_y = -1 : 1/50 : 1;
[x, y] = meshgrid(range_x, range_y);
z = x.^4 - 2*x.^2 + y.^4 - 2*y.^2 + 5;
surf(x, y, z), grid on;
xlabel('x')
ylabel('y')
zlabel('z')


%% TASK 4
if(exist('SUBPLOT_ENABLED', 'var') > 0 && SUBPLOT_ENABLED)
    subplot(2,2,4);
else
    clc;
    clear;
end;
x = randi(100, 15, 1);
pie(x);
title('�������� �����') 


%% ��������� �ʲ�ֲ
clc;
clear;
