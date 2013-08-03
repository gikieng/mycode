/*
 * =====================================================================================
 *
 *       Filename:  post.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年08月01日 21时59分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(void)
{
    void edit(char title[]);
    FILE *fp;
    struct tm *timenow; 
    time_t now;
    char year[4],day[2],month[2];
    char date[19]="\0";
    char str[100],hail[]=".md";
    int f;
    time(&now);
    timenow =gmtime (&now);
    sprintf(year,"%d",timenow->tm_year+1900);
    sprintf(day,"%d",timenow->tm_mday);
    sprintf(month,"%d",timenow->tm_mon+1);
    strcat(date,year);
    date[4]='-';
    strcat(date,month);
    strcat(date,"-");
    strcat(date,day);
    strcat(date,"-");
    char title[500]="gikieng.github.com/_posts/";
   strcat(title,date);
   printf("please input your title\n");
   scanf("%s",str);
   strcat(title,str);
   strcat(title,hail);
   printf("%s\n",title);
   if((fp=fopen(title,"r"))==NULL)
   {
       printf("你将新建一篇新文章\n");
       if((fp=fopen(title,"w"))==NULL)
   {
       printf("can't not open the file");
       exit(0);
   }
   fprintf(fp,"%s","---\nlayout: post\ntitle: ");
   fprintf(fp,"%s","\"");
   fprintf(fp,"%s",str);
   fprintf(fp,"%s","\"\n");
   fprintf(fp,"%s","---");
   fclose(fp);} 
   printf("是否要继续编辑：1(yes) or 2(no)\n");
   scanf("%d",&f);
   if(f==1)edit(title);
   
   return 0;
}

void edit(char title[])
{   
    char cmd [500]="gedit ";
    printf("请输入你的编辑器:\n");
    scanf("%s",cmd);
    strcat(cmd," ");
    strcat(cmd,title);

    system(cmd);
}
