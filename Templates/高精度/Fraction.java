import java.math.*;
import java.util.*;

class Fraction implements Comparable
{
    BigInteger numerator, denominator, gcd;
    
    public int compareTo(Object o2)
    {
        Fraction s2 = ((Fraction) o2);
        return this.compareTo(s2);
    }
    
    void set(String n, String d)
    {
        numerator = new BigInteger(n);
        denominator = new BigInteger(d);
        this.simplify();
        //System.out.println(numerator.toString() + " " + denominator.toString());
    }
    
    void simplify()
    {
        gcd = numerator.gcd(denominator);
        numerator = numerator.divide(gcd);
        denominator = denominator.divide(gcd);
        if (denominator.compareTo(BigInteger.ZERO) < 0)
        {
            numerator = numerator.negate();
            denominator = denominator.negate();
        }
    }
    
    Fraction negate()
    {
        Fraction z = this;
        z.numerator = z.numerator.negate();
        return z;
    }
    
    Fraction abs()
    {
        Fraction z = new Fraction();
        if (numerator.compareTo(BigInteger.ZERO) < 0)
        {
            z.numerator = numerator.negate();
        }
        else
        {
            z.numerator = numerator;
        }
        if (denominator.compareTo(BigInteger.ZERO) < 0)
        {
            z.denominator = denominator.negate();
        }
        else
        {
            z.denominator = denominator;
        }
        return z;
    }
    
    boolean zero()
    {
        return numerator.compareTo(BigInteger.ZERO) == 0;
    }
    
    int compareTo(Fraction y)
    {
        Fraction z = this.subtract(y);
        return z.numerator.compareTo(BigInteger.ZERO);
    }
    
    Fraction add(Fraction y)
    {
        Fraction z = new Fraction();
        gcd = denominator.gcd(y.denominator);
        z.denominator = denominator.multiply(y.denominator).divide(gcd);
        z.numerator = numerator.multiply(z.denominator.divide(denominator)).add(y.numerator.multiply(z.denominator.divide(y.denominator)));
        z.simplify();
        return z;
    }
    
    Fraction subtract(Fraction y)
    {
        Fraction z = new Fraction();
        gcd = denominator.gcd(y.denominator);
        z.denominator = denominator.multiply(y.denominator).divide(gcd);
        z.numerator = numerator.multiply(z.denominator.divide(denominator)).subtract(y.numerator.multiply(z.denominator.divide(y.denominator)));
        z.simplify();
        return z;
    }
    
    
    Fraction multiply(Fraction y)
    {
        Fraction z = new Fraction();
        z.numerator = numerator.multiply(y.numerator);
        z.denominator = denominator.multiply(y.denominator);
        z.simplify();
        return z;
    }
    
    Fraction divide(Fraction y)
    {
        Fraction z = new Fraction();
        z.numerator = numerator.multiply(y.denominator);
        z.denominator = denominator.multiply(y.numerator);
        z.simplify();
        return z;
    }
    
    void print()
    {
        if (denominator.compareTo(BigInteger.ONE) != 0)
        {
            System.out.printf("%s/%s", numerator.toString(), denominator.toString());
        }
        else
        {
            System.out.printf("%s", numerator.toString());
        }
        System.out.println();
    }
}
