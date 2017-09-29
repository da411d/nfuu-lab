%Завданя 1, 2
x = -2*pi :pi/20: 2*pi ;
y = 5 * cos(2*x);
z = (x.^3 - 2) ./ 15;
plot(x,y,'y*')
hold on
plot(x,z,'rs')
title('Побудова двох графіків в одному вікні')
xlabel('x')
ylabel('y')
grid on
figure
subplot(2,1,1)
plot(x,y,'y*')
title('y=f(x)')
xlabel('x')
ylabel('y')
grid on
subplot(2,1,2)
plot(x,z,'gs')
title('z=f(x)')
xlabel('x')
ylabel('z')
grid on

%Завданя 3
fi = 0 : pi/100 : 2*pi;
r = cos(5 * fi);
polar(fi,r)
grid on

%Завданя 4.A
x = -2*pi : pi/20 : 2*pi;
y = -2*pi : pi/20 : 2*pi;
ezplot('x^4 - 6*x^2*4^2 + 9*y^2 - 5*x^2 - 10')
grid on
%Завданя 4.Б
ezplot('2*cos(t)*(1 + 3*cos(2*t))', '2*sin(t)*(51 + 3*sin(4*t))', [-2*pi, 2*pi])
grid on