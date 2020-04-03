/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DynamicLib.hpp
*/

#ifndef OOP_ARCADE_2019_DYNAMICLIB_HPP
#define OOP_ARCADE_2019_DYNAMICLIB_HPP

#include <dlfcn.h>

#include <exception>
#include <string>

namespace core {

template <typename T>
class DynamicLib {
   public:
    template <typename... TArgs>
    explicit DynamicLib(const std::string& path, TArgs... args) : _path(path), _lib(nullptr), _handle(nullptr) {
        using creator = T* (*)(TArgs... args);

        _handle = dlopen(_path.c_str(), RTLD_LAZY);

        if (!_handle)
            throw std::exception();

        dlerror();
        auto createFunc = reinterpret_cast<creator>(dlsym(_handle, "create"));

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
