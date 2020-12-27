#include<stdio.h>
#include<string.h>
#define LINE 256
#define TXT 252
#define WORD 30
#define TRUE 1
#define FALSE 0

void a_print(char txt [][LINE],char word [],int n)//for option a
{
    int i=2;
    for(i=2;i<n;i++)
        if(strstr(txt[i],word)!=NULL)//check if out word is substring of the current line
            printf("%s",txt[i]);
}
void check_and_print_word(char word [], char this_word[],int word_size){//help method for option b
    char* word_ptr=word;
    char* this_word_ptr=this_word;
    while(*this_word_ptr!='\0'){
        if(*this_word_ptr==*word_ptr)
        {
            word_ptr++;
            word_size--;

        }
        this_word_ptr++;
    }
    if(word_size==0)
        printf("%s\n", this_word);
}
//this method responisble for spliting the line into words
//if there is an option that the curr word is similiar to our word
//then this function sending the word to function check_and_print_word() for checking and printing
void check_by_words(char line[],char word [], char this_word[],int word_size){
    int i=0,j=0;
    while(line[i]!='\n'){
        while(line[i]!=' '&&line[i]!='\t'&&line[i]!='\n'&&line[i]!='\r')//for split by space, tab, new line or \r. by the way, originally \r should not appear but it appears in yours test file.
        {
            this_word[j]=line[i];
            i++;
            j++;
        }
            this_word[j]='\0';//end of the curr word
            if(j==word_size+1||j==word_size)//check if the this_word is in this range word_size=<this_word<=word_size+1
                check_and_print_word(word,this_word,word_size);
        j=0;//re-init
        if(line[i]!='\n')
            i++;
}
}
//for option b
void b_print(char txt [][LINE],char word [],int num_line,int word_size){
    char sub[WORD];
    for(int i=2;i<num_line;i++){//starting from line 2 because the first two lines are for init
        check_by_words(txt[i],word,sub,word_size);
    }
    
}
int main(){
    char txt [TXT][LINE];//array of strings
    int num_lines=0;
    while(fgets(txt[num_lines],LINE,stdin)){
        num_lines++;//counter for the real number of lines
    }
    char word[WORD];//our word
    char* ptr=txt[0];
    int size=0;
    while(*ptr!=' '&&*ptr!='\t'){
        word[size]=*ptr;
        ptr++;
        size++;//counter for the real number of our word
    }
    word[size]='\0';//the end of our word
    ptr++;//skip on space or tab
    char option=*ptr;
    if(option=='a'){
        a_print(txt,word,num_lines);
    }
    else if(option=='b'){
        b_print(txt,word,num_lines,size);
    }
}
