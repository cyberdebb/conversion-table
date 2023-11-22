#ifndef CYPHER_HPP
#define CYPHER_HPP

#include "conversiontable.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Cypher
{
private:
  size_t *m_code;
  ConversionTable *conv = new ConversionTable();

public:
  Cypher();
  Cypher(size_t code);
  void NewConversionTable(size_t code);
  string EncryptText(string input);
  string DecryptText(string input);
  void ShowMenu(size_t user);

  ~Cypher();
};

#endif
