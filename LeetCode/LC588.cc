/**
 * LC 588 Design In-Memory File system.
 */
#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <memory>

class FileSystem
{
public:
    FileSystem()
    {
        root_ = std::make_shared<File>();
    }

    std::vector<std::string> ls(std::string path)
    {
        std::vector<std::string> ls_result;
        std::vector<std::string> files;
        std::shared_ptr<File> t = root_;
        if (path != "/") {
            SplitPath(path, files);

            int path_len = static_cast<int>(files.size());
            for (int i = 1; i < path_len; i++) {
                t = t->files_.at(files[i]);
            }

            if (t->is_file_) {
                ls_result.emplace_back(t->name_);
                return ls_result;
            }
        }

        for (const auto& p : t->files_)
            ls_result.emplace_back(p.first);


        return ls_result;
    }

    void mkdir(std::string path)
    {
        std::shared_ptr<File> t = root_;
        std::vector<std::string> files;
        SplitPath(path, files);
        int path_len = static_cast<int>(files.size());
        for (int i = 1; i < path_len; i++) {
            if (t->files_.find(files[i]) != t->files_.end()) {
                t->files_.emplace(files[i], std::make_shared<File>(files[i], false));
            }
            t = t->files_.at(files[i]);
        }
    }

    void addContentToFile(std::string file_path, std::string content)
    {

    }

    std::string readContentFromFile(std::string file_path)
    {
        return "";
    }


private:
    void SplitPath(std::string path, std::vector<std::string>& result)
    {
        size_t pos = 0;
        std::string token;
        std::string delim("/");
        while ((pos = path.find(delim)) != std::string::npos) {
            token = path.substr(0, pos);
            result.emplace_back(token);
            path.erase(0, pos + delim.length());
        }
        if (path != "")
            result.emplace_back(path);
    }

    struct File
    {
        File() : name_("/"), is_file_(false) {}
        File(std::string name, bool is_file): name_(name), is_file_(is_file) 
        {}

        std::string name_;
        std::unordered_map<std::string, std::shared_ptr<File>> files_;
        bool is_file_;
    };
    std::shared_ptr<File> root_;
};

int main()
{

}
