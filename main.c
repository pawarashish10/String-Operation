/*Name - Ashish Pawar
 * Coding challange DPS technology
 * Last Modified - 2/2/2017
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//Function for sorting Words of Sentence
struct node 
{
    int length;
    char wrd[5];
    struct node *next;
};
struct node *header,*ptr, *temp,*nxt, *tail,*header1,*ptr1,*nxt1;
void insert_front(int length,char *wrd);
void insert_end();
void insert_any();
void display();

void insert_end(int len,char *word)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->length=len;
    strcpy(temp->wrd,word);
    ptr = header;
    if (ptr == NULL)
    {
        header=temp;
        header->next=NULL;
    }
    else
    {
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
        temp->next = NULL;
    }
}



void display()
{
    ptr = header;
    if(ptr == NULL)
        printf("\nlist is empty \n");
    else
    {
        printf("\tLength \t\tString\n");
        while(ptr != NULL)
        {
            printf("\n\t  %d", ptr->length);
            printf("\t\t%s\n", ptr->wrd);
            ptr = ptr->next;
        }
        
    }
}


int strcicmp(char *str1, char *str2)
{
    int flag = 0;
    int res,i;
    str1[4] = '\0';
    str2[4] = '\0';
    for(i = 0; i < 4; i++)
    {
        if(str1[i] >= 65 && str1[i] <= 90 )
        {
            str1[i] = str1[i] + 32;
        }
        if(str2[i] >= 65 && str2[i] <= 90 )
        {
            str2[i] = str2[i] + 32;
        }

    }
    res = strcmp(str1,str2);
    return res;
    
}
void search(char *find)
{
    ptr = header;
    int flag = 0, sense = 0, inSense = 0;
    int res,ch;
    printf("\n \t1.Case Sensitive \n\t2. case inSensitive  \n\tyour choice  :  ");
    scanf("%d",&ch);
    fflush(stdin);
    while(1)
    {
        if(ch >= 1 && ch <=2)
        {
            break;
        }
        else
        {
            printf("\nplease enter one or two" );
            scanf("%d",&ch);
        }
    }
    
    switch(ch)
    {
        case 1:
            sense = 1;
        break;
        case 2:
            inSense = 1;
        break;
    }  

    while(ptr != NULL)
    {
        //ptr = ptr->next;
        if(sense == 1)
            res = strcmp(ptr->wrd,find);
        else if(inSense == 1)
            res = strcicmp(ptr->wrd,find);
        if(res == 0)
        {
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }
    if(flag == 1)
    {
        printf("\nfound string-> %s\n",find);
    }
    else
    {
        printf("\nNot Found\n");
    }
}

void sortString(char *S)
{
	int string_index,m, word_index, p,q,temp_index;
	int word_length = 0, wrd_strt_loc = 0, space_cntr = 1;
	int start_loc, end_loc, i;
	int char_Val = 0;
	int alph_array[128] = { 0 };
    
	for (string_index = 0; string_index <= strlen(S); string_index++)
	{
		if (((S[string_index] == ' ' || S[string_index] == '\t') && (S[string_index + 1] != ' ' || S[string_index + 1] != '\t')) || (S[string_index] == '\0'))
		{
			word_length = string_index - (wrd_strt_loc + space_cntr - 1);
			
			start_loc = wrd_strt_loc;
			end_loc = (word_length + wrd_strt_loc) - 1;
			char *temp_word;
			temp_word = malloc(word_length * sizeof(char));
			
			for (temp_index = 0; temp_index < word_length; temp_index++)
			{
				temp_word[temp_index] = 0;
			}
			
			temp_index = 0;
            i = 0;
			for (word_index = start_loc; word_index < end_loc +1; word_index++)
			{
				char_Val = (int)S[word_index];
                
				if (char_Val >= 65 && char_Val <= 90)
				{
					alph_array[char_Val - 65]++;
				}
				else if (char_Val >= 97 && char_Val <= 122)
				{
					alph_array[char_Val - 71]++;
				}
				else if (char_Val >= 48 && char_Val <= 57)
                {
                    alph_array[char_Val + 4]++;
                }
                else
				{
					temp_word[temp_index] = S[word_index];
					temp_index++;
				}
			
			}
            
            
			word_index = start_loc;
			for (m = 0,p = 26; m < 26 && p < 52; ++m, ++p)
			{
				if( alph_array[m] > 0)
				{
					while (alph_array[m] != 0)
					{
			
						S[word_index] = (char)(m + 65);
						word_index++;
						alph_array[m]--;
					}
				}
				if(alph_array[p] > 0)
				{
					while (alph_array[p] != 0)
					{
			
						S[word_index] = (char)(p + 71);
						word_index++;
						alph_array[p]--;
					}
			
				}
			}
            
            for (q = 52; q < 62; ++q)
            {
                if(alph_array[q] > 0)
				{
					while (alph_array[q] != 0)
					{
			
						S[word_index] = (char)(q - 4);
						word_index++;
						alph_array[q]--;
					}
			
				}
            }
			for (temp_index = 0; temp_index < word_length; temp_index++)
			{
				if (temp_word[temp_index] != 0)
				{
					S[word_index] = temp_word[temp_index];
					word_index++;
				}
			}
			
			wrd_strt_loc = string_index + 1;
			space_cntr = 1;
		}
		else if (S[string_index + 1] == ' ' && S[string_index] == ' ')
		{
			space_cntr++;
		}
	}
}


//Function for reversing Words of Sentence
void reverseString(char *S)
{
	int string_index, m, i, p, q;
	int word_length = 0, wrd_strt_loc = 0, space_cntr = 1, tab_cntr = 0;
	int start_loc, end_loc;
	m = strlen(S);
	char * r_string = malloc(strlen(S) * sizeof(char) + 1);

	//for (p = 0; p < strlen(S); p++)
	//	r_string[p] = ' ';
	q = strlen(S);
    for (p = 0; p < strlen(S); p++)
	{
		if(S[p] == '\t')
			r_string[q-p-1] = '\t';
		else
			if(r_string[p]!='\t')
			r_string[p] = ' ';
	}
    
	r_string[m] = '\0';
	m = strlen(S);
	for (string_index = 0; string_index <= strlen(S); string_index++)
	{
		if (((S[string_index] == ' ' || S[string_index] == '\t') && (S[string_index + 1] != ' ' || S[string_index + 1] != '\t')) || (S[string_index] == '\0'))
		{
			word_length = string_index - (wrd_strt_loc + space_cntr - 1);

			start_loc = wrd_strt_loc;
			end_loc = (word_length + wrd_strt_loc) - 1;
            
			m = m - word_length;

			for (i = start_loc; i <= end_loc; i++)
			{
				r_string[m] = S[i];
				m++;
			}

			//printf("\n");
			wrd_strt_loc = string_index + 1;
			m = m - word_length - space_cntr;
			space_cntr = 1;
		}
		else if ((S[string_index] == ' ' || S[string_index] == '\t') && (S[string_index + 1] == ' ' || S[string_index + 1] == '\t'))
		{
			//space_cntr++;
            if(S[string_index] == '\t')
            {

                //r_string[m] == '\t';
                tab_cntr++;
            }
            else
            {
                space_cntr++;
            }
		}
	}
	strcpy(S,r_string);
}

//Function to take Input from User

char * takeInputString()
{
    char *str;
    char ch;
    int i;
	printf("\nPlease enter a sentence and Press ENTER key \n");
	ch = getchar();
    while( ch == ' ' || ch == 9 || ch == '\t')
    {
        ch = getchar();
    }
    while(ch == '\n')
    {
        printf("Invalid sentence!!!, please re-Enter\n");
        ch = getchar(); 
    }
    
    int sze = 1;
    str = malloc(sze*sizeof(char));
    str[sze-1] = ch;
    
    while(ch != '\n')
    {
        sze++;
        ch = getchar();
        str = realloc(str,sze*sizeof(char));
        str[sze-1] = ch;
        //printf("%c",String);
    }
    str[sze-1] = '\0';
    
    i = strlen(str);
    while(str[i-1] == ' ' || str[i-1] == 9)
    {
        i--;
    }
    str[i] = '\0';
    
    return str;
}

//main function

void splitAndAddToLinkList(char *S)
{
    int string_index,m, word_index, p,q,temp_index;
	int word_length = 0, wrd_strt_loc = 0, space_cntr = 1;
	int start_loc, end_loc, i;
	int char_Val = 0;
	int alph_array[128] = { 0 };
    char *link_wrd;
    link_wrd = malloc(5 * sizeof(char));
	for (string_index = 0; string_index <= strlen(S); string_index++)
	{
		if (((S[string_index] == ' ' || S[string_index] == '\t') && (S[string_index + 1] != ' ' || S[string_index + 1] != '\t')) || (S[string_index] == '\0'))
		{
			word_length = string_index - (wrd_strt_loc + space_cntr - 1);
			
			start_loc = wrd_strt_loc;
			end_loc = (word_length + wrd_strt_loc) - 1;
			char *temp_word;
			temp_word = malloc(word_length * sizeof(char));
			
			for (temp_index = 0; temp_index < word_length; temp_index++)
			{
				temp_word[temp_index] = 0;
			}
			
			temp_index = 0;
            i = 0;
			for (word_index = start_loc; word_index < end_loc +1; word_index++)
			{
				char_Val = (int)S[word_index];
                if(i<4)
                {
                    link_wrd[i] = S[word_index];
                    i++;
                }
				if (char_Val >= 65 && char_Val <= 90)
				{
					alph_array[char_Val - 65]++;
				}
				else if (char_Val >= 97 && char_Val <= 122)
				{
					alph_array[char_Val - 71]++;
				}
				else if (char_Val >= 48 && char_Val <= 57)
                {
                    alph_array[char_Val + 4]++;
                }
                else
				{
					temp_word[temp_index] = S[word_index];
					temp_index++;
				}
			
			}
            
            link_wrd[i] ='\0';
            if(word_length>0)
            {
                //printf("-%s", link_wrd);
                insert_end(word_length,link_wrd);
            }
			word_index = start_loc;
			
			wrd_strt_loc = string_index + 1;
			space_cntr = 1;
		}
		else if (S[string_index + 1] == ' ' && S[string_index] == ' ')
		{
			space_cntr++;
		}
	}
}

void init_link()
{
    ptr = header;
    while(ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    header = ptr;
}

void sortedInsert(struct node** head, struct node* new_node)
{
    struct node* current;
    if (*head == NULL || strcmp((*head)->wrd,new_node->wrd)>= 0)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        current = *head;
        while (current->next!=NULL && strcmp(current->next->wrd,new_node->wrd) < 0)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void insertionSort(struct node **head)
{
    struct node *sorted = NULL;
    struct node *current = *head;
    while (current != NULL)
    {
        struct node *next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    *head = sorted;
}


int main() 
{
    printf("\t\tCoding Challange(String Operation)\n\n");
    char ch = '\0';
    int choice=0,i;
    header = NULL;
    char *String, *sorted_String, *reversed_String;
    String = takeInputString();
    char find[50];
    char add[50];

    splitAndAddToLinkList(String);

    display();
    while(choice!=7)
    {
        printf("\n\tMENU DEMONSTRATION");
        printf("\n\t------------------------------");
        printf("\n\n\t 1. sort");
        printf("\n\t 2. search");
        printf("\n\t 3. add");
        printf("\n\t 4. Initialize");
        printf("\n\t 5. display");
        printf("\n\t 6. EXIT");
        printf("\n\n Enter Your CHoice: ");
        scanf("%d",&choice);
        fflush(stdin);
        while(1)
        {
            if(choice >= 1 && choice <=7)
            {
                break;
            }
            else
            {
                printf("\nplease enter valid data");
                scanf("%d",&choice);
            }
        }
        switch(choice)
        {
            case 1:
                insertionSort(&header);
                printf("\n   sorting completed \n");
                //display();
                break;
            case 2:
                printf("\nenter pattern to be searched  : ");
                scanf("%s",find);
                search(find);
                printf("\n   search completed \n");
                break;
            case 3:
                printf("\nAdd new string to link list\n");
                String = takeInputString();
                splitAndAddToLinkList(String);
                insertionSort(&header);
                printf("\n   new string added\n");
            break;
            case 4:
                init_link();
                 printf("\n   initialization completed\n");
            break;
            case 5:
                display();
            break;
            //case 6:
            
            //break;
            case 6:
                printf("\nYOU SELECTED OPTION %c",7);
                exit(0);
                otherwise:
                printf("\nINVALID SELECTION...Please try again");
        }getch();
    }
    return 0;
}
