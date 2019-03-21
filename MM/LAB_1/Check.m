function status = Check(m)
    status = false;
    for j = 1:6
        count_positive = 0;
        count_negative = 0;
        for i = 1:6
            if(m(i, j) < 0)
                count_negative = count_negative + 1;
            else
                count_positive = count_positive + 1;
            end;
        end
        if(count_positive == count_negative)
            status = true;
        end;
    end
end