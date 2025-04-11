#include <iostream>
#include <lua5.3/lua.hpp>

class HelloWorld {
public:
    static int printHello(lua_State* L) {
        std::cout << "Hello World" << std::endl;
        return 0;
    }
};

extern "C" int luaopen_helloworld(lua_State* L) {
    lua_newtable(L);
    lua_pushcfunction(L, HelloWorld::printHello);
    lua_setfield(L, -2, "printHello");
    return 1;
}

int main() {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    
    // Загружаем наш модуль
    luaopen_helloworld(L);
    lua_setglobal(L, "helloworld");
    
    // Выполняем Lua скрипт
    luaL_dofile(L, "script.lua")
    
    lua_close(L);
    return 0;
}
