function c = M(a, b)
    c = zeros(6, 6);
    for i = 1:6
        for j = 1:6
            c(i, j) = (a(i, j) + b(i, j)) / 2;
        end
    end
end