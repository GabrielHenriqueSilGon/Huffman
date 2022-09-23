#include "tree.hpp"
#include "compara.hpp"

using namespace std;

int
main ()
{

  seiva s;

  string frase =
    {
"tres pratos de trigo para tres tigres tristes com tres graos de trigo cada" };

  contas (&s, frase);

  cout << "\nContagem de palavras:" << endl;

  unordered_map < string, float >::iterator it;
  for (it = s.m.begin (); it != s.m.end (); it++)
    cout << it->first << ": " << it->second << endl;

  MinMax (&s);
  cout << "\nMin: " << s.Min << endl;
  cout << "Max: " << s.Max << endl;
  cout << "Tamanho: " << s.Tam << endl;

  HuffmanRP (&s);

  cout << "\nContabilizacao normalizada:" << endl;
  for (it = s.m.begin (); it != s.m.end (); it++)
    cout << it->first << " - " << it->second << endl;
    
  cout << "\n\nCodificando com Huffman, fica:\n";

  HuffmanCodes(&s);

  return 0;
}


