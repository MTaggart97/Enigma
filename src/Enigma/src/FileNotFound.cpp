#include <sstream>

namespace Enigma {
    /**
     * Extend the runtime exception class to catch 
     * if a file isn't found.
     */
    class FileNotFound: public std::runtime_error {
    public:

    FileNotFound(const std::string* st)
        : std::runtime_error( "File Not Found: " ), file( st )
        {}

    const std::string* get_file() const {
        return file;
    }
    private:
        const std::string* file;
    };
}
