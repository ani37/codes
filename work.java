
import java.util.Arrays;
import java.math.*;
import java.util.Scanner;
public class work{

     public static BigInteger x =BigInteger.ZERO;
     public static BigInteger y =BigInteger.ZERO;
     
public static BigInteger power(BigInteger base, BigInteger e, BigInteger m)
  {
    BigInteger result = BigInteger.ONE;
    base = base.mod(m);
    for (int idx = 0; idx < e.bitLength(); ++idx) {
      if (e.testBit(idx)) {
        result = result.multiply(base).mod(m);
      }
      base = base.multiply(base).mod(m);
    }
    return result;
  }
 public static String ASCIISentence(String str) 
    { 
        int l = str.length(); 
        int convert; 
        String res = "1",temp="";
        for (int i = 0; i < l; i++) { 
            convert = str.charAt(i); 
            temp    = Integer.toString(convert);
            if(temp.length()==1)+
            {
              temp = "00" + temp;
            }
            if(temp.length()==2)
            {
              temp = "0" + temp;
            }
            res = res + temp; 
        }
        return res; 
    } 
    public static String normalSentence(String str) 
    { 
        int l = str.length(); 
        int convert; 
        String res = "",temp="";
        for (int i = 1; i < l-2; i+=3) 
        {    
           temp = "" + str.charAt(i) + str.charAt(i+1) + str.charAt(i+2); 

            int result = Integer.parseInt(temp);
            res = res + Character.toString((char)result); 

        }
        return res; 
    } 
  public static void Point_mult(BigInteger xf,BigInteger xs,BigInteger k,BigInteger a,BigInteger Mod)
{
  BigInteger xm = BigInteger.ZERO;
  BigInteger ym = BigInteger.ZERO;
  BigInteger xt = BigInteger.ZERO;
  BigInteger yt = BigInteger.ZERO;

  while(!BigInteger.ZERO.equals(k)) 
  {//  System.out.println(xf + " " + xs);
    
   if(BigInteger.ZERO.equals(k.mod(BigInteger.valueOf(2))))
   {
    k = k.divide(BigInteger.valueOf(2));
  Point_addition(xf,xs,xf,xs,a,Mod);
  xf  = x;
  xs  = y;
  //System.out.println(x + " " + x);
   }

   else 
   {
    k= k.subtract(BigInteger.ONE);
    if(xm.equals(xt) && ym.equals(yt))
    { 
       xm  = (xf);
       ym  = (xs);

    }
    else
    {
    Point_addition(xm,ym,xf,xs,a,Mod);
      xm  = (x);
      ym  = (y);
    }
   }
  }
  x = xm;
  y = ym;
 
return;
}
 public static void Point_addition(BigInteger xf,BigInteger xs,BigInteger yf,BigInteger ys,BigInteger a,BigInteger Mod)
{
BigInteger Lamda,Inv;
  x = BigInteger.ZERO;
  y = BigInteger.ZERO;
  if(xf.equals(yf) && xs.equals(ys))
  {   
    Lamda = ((((xf.multiply(xf)).mod(Mod)).multiply(BigInteger.valueOf(3))).add(a)).mod(Mod);
      Inv = (xs.multiply(BigInteger.valueOf(2))).modInverse(Mod);
   Lamda  =  (Lamda.multiply(Inv)).mod(Mod);
   x      =  (((Lamda.multiply(Lamda)).subtract(xf.multiply(BigInteger.valueOf(2)))).add(Mod)).mod(Mod);
   y      =  (((Lamda.multiply(xf.subtract(x))).subtract(xs)).add(Mod)).mod(Mod);
   // System.out.println(x + "==" + y);
   return;
  }
  else 
  { 
    if(xf.equals(BigInteger.ZERO) && xs.equals(BigInteger.ZERO))
    {
      x = yf;
      y = ys;
 
      return;
    }
  //   System.out.println(xf + " " + yf);
    if(yf.equals(BigInteger.ZERO) && ys.equals(BigInteger.ZERO))
    {
      x = xf;
      y = xs;
      return;
    }
    Lamda =  ys.subtract(xs);
      Inv = ( yf.subtract(xf)).modInverse(Mod);
   Lamda  =  (Lamda.multiply(Inv)).mod(Mod);
   x      =  (((Lamda.multiply(Lamda)).subtract(xf.add(yf))).add(Mod)).mod(Mod);
   y      =  (((Lamda.multiply(xf.subtract(x))).subtract(xs)).add(Mod)).mod(Mod);
  }
return;
}

