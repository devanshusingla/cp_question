/************************************************************
/  AUTHOR :  DEVANSHU SINGLA                                /
/  NICK :  DSINGLA                                          /
/  INSTITUTE :  IITK                                        /
************************************************************/
//                     TEMPLATE                            //

#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define MOD 1000000007
#define For(i, n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define F first
#define S second
#define MAX(x, y) (x) > (y) ? (x) : (y)
#define MIN(x, y) (x) < (y) ? (x) : (y)

using namespace std ;

struct Graph { 
    int V; 
    set<int>* adjList; 
}; 
 
struct tunnel {
	long x;
	long y;
};

struct branch {
	long x;
	long y;
	long z;
};

Graph* createGraph(int V) 
{ 
    Graph* graph = new Graph; 
    graph->V = V; 
   
    graph->adjList = new set<int>[V]; 
  
    return graph; 
} 
  
void addEdge(Graph* graph, int src, int dest) 
{ 
    graph->adjList[src].insert(dest); 
  
    graph->adjList[dest].insert(src); 
} 
  
void printGraph(Graph* graph) 
{ 
    for (int i = 0; i < graph->V; ++i) { 
        set<int> lst = graph->adjList[i]; 
        cout << endl << "Adjacency list of vertex "
             << i << endl; 
  
        for (auto itr = lst.begin(); itr != lst.end(); ++itr) 
            cout << *itr << " "; 
        cout << endl; 
    } 
}

template<typename T>
long djkstra(struct Graph *g, T **data){

	vector<pair<int,long>> distance(g->V,pair<int,long>{0,LONG_MAX}) ;
	distance[0].second = 0 ;
	vector<pair<int,long>> np ;
	np.push_back(pair<int,long> {0, 0}) ;
	int v = g->V ;

	int min_found = 0;
	long min_dis;
	while(!min_found){
		pair<int,long> min = np[0];
		int min_index = 0 ;
		//cout<<"\n points in contest\n" ;
		for(int i=0; i<np.size(); i++){
			if(min.second > np[i].second){
				min = np[i] ;
				min_index = i;
			}
			//cout<<"\n point: "<<np[i].first<<" distance: "<<np[i].second ;
		}
		//cout<<"\n\n min value is of\n point: "<<min.first<<" distance: "<<min.second ;
		//cout<<endl<<endl ;

		if(min.first == v-1){
			//cout<<"\nfinally found minimun distance: "<<min.second ;
			return min.second ;
		}

		distance[min.first].first = 1;
		np.erase(np.begin() + min_index) ;

		for(auto itr:(g->adjList)[min.first]){
			if(distance[itr].first){
				//cout<<"point: "<<distance[itr].first<<" has been traversed\n" ;
				continue ;
			}
			int flag=1 ;
			for(auto i=np.begin(); i!=np.end(); i++){
				//cout<<"\n np_first: "<<(*i).first<<" np_second: "<<(*i).second ;
				//cout<<"\nexpected distance: "<<min.second + Distance(*(data[itr]), *(data[min.first]))<<" of point: "<<itr ;
				//cout<<"\ndistance between point: "<<itr<<" and point: "<<min.first<<" is "<<Distance(*(data[itr]), *(data[min.first])) ;
				if((*i).first == itr){
					//cout<<"I found you\n" ;
					(*i).second = MIN((*i).second, min.second + Distance(*(data[itr]), *(data[min.first]))) ;
					flag = 0;
					break ;
				}
			}

			if(flag){
				//cout<<"I am here" ;
				np.push_back(pair<int, long> {itr, min.second + Distance(*(data[itr]), *(data[min.first]))}) ;
			}
		}
	}

	return min_dis ;
	return 0;
}

long Distance(tunnel t1, tunnel t2){
	return (abs(t1.x - t2.x) + abs(t1.y - t2.y)) ;
}

long Distance(branch b1, branch b2){
	//cout<<"\ndistance of branches called" ;
	return (abs(b1.x - b2.x) + abs(b1.y - b2.y) + abs(b1.z - b2.z)) ;
}

void solve(){
	int n1, n2, p1, p2, e1, e2;
	long t1, t2, x, y, z, d1, d2;
	cin>>n1>>n2;
	cin>>t1>>t2;
	cin>>e1>>e2 ;
	//cout<<t1<<t2 ;
	struct Graph *g1 = createGraph(n1) ;
	struct tunnel *t[n1] ;
	for(int i=0; i<n1; i++){
		t[i] = new struct tunnel ;
	}
	struct Graph *g2 = createGraph(n2) ;
	struct branch *b[n2] ;
	for(int i=0; i<n2; i++){
		b[i] = new struct branch ;
	}

	for(int i=0; i<n1; i++){
		cin>>t[i]->x ;
		//cout<<"\nx: "<<t[i]->x ;
		cin>>t[i]->y ;
	}
	for(int i=0; i<n2; i++){
		cin>>b[i]->x ;
		//cout<<b[i]->x ;
		cin>>b[i]->y ;
		cin>>b[i]->z ;
	}
	for(int i=0; i<e1; i++){
		cin>>p1 ;
		cin>>p2 ;
		addEdge(g1, p1, p2) ;
	}
	for(int i=0; i<e2; i++){
		cin>>p1 ;
		cin>>p2 ;
		addEdge(g2, p1, p2) ;
	}

	//printGraph(g1) ;
	//printGraph(g2) ;
	//cout<<"\n\n*******  graph1  *******\n\n" ;
	d1 = djkstra(g1, t) ;
	//cout<<"\n\n*******  graph2  *******\n\n" ;
	d2 = djkstra(g2, b) ;
	//cout<<"\n\nd1: "<<d1 ;
	//cout<<"\nd2: "<<d2 ;

	ll diff = (ll)d1 * (ll)t1 - (ll)d2 * (ll)t2 ;

	if(diff>0) cout<<"lucario as always" ;
	else if(diff<0) cout<<"dugtrio got better luck today" ;
	else cout<<"not in mood to bet" ;
}

int main(){
	#ifndef ONLINE_JUDGE 
  
    // For getting input from input.txt file 
    freopen("input.txt", "r", stdin); 
  
    // Printing the Output to output.txt file 
    freopen("output.txt", "w", stdout); 
  
	#endif

	//ios_base::sync_with_stdio(false) ;

	//cout<<"hello" ;
	solve();	
}

/*# cp_question
first self made cp question for pclub secy test

#2                              Earth vs Fighting

There is tournament of pokemon to test whether ground pokemon are faster or fighting type pokemons. In the tournament, dugtrio is representing ground pokemon and lucario is representing fighting type pokemons. Both pokemons start at their initial position t<sub>0</sub> and b<sub>0</sub>.Dugtrio and Lucario take time T<sub>1</sub> and T<sub>2</sub> respectively. Lucario has to move on pillars, with top of pillar i represented by b<sub>i</sub>. Dugtrio has to go through tunnels linked at some places, which each such place i represented by t<sub>i</sub>. There are n<sub>2</sub> pillars and lucario has to reach to pillar n<sub>2</sub>-1 to win. The pillars between which Lucario can jump are p1<sub>i</sub> and p2<sub>i</sub> and number of such possible jumps are m<sub>1</sub>. There are n<sub>1</sub> interlinks between tunnels and dugtrio has to reach end of this tunnel maze which is at n<sub>1</sub>-1. The tunnels are joined by a<sub>i</sub>. You have to place your bet on one pokemon. On which pokemon will you place your bet to become richer?

Values of b<sub>i</sub> and t<sub>j</sub> are i and j respectively and i and j belong to (0, n<sub>1</sub>) and (0, n<sub>2</sub>) respectively.

#3 INPUT

First line contains space separated n<sub>1</sub> and n<sub>2</sub>.
Followed by space separated m<sub>1</sub> and m<sub>2</sub>.
Followed by space separated T<sub>1</sub> and T<sub>2</sub>.
Following n<sub>1</sub> lines contain x and y coordinates separated by spaces.
Following n<sub>2</sub> lines contain x, y and z coordinates separated by spaces.
Following m<sub>1</sub> lines contain space separated p<sub>i</sub> and p<sub>j</sub>
Following m<sub>2</sub> lines contain space separated a<sub>i</sub> and a<sub>j</sub>
*/