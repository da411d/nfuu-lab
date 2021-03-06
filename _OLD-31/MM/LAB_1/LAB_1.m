clc;
clear;

%% PART 1
x = 33;
y = 2;
F_1 = F(x, y)

%% PART 2
arr = randi(10, 10, 1);
a = 5;
S_2 = S(arr, a)

%% PART 3
arr_width = randi(10, 12, 1);
arr_height = randi(10, 12, 1);
arr_depth = randi(10, 12, 1);
for i=1:12
    V = arr_width(i) * arr_height(i) * arr_depth(i);
    disp(['��`�� ', num2str(i), ' ������������� = ', num2str(V)])
end;

%% PART 4
A = randi(10, 6, 6);
B = randi(10, 6, 6);
C = M(A, B)

%% PART 5
matrix = [
    1 2 3 4 5 6;
    2 4 6 8 8 8;
    2 4 6 8 8 8;
    2 2 2 2 2 -2;
    1 2 1 2 1 -1;
    1 2 1 2 1 1;
]
check = Check(matrix)