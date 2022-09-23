#include "tree.hpp"
#include "compara.hpp"
using namespace std;

void
Picador (seiva palavra)
{


  ifstream leitor ("./src/input/arq.txt");

  if (leitor.is_open ())
    {

      while (!leitor.eof ())
	{

	  string nlinha = "";
	  string linha;
	  getline (leitor, linha);

	  contas (&palavra, linha);
 
	}

    }
  else
    {
      cout << "erro" << endl;
    }

  leitor.close ();
}


void
contas (seiva * palavra, string str)
{
  stringstream ss (str);
  string p;
  while (ss >> p)
    palavra->m[p]++;

}

void
MinMax (seiva * palavra)
{

  float min = 2200.0;
  float max = 0.0;
  int tamanho = 0;

  unordered_map < string, float >::iterator it;
  for (it = palavra->m.begin (); it != palavra->m.end (); it++)
    {
      if (it->second < min)
	{
	  min = it->second;
	}
      else if (it->second > max)
	{
	  max = it->second;
	}
      tamanho++;
    }

  palavra->Min = min;
  palavra->Max = max;
  palavra->Tam = tamanho;
}

void
HuffmanRP (seiva * palavra)
{

  unordered_map < string, float >::iterator it;
  for (it = palavra->m.begin (); it != palavra->m.end (); it++)
    {
       palavra->m.at(it->first) = it->second /(palavra->Max - palavra-> Min);
    }
}
