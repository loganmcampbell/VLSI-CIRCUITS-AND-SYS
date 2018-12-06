#include<iostream>
#include<fstream>
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
void read (string filename,string collect[])
{
  ifstream infile;
  infile.open(filename.c_str());
  string line; int x = 0;
  if(infile.fail())
  {
    cout << "Error Opening file!" << endl;
    exit(-1);
  }
  else
  {
    for (int a = 0; a < linecount(filename); a++)
    {
      getline(infile,collect[a]);
    }
  }


}

int main()
{
  string filename;
  cout << "Enter filename : \"filename.pe\" to gather information: ";
  cin  >> filename;
  int size = linecount(filename);
  string obtain [size];
  read(filename,obtain);
  for(int x = 0; x < size; x ++)
  {
    cout << obtain[x] << endl;
  }

}
