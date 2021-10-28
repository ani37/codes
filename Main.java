import java.math.BigInteger;
import java.util.Scanner;


public class Main {



   
   public static BigInteger power(BigInteger base, BigInteger e)
  {
    BigInteger result = BigInteger.ONE;
    base = base;
    for (int idx = 0; idx < e.bitLength(); ++idx) {
      if (e.testBit(idx)) {
        result = result.multiply(base);
      }
      base = base.multiply(base);
    }
    return result;
  }
    public static Scanner sc = new Scanner(System.in);
    public static void main (String[] args) throws java.lang.Exception
    {
        int T;
        T =sc.nextInt();
        
        BigInteger mod = sc.nextBigInteger();
        
        for(int test = 0;test<T;test++)
        {

                  
        BigInteger L = sc.nextBigInteger();
 
        BigInteger R =sc.nextBigInteger();
        BigInteger On = BigInteger.ONE;
         BigInteger To= BigInteger.valueOf(2);
         

        BigInteger x,y;

        if(L.mod(To).equals(On))
        {
         x  = L;
        }
        else x = L.add(On);
      if(R.mod(To).equals(On))
      {
       y  = R;
      }
  else y = R.subtract(On);
  //n =  (y-x)/2 +1;
  BigInteger n = ((y.subtract(x)).divide(To)).add(On);
  BigInteger p = (x.subtract(On)).divide(To);
  BigInteger a = power(BigInteger.valueOf(3),p);
  BigInteger k = power(BigInteger.valueOf(3),n);
             ((k.subtract(On)).multiply(a)).divide(To);
             k.mod(mod);
  BigInteger ans = k;
   if(L.mod(To).equals(On))
        {
         x  = L.add(On);
        }
        else x = L;
      if(R.mod(To).equals(On))
      {
       y  = R.subtract(On);
      }
  else y = R;

  n = y.subtract(x).divide(To).add(On);
  if(n.compareTo(On)==1)
  {   
     p = x.divide(To);
     a = power(BigInteger.valueOf(3),p);
     BigInteger f = n.divide(To);
     k = power(BigInteger.valueOf(9),f);
      ((k.subtract(On)).multiply(a)).divide(BigInteger.valueOf(4));
      k.mod(mod);
     ans.add(k);
     ans.add(f.multiply(To));
  }
     ans.mod(mod);
    if(y.equals(To) && n.mod(To).equals(On))
    {
      ans.add(On);
    }
    else if(n.mod(To).equals(On))
    {
      
      n = (y.subtract(To)).divide(To);

        if(n.mod(To).equals(On))
          a = BigInteger.valueOf(3);
        else a = BigInteger.valueOf(-3);
        k =  power(BigInteger.valueOf(-3),n);
        ((k.subtract(On)).multiply(a)).divide(BigInteger.valueOf(-2));
       k.mod(mod);
       ans.add(k);
       ans.add(On);
       ans.mod(mod);
    }
  System.out.println(ans);

    }
}
}