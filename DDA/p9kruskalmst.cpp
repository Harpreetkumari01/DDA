#include<iostream>
using namespace std;

class edge
{
	public:
	int v1;
	int v2;
	int w;	
};

class node
{
	public:
	int ele;
	node *next;
	node()
	{
		next=NULL;	
	}
		
};

class list
{
	public:
	node *head;
	node *tail;
	list()
	{
		head=tail=0;
	}	
};

node *vlist;   //store vertex names
list *comp;
void create_comp(int v)
{
	comp=new list[v+1];
	for(int i=1;i<=v;i++)
	{
		comp[i].head=comp[i].tail=&vlist[i];
	}
}

void sort(edge *E,int e)
{
	int j;
	edge temp;
	for(int i=2;i<=e;i++)         //insertion sort
	{
		j=i-1;
		temp=E[i];
		while(j>0&&E[j].w>temp.w)
		{
			E[j+1].v1=E[j].v1;
			E[j+1].v2=E[j].v2;
			E[j+1].w=E[j].w;
			j--;
		}
		E[j+1]=temp;
	}
}

void kruskel(edge *E,int e,int v)
{
	node* h2;
	create_comp(v);  //creating v disjoint sets (i.e. lists) for each vertex
	sort(E,e);
	//now E[] stores edges in sorted order of their edge weights
	cout<<"\nselected edges are: ";
	for(int i=1;i<=e;i++)
	{	//if the two vertices belong to same set do not include the edge as it will form a cycle
		if((comp[E[i].v1].head!=comp[E[i].v2].head)&&(comp[E[i].v1].tail!=comp[E[i].v2].tail)) //check for cycle
		{   //since it will not form a cycle add the edge
			h2=comp[E[i].v2].head;
			//joining two lists v1 and v2 (i.e. adding edge from v1 and v2)
			//first doing changes in v1
			comp[E[i].v1].tail->next=h2;            
			comp[E[i].v1].tail=comp[E[i].v2].tail;
			//then doing changes for v2
			while(h2!=NULL)                    
			{
				comp[h2->ele]=comp[E[i].v1];
				h2=h2->next;
			}
			//now printing the selected edge
			cout<<"("<<E[i].v1<<" , "<<E[i].v2<<") ";
		}
	}
}

int main()
{
	edge *E;   //stores edges information
	int v,e;   //no. of vertices and edges
	cout<<"\nenter no. of vertices: ";
	cin>>v;
	cout<<"\nenter no. of edges: ";
	cin>>e;
	vlist=new node[v+1];
	for(int i=1;i<=v;i++)     
	{
		vlist[i].ele=i;
	}
	E = new edge[e+1];
	cout<<"\nenter edges in format v1 v2 and weight";
	for(int i=1;i<=e;i++)
	{
		cout<<"\nenter edge no"<<i<<": ";
		cin>>E[i].v1>>E[i].v2>>E[i].w;
	}
	kruskel(E,e,v);
}
