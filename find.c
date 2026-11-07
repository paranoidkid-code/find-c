
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

void search_dir(const char *current_path, const char *target) {
    DIR *dir = opendir(current_path);
    if (dir == NULL) {
        return;
    }
    struct dirent *entry;
    char full_path[2048];
    struct stat file_stat;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        snprintf(full_path, sizeof(full_path), "%s/%s", current_path, entry->d_name);
        if (strstr(entry->d_name, target) != NULL) {
            printf("\033[1;32mFound a match:\033[0m %s\n", full_path);
        }
        if (stat(full_path, &file_stat) == 0) {
            if (S_ISDIR(file_stat.st_mode)) {
                search_dir(full_path, target);
            }
        }
    }
    closedir(dir);
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Usage: find <keyword>\n");
        return 1;
    }
    printf("Searching for '%s'...\n", argv[1]);
    search_dir(".", argv[1]);
    printf("\nSearch completed\n");
    return 0;
}
