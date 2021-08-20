/**
 * The Daily Byte
 *
 * Defanging IPs
 *
 * Given a valid IP address, defang it.
 *
 * Note: To defang an IP address, replace "." with "[.]"
 */

#include <string>
#include <cstdio>
#include <iostream>

using std::string;

void Defang(string& ip)
{
    int idx = 0;
    while ( (idx = ip.find('.', idx)) != string::npos) {
        ip.replace(idx, 1, "[.]");
        idx = idx + 3;
    }
}

int main()
{
    string tc1("127.0.0.1");
    string tc2("192.168.1.1");
    Defang(tc1);
    Defang(tc2);
    std::cout << tc1 << "\n";
    std::cout << tc2 << "\n";
    return 0;
}
