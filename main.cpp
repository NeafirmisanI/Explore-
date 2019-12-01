#include <stdio.h>
#include <iostream>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include "engine.h"

using namespace std;

void listdir(const char *name, int indent, string& key)
{
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(name)))
        return;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            snprintf(path, sizeof(path), "%s/%s/", name, entry->d_name);
            listdir(path, indent + 2, key);
        } else {
            if(indent > 0){
                openfile(name, entry->d_name, key);
               // printf("%s %s\n", name, entry->d_name);
            } else{
                openfile(entry->d_name, key);
               // printf("%s\n", entry->d_name);
            }
        }
    }
    closedir(dir);
}

int main(void) {
    string key;
    cin >> key;
    listdir(".", 0, key);
    return 0;
}
