#include "cypher.hpp"

int main()
{
  size_t user=0;
  char ch;

  loop:
  bool crypt=false;

  cout<<"WELCOME TO UFSC MESSAGE CYPHER!" <<endl;

  cout << "Write a message: " << endl;
  string *input = new string;

  while(getline(cin, *input))
   if(*input != ""){
          break;
    }

  cout<< "Message:\n" << *input << endl << endl;

  cout<<"Enter your UFSC registration:"<<endl;
  size_t *code = new size_t;
  cin>>*code;
  cout<<endl;

  user++;

  Cypher id(*code);
  id.NewConversionTable(*code);

  while(true){
    id.ShowMenu(user);

    cout << "Select an option: ";
    cin >> ch;

    if(ch == '1')
    {
      string encrypted;
      encrypted = id.EncryptText(*input);
      cout << "Encrypted message: " << endl << encrypted << endl << endl;
      crypt = true;
      continue;
    }

    if(ch == '2')
    {
      if(crypt){
      string decrypted;
      decrypted = id.DecryptText(id.EncryptText(*input));
      cout << "Reverted message: " << endl << decrypted << endl << endl;
    }
    else
    cout<< "Encrypt your message first!" << endl << endl;

      continue;
    }

    if(ch == '3')
    {
      cout << "Write a new message: " << endl;
      while(getline(cin, *input))
      if(*input != ""){
          break;
    }
      cout<< "New message:\n" << *input << endl << endl;
      crypt = false;

      continue;
    }

    if(ch == '4')
    {
      break;
    }
}

delete code;
delete input;

char answer;
cout<<"Do you want to enter with a new registration?" << endl;
cout<<"y- yes" << endl<< "n- no" << endl;
cin>>answer;
cout<< endl;

if(answer=='y')
goto loop;

  return 0;
}
