#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <stack>
#include <vector>
using namespace std;

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
// A directed graph using adjacency list representation
class Graph
{
    int V; // No. of vertices in graph
    vector<int> *adj; // Pointer to an array containing adjacency lists
    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int , int , bool [], int [], int &);

public:
    Graph(int V); // Constructor
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add v to u’s list.
}

// Prints all paths from 's' to 'd'
void Graph::printAllPaths(int s, int d)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];

    // Create an array to store paths
    int *path = new int[V];
    int path_index = 0; // Initialize path[] as empty
    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index);
}


void Graph::printAllPathsUtil(int u, int d, bool visited[],
                            int path[], int &path_index)
{
    // Mark the current node and store it in path[]
    int sum;
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    // If current vertex is same as destination, then print
    // current path[]
    if (u == d)
    {
        for (int i = 0; i<path_index; i++)
        {
            cout << path[i] << " ";
            sum += path[i];
        }

        sum = sum - 3;
    //    if(sum <= 0)
      //    cout << '0';
  //      else
      //    cout << "SUM : " << sum << endl;

        cout << endl;
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        vector<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index);
    }

    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}

void ROF (vector<int> pV, int &mn, vector<int> nV, vector<int> &collect)
{
  //  [A]   [A]
  //(B X, B X)
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
//  cout << "}";
}

void LOF(vector<int> pV, int &mn, vector<int> nV, vector<int> &collect)
{
  // [A]   [A]
  // (X  B, X  B)
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
//  cout << "\tLEFT :\t{ ";
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
    //  cout << table[j] << " ";
    collect.push_back(table[i]);

    }
   }
  }
//  cout << "}";

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
    //  cout << table[j] << " ";
    collect.push_back(table[i]);

    }
   }
  }
//  cout << "}";

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

//  cout << "\tBELOW :\t{ ";
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

    //  cout << table[j] << " ";
    }
   }
  }
//  cout << "}";

}



// string obtain (string filename, string collect[])
// {
//   ifstream input;
//   input.open(filename.c_str());
//   //cout << "START : " << initial;
//   int iterator = 0;
//   while (input.good()) //infile.good()
//   {
//     string capture;
//     getline(input,capture);
//     collect[iterator] = capture;
//     //cout <<"captured : " << iterator << endl;
//     iterator++;
//
//   }
//   input.close();
// }
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
  cout << "Enter filename : \"filename.size\" to gather information: ";
  cin  >> filename;
  infile.open(filename.c_str());

  if(infile.fail())
  {
    cout << "Error Opening file!" << endl;
    exit(-1);
  }
  int modules = linecount(filename) + 1;

  ifstream file;
  string filename2;
  cout << "Enter filename : \"filename.sp\" to gather information: ";
  cin  >> filename2;
  file.open(filename2.c_str());

  if(file.fail())
  {
    cout << "Error Opening file!" << endl;
    exit(-1);
  }

  //infile >> width;
  //infile >> height;
  //cout << "[WIDTH] : " << width << " [HEIGHT] : " << height << endl;
  int modulew [linecount(filename) + 1];  int moduleh [linecount(filename) + 1];

  int w; int h; int n = 1;
  while(infile >> w >> h)
  {
    modulew[n] = w;
    moduleh[n] = h;
    cout << "MODULE [" << n << "] : " << w << " " << h;
    n++;
    cout << endl;
  }
  string collect[linecount(filename2) + 1];
  read(filename2,collect);

  //string test = "+1 7 4 5 2 6 3 8 -8 4 7 2 5 3 6 1\0";

  for (int x = 1; x <= modules; x++)
  {
  string test = collect[x];
  cout << test << endl;
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
          cout << "!POSTIVE! : " << test[position] <<  endl;
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
          cout << "!NEGATIVE! : " << test[position] <<  endl;
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
    Graph g(modules + 2);
    int s = 1;
    int t = 2;

    // for (int x = 1; x <= modules; x++)
    // {
      cout << "MODULE [" << x << "] : " << endl;
      ROF(evaluate1,x,evaluate2,collect1);
      LOF(evaluate1,x,evaluate2,collect2);
      AOF(evaluate1,x,evaluate2,collect3);
      BOF(evaluate1,x,evaluate2,collect4);


      for(int y = 1; y <= modules; y++)
      {
      if (collect1.empty())
      {
        //cout << "CONNECTED" << endl;
        g.addEdge(s,x);
      }
      else
      {
        while(!collect1.empty())
        {
        //  cout << "CONNECTED" << endl;
          g.addEdge(collect1.back(),x);
          collect1.pop_back();
        }
      }
      collect1.clear();


      if (collect2.empty())
      {
      //  cout << "CONNECTED" << endl;
        g.addEdge(x,t);
      }
      collect2.clear();

      for(int i = 1; i <= modules; i++)
      {
        g.printAllPaths(s,i);
      }

      }


      if (collect3.empty())
      {
      //  cout << "CONNECTED" << endl;
        g.addEdge(x,t);
      }
      collect3.clear();



      if (collect4.empty())
      {
        //cout << "CONNECTED" << endl;
        g.addEdge(s,x);
      }
      else
      {
        while(!collect4.empty())
        {
          //cout << "CONNECTED" << endl;
          g.addEdge(collect4.back(),x);
          collect4.pop_back();
        }
      }
      collect4.clear();


    for(int i = 1; i <= modules; i++)
    {
      g.printAllPaths(s,i);
    }

}
for(int k = 1; k < modules; k++)
    {
	     cout << "Module: " << k << " Width: " << modulew[k] << " Height: " << moduleh[k] << " Location: "  << endl;
    }

  return 0;
}
