#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>

using std::max_element;
using std::cout, std::endl, std::ifstream, std::stringstream, std::string, std::vector;

vector<int> ParseFile(const string& filename)
{
    ifstream infile(filename);

    vector<int> counts;

    string buffer;
    int current = 0;
    int sum = 0;
    while (std::getline(infile, buffer, '\n'))
    {
        if (buffer == "")
        {
            counts.push_back(sum);
            sum = 0;
        }
        else
        {
            stringstream(buffer) >> current;
            sum += current;
        }
    }

    return counts;
}

int GetMax(const vector<int>& counts)
{
    return std::distance(counts.begin(), std::max_element(counts.begin(), counts.end()));
}

std::vector<int> GetMaxN(const vector<int>& counts, const int N)
{
    vector<int> copy(counts);
    std::sort(copy.begin(), copy.end());
    std::vector<int> topN(copy.end() - N, copy.end());
    return topN;
}

void PrintVector(const vector<int>& vec)
{
    for (auto n : vec)
    {
        cout << n << endl;
    }
}

int main()
{
    auto counts = ParseFile("input.txt");
    cout << GetMax(counts) << endl;
    auto max3 = GetMaxN(counts, 3);
    PrintVector(max3);
    cout << std::reduce(max3.begin(), max3.end()) << endl;
    return 0;
}