   public static void main(String args[]) throws java.lang.Exception
    {

        //int input[] = {2,5,3,1,2,10,6,7,8};
   BigInteger Mod,Message,C,X,Y,A,B,P,K,Gf,Gs,Pms,Pmf,Pbf,Pbs,Encrip1f,Encrip1s,Encrip2f,Encrip2s,Pirxf,Pirxs,Decrip1f,Decript1s,Decript2f,Decript2s;
    Mod = new BigInteger("8948962207650232551656602815159153422162609644098354511344597187200057010413552439917934304191956942765446530386427345937963894309923928536070534607816947"); 
      A = new BigInteger("6294860557973063227666421306476379324074715770622746227136910445450301914281276098027990968407983962691151853678563877834221834027439718238065725844264138");
      B = new BigInteger("3245789008328967059274849584342077916531909009637501918328323668736179176583263496463525128488282611559800773506973771797764811498834995234341530862286627");
     P  = new BigInteger("10000000074234235235546334");
     Gf = new BigInteger("6792059140424575174435640431269195087843153390102521881468023012732047482579853077545647446272866794936371522410774532686582484617946013928874296844351522");
     Gs = new BigInteger("6592244555240112873324748381429610341312712940326266331327445066687010545415256461097707483288650216992613090185042957716318301180159234788504307628509330");
      K = new BigInteger("47");
    Pmf = BigInteger.ZERO;
    Pms = BigInteger.ZERO;
     Pbf = BigInteger.ZERO;
    Pbs = BigInteger.ZERO;

Scanner scanner = new Scanner(System.in);
String mess = scanner.nextLine();
String asciimess = ASCIISentence(mess);
Message = new BigInteger(asciimess);

        // BigInteger result = B.mod(A); 
      //System.out.println(result);
   //   Pair <BigInteger,BigInteger> generator,plainMsg,pbkey,encrip1,encrip2,pirx,decrip1,decrip;

    for (int i = 0; i < 1000; ++i)
     {
        
       C  = (Message.multiply(BigInteger.valueOf(1000))).add(BigInteger.valueOf(i));
       X = (((C.multiply(C)).mod(Mod)).multiply(C)).mod(Mod);
       Y =  (A.multiply(C)).mod(Mod);
       X = (X.add(Y.add(B))).mod(Mod);
       Y = (Mod.subtract(BigInteger.ONE)).divide(BigInteger.valueOf(2));
   if(power(X,Y,Mod).equals(BigInteger.ONE))
       {   
   Y = (Mod.add(BigInteger.ONE)).divide(BigInteger.valueOf(4));
   Pmf = C;
   Pms = power(X,Y,Mod);
   break; 
      }
   }

    Point_mult(Gf,Gs,P,A,Mod); //public key of reciever
    Pbf = x;
     Pbs =y;
     System.out.println( Pbf + " " + Pbs);

//   Scanner scanner = new Scanner(System.in);
// try{
//      Pbf = scanner.nextBigInteger();
//      Pbs = scanner.nextBigInteger();
// } catch(NumberFormatException ex) {
//      System.out.println("Re-enter the numbers without spaces\n");
// }
     Point_mult(Pbf,Pbs,K,A,Mod);//k times public key
     Pirxf= x;
     Pirxs = y;
      Point_mult(Gf,Gs,K,A,Mod);//k times generator
     Encrip1f= x;
    Encrip1s = y;
    //System.out.println( Pirxf + " " + Pirxs);
     Point_addition(Pirxf,Pirxs,Pmf,Pms,A,Mod);// one of the points in elliptical curve
     // System.out.println(Pmf + " " + Pms);
     Encrip2f= x;
    Encrip2s = y;
   //System.out.println( Pmf + " " + Pms);
    //   K = K.multiply(P);
 //   P = BigInteger.valueOf(19);
   Point_mult(Encrip1f,Encrip1s,P,A,Mod);// sub to    
     Decript2f= x;
     Decript2s = y.multiply(BigInteger.valueOf(-1));
   Point_addition(Encrip2f,Encrip2s,Decript2f,Decript2s,A,Mod);//
     Decrip1f= x;  
     Decript1s= y;

     BigInteger Ans = Decrip1f.divide(BigInteger.valueOf(1000)); 
     String demess = Ans.toString();
     demess = normalSentence(demess);
     System.out.println("Message : " + demess);
 

}
}