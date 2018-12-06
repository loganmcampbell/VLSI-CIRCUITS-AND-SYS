#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

void open (string filename)
{
  ifstream infile;
  infile.open(filename.c_str());
  if(infile.fail())
  {
    cout << "Error Opening file!" << endl;
    exit(-1);
  }
  else
  {
    cout << "SUCCESSFULLY OPENED" << endl;

  }

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
string obtain (string filename, string collect[], string &initial)
{
  ifstream input;
  input.open(filename.c_str());
  getline(input,initial);
  //cout << "START : " << initial;
  int iterator = 0;
  while (input.good()) //infile.good()
  {
    string capture;
    getline(input,capture);
    collect[iterator] = capture;
    //cout <<"captured : " << iterator << endl;
    iterator++;

  }
  input.close();
}
void print (string array[], int size)
{
  for (int x = 0; x < size; x++)
  {
    cout << array[x] << endl;
  }
}

int main()
{
  string filename;
  cout << "Enter filename : \"filename.pe\" to gather information: ";
  cin  >> filename;
  open(filename);
  string initial;
  string collect[linecount(filename)-1];
  obtain(filename,collect,initial);

  cout << initial << endl;
  return 0;
}
