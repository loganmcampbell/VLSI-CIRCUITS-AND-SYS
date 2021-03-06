#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <cctype>
#include <map>
#include <list>
#include <vector>
#include <climits>
using namespace std;
#define NINF INT_MIN
class AdjListNode

{

        int v;

        int weight;

    public:

        AdjListNode(int _v, int _w)

        {

            v = _v;

            weight = _w;

        }

        int getV()

        {

            return v;

        }

        int getWeight()

        {

            return weight;

        }

};

class graph
{
  int V;
   list<AdjListNode>  *adj;
  void topologicalSortUtil(int mod, bool visited[], stack<int>& Stack);


private:
    //map<int, vector<int> > graph;
    int modules;
public:

    // void constructG(int modules)
    // {
    //   for(int x = 0; x < modules +1; x++)
    //   {
    //     vector<int> v;
    //     graph[x] = v;
    //   }
    //   this->modules = modules;
    // }
    graph(int V);
    void topologicalSort();
    void addEdge(int module1,int module2,int weight);
    void addG(int v, int w);
    void longestPath(int s);


    // void printGraph()
    // {
    //   for (int x = 0; x < modules + 1; x++)
    //   {
    //     cout << "mod : " << x << " | ";
    //     while(!graph[x].empty())
    //     {
    //       cout << graph[x].back() << " ";
    //       graph[x].pop_back();
    //     }
    //     cout << endl;
    //
    //   }
    // }




};

// void graph::addG(int v, int w)
// {
//   adj[v].push_back(w);
// }

graph::graph(int V)
{
  this -> V = V;
  adj = new list<AdjListNode>[V];
}

void graph::addEdge(int module1 , int module2, int weight)
{

    //graph[module1].push_back(module2);
    AdjListNode node(module2,weight);
    adj[module2].push_back(node);

  }


  void graph::topologicalSortUtil(int v, bool visited[],
                                  stack<int> &Stack)
  {

      visited[v] = true;

      list<AdjListNode>::iterator i;
      for (i = adj[v].begin(); i != adj[v].end(); ++i)
      {
          AdjListNode node = *i;
          if (!visited[node.getV()])
              topologicalSortUtil(node.getV(), visited, Stack);
      }

      Stack.push(v);
  }

  void graph::topologicalSort()
  {
      stack<int> Stack;

      bool *visited = new bool[V];
      for (int i = 0; i < V; i++)
          visited[i] = false;

      for (int i = 0; i < V; i++)
        if (visited[i] == false)
          topologicalSortUtil(i, visited, Stack);

      while (Stack.empty() == false)
      {
          cout << Stack.top() << " ";
          Stack.pop();
      }
  }
  void graph::longestPath(int s)
  {
      stack<int> Stack;
      int dist[V];

      // Mark all the vertices as not visited
      bool* visited = new bool[V];
      for (int i = 0; i < V; i++)
          visited[i] = false;


      for (int i = 0; i < V; i++)
          if (visited[i] == false)
              topologicalSortUtil(i, visited, Stack);


      for (int i = 0; i < V; i++)
          dist[i] = NINF;
      dist[s] = 0;


      while (Stack.empty() == false) {

          int u = Stack.top();
          Stack.pop();

          list<AdjListNode>::iterator i;
          if (dist[u] != NINF) {
              for (i = adj[u].begin(); i != adj[u].end(); ++i)
                  if (dist[i->getV()] < dist[u] + i->getWeight())
                      dist[i->getV()] = dist[u] + i->getWeight();
          }
      }


      for (int i = 0; i < V; i++)
          (dist[i] == NINF) ? cout << "INF " : cout << dist[i] << " ";
  }


