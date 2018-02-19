clear
clc
% Обробка одновимірного масиву
n=10;s=0;s1=0;s2=0;s3=0;

for i=1:n
	A1(i) = (i.^2 - 5*cos(i) ) / (sqrt(i.^3) + 4*i - 5);
end
ac = s1 / n
minA = min(A1)
maxA = max(A1)
for i=1:n
	s2 = s2 + (A1(i)-ac).^2;
end
s = s + (A1(i)-ac).^2;
s3 = (s/(n-1))^0.5
z = sin(s1/max(A1)) - log2(abs(max(A1)+min(A1)))^3/cos(ac+s3)^2


% Обчислення двовимірного масиву та розв’язування матричного рівняння
for i=1:4
	for j=1:4
		A(i,j) = (i - j) / (i + j.^2 / 2)
		B(i,j) = (i.^2 - cos(j)) / (1.5 + i*j)
	end
end

% Побудова матриць рівняння та його розв’язок
A1 = 3*A'
C1 = A1*(2*A+3*B)
C = inv(C1)
D = inv(B)*(2*A+5*B')
X = C*D
% Перевірка
D1 = C1*X