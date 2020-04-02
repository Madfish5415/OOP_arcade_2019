/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DynamicLib.hpp
*/

#ifndef OOP_ARCADE_2019_DYNAMICLIB_HPP
#define OOP_ARCADE_2019_DYNAMICLIB_HPP

#include <string>
#include <exception>
#include <dlfcn.h>

namespace core {

template <typename T, typename... TArgs>
class DynamicLib {
   public:
    explicit DynamicLib(const std::string& path, TArgs... args) : _path(path), _lib(nullptr), _handle(nullptr) {
        _handle = dlopen(_path, RTLD_LAZY);

        if (!_handle)
            throw std::exception();

        dlerror();
        auto createFunc = (T*) dlsym(_handle, "create");

        if (dlerror()) {
            dlclose(_handle);
            throw std::exception();
        }

        _lib = createFunc(args...);
    };
    ~DynamicLib() {
        delete _lib;
        dlclose(_handle);
    };

   public:
    T& get() {
        if (_lib == nullptr)
            throw std::exception();

        return *_lib;
    };

   private:
    std::string _path;
    T* _lib;
    void *_handle;
};

}

#endif  // OOP_ARCADE_2019_DYNAMICLIB_HPP
