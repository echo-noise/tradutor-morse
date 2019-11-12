// tradutor simples de codigo morse
#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <vector>

using namespace std;
string translate(string orig,map<string,char> dict);
string translate(string orig,map<char,string> dict);

int main() 
{
    map<char,string> toMorse =
    {
        {'A',".-"},
        {'B',"-..."},
        {'C',"-.-."},
        {'D',"-.."},
        {'E',"."},
        {'F',"..-."},
        {'G',"--."},
        {'H',"...."},
        {'I',".."},
        {'J',".---"},
        {'K',"-.-"},
        {'L',".-.."},
        {'M',"--"},
        {'N',"-."},
        {'O',"---"},
        {'P',".--."},
        {'Q',"--.-"},
        {'R',".-."},
        {'S',"..."},
        {'T',"-"},
        {'U',"..-"},
        {'V',"...-"},
        {'W',".--"},
        {'X', "-..-"},
        {'Y',"-.--"},
        {'Z',"--.."},
        {'0',"-----"},
        {'1',".----"},
        {'2',"..---"},
        {'3',"...--"},
        {'4',"....-"},
        {'5',"....."},
        {'6',"-...."},
        {'7',"--..."},
        {'8',"---.."},
        {'9',"----."},
        {'.',".-.-.-"},
        {',',"--..--"},
        {'?',"..--.."},
        {'!',"-.-.--"},
        {'/',"-..-."},
        {'(',"-.--."},
        {')',"-.--.-"},
        {'&',".-..."},
        {':',"---..."},
        {';',"-.-.-."},
        {'=',"-...-"},
        {'-',"-....-"},
        {'_',"..--.-"},
        {'"',".-..-."},
        {'$',"...-..-"},
        {'@',".--.-."},
        {' ',"/"}
    };
    map<string,char> toAlpha;
    map<char,string>::iterator it;

    for (it = toMorse.begin(); it != toMorse.end(); ++it) 
    { 
        toAlpha[it->second] = it->first; 
    }
    
    string input;
    char opt;

    cout << "String to convert: " << endl;
    getline(cin, input);

    
    while (opt != 'q') {
        cout << "Current string: " << input << endl;
        cout << "Options:\n\ta. Alpha to morse\n\tb. Morse to alpha;\n" 
            << "\tc. Correct/Re-enter message\n\tq. Quit" << endl;
        cin >> opt;
        switch(opt)
        {
            case 'a':
                cout << "translation>> " << translate(input,toMorse) << endl;
                break;
            case 'b':
                cout << "translation>> " << translate(input,toAlpha) << endl;
                break;
            case 'c':
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "String to convert:" << endl;
                getline(cin, input);
                break;
            case 'q':
                cout << "bye" << endl;
                break;
            default:
                cout << "invalid opt" << endl;
        } 
    }

    return 0;
}

string translate(string orig, map<char,string> dict) 
{
    string translation = "";

    for(unsigned int i=0; i<orig.length(); i++) 
    {
        translation += dict.at(toupper(orig[i]));
        translation += ' ';
    }

    return translation;
}

string translate(string orig, map<string,char> dict) 
{
    string translation = "";
    vector<string> splitter;
    int sp_control = 0;

    splitter.push_back("");

    for(unsigned int i=0; i < orig.length(); ++i)
    {
        if (orig[i] == ' ') 
        {
            splitter.push_back("");
            sp_control += 1; 
        }
        else 
        { 
            splitter[sp_control].push_back(orig[i]); 
        }
    }

    for(unsigned int x = 0; x < splitter.size(); ++x )
    {
        translation += dict.at(splitter[x]);
    }

    return translation;
}
