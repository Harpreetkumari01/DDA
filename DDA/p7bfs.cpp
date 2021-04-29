#include <iostream>
#include<queue>
using namespace std;

template<class T>
class Node
{
	public:
		T elem;
		Node<T>* next;
			
		Node()
		{
			elem=0;
			next=NULL;
		}
		
		Node(T elem,Node<T>* next=NULL)
		{
			this->elem=elem;
			this->next=next;
		}
};

template<class T>
class AjList : protected Node<T>
{
	public:
		Node<T> *head;
		Node<T> *tail;
		
	public:
		AjList();
		~AjList();
		bool empty() const;
		int size();
		const T& front() const;
		void addFront(const T& e);
		void addToTail(const T& e);
		void removeFront();
		void print();
};

template<class T>
AjList<T>::AjList() // constructor
 {
 	head=NULL;
 	tail=NULL;	
 }

template<class T>
AjList<T>::~AjList() // destructor
{ 
	while (head!=NULL) 
		removeFront(); 
}

template<class T>
bool AjList<T>::empty() const 
{ 
	return head == NULL;
}

template<class T>
const T& AjList<T>::front() const // get front element
{ 
	return head->elem; 
}

template<class T>
int AjList<T>::size()
{
	int s=0;
	Node<T>* temp=head;
	while(temp!=NULL)
	{
		s++;
		temp=temp->next;
	}
	return s;
}

template<class T>
void AjList<T>::addFront(const T& e) 
{
	if(head==NULL)   
	{
		head=tail=new Node<T>(e);
	}
	else
	{
		head=new Node<T>(e,head);
	}
}

template<class T>
void AjList<T>::addToTail(const T& e) 
{
	if(head==NULL&&tail==NULL)   //NO element
	{
		head=tail=new Node<T>(e);
	}
	else
	{
		tail->next=new Node<T>(e,NULL);
		tail=tail->next;
	}
}

template<class T>
void AjList<T>::removeFront() 
{	
	 if(head==NULL)
	 {
	 	cout<<"\nError:There is no element in the list to remove...";
	 	return;
	 }

	Node<T>* temp=head;
	head=head->next;
	
	if(head==NULL)  //One element
	{
		tail=NULL;
	}
	delete temp;
	 
	
}

template<class T>
void AjList<T>::print()
{
	Node<T>* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->elem<<"   ";
		temp=temp->next;
	}
}

template<class T>
class Graph 
{
  int numVertices;
  AjList<int>* adjLists;
  bool* visited;

   public:
  Graph(int vertices);
  void addEdgeDir(int src, int dest);
  void addEdgeUndir(int src, int dest);
  void BFS(int startVertex);
  void printList(int src);
};


template<class T>
Graph<T>::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new AjList<T>[vertices];
}

template<class T>
void Graph<T>::addEdgeUndir(int src, int dest) 
{
  adjLists[src].addToTail(dest);
  adjLists[dest].addToTail(src);
}

template<class T>
void Graph<T>::addEdgeDir(int src, int dest) 
{
  adjLists[src].addToTail(dest);
}

template<class T>
void Graph<T>::printList(int src)
{
	adjLists[src].print();
}

template<class T>
void Graph<T>::BFS(int startVertex) 
{
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
  {
  	visited[i] = false;
  }
    
	queue<int> my_queue;
	my_queue.push(startVertex);   //add start to the search
	Node<T>* temp;

  while (!my_queue.empty()) 
  {
    int currVertex = my_queue.front();
    temp=adjLists[currVertex].head;
    my_queue.pop();                   //pull a node

	if(!visited[currVertex])      //process if not seen
    {
    	visited[currVertex] = true;
        cout<<currVertex<<" ";
	}

    for (int i =1; i <= adjLists[currVertex].size(); ++i)    //push all unseen children
	{
      int adjVertex = temp->elem;

      if (!visited[adjVertex]) 
	  {
        my_queue.push(adjVertex);
      }
      temp=temp->next;
    }
  }
}

int main() 
{
  int vertices;
  cout<<"Enter the total number of vertices in the graph: ";
  cin>>vertices;
  
  Graph<int> g(vertices);
  
  int edge;
  cout<<"\nEnter the number of edges in the graph: ";
  cin>>edge;
  
  char directed;
  cout<<"\ngraph is directed or not(y/n): ";
  cin>>directed;
  
  int start,end;
  for(int i=1;i<=edge;i++)
  {
  	cout<<"\nFor Edge "<<i<<" : ";
  	cout<<"\nStart vertex(0 to "<<vertices-1<<"): ";
  	cin>>start;
  	cout<<"\nEnd vertex(0 to "<<vertices-1<<" ): ";
  	cin>>end;
  	if(directed=='n'||'N')
  		g.addEdgeUndir(start,end);
  	if(directed=='y'||'Y')
	    g.addEdgeDir(start,end);		
  }
  
  for(int i=0;i<vertices;i++)
  {
  	cout<<"\n"<<i<<"->";
  	g.printList(i);
  }
  int source;
  cout<<"\nEnter the source vertex: ";
  cin>>source;
  g.BFS(source);

  return 0;
}