int linecount (string filename)
{
  int count = 0;  string lines;
  ifstream input;
  input.open(filename.c_str());
  while (std::getline(input,lines))
    {
      ++count;
    }
  input.close();
  count - 1;
  return count;
}
void ROF (vector<int> pV, int &mn, vector<int> nV, vector<int> &collect)
{
  //  [A]   [A]
  //(B X, B X)
  if (mn == 0)
  {

  }
  else
  {
    int PA;int NA;
    vector<int>table;
    int nummod = 8;
    for (int x =0; x < nummod; x++)
    {
      if (pV[x] == mn)
      {
        PA = x;
        //cout << "LOCATION OF mn is on PV = " << x << endl;
      }
      if (nV[x] == mn)
      {
        NA = x;
        //cout << "LOCATION OF mn is on NV = " << x << endl;
      }
    }
    //cout << "\tRIGHT :\t{ ";
    for (int B = 0; B < nummod; B++)
    {
      if ((B > NA))
      {
        table.push_back(nV[B]);
      }
      if ((B > PA))
      {
        table.push_back(pV[B]);
      }
    }

    for(int i =0; i < table.size(); i++)
    {
     for ( int j=i+1; j < table.size() ; j++ )
     {
      if (table[i] == table[j])
      {
        //cout << table[j] << " ";
        collect.push_back(table[i]);
      }
     }
    }
  }

  //cout << "}";
}
void LOF(vector<int> pV, int &mn, vector<int> nV, vector<int> &collect)
{
  // [A]   [A]
  // (X  B, X  B)
  if (mn == 0)
  {

  }
  else
  {
  int PA;int NA;
  vector<int>table;
  int nummod = 8;
  for (int x =0; x < nummod; x++)
  {
    if (pV[x] == mn)
    {
      PA = x;
    }
    if (nV[x] == mn)
    {
      NA = x;
    }
  }
 //cout << "\tLEFT :\t{ ";
  for (int B = 0; B < nummod; B++)
  {
    if ((B < NA))
    {
      //cout << "NV : " << nV[B] << endl;
      table.push_back(nV[B]);
    }
    if ((B < PA))
    {
      //cout << "PV : " << pV[B] << endl;
      table.push_back(pV[B]);
    }

  }

  for(int i = 0; i < table.size(); i++)
  {
   for ( int j=i+1; j < table.size() ; j++ )
   {
    if (table[i] == table[j])
    {
    //cout << table[j] << " ";
    collect.push_back(table[i]);
    }
   }
  }
  //cout << "}";

}
}
void AOF(vector<int> pV, int &mn, vector<int> nV,vector<int> &collect)
{
  // [A]      [A]
  // (X  B, B  X)
  int PA;int NA;
  vector<int>table;
  int nummod = 8;
  for (int x =0; x < nummod; x++)
  {
    if (pV[x] == mn)
    {
      PA = x;
    }
    if (nV[x] == mn)
    {
      NA = x;
    }
  }
  //cout << "\tABOVE :\t{ ";
  for (int B = 0; B < nummod; B++)
  {
    if ((B > NA))
    {
      //cout << "NV : " << nV[B] << endl;
      table.push_back(nV[B]);
    }
    if ((B < PA))
    {
      //cout << "PV : " << pV[B] << endl;
      table.push_back(pV[B]);
    }
  }

  for(int i = 0; i < table.size(); i++)
  {
   for ( int j=i+1; j < table.size() ; j++ )
   {
    if (table[i] == table[j])
    {
      //cout << table[j] << " ";
    collect.push_back(table[i]);

    }
   }
  }
 //cout << "}";

}
void BOF(vector<int> pV, int &mn, vector<int> nV,vector<int> &collect)
{
  //    [A] [A]
  // (B  X , X  B)
  int PA; int NA;
  vector<int>table;

  int nummod = 8;
  for (int x = 0; x < nummod; x++)
  {
    if (pV[x] == mn)
    {
      PA = x;
    }
    if (nV[x] == mn)
    {
      NA = x;
    }
  }

 //cout << "\tBELOW :\t{ ";
  for (int B = 0; B < nummod; B++)
  {

    if ((B < NA))
    {
      //cout << "NV : " << nV[B] << endl;
      table.push_back(nV[B]);
    }
    if ((B > PA))
    {
      //cout << "PV : " << pV[B] << endl;
      table.push_back(pV[B]);
    }
  }

  for(int i = 0; i < table.size(); i++)
  {
   for ( int j=i+1; j < table.size() ; j++ )
   {
    if (table[i] == table[j])
    {
      collect.push_back(table[i]);

    // cout << table[j] << " ";
    }
   }
  }
//cout << "}";
}
void read (string filename, string collect [])
{
  ifstream infile;
  infile.open(filename.c_str());
  if(infile.fail())
  {
    //cout << "Error Opening file!" << endl;
    exit(-1);
  }
  else
  {
    //cout << "SUCCESSFULLY OPENED" << endl;
  }
  string lines;
  for (int a = 1; a < linecount(filename) + 1; a++)
  {
    getline(infile, collect[a]);
  }
}

