#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <list>
#include <set>
#include <functional>
#define RELATIVE 0
#define ABSOLUTE 1
#define INVALID -1
using namespace std;
struct dir_t
{
    struct dir_t *father;
    string dir_name;
    set<string> sub_dir_names;
    map<string, struct dir_t *> sub_dirs;
};
dir_t *pwd;
dir_t *root;
int path_type;
int path_resolve(char *path);
void ls(void);
void mkdir(string dir_name);
void rmdir(char *path);
void cd(char *path);
int main(int argc, char const *argv[])
{
    int cmd_cnt;
    char cmd_buf[20];
    char args[300];
    while (~scanf("%d", &cmd_cnt))
    {
        root = new dir_t;
        root->father = 0;
        root->dir_name = "/";
        pwd = root;
        for (int i = 0; i < cmd_cnt; i++)
        {
            scanf("%s", cmd_buf);
            if (!strcmp(cmd_buf, "ls"))
            {
                ls();
            }
            else if (!strcmp(cmd_buf, "rm"))
            {
                scanf("%s", args);
                rmdir(args);
            }
            else if (!strcmp(cmd_buf, "cd"))
            {
                scanf("%s", args);
                cd(args);
                //cd(args, 0);
            }
            else if (!strcmp(cmd_buf, "mkdir"))
            {
                scanf("%s", args);
                mkdir(args);
            }
        }
        delete root;
    }
    return 0;
}
//return 0 if success
//return 1 if failure
int path_resolve(char *path)
{
    char *pos, *new_pos;
    char *membuf = new char[300];
    pos = membuf;
    strcpy(membuf, path);
    if (membuf[0] == '/')
    {
        pwd = root;
        path_type = ABSOLUTE;
        pos++;
        if (pos[0] == 0)
        {
            delete[] membuf;
            return 0;
        }
        else
        {
            while ((new_pos = strchr(pos, '/')))
            {
                *new_pos = 0;
                string dir_name = pos;
                if (!strcmp(pos, ".."))
                {
                    if (pwd->father)
                    {
                        pwd = pwd->father;
                        pos = new_pos + 1;
                    }
                    continue;
                }
                else if (!strcmp(pos, "."))
                {
                    pos = new_pos + 1;
                    continue;
                }
                decltype(pwd->sub_dirs.find(dir_name)) __next;
                if ((__next = pwd->sub_dirs.find(dir_name)) == pwd->sub_dirs.end())
                {
                    delete[] membuf;
                    return 1;
                }
                else
                {
                    pwd = __next->second;
                }
                pos = new_pos + 1;
            }
            string dir_name = pos;
            if (!strcmp(pos, ".."))
            {
                if (pwd->father)
                {
                    pwd = pwd->father;
                }
                delete[] membuf;
                return 0;
            }
            else if (!strcmp(pos, "."))
            {
                delete[] membuf;
                return 0;
            }
            decltype(pwd->sub_dirs.find(dir_name)) __next;
            if ((__next = pwd->sub_dirs.find(dir_name)) == pwd->sub_dirs.end())
            {
                delete[] membuf;
                return 1;
            }
            else
            {
                pwd = __next->second;
                delete[] membuf;
                return 0;
            }
        }
    }
    else
    {
        path_type = RELATIVE;
        while ((new_pos = strchr(pos, '/')))
        {
            *new_pos = 0;
            string dir_name = pos;
            if (!strcmp(pos, ".."))
            {
                if (pwd->father)
                {
                    pwd = pwd->father;
                    pos = new_pos + 1;
                }
                continue;
            }
            else if (!strcmp(pos, "."))
            {
                pos = new_pos + 1;
                continue;
            }
            decltype(pwd->sub_dirs.find(dir_name)) __next;
            if ((__next = pwd->sub_dirs.find(dir_name)) == pwd->sub_dirs.end())
            {
                delete[] membuf;
                return 1;
            }
            else
            {
                pwd = __next->second;
            }
            pos = new_pos + 1;
        }
        string dir_name = pos;
        if (!strcmp(pos, ".."))
        {
            if (pwd->father)
            {
                pwd = pwd->father;
            }
            delete[] membuf;
            return 0;
        }
        else if (!strcmp(pos, "."))
        {
            delete[] membuf;
            return 0;
        }
        decltype(pwd->sub_dirs.find(dir_name)) __next;
        if ((__next = pwd->sub_dirs.find(dir_name)) == pwd->sub_dirs.end())
        {
            delete[] membuf;
            return 1;
        }
        else
        {
            pwd = __next->second;
            delete[] membuf;
            return 0;
        }
    }
    abort();
    return -1;
}
/*
void ls(char *path)
{
    
    dir_t *saved_pwd = pwd;
    int list_size;
    if (!path_resolve(path))
    {
        if ((list_size = pwd->sub_dirs.size()) == 0)
        {
            puts("ls: (empty directory)");
        }
        else
        {
            priority_queue<string> sub_names;
            for (auto &&i : pwd->sub_dir_names)
            {
                sub_names.push(i);
            }
            for (int i = 0; i < list_size; i++)
            {
                cout << sub_names.top() << ((i == list_size - 1) ? '\n' : ' ');
                sub_names.pop();
            }
        }
    }
    else
    {
        puts("ls: no such directory");
    }
    pwd = saved_pwd;
    
}
*/
void ls(void)
{
    int list_size;
    if ((list_size = pwd->sub_dirs.size()) == 0)
    {
        puts("ls: (empty directory)");
    }
    else
    {
        priority_queue<string, vector<string>, greater<string>> sub_names;
        for (auto &&i : pwd->sub_dir_names)
        {
            sub_names.push(i);
        }
        for (int i = 0; i < list_size; i++)
        {
            cout << sub_names.top() << ((i == list_size - 1) ? '\n' : ' ');
            sub_names.pop();
        }
    }
}
void mkdir(string dir_name) //work in pwd only
{
    if (pwd->sub_dirs.find(dir_name) == pwd->sub_dirs.end())
    {
        dir_t *new_dir = new dir_t;
        new_dir->father = pwd;
        new_dir->dir_name = dir_name;
        pwd->sub_dir_names.insert(dir_name);
        pwd->sub_dirs[dir_name] = new_dir;
    }
    else
    {
        puts("mkdir: directory already exist");
    }
}
void rmdir(char *path)
{
    //dir_t *dir = pwd;
    string dir_name = path;
    if (pwd->sub_dirs.find(dir_name) != pwd->sub_dirs.end())
    {
        delete pwd->sub_dirs.find(dir_name)->second;
        pwd->sub_dir_names.erase(dir_name);
        pwd->sub_dirs.erase(dir_name);
    }
    else
    {

        if (*path == '/')
        {
            //pwd = dir;
            rmdir(path + 1);
            return;
        }

        puts("rm: no such directory");
    }
    //pwd = dir;
}
/*
void rmdir(char *path)
{
    dir_t *dir = pwd;

    if (!path_resolve(path))
    {
        dir_t *dir_father = pwd->father;
        if (pwd == root)
        {
            pwd = dir;
            return;
        }

        dir_father->sub_dir_names.erase(pwd->dir_name);
        dir_father->sub_dirs.erase(pwd->dir_name);
        delete pwd;
    }
    else
    {
        
        if (path_type == ABSOLUTE)
        {
            pwd = dir;
            rmdir(path + 1);
            return;
        }
        
        puts("rm: no such directory");
    }
    pwd = dir;
}
*/
void cd(char *path)
{
    //dir_t *dir;
    string full_path = "cd: /";
    dir_t *saved_pwd = pwd;
    if (!path_resolve(path))
    {
        saved_pwd = pwd;

        list<string> names;
        while (pwd->father)
        {
            names.push_front(pwd->dir_name);
            pwd = pwd->father;
        }
        for (auto &&i : names)
        {
            full_path += i;
            full_path += "/";
        }
        if (!names.empty())
            full_path.pop_back();
        //if (!flag)
        cout << full_path << endl;
        pwd = saved_pwd;
        /*
        if (path_type == RELATIVE)
        {
            printf("cd: %s\n", path);
        }
        else if (path_type == ABSOLUTE)
        {
            printf("cd: %s\n", path);
        }
        */
        //pwd = dir;
    }
    else
    {

        if (path_type == ABSOLUTE)
        {
            pwd = saved_pwd;
            cd(path + 1);
            return;
        }

        //if (!flag)
        puts("cd: no such directory");
        pwd = saved_pwd;
    }
}
