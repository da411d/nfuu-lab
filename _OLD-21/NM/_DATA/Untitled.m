k = 2;
x = -2.5;
c = 0.31;
a = 0.93;
b = 5.61;
format short;
y = log(k.*x)./sin(7) - (abs(x - a.^2)).^0.5 - (10^4 .* (a-b))/(cos(k.*x)) + (x - a.^2).^(1/3) + c.^3;
y