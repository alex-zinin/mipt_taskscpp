#include <iostream>
#include<fstream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

bool operator<(const pair<string, int>& lhs, const pair<string, int>& rhs)
{
    return lhs.second < rhs.second;
}



int main() {
    std::ifstream file("on.txt");
    map<string, int> words;
    vector<pair<string, int>> data;
    if(file.is_open())
    {
        string word;
        while(!file.eof())
        {
            file >> word;
           // getline(file, word, ' ');
            if(word[0] <= 'Z' && word[0] >= 'A')
                word[0] += 32;
            if(*word.rbegin() == ',')
                word.erase(word.end()-1, word.end());
            words[word]++;
        }
    }

    for(auto &x: words)
        data.emplace_back(make_pair(x.first,x.second));

    sort(data.begin(), data.end(), [](const pair<string, int>& lhs , const pair<string, int>& rhs)
    {
        return lhs.second > rhs.second;
    });

    for(auto &x : data)
    {
        cout << x.first << " " << x.second << endl;
    }


    return 0;
}
