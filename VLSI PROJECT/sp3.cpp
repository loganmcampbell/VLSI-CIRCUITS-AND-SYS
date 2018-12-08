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
  cout << "\tRIGHT :\t{ ";
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
      cout << table[j] << " ";
      collect.push_back(table[i]);
    }
   }
  }
  cout << "}";
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
 cout << "\tLEFT :\t{ ";
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
    cout << table[j] << " ";
    collect.push_back(table[i]);
    }
   }
  }
  cout << "}";

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
  cout << "\tABOVE :\t{ ";
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
      cout << table[j] << " ";
    collect.push_back(table[i]);

    }
   }
  }
 cout << "}";

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

 cout << "\tBELOW :\t{ ";
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

     cout << table[j] << " ";
    }
   }
  }
cout << "}";
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
  //cout << "Enter filename : \"filename.sp\" to gather information: ";
  //cin  >> filename2;
  filename2 = "Test.sp";
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
    //cout << "MODULE [" << n << "] : " << w << " " << h;
    n++;
    //cout << endl;
  }
  string collect[linecount(filename2) + 1];
  read(filename2,collect);

  for (int x = 1; x <= modules; x++)
  {
  string test = collect[1];
  //cout << test << endl;
  cout << endl;
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
          //cout << "!POSTIVE! : " << test[position] <<  endl;
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
          //cout << "!NEGATIVE! : " << test[position] <<  endl;
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
    //Graph g(modules + 2);
    int s = 1;
    int t = 2;

    // for (int x = 1; x <= modules; x++)
    // {
      cout << "MODULE [" << x << "] : " << endl;
      ROF(evaluate1,x,evaluate2,collect1);
      LOF(evaluate1,x,evaluate2,collect2);
      AOF(evaluate1,x,evaluate2,collect3);
      BOF(evaluate1,x,evaluate2,collect4);
      //cout << "here " << endl;


      for(int y = 1; y <= modules; y++)
      {
      if (collect1.empty())
      {
        //cout << "CONNECTED" << endl;
        //g.addEdge(s,x);
      }
      else
      {
        while(!collect1.empty())
        {
          //cout << "CONNECTED1" << endl;

          //g.addEdge(collect1.back(),x);
          //cout << "CONNECTED1" << endl;

          collect1.pop_back();
          //cout << "CONNECTED1" << endl;

        }
      }
      collect1.clear();


      if (collect2.empty())
      {
        //cout << "CONNECTED2" << endl;
        //g.addEdge(x,t);
      }
      collect2.clear();

      for(int i = 1; i <= modules; i++)
      {
        //g.printAllPaths(s,i);
      }

      }


      if (collect3.empty())
      {
      //  cout << "CONNECTED" << endl;
      //  g.addEdge(x,t);
      }
      collect3.clear();



      if (collect4.empty())
      {
        //cout << "CONNECTED" << endl;
        //g.addEdge(s,x);
      }
      else
      {
        while(!collect4.empty())
        {
          //cout << "CONNECTED" << endl;
          //g.addEdge(collect4.back(),x);
          collect4.pop_back();
        }
      }
      collect4.clear();


    for(int i = 1; i <= modules; i++)
    {
      //g.printAllPaths(s,i);
    }

}
// for(int k = 1; k < modules; k++)
//     {
// 	     cout << "Module: " << k << " Width: " << modulew[k] << " Height: " << moduleh[k] << " Location: "  << endl;
//     }

  return 0;
}
