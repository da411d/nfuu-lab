classdef DavidFraction
   properties
       numerator % numerator
       denominator % denominator
   end
   
   methods
       % CONSTRUCTOR
       function obj = DavidFraction(num, denom)
           obj.numerator = num;
           obj.denominator = denom;
       end
       
       % PLUS
       function obj = plus(a, b)
           if a.denominator == b.denominator
               obj = DavidFraction(a.numerator + b.numerator, a.denominator);
           else
               obj = DavidFraction(a.numerator*b.denominator + b.numerator*a.denominator, a.denominator*b.denominator);
           end
       end
       
       % MINUS
       function obj = minus(a, b)
           if a.denominator == b.denominator
               obj = DavidFraction(a.numerator - b.numerator, a.denominator);
           else
               obj = DavidFraction(a.numerator*b.denominator - b.numerator*a.denominator, a.denominator*b.denominator);
           end
       end
       
       % MULTIPLY
       function obj = mtimes(a, b)
           obj = DavidFraction(a.numerator*b.numerator, a.denominator*b.denominator);
       end
       
       % <
       function bool = lt(a, b)
           bool = a.numerator/a.denominator < b.numerator/b.denominator;
       end
       
       % >
       function bool = gt(a, b)
           bool = a.numerator/a.denominator > b.numerator/b.denominator;
       end
       
       % OUTPUT OVERLOAD
       function display(self)
            disp([inputname(1), ' = ', num2str(self.numerator), '/', num2str(self.denominator)]);
            disp(' '); 
       end
   end
end
