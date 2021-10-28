import java.util.*;
import java.io.*;
import java.math.*;
import java.lang.*;
public class Rough{
      
    static class InputReader { 
        private final InputStream stream;
	private final byte[] buf = new byte[8192];
	private int curChar, snumChars;
 	public InputReader(InputStream st) {
            this.stream = st;
	} 
	public int read() {
            if (snumChars == -1)
	 	throw new InputMismatchException();
            if (curChar >= snumChars) {
		curChar = 0;
                try {
                    snumChars = stream.read(buf);
		} 
                catch (IOException e) {
                    throw new InputMismatchException();
           	}
		if (snumChars <= 0)
                    return -1;
            }
            return buf[curChar++];
	}
        public int ni() {
            int c = read();
            while (isSpaceChar(c)) {
               	c = read();
            }
            int sgn = 1;
            if (c == '-') {
		sgn = -1;
		c = read();
            }
            int res = 0;
            do {
		res *= 10;
		res += c - '0';
		c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
	} 
	public long nl() {
            int c = read();
            while (isSpaceChar(c)) {
            c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
	} 
	public int[] nia(int n) {
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
		a[i] = ni();
            }
            return a;
	} 
	public String rs() {
            int c = read();
            while (isSpaceChar(c)) {
		c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
		res.appendCodePoint(c);
                    c = read();
            } while (!isSpaceChar(c));
            return res.toString();
	}
	public String nextLine() {
            int c = read();
            while (isSpaceChar(c))
		c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isEndOfLine(c));
            return res.toString();
        } 
	public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
 
	private boolean isEndOfLine(int c) {
            return c == '\n' || c == '\r' || c == -1;
	} 
    }
    static PrintWriter w = new PrintWriter(System.out);
    
    static boolean prime[]=new boolean[(int)1e8+1];
     static void sieve() {
	Arrays.fill(prime, true);
	prime[0] = prime[1] = false;
	for(int i = 2 ; i * i <=(int)1e8 ; ++i) {
            if(prime[i]) {
                for(int k = i * i; k<(int)1e8 ; k+=i) {
                    prime[k] = false;
                }
            }
	}
			
    }
	
	
    public static void main(String []args){
         InputReader sc=new InputReader(System.in);

        sieve();
        int t=sc.ni();
        while(t-->0){
            int n=sc.ni();
            int count=0;
            for(int i=0;i<n;i++){
                int a=sc.ni();
                if(prime[a])
                    count++;
            }
            w.println(count);
        }
        w.close();
    }
    
}