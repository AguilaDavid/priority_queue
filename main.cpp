/**
 * @brief
 * This file contains a possible example of using the file with insertion according to priorities.
 *
 * @date
 * 07-08-2023
 */

#include <iostream>
#include <stdio.h>
#include <clistafunction.h>

using namespace std;

const int MAX_SIZE = 10000;

char buffer[MAX_SIZE];

void readfile();
void uppercase();
void lowercase();
void removeSpaces();
void statistics();
void deletefile();

int main()
{
    Clistafunction a;

    a.insert(uppercase,0);
    a.insert(removeSpaces,1);
    a.insert(deletefile,-1);
    a.insert(statistics,-2);
    a.insert(lowercase,0);
    a.insert(readfile,1);

    a.exe_sequence();

    cout << "[OUTPUT] " << buffer << endl;

    return 0;
}

void readfile()
{
    cout << "Executing: " << __func__ << endl;

    FILE *file;

    // There was an error in the opening
    if ( (file = fopen("note.txt", "r")) == NULL){
       cout << "File opening problems" << endl;
       return;
    }

    fread(buffer, sizeof(buffer), 1, file);

    fclose(file);
}

void deletefile()
{
    cout << "Executing: " << __func__ << endl;
    remove("note.txt");
}

void uppercase()
{
    cout << "Executing: " << __func__ << endl;
    for(int i=0; buffer[i]!='\0';i++)
        if(buffer[i]>='a' && buffer[i]<='z')
            buffer[i]-=32;
}

void lowercase()
{
    cout << "Executing: " << __func__ << endl;
    for(int i=0; buffer[i]!='\0';i++)
        if(buffer[i]>='A' && buffer[i]<='Z')
            buffer[i]+=32;
}

void removeSpaces()
{
    cout << "Executing: " << __func__ << endl;
    for(int i=0; buffer[i]!='\0';i++)
        if(buffer[i]==char(32)){
            buffer[i]=buffer[i+1];
            i++;
        }
}

void statistics()
{
    cout << "Executing: " << __func__ << endl;
    int cont[6];
    for(int i=0;i<6;i++) cont[i]=0;
    for(int i=0; buffer[i]!='\0';i++)
    {
        if(buffer[i]>='A' && buffer[i]<='Z')
            cont[0]++;
        if(buffer[i]>='a' && buffer[i]<='z')
            cont[1]++;
        if(buffer[i]==char(32))
            cont[2]++;
        cont[3]++;
    }
    cout << endl << "statistics" << endl;
    cout << "uppercase: " << cont[0] << endl;
    cout << "lowercase: " << cont[1] << endl;
    cout << "space: " << cont[2] << endl;
    cout << "length: " << cont[3] << endl;
    cout << endl;
}
