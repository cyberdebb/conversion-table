#include "cypher.hpp"

Cypher::Cypher()
{
  m_code = NULL;
}

Cypher::Cypher(size_t code) : Cypher()
{
  this->m_code = new size_t(code);
  conv= new ConversionTable();
  conv->CreateConvTable(1);
}

void Cypher::NewConversionTable(size_t code)
{
  size_t num=0;
  size_t k=0;

  do{
    num+=code%10;
    code/=10;
    k++;
 }while(k<4);

  conv->CreateConvTable(num);
}

string Cypher::EncryptText(string input)
{
    string result;
    result= conv->EncrypFromTable(input);
    return result;
}

string Cypher::DecryptText(string input)
{
    string result;
    result = conv->DecrypFromTable(input);
    return result;
}

void Cypher::ShowMenu(size_t user)
{
  cout << "---------------------USER " << user << "-----------------------" << endl;
  cout << "Select an option:" << endl;
  cout << "1. Encrypt the message" << endl;
  cout << "2. Decrypt the message" << endl;
  cout << "3. Write a new message" << endl;
  cout << "4. Exit" << endl;
  cout << "--------------------------------------------------" << endl;
}

Cypher::~Cypher()
{
    //cout << "Destructor called" << endl;
    if(m_code) delete m_code;
    delete conv;
}
