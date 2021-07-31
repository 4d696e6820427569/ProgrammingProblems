#include <unordered_map>
#include <string>

using std::unordered_map;
using std::string;

int main()
{
    unordered_map<char, int> m;
    string tc1("abcde");
    printf("%d\n", m['a']);
    m.find('a') != m.cend() ? printf("Not found after accessing.\n") : printf("Found after accessing.\n");
    m['a']++;
    printf("%d\n", m['a']);
    return 0;
}
