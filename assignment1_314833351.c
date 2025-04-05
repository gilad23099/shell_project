#define MAX 100
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


char* isValidCommand(char* cmd);
int isFileExists(char* filePath);
int executeCommand(char* filePath,char* args[]);

int main(int argc,const char * argv[]){
    char input[MAX];
    char*filePath;
    char tempInput[MAX];
    char* args[10];
    
    while(1){
         
         printf("$ ");
         fgets(input,MAX,stdin);
         input[strlen(input)-1]='\0';
         strcpy(tempInput,input);
         if(strcmp(input,"leave")==0)
         { 
              exit(1);
         }
         int i=0;
         char* token=strtok(tempInput," \t");
         while(token != NULL && i<9){
         
              args[i++]=token;
              token=strtok(NULL," \t");
         }
         
         args[i]=NULL;
         
         if(args[0]==NULL) continue;
         
         filePath=isValidCommand(args[0]);
         
         if(filePath==NULL){
             printf("%s- INVALID COMMAND\n",args[0]);
             continue;
         }
         executeCommand(filePath,args);
         free(filePath);
         
     }
     return 0;
}

char * isValidCommand(char* cmd){
      
      char* originalPath=getenv("PATH");
      char pathCopy[MAX];
      strcpy(pathCopy,originalPath);
      char* tempDir=strtok(pathCopy,":");
      char filePath[MAX];
      char* returnedFilePath;
       

      
      while(tempDir!=NULL){
            
            snprintf(filePath,MAX,"%s/%s",tempDir,cmd);
     	       
            if(isFileExists(filePath)){
		   returnedFilePath=calloc(strlen(filePath)+1,sizeof(char));
		   strcpy(returnedFilePath,filePath);
		   return returnedFilePath; 
	    }     
     	     
            tempDir=strtok(NULL,":");
           
      }
      
      return NULL;

}

int isFileExists(char* filePath){
    FILE *file=fopen(filePath,"r");
    if(file!=NULL){
        fclose(file);
        return 1;
    }
    return 0;
}

int executeCommand(char* filePath,char* args[]){
    int stat;
    pid_t pid=fork();
         
    if(pid==0){
	execv(filePath,args);
	perror("execv failed");
	exit(1);
     }
     else if(pid>0){
     	wait(&stat);
     } 
     else
     {
	perror("fork failed");
     }
}



