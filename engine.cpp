#include <iostream>
#include <fstream>
#include <string.h>
#include "engine.h"

using namespace std;

char* concat(const char *s1, const char *s2)
{
    char *result = (char*)malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}


int diff_files(ifstream& file, string& key){
    string line;
    int line_number = 0;
    while(getline(file, line)){
        std::size_t found = line.find(key);
        if(found != std::string::npos){
           // cout << "Founded at line: " << line_number << '\n';
            return line_number;
        }
        line_number++;
    }
    return -1;
}

void openfile(const char* dir_name, const char* file_name, string& key){
    char* total = concat(dir_name, file_name);
    ifstream file(total);
    if(file.is_open()){
        int founded = diff_files(file, key);
        if(founded != -1){  
            printf("Founded at file: %s positinon: %d \n", total, founded);
        } else{
            return;
        }
    } else{
        printf("Failed to open file: %s\n", total);
        return;
    }
}

void openfile(const char* file_name, string& key){
    ifstream file(file_name);
    if(file.is_open()){
        int founded = diff_files(file, key);
        if(founded != -1){  
            printf("Founded at file: %s positinon: %d \n", file_name, founded);
        } else{
            return;
        }
    } else{
        printf("Failed to open file: %s\n", file_name);
        return;
    }
}