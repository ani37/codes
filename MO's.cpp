q:
   The internet speed at nits its too slow sometimes.you are doing some task and thought to lisen to a music in youtube.The video consumes 
   'D' amount of data in one second.The server can send data amounts N times.Due to the varying internet speed,the amount of data sent by the 
   server may vary with time.since you are busy on your task ,you want an unbuffered stream of video.so your task is to find after what second/s you
   should start watching the complete video without strucking.In i'th second the server can send Ai amount of data
   Note here D must be an integral multiple of the sum of
   of the total amount of data send by the server.
   Input

The first line contains two space-separated integers, N and D (1 ≤ n ≤ 10^5, 1 ≤ X ≤ 10^9).

The second line contains n space-separated integers, A1, A2, A3 ... An. (0 ≤ Ai ≤ 10^9)
Output
print a single integer denoting the minimum number of seconds after which you can start watching the video.
case1:
2 4
5 5
Output
1
case2:
6 2
1 2 3 3 6 8
Output
2


q:Aman likes prime numbers and he has given you a task,find a,b,c,d in 
 a^3 +b^3+ c^3 +d^3=N ,where N is guaranted to be an odd number and  b,c,d are prime numbers and a is s .
  Input

The first line only a single integer N (1 ≤ N≤ 10^18). 
Output
single line space-separated integer a,b,c,d.If there are multiple answer print any one.if there are no values for the above condition then print -1.
or print the sum of a+b+c+d(agar test case....)
input
161
Output
1 2 3 5
input
101
Output
-1


q3:
Recently manu came to know about some properties of factors of a number.so he thought to test their properties to know if his friends know about it.
First you have to print total factors of a number, he knew this was easy he gave another task with it,so
you have to also find the number of ordered pairs (a, b) such that a and b are factors of n and a and b are coprime.Prove manu you have better knowledge 
about the factors of a number.

Input
The first line contains one integer T (1 ≤ T ≤ 120000) — the number of queries you have to answer.

Then T lines follow.The ith line contains a single integer n (1 ≤ n ≤ 120000).
Output
Output T integers — answer to each query.
case1:
3
2
8
12
Output
2 3
4 7
6 15
factors of 2 are 2 and Ordered pairs-{1, 1}, {1, 2}, {2, 1}

factors of 8 are 4 and Ordered pairs-{1, 1}, {1, 2}, {1, 4}, {1, 8}, {2, 1}, {4, 1}, {8, 1}
q4:

You are given an array of N integers a1, a2, a3, ...aN. You need to process Q cases.

There are two types of queries which are as follows :

* 1 l r - - find the value of the expression : 3 * al + 6 * al+1 + 9 * al+2 .... rth term.

* 2 x y - update the value at index x to y times x.
Input

The first line of input contains 2 integers N and Q, 1 ≤ N, Q ≤ 10^5

Next line contains N integers of the array a1, a2, a3, ...aN,  - 10^6 ≤ ai ≤ 10^6,0 ≤ y ≤ 10.

Next Q lines contain queries in the format described above.
Output

For every query of type 1 output the required answer on a new line.
5 4
5 3 6 9 1
1 1 3
2 3 5
2 5 7
1 2 5
output
87
204
