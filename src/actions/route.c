#include "webc-actions.h"

WEBCAPI Route* MakeRoute(Cstr path, char* buffer)
{
    Route* route = (Route*) malloc(sizeof(Route));
    route->path = (char*) malloc(sizeof(char) * (strlen(path) + 1));
    strcpy(route->path, path);
    route->buffer = (char*) malloc(sizeof(char) * (strlen(buffer) + 1));
    strcpy(route->buffer, buffer);

    return route;
}

WEBCAPI Tree MakeTree(Cstr root, Route* first, ...)
{
    Tree result = {0};
    result.root = root;
    result.count = 0;
    if(first == NULL) return result;

    va_list args;
    va_start(args, first);
    result.count++;
    for (Route* next = va_arg(args, Route*); next != NULL; next = va_arg(args, Route*)) {
        result.count++;
    }
    va_end(args);

    result.routes = (Route**) malloc(sizeof(result.routes[0]) * result.count);
    if (result.routes == NULL) {
        PANIC("could not allocate memory: %s", strerror(errno));
    }

    va_start(args, first);
    result.routes[0] = first;
    for (size_t i = 1; i < result.count; ++i) {
        Route* next = va_arg(args, Route*);
        result.routes[i]= next;
    }
    va_end(args);

    return result; 
}


