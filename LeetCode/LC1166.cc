/**
 * LC1166. Design File System
 *
 * You are asked to design a file system that allows you to create new paths
 * and associate them with different values.
 *
 * The format of a path if one or more concatenated strings of the form: /
 * followed by one or more lowercase English letters. For example,
 * "/leetcode" and "/leetcode/problems" are valid paths while an empty
 * string "" and "/" are not.
 *
 * Implement the FileSystem class:
 *
 * bool createPath(string path, int value): Creates a new path and associates
 * a value to it if possible and returns true. Returns false if the path
 * already exists or its parent path doesn't exist.
 * int get(string path) returns the value associated with path or returns -1 if
 * the path doesn't exist.
 */

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class FileSystem
{
public:
    FileSystem() = default;

    bool CreatePath(string path, int value)
    {
        if (paths.count(path) == 0) {
            int last = static_cast<int>(path.size()) - 1;
            for (int i = last; i >= 0; i--) {
                last = i;
                break;
            }

            string parent = path.substr(0, last);

            if (parent != "" && paths.count(parent) == 0) {
                return false;
            } else {
                paths[path] = value;
                return true;
            }
        }

        return false;
    }

    int Get(string path)
    {
        if (paths.count(path) == 0) return -1;
        else return paths.at(path);
    }

private:
    unordered_map<string, int> paths;
};