int main()
{
  ifstream infile;
  int width; int height;

  string filename;
  //cout << "Enter filename : \"filename.size\" to gather information: ";
  //cin  >> filename;
  filename = "Test.size";
  infile.open(filename.c_str());

  if(infile.fail())
  {
    cout << "Error Opening file!" << endl;
    exit(-1);
  }
  int modules = linecount(filename) + 1;
  ifstream file;
  string filename2;
  filename2 = "Test.sp";
  file.open(filename2.c_str());

  if(file.fail())
  {
    cout << "Error Opening file!" << endl;
    exit(-1);
  }
  //cout << "[WIDTH] : " << width << " [HEIGHT] : " << height << endl;
  int modulew [linecount(filename) + 1];  int moduleh [linecount(filename) + 1];

  int w; int h; int n = 1;
  while(infile >> w >> h)
  {
    modulew[n] = w;
    moduleh[n] = h;
    //cout << "MODULE [" << n << "] : " << w << " " << h;
    n++;
    //cout << endl;
  }
  string collect[linecount(filename2) + 1];
  read(filename2,collect);
  // graph gH;
  // graph gV;
  graph gH(modules);
  graph gV(modules);


  for (int x = 0; x < modules; x++)
  {
  string test = collect[1];
  //cout << endl;
  vector<int>evaluate1;
  vector<int>evaluate2;
  bool start = false; bool flip = true;
  // WE NEED TO USE POST EXPRESSION STRATEGY
	for (int position = 0; position < test.size(); position++)
  {
		if (test[position] != '\n' && test[position] != ' ' && test[position] != '\0')
		{
      if (test[position] == '+' || flip == true )
      {
        flip = true;
        if (isdigit(test[position]))
        {
          int convert = test[position];
          convert = convert - 48;
          evaluate1.push_back(convert);
        }
        else
          {
          }
      }
      if (test[position] == '-' || flip == false)
      {
        flip = false;
        if (isdigit(test[position]))
        {
          int convert = test[position];
          convert = convert - 48;
          evaluate2.push_back(convert);
        }
      }
    }
  }


    vector<int> collect1;
    vector<int> collect2;
    vector<int> collect3;
    vector<int> collect4;


      cout << "MODULE [" << x << "] : " << endl;
      ROF(evaluate1,x,evaluate2,collect1);
      LOF(evaluate1,x,evaluate2,collect2);
      AOF(evaluate1,x,evaluate2,collect3);
      BOF(evaluate1,x,evaluate2,collect4);
      int w = 0;
      int h = 0;

      if (collect1.empty())
      {
        if (x != 0)
        {
    //      gH.addG(x,modulew[x]);
          // cout << "HC1 : " << x << " " << modules << endl;

        //cout << "CONNECTED1" << endl;
        }
      }
      else
      {
        while(!collect1.empty())
        {
          //cout << "CONNECTED1" << endl;
          //cout << "H!C1 : " << x << " " << collect1.back() << endl;
          modulew[x] = w;
          gH.addEdge(x,collect1.back(),w);

          //cout << "CONNECTED1" << endl;

          collect1.pop_back();
          //cout << "CONNECTED1" << endl;

        }
      }



      if (collect2.empty())
      {
        if(x != 0)
          modulew[x] = w;
        gH.addEdge(0,x,w);

        // cout << "CONNECTED1" << endl;
      }


      if (collect3.empty())
      {
        //cout << "CONNECTED" << endl;
        if(x != 0)
          moduleh[x] = h;
          gV.addEdge(x,modules,h);


      }
      else
      {
        while(!collect3.empty())
        {
          moduleh[x] = h;
          gV.addEdge(x,collect3.back(),h);

          collect3.pop_back();

        }
      }

      if (collect4.empty())
      {
        if(x != 0)
        moduleh[x] = h;
        gV.addEdge(0,x,h);

      }

      int s = 0;


      //gH.weight(weight);

      collect1.clear();
      collect2.clear();
      collect3.clear();
      collect4.clear();
}
    cout << "V: " << endl;
  //    gV.topologicalSort();
      //gV.printGraph();
    cout << endl << "H: " << endl;
    //  gH.topologicalSort();
      //gH.printGraph();



      // for (int x = 1; x <= modules; x++)
      // {
      //   gH.addWeight(0,x,modulew[x]);
      //   gV.addWeight(0,x,moduleh[x]);
      // }
      //gH.longestPath(s);
      //gV.longestPath(s);
      // cout << "x" << endl;
      // gH.longestPath(s);
      // gV.longestPath(s);
      // cout << "K" << endl;

  return 0;
}
