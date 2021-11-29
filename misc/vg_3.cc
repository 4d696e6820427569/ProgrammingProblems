/**
 * Tool List
 *
 * A milling machine in a manufacturing facility has a tool change system. The
 * tool changer holds n tools and some duplicate tools may be included. The
 * operator must move through the tools one at a time, either moving left or
 * right. The tool changer is circular, so when the last tool in the tools
 * array is reached in either direction, the next tool is at the other end of
 * the array.
 *
 * Given the name of the next tool needed, determine the minimum number of left
 * or right moves to reach it.
 *
 * Example:
 * tools = ['ballendmill', 'keywaycutter', 'slotdrill', 'facemill']
 * startIndex = 1
 * target = 'ballendmill'
 *
 * The tool currently in use is keyway cutter at index 1. The desired tool is
 * ballendmill at index 0. It can be reached by moving right 3 steps or left 1
 * step. The minimum number of moves is 1.
 *
 * Constraints
 * 1 <= n <= 100
 * 0 <= startindex <= n - 1
 * 1 <= lengths of tools[i] and target <= 100
 * targets is in tools
 */

#include <vector>
#include <string>

using std::vector;
using std::string;

int toolchange(vector<string> tools, int startindex, string target)
{
    return 0;
}

int main()
{
    return 0;
}
