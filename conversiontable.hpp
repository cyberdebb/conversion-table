#ifndef CONVERSIONTABLE_HPP
#define CONVERSIONTABLE_HPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ConversionTable
{
private:
  vector< pair<char,char >> m_table;

public:
  ConversionTable();
  void CreateConvTable(int disp);

  string EncrypFromTable(string input);
  string DecrypFromTable(string input);

  ~ConversionTable();
};

#endif
