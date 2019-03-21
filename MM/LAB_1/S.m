function sum = S(arr, a)
    sum = 0;
    for i=1:10
        if (arr(i) > a)
            sum = sum + a;
        end;
    end;
end