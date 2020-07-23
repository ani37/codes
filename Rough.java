package rough;
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;
import java.text.*;
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
    static long mod1=998244353L,mod=1000000007L;
    
    
    public static void main (String[] args)throws IOException{      
        InputReader sc=new InputReader(System.in);
        //findFact();
        
        int n=sc.ni();
        int arr[]=new int[n];
        int c=0;
        for(int i=0;i<n;i++)arr[i]=Math.abs(sc.ni());
        for(int l=1;l<=n;l++){
            long co[]=new long[3];
            int i=0;
            for(i=0;i<l-1;i++){
                //int in=arr[i]%3;
                 co[arr[i]%3]++;
            }
            for(;i<n;i++){
                co[(arr[i]%3)]++;
               // long ans=nCr(co[1],3)+nCr(co[2],3)+nCr(co[0],3)+co[0]*co[1]*co[2];
                long ans=(co[0]*(co[0]-1)*(co[0]-2))/6+(co[1]*(co[1]-1)*(co[1]-2))/6+(co[2]*(co[2]-1)*(co[2]-2))/6+co[0]*co[1]*co[2];
                if(ans%3==0&&ans>0)c++;
                co[(arr[i-l+1]%3)]--;
            }
        }
        
        w.println(c);
        w.close();
    }
}
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;
import java.text.*;
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
    static long mod1=998244353L,mod=1000000007L;
    
    
    public static void main (String[] args)throws IOException{      
        InputReader sc=new InputReader(System.in);
        //findFact();
        
        // int n=sc.ni();
        // int arr[]=new int[n];
        // int c=0;
        // for(int i=0;i<n;i++)arr[i]=Math.abs(sc.ni());
        // for(int l=1;l<=n;l++){
        //     long co[]=new long[3];
        //     int i=0;
        //     for(i=0;i<l-1;i++){
        //         //int in=arr[i]%3;
        //          co[arr[i]%3]++;
        //     }
        //     for(;i<n;i++){
        //         co[(arr[i]%3)]++;
        //        // long ans=nCr(co[1],3)+nCr(co[2],3)+nCr(co[0],3)+co[0]*co[1]*co[2];
        //         long ans=(co[0]*(co[0]-1)*(co[0]-2))/6+(co[1]*(co[1]-1)*(co[1]-2))/6+(co[2]*(co[2]-1)*(co[2]-2))/6+co[0]*co[1]*co[2];
        //         if(ans%3==0&&ans>0)c++;
        //         co[(arr[i-l+1]%3)]--;
        //     }
        // }
        
        // w.println(c);
        w.close();
    }
}