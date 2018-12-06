#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <stack>
#include <vector>
using namespace std;


void ROF(vector<int> pV, int &mn, vector<int> nV)
{
  //(B A, B A)
  int B1; int A1; int B2; int A2;
  // num modules or size of vector
  int nummod = 8;
  for (int x =0; x < nummod; x++)
  {
    if (pV[x] == mn)
    {
      B1 = x;
      //cout << "LOCATION OF mn is on PV = " << x << endl;
    }
    if (nV[x] == mn)
    {
      B2 = x;
      //cout << "LOCATION OF mn is on NV = " << x << endl;
    }
  }
  cout << "\tRIGHT :\t{ ";
  for (int x = 0; x < nummod; x++)
  {
    if ( ((x > B1) && (x > B2)) && x != pV[x])
    {
       cout << pV[x] << " ";
    }

  }
  cout << "}";
}

void LOF(vector<int> pV, int &mn, vector<int> nV)
{
  // AB, AB
  int B1; int A1; int B2; int A2;
  // num modules or size of vector
  int nummod = 8;
  for (int x =0; x < nummod; x++)
  {
    if (pV[x] == mn)
    {
      B1 = x;
      //cout << "LOCATION OF mn is on PV = " << x << endl;
    }
    if (nV[x] == mn)
    {
      B2 = x;
      //cout << "LOCATION OF mn is on NV = " << x << endl;
    }
  }
  cout << "\tLEFT :\t{ ";
  for (int x = 0; x < nummod; x++)
  {
    if ( ((x < B1) && (x < B2)) && x != pV[x])
    {
       cout << pV[x] << " ";
    }

  }
  cout << "}";
}

void AOF(vector<int> pV, int &mn, vector<int> nV)
{
  // AB BA
  int B1; int A1; int B2; int A2;
  // num modules or size of vector
  int nummod = 8;
  for (int x =0; x < nummod; x++)
  {
    if (pV[x] == mn)
    {
      B1 = x;
      //cout << "LOCATION OF mn is on PV = " << x << endl;
    }
    if (nV[x] == mn)
    {
      B2 = x;
      //cout << "LOCATION OF mn is on NV = " << x << endl;
    }
  }
  cout << "\tABOVE :\t{ ";
  for (int x = 0; x < nummod; x++)
  {
    if ( ((x < B1) && (x > B2)) && x != pV[x])
    {
       cout << pV[x] << " ";
    }

  }
  cout << "}";
}

void BOF(vector<int> pV, int &mn, vector<int> nV)
{
  // AB BA
  int B1; int A1; int B2; int A2;
  // num modules or size of vector
  int nummod = 8;
  for (int x =0; x < nummod; x++)
  {
    if (pV[x] == mn)
    {
      B1 = x;
      //cout << "LOCATION OF mn is on PV = " << x << endl;
    }
    if (nV[x] == mn)
    {
      B2 = x;
      //cout << "LOCATION OF mn is on NV = " << x << endl;
    }
  }
  cout << "\tBELOW :\t{ ";
  for (int x = 0; x < nummod; x++)
  {
    if ( ((B1 < x) && (B2 > x)) && x != pV[x])
    {
       cout << pV[x] << " ";
    }

  }
  cout << "}";

}




int main()
{
  string test = "+1 7 4 5 2 6 3 8 -8 4 7 2 5 3 6 1\0";
	vector<int> test1;
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

    int modules = 8;
    // use reference on parameter mn
    for (int x = 1; x <= modules; x++)
    {
      cout << "MODULE [" << x << "] " << endl;
      ROF(evaluate1,x,evaluate2);
      LOF(evaluate1,x,evaluate2);
      AOF(evaluate1,x,evaluate2);
      BOF(evaluate1,x,evaluate2);

      cout << endl; cout << endl;
    }


  return 0;
}
