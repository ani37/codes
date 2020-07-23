
#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define MX 501
#define BILLION  1000000000L;
struct timespec start, stop;
double accum;
int N,E; // no of vertices
int graph[MX][MX],edge[MX*MX][2]; // adj matrix and edges
// this method returns a minimum distance for the
// vertex which is not included in set.
int Bellman_Ford(int S){
    int i,u,v,k,distance[MX],par[MX],flag=1;
    // Initialize distance of all vertices as infinite.
    for(i=0;i<N;i++){
        distance[i] = INF , par[i] = -1 ;
    }
    distance[S-1]=0 ;
    // Relax all edges |N| - 1 times. A simple
    // shortest path from src to any other
    // vertex can have at-most |N| - 1 edges
    for(i=0;i<N-1;i++){
         for(k=0;k<E;k++){
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+graph[u][v] < distance[v])
                distance[v] = distance[u] + graph[u][v] , par[v]=u ;
         }
    }
    // check for negative-weight cycles.
    for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+graph[u][v] < distance[v])
                flag = 0 ;
        }
        if(flag){
          //  cout<<"Vertex\t\tDistance from source"<<'\n';
           
        }
        return flag;
}
void solve(){   
     //input
     int i,j;
    // printf("BELLMAN FORD\n");
    // printf("Enter no. of vertices:\n");
    scanf("%d",&N);
 //   printf("Enter graph in matrix form:\n");
    for(i=0;i<N;i++)
         for(j=0;j<N;j++){
            scanf("%d",&graph[i][j]);
            if(graph[i][j]!=0)
                edge[E][0]=i,edge[E++][1]=j;
        }
     //start timer
    if( clock_gettime( CLOCK_REALTIME, &start) == -1 ) {
      perror( "clock gettime" );
      return ;
    }
     // Algorithm
    if(Bellman_Ford(1)){
    	;
    } // keeping source as 1
    //     printf("\nNo negative weight cycle\n");
    // else printf("\nNegative weight cycle exists\n");
    // end timer
    if( clock_gettime( CLOCK_REALTIME, &stop) == -1 ) {
          perror( "clock gettime" );
          return ;
        }
    //time difference
    accum = ( stop.tv_sec - start.tv_sec ) + 
     (double)( stop.tv_nsec - start.tv_nsec )/ (double)BILLION;
     cout << setprecision(10) << fixed << accum << '\n';
}


signed main(){

 int T;cin >> T;while (T--)
 solve();
 return 0;
}




