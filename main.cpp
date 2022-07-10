#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> control_words(vector<string> words_ins)
{
    ifstream file("word_list.txt");
    if (!file)
        exit(1);
    int index = 0;
    vector<int> index_of_words;
    for(int i = 0; i < words_ins.size(); i++)
    {
        int j = 1;
        string word;
        ifstream tmp("word_list.txt");
        while(tmp >> word)
        {
            index++;
            //cout << word << " " << words_ins[i] << endl;
            if(word == words_ins[i])
            {
                index_of_words.push_back(index);
                index = 0;
                break;
            }
            else if (words_ins[i] == "")
            {
                perror("Error: Word not found, empty");
                exit(1);
            }
            else if (words_ins[i] != word)
            {
                if (j == 2048)
                {
                    perror("Error: Word not found");
                    //cout << j << endl;
                    exit(1);
                }
                j++;  
            }     
        }
    }
    return index_of_words;
}

vector<string> binary_convert(vector<int> integers)
{
    vector<string> binary_words;
    for(int i = 0; i < integers.size(); i++)
    {
        string binary_word;
        int j = integers[i];
        while(j > 0)
        {
            binary_word = to_string(j % 2) + binary_word;
            j /= 2;
        }
        if (binary_word.size() < 11)
        {
            int k = 11 - binary_word.size();
            for(int l = 0; l < k; l++)
            {
                binary_word = "0" + binary_word;
            }
        }
        binary_words.push_back(binary_word);
    }
    return binary_words;
}

int main(int argc, char** argv)
{
    if (argc != 13)
        return (0);
    vector<int> index_of_words;
    vector<string> binary_of_index;
    vector<string> word_list(argv + 1, argv + argc);
    /*for (int i = 0; i < word_list.size(); i++)
        cout << word_list[i] << "\n";*/
    index_of_words = control_words(word_list);
    /*for (int i = 0; i < index_of_words.size(); i++)
        cout << index_of_words[i] << "\n";*/
    binary_of_index = binary_convert(index_of_words);
    /*for (int i = 0; i < binary_of_index.size(); i++)
        cout << binary_of_index[i] << "\n";
    cout << endl;*/
    return 0;
}