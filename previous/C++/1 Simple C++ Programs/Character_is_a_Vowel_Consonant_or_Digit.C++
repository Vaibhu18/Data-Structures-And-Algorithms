
#include <iostream>
using namespace std;

int main()
{
    char ch;
    cout << "Enter any character : ";
    cin >> ch;

    if((int) ch - '0' >= 0 && (int) ch - '0' <= 9  ){
        cout<<"You enter digit";
    }else if(isalpha(ch)){
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
        cout<<"You enter vowels";
    }else{
        cout<<"You enterd consonant";
    }
    }else{
        cout<<"You enter spacial symbol";
    }
    
}