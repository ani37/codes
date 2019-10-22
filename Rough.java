package rough;
import java.util.*;
import java.lang.*;
import java.lang.reflect.Array;
import java.io.*;
import java.math.*;
import java.text.DecimalFormat;
public class Rough{     
   static class Node{
       Node left,right;
       int data;
       public Node(int data){
            this.left=null;
            this.right=null;
            this.data=data;
       
       }
   }
   public static int pi;
    static Map<Integer,Integer> map;
    static void init(int arr[]){
        pi=arr.length;
        map=new HashMap<Integer,Integer>();
        for(int i=0;i<arr.length;i++){
            map.put(arr[i],i);
        }
    }
    static Node buildT(int in[],int post[],int l,int h){
        if(l>h){
               return null;
           }
           Node node=new Node(post[--pi]);
           if(l==h){
               return node;
           }
           int j=map.get(node.data);
           node.right=buildT(in,post,j+1,h);
           node.left=buildT(in,post,l,j-1);
           return node;
    }
	// Complete the function
        static Node buildTree(int in[], int post[], int n)
	{
	    init(in);
	    return buildT(in,post,0,n-1);
	    
	}
    static void printPO(Node root){
         if(root==null)
             return;
         printPO(root.left);
         printPO(root.right);
         System.out.print(root.data+" ");
    }
    //static int pr[],io[];
    public static void main(String[] args) throws IOException {   
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int io[]=new int[n];
        int po[]=new int[n];
        for(int i1=0;i1<n;i1++){
             io[i1]=sc.nextInt();                                
        }
        for(int i1=0;i1<n;i1++){
             po[i1]=sc.nextInt();                                
        }
        Node node=buildTree(io,po,n);
        printPO(node);
        System.out.println();
    }
}