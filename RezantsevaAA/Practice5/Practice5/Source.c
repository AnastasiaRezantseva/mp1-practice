#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <profileapi.h>
#include <malloc.h>

#define MAX_PATH_LEN 100
char* getPath();
void getFiles(char* path, struct file* files);
int getCountOfFiles(char* path);
int* getlensFileNames(char* path, int count_files);

void QuickSort(struct file* files, int size);
void BubbleSort(struct file* files, int len);
void InsertSort(struct file* files, int len);

void print_files(struct file* files, int len);
struct file* cpy_arr(struct file* files, int len, int* lensNames);
void sortFiles(struct file* files, int len, int* lensNames);

struct file
{
    char* name;
    int size;
};

int main()
{
    struct file* files;
    char path[MAX_PATH_LEN];
    int count_files;
    int* lensNames;
    int i;

    strcpy(path, getPath());
    count_files = getCountOfFiles(path); // counting the number of files
    lensNames = getlensFileNames(path, count_files); // counting the length of file names

    files = (struct file*)malloc(count_files * sizeof(struct file)); //memory allocation
    for (i = 0; i < count_files; i++)
    {
        files[i].name = (char*)malloc((lensNames[i] + 1) * sizeof(char));
    }
    getFiles(path, files);
    sortFiles(files, count_files, lensNames);
    return 0;
}


void sortFiles(struct file* files, int count_files, int* lensNames)
{
    struct file* copy;
    char sort_selection[100] = "";
    char sortEnough[100] = "";
    int i;
    int enough = 1;
    long long time1;
    long long time2;

    while (enough)
    {

        copy = cpy_arr(files, count_files, lensNames);
        printf("\nChoose sort: \n1-Bubble Sort\n2-Insertion Sort\n3-Quick Sort\n");
        do
        {
            gets(sort_selection);

            if ((strcmp(sort_selection, "1") != 0) && (strcmp(sort_selection, "2") != 0) && (strcmp(sort_selection, "3") != 0))
            {
                printf("incorrest data, please enter 1 - if you want to use a Bubble Sort, 2 - Insertion Sort, 3 - Quick Sort:\n");
            }
        } while ((strcmp(sort_selection, "1") != 0) && (strcmp(sort_selection, "2") != 0) && (strcmp(sort_selection, "3") != 0));

        if (strcmp(sort_selection, "1") == 0)
        {
            QueryPerformanceCounter(&time1);
            BubbleSort(copy, count_files);
            QueryPerformanceCounter(&time2);
            printf("\nThis is sorted list of your files in this directory\n");
            print_files(copy, count_files);
        }
        else if (strcmp(sort_selection, "2") == 0)
        {
            QueryPerformanceCounter(&time1);
            InsertSort(copy, count_files);
            QueryPerformanceCounter(&time2);
            printf("\nThis is sorted list of your files in this directory\n");
            print_files(copy, count_files);
        }
        else
        {
            QueryPerformanceCounter(&time1);
            QuickSort(copy, count_files);
            QueryPerformanceCounter(&time2);
            printf("\nThis is sorted list of your files in this directory (sorted by quick_sort)\n");
            print_files(copy, count_files);
        }
        printf("it took  %lld milliseconds to sort\n\n", time2 - time1);
        printf("If you want to sort again this directory -- enter 'yes', else - enter 'no'\n");

        do
        {
            gets(sortEnough);

            if ((strcmp(sortEnough, "yes") != 0) && (strcmp(sortEnough, "no") != 0)) {
                printf("incorrest data, please enter only 'yes' or 'no'\n");
            }
        } while ((strcmp(sortEnough, "yes") != 0) && (strcmp(sortEnough, "no") != 0));

        if (strcmp(sortEnough, "no") == 0)
        {
            enough = 0;
        }

        // freeing memory
        for (i = 0; i < count_files; i++)
        {
            free(copy[i].name);
        }
        free(copy);
    }
}

char* getPath() {
    char path[MAX_PATH_LEN];
    while (TRUE)
    {
        printf("enter the path to directory\n");
        gets(path);

        strcat(path, "//*");

        if (checkPath(path))
        {
            return path;

        }
        else
        {
            printf("Path is incorrect\n Try again, don't give up!!!\n");
        }
    }
}


int checkPath(char* path)
{
    WIN32_FIND_DATAA files_data;
    HANDLE h_file = FindFirstFileA(path, &files_data);

    FindNextFileA(h_file, &files_data);
    if (h_file == INVALID_HANDLE_VALUE)
    {
        return 0;
    }
    return 1;
}

struct file* cpy_arr(struct file* files, int len, int* lensNames) //copying so as not to change the original data
{
    int i;
    struct file* copy_files;
    copy_files = (struct file*)malloc(len * sizeof(struct file));
    for (i = 0; i < len; i++) //memory allocation for strings
    {
        copy_files[i].name = (char*)malloc((lensNames[i] + 1) * sizeof(char));
    }
    for (i = 0; i < len; i++) //filling in the nameand size of the files
    {
        strcpy(copy_files[i].name, files[i].name);
        copy_files[i].size = files[i].size;
    }

    return copy_files;
}

int getCountOfFiles(char* path)
{
    int count = 0;
    WIN32_FIND_DATAA files_data;
    HANDLE h_file = FindFirstFileA(path, &files_data);

    FindNextFileA(h_file, &files_data);

    while (FindNextFileA(h_file, &files_data) != NULL)
    {
        if (files_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            continue;
        }
        count++;
    }
    FindClose(h_file);

    return count;
}

int* getlensFileNames(char* path, int count_files) //finding the length of a string to allocate memory
{
    int* lens = (int*)malloc(count_files * sizeof(int));
    WIN32_FIND_DATAA files_data;
    HANDLE h_file = FindFirstFileA(path, &files_data);

    FindNextFileA(h_file, &files_data);

    int i = 0;
    while (FindNextFileA(h_file, &files_data) != NULL)
    {
        if (files_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            continue;
        }
        lens[i] = strlen(files_data.cFileName);
        i++;
    }
    FindClose(h_file);

    return lens;
}

void getFiles(char* path, struct file* files) //filling
{
    WIN32_FIND_DATAA files_data;
    HANDLE h_file = FindFirstFileA(path, &files_data);

    FindNextFileA(h_file, &files_data);

    int i = 0;
    printf("\nList of files as they are located in the directory:\n");
    while (FindNextFileA(h_file, &files_data) != NULL)
    {
        if (files_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            continue;
        }
        printf("%s       ", files_data.cFileName);
        strcpy(files[i].name, files_data.cFileName);
        printf("%d\n", files_data.nFileSizeLow);
        files[i].size = files_data.nFileSizeLow;

        i++;
    }
    FindClose(h_file);

}

void print_files(struct file* files, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%s   %d\n", files[i].name, files[i].size);
    }
}



void InsertSort(struct file* files, int len)
{
    struct file tmp;
    tmp.name = "";
    tmp.size = 0;
    int i, j, tmp1, tmp2;
    for (i = 1; i < len; i++)
    {
        tmp.name = "111";
        tmp.size = -1;
        tmp1 = files[i].size;
        j = i - 1;
        while ((j >= 0) && (files[j].size > tmp1))
        {
            tmp2 = files[j + 1].size;
            files[j + 1].size = files[j].size;
            files[j].size = tmp2;
            j--;
        }

    }
}


void BubbleSort(struct file* files, int len)
{
    int i, j;
    struct file tmp;
    tmp.name = "";
    tmp.size = 0;

    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            tmp.name = "111";
            tmp.size = -1;
            if (files[j + 1].size < files[j].size)
            {
                tmp = files[j];
                files[j] = files[j + 1];
                files[j + 1] = tmp;
            }
        }
    }

}


void QuickSort(struct file* files, int size)
{
    int i = 0;
    int j = size - 1;
    struct file tmp;
    tmp.name = "111";
    tmp.size = -1;
    int mid = files[size / 2].size;
    do
    {
        while (files[i].size < mid)
        {
            i++;
        }

        while (files[j].size > mid)
        {
            j--;
        }

        if (i <= j)
        {
            tmp = files[i];
            files[i] = files[j];
            files[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0)
    {
        QuickSort(files, j + 1);
    }
    if (i < size)
    {
        QuickSort(&files[i], size - i);
    }
}