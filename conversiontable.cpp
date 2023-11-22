#include "conversiontable.hpp"

ConversionTable::ConversionTable() {}

void ConversionTable::CreateConvTable(int disp)
{
    for(size_t i=0; i<256; i++)
    {
        pair<char,char> p;
        p.first = i;
        p.second = p.first + disp;
        m_table.push_back(p);
    }
}

string ConversionTable::EncrypFromTable(string input)
{
string result;

    for(size_t i=0; i<input.length(); i++)
    {
        char chi = input.at(i); //input character
        char cho = m_table.at(chi).second;  //output character
        result += cho;
    }
    return result;
}

string ConversionTable::DecrypFromTable(string input)
{
    string result;

    for(size_t i=0; i<input.length(); i++)
    {
        char chi = input.at(i); //input character

        for(size_t j=0; j<m_table.size(); j++)
        {
            if(chi == m_table.at(j).second)
            {
                result += m_table.at(j).first;
                break;
            }
        }
    }

    return result;
}

ConversionTable::~ConversionTable() {}
