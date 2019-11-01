#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include<conio.h>
#define debug printf("ok\n");

int khazane;
int mardom;
int darbar;
int totalproblems;
int counter[20];
typedef struct node {
	int problemnum;
	// Soorate Moshkel:
    char problem[200];
    // Rahe halle aval:
    char sol1[100];
    int mardom1;
    int darbar1;
    int khazane1;
    // Rahe halle dovom:
    char sol2[100];
    int mardom2;
    int darbar2;
    int khazane2;
    // Counter
    int count;
    // Moshkele baadi:
    struct node	 * next;
} node_problems;

void Add_End(node_problems * list,node_problems * new_node)
{	
	node_problems * current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = malloc(sizeof(node_problems));
    current->next = new_node;
    current->next->next = NULL;
}

int Exists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

node_problems * Find_Node(node_problems * head , node_problems * current , int val)
{
	node_problems * backup = NULL;
	backup = current;
	int i;
	for(i = 0;i < val;i++)
	{	
		backup = current;
		current = current->next;
	}
	
	return current;
}

void Remove_Node (node_problems * head, int val)
{
	node_problems * backup2 = NULL;
	node_problems * current = NULL;
	current = head;
	backup2 = current;
	int i;
	for(i = 0;i < val;i++)
	{	
		backup2 = current;
		current = current->next;
	}
	current->count = current->count - 1;
	
	if (current->count < 1)
	{	
		totalproblems--;
		backup2->next = backup2->next->next;
		free(current);
	}
}

char* LastCharDelete (char* name)
{
	int i = 0;
	for(i = 0;i < 20;i++)
	{
		if(name[i] == 't' && name[i-1] == 'x' && name[i-2] == 't' && name[i-3] == '.')
		{
			name[i+1] = '\0';
			break;
		}
	}
	return name;
}

void PrintProblem(node_problems * pf)
{
	system("@cls||clear");
	char wm , wd , wk;
	wm = wd = wk = ' ';
	if(mardom <21)wm = '*';
	if(darbar <21)wd = '*';
	if(khazane <21)wk = '*';
	printf("_______________________________________________________________\n");
	printf("|       Mardom       |       Darbar       |      Khazane       |\n");
	printf("|     %5d%c         |      %5d%c        |      %5d%c        |\n" , mardom ,wm, darbar ,wd, khazane,wk);
	printf("|____________________|____________________|____________________|________________________________________________________\n\n");
	printf("%s" , pf->problem);
	printf("1- %s" , pf->sol1);
	printf("2- %s\n\n\n\n\n\n" , pf->sol2);
	printf("0- Exit Game\n");
	printf("________________________________________________________________________________________________________________________");
}

node_problems * head = NULL;

int main(){
	srand(time(NULL));
while(1){
	int i = 0;
	int totalfiles = 0;
	system("@cls||clear");
	printf("____________________________\n|Main Menu:                 |\n|1- Start Game              |\n|2- Create File             |\n|3- About this project      |\n|4- Change Theme            |\n|5- Exit                    |\n|___________________________|\n");
	printf("|Created By:                |\n|        Ahmadrezadl        |\n|___________________________|\n");
	char choose = '6';
	fflush(stdin);
	choose = getch();
	while (choose != '1' && choose != '2' && choose != '3' && choose != '4' && choose != '5' && choose != '6')
	choose = getch();
	if (choose == '4')
	{
		fflush(stdin);
		system("@cls||clear");
		printf("Choose your Theme:\n");
		printf("_____________________________\n");
		printf("|1- Blue and White           |\n");
		printf("|____________________________|\n");
		printf("|2- Green and White          |\n");
		printf("|____________________________|\n");
		printf("|3- Red and White            |\n");
		printf("|____________________________|\n");
		printf("|4- Black and White          |\n");
		printf("|____________________________|\n");
		printf("|5- Exit to Menu             |\n");
		printf("|____________________________|\n");
		while (1){
		char theme;
		theme = getch();
		if (theme == '1')
			system("color f1");
		if (theme == '2')
			system("color f2");
		if (theme == '3')
			system("color f4");
		if (theme == '4')
			system("color f0");
			if (theme == '5')
			break;
			}
		continue;
	}
	if (choose == '5')
	{
		return 0;
	}
	if (choose == '3')
	{
		system("@cls||clear");
		fflush(stdin);
		printf("Developed by: Ahmadrezadl\n\n");
		printf("Feauters:\n");
		printf("__________________________________________________________________\n");
		printf("|1- You can exit and save game anywhere with entering '0' Number. |\n");
		printf("|_________________________________________________________________|\n");
		printf("|2- You can play with many users without destroy other's saves    |\n");
		printf("|_________________________________________________________________|\n");
		printf("|3- You can play this game in a visual app.                       |\n");
		printf("|_________________________________________________________________|\n");
		printf("|4- You can add your game's files and advance this game.          |\n");
		printf("|_________________________________________________________________|\n");
		printf("|5- You can read 'Error_log.txt' after recieving error in game.   |\n");
		printf("|_________________________________________________________________|\n");
		printf("|6- You can change Theme in menu!                                 |\n");
		printf("|_________________________________________________________________|\n");
		printf("|7- You can see low val warning (the '*' character behind values) |\n");
		printf("|_________________________________________________________________|\n\n");
		printf("Press Any key to continue...");
		_getch();
		continue;
	}
	if (choose == '2')
	{
		system("@cls||clear");
		FILE *choices;
		choices = fopen("CHOICES.txt" , "a");
		printf("Creating File:\n");
		printf("Enter the FileName: ");
		char filename[30];
		fflush(stdin);
		gets(filename);
		fprintf(choices, "\n%s.txt", filename);
		strcat(filename,".txt");
		system("@cls||clear");
		printf("Editing %s ...\n\nEnter The Problem: " , filename);
		FILE *newfile;
		newfile = fopen(filename,"w");
		fclose(choices);
		char buffer[200];
		int int1;
		int int2;
		int int3;
		gets(buffer);
		fprintf(newfile,"%s\n" , buffer);
		printf("Enter Soulation 1: ");
		gets(buffer);
		fprintf(newfile,"%s\n" , buffer);
		printf("Enter Soulation Consequences of Sol1 (People/Court/Treasury): ");
		fflush(stdin);
		scanf("%d / %d / %d" , &int1 , &int2 , &int3);
		fflush(stdin);
		fprintf(newfile ,"%d\n%d\n%d\n" , int1 , int2 , int3);
		printf("Enter Soulation 2: ");
		gets(buffer);
		fprintf(newfile,"%s\n" , buffer);
		printf("Enter Soulation Consequences of Sol2 (People/Court/Treasury): ");
		fflush(stdin);
		scanf("%d / %d / %d" , &int1 , &int2 , &int3);
		fprintf(newfile ,"%d\n%d\n%d" , int1 , int2 , int3);
		fclose(newfile);
		continue;
	}
	int loadgame = 0;
	system("@cls||clear");
	printf("Enter your name: ");
	char name[20];
	fflush(stdin);
	gets(name);
	printf("Welcome %s!\n" , name);
	strcat(name,".bin");
	char line [200];
	char filenames[20][100];
	if (Exists(name))
	{
		char ans;
		printf("Load Game?\n1- Yes\n2- No\n");
		fflush(stdin);
		ans = getch();
		while(ans != '2' && ans != '1')
		ans = getch();
		if(ans == '2')
			loadgame = 0;
		else
			loadgame = 1;
	}
	else
		loadgame = 0;
		
	if (loadgame == 1)
	{
		FILE *save;
		save = fopen(name,"rb");
		if (save == NULL)
		{
			printf("Error! Cannot Load Game!");
			FILE * errorlog;
			errorlog = fopen("Error_log.txt" ,"w");
			fflush(errorlog);
			fprintf(errorlog , "Error! Cannot Load Game!");
			fclose(errorlog);
			return -1;
		}
		int ingame;
		fread(&ingame, sizeof(int),1,save);
		if(ingame == 0)
		{
			system("@cls||clear");
			printf("Loaded game is ended.\nStarting new game.\nPress any key to continue...");
			fclose(save);
			loadgame = 0;
			fflush(stdin);
			_getch();
		}
		else
		{
			fread(&mardom,sizeof(int) ,1,save);
			fread(&darbar,sizeof(int) ,1,save);
			fread(&khazane,sizeof(int) ,1,save);
			fread(&totalfiles,sizeof(int) , 1 , save);
			for(int k = 0; k < totalfiles;k++)
			{
				fread(&counter[k],sizeof(int),1,save);
			}
			FILE *choices;
		choices = fopen("CHOICES.txt","r");
		if (choices == NULL)
		{
			FILE * errorlog;
			errorlog = fopen("Error_log.txt" , "w");
			fflush(errorlog);
			fprintf(errorlog , "Error! Cannot Find CHOICES.txt\nPlease make sure you putted CHOICES.txt in a same folder.");
			printf("Error! Cannot Find CHOICES.txt ! open Error_log for more info.");
			fclose(errorlog);
			return -1;
		}
		while(fgets(line, sizeof line, choices)!=NULL) 
		{
		strcpy(filenames[i], line);
		LastCharDelete(filenames[i]);
		i++;
		if (i==20)
		break;
		}
	totalfiles = i;
	totalproblems = i;
	head = malloc(sizeof(node_problems));
	if (head == NULL) 
	{
	FILE * errorlog;
	errorlog = fopen("Error_log.txt" , "w");
	fflush(errorlog);
	fprintf(errorlog , "Error! Out of Memory\nContact Ahmadrezadl@aut.ac.ir for more help.");
	printf("Error! Out of Memory.\n Check Error_log.txt for more info");
    return 1;
	}
	FILE *filep;
	
	char buffer [5];
	int headnumber;
	while (counter[headnumber] == 0)headnumber++;
filep = fopen(filenames[headnumber],"r");
	if(filep == NULL)
	{
		FILE * errorlog;
		errorlog = fopen("Error_log.txt" ,"w");
		fflush(errorlog);
		fprintf(errorlog , "Error! Cannot find %s\nPlease make sure you putted %s in a same folder.",filenames[0] , filenames[0]);
		printf("Error! Cannot find %s" , filenames[0]);
		fclose(errorlog);
		return -1;
	}
	head->problemnum = headnumber;
	fgets(head->problem,200,filep);
	fgets(head->sol1,100,filep);
	fgets(buffer,5,filep);
	head->mardom1 = atoi(buffer);
	fgets(buffer,5,filep);
	head->darbar1 = atoi(buffer);
	fgets(buffer,5,filep);
	head->khazane1 = atoi(buffer);
	fgets(head->sol2,100,filep);
	fgets(buffer,5,filep);
	head->mardom2 = atoi(buffer);
	fgets(buffer,5,filep);
	head->darbar2 = atoi(buffer);
	fgets(buffer,5,filep);
	head->khazane2 = atoi(buffer);
	head->next = NULL;
	head->count = counter[0];

	for (i = headnumber+1;i < totalfiles;i++)
	{	
		if (counter[i] == 0)
		continue;
		node_problems * new_node = NULL;
		new_node = malloc(sizeof(node_problems));
		if (new_node == NULL) 
		{
			FILE * errorlog;
			errorlog = fopen("Error_log.txt" , "w");
			fflush(errorlog);
			fprintf(errorlog , "Error! Out of Memory\nContact Ahmadrezadl@aut.ac.ir for more help.");
			printf("Error! Out of Memory.\n Check Error_log.txt for more info");
			fclose(errorlog);
		    return 1;
		}
		filep = fopen(filenames[i],"r");
		if(filep == NULL)
		{
			FILE * errorlog;
			errorlog = fopen("Error_log.txt" ,"w");
			fflush(errorlog);
			fprintf(errorlog , "Error! Cannot find %s\nPlease make sure you putted %s in a same folder.",filenames[i] , filenames[i]);
			printf("Error! Cannot find %s" , filenames[i]);
			fclose(errorlog);
			return -1;
		}
		new_node->problemnum = i;
		fgets(new_node->problem,200,filep);
		fgets(new_node->sol1,100,filep);
		fgets(buffer,5,filep);
		new_node->mardom1 = atoi(buffer);
		fgets(buffer,5,filep);
		new_node->darbar1 = atoi(buffer);
		fgets(buffer,5,filep);
		new_node->khazane1 = atoi(buffer);
		fgets(new_node->sol2,100,filep);
		fgets(buffer,5,filep);
		new_node->mardom2 = atoi(buffer);
		fgets(buffer,5,filep);
		new_node->darbar2 = atoi(buffer);
		fgets(buffer,5,filep);
		new_node->khazane2 = atoi(buffer);
		new_node->next = NULL;
		new_node->count = counter[i];
		Add_End(head,new_node);
		if (i == totalfiles-1)
		{
			new_node->next = head;
		}
	}
	fclose(filep);
		}
	}
	if (loadgame == 0)
	{
		khazane = 50;
		mardom = 50;
		darbar = 50;
		
		FILE *choices;
		
		choices = fopen("CHOICES.txt","r");
		if (choices == NULL)
		{
			FILE * errorlog;
			errorlog = fopen("Error_log.txt" , "w");
			fflush(errorlog);
			fprintf(errorlog , "Error! Cannot Find CHOICES.txt\nPlease make sure you putted CHOICES.txt in a same folder.");
			printf("Error! Cannot Find CHOICES.txt ! open Error_log for more info.");
			fclose(errorlog);
			return -1;
		}
		while(fgets(line, sizeof line, choices)!=NULL) 
		{
		strcpy(filenames[i], line);
		LastCharDelete(filenames[i]);
		i++;
		if (i==20)
		break;
		}
	totalfiles = i;
	totalproblems = i;
	head = malloc(sizeof(node_problems));
	if (head == NULL) 
	{
	FILE * errorlog;
	errorlog = fopen("Error_log.txt" , "w");
	fflush(errorlog);
	fprintf(errorlog , "Error! Out of Memory\nContact Ahmadrezadl@aut.ac.ir for more help.");
	printf("Error! Out of Memory.\n Check Error_log.txt for more info");
    return 1;
	}
	FILE *filep;
	filep = fopen(filenames[0],"r");
	if(filep == NULL)
	{
		FILE * errorlog;
		errorlog = fopen("Error_log.txt" ,"w");
		fflush(errorlog);
		fprintf(errorlog , "Error! Cannot find %s\nPlease make sure you putted %s in a same folder.",filenames[0] , filenames[0]);
		printf("Error! Cannot find %s" , filenames[0]);
		fclose(errorlog);
		return -1;
	}
	char buffer [5];
	head->problemnum = 0;
	counter[0] = 3;
	fgets(head->problem,200,filep);
	fgets(head->sol1,100,filep);
	fgets(buffer,5,filep);
	head->mardom1 = atoi(buffer);
	fgets(buffer,5,filep);
	head->darbar1 = atoi(buffer);
	fgets(buffer,5,filep);
	head->khazane1 = atoi(buffer);
	fgets(head->sol2,100,filep);
	fgets(buffer,5,filep);
	head->mardom2 = atoi(buffer);
	fgets(buffer,5,filep);
	head->darbar2 = atoi(buffer);
	fgets(buffer,5,filep);
	head->khazane2 = atoi(buffer);
	head->next = NULL;
	head->count = 3;
	for (i = 1;i < totalfiles;i++)
	{	
		node_problems * new_node = NULL;
		new_node = malloc(sizeof(node_problems));
		if (new_node == NULL) 
		{
			FILE * errorlog;
			errorlog = fopen("Error_log.txt" , "w");
			fflush(errorlog);
			fprintf(errorlog , "Error! Out of Memory\nContact Ahmadrezadl@aut.ac.ir for more help.");
			printf("Error! Out of Memory.\n Check Error_log.txt for more info");
			fclose(errorlog);
		    return 1;
		}
		filep = fopen(filenames[i],"r");
		if(filep == NULL)
		{
			FILE * errorlog;
			errorlog = fopen("Error_log.txt" ,"w");
			fflush(errorlog);
			fprintf(errorlog , "Error! Cannot find %s\nPlease make sure you putted %s in a same folder.",filenames[i] , filenames[i]);
			printf("Error! Cannot find %s" , filenames[i]);
			fclose(errorlog);
			return -1;
		}
		new_node->problemnum = i;
		fgets(new_node->problem,200,filep);
		fgets(new_node->sol1,100,filep); 
		fgets(buffer,5,filep);
		new_node->mardom1 = atoi(buffer);
		fgets(buffer,5,filep);
		new_node->darbar1 = atoi(buffer);
		fgets(buffer,5,filep);
		new_node->khazane1 = atoi(buffer);
		fgets(new_node->sol2,100,filep);
		fgets(buffer,5,filep);
		new_node->mardom2 = atoi(buffer);
		fgets(buffer,5,filep);
		new_node->darbar2 = atoi(buffer);
		fgets(buffer,5,filep);
		new_node->khazane2 = atoi(buffer);
		new_node->next = NULL;
		new_node->count = 3;
		counter[i] = 3;
		Add_End(head,new_node);
		if (i == totalfiles-1)
		{
			new_node->next = head;
		}
	}
	fclose(filep);
	} 
	node_problems * currentproblem = NULL;
	currentproblem = head;
	while (mardom > 0 && khazane > 0 && darbar > 0 && (mardom + darbar + khazane) / 3 > 9)
	{
		if (totalproblems == 0)
		{
			FILE *choices;
		
		choices = fopen("CHOICES.txt","r");
		if (choices == NULL)
		{
			FILE * errorlog;
			errorlog = fopen("Error_log.txt" , "w");
			fflush(errorlog);
			fprintf(errorlog , "Error! Cannot Find CHOICES.txt\nPlease make sure you putted CHOICES.txt in a same folder.");
			printf("Error! Cannot Find CHOICES.txt ! open Error_log for more info.");
			fclose(errorlog);
			return -1;
		}
		while(fgets(line, sizeof line, choices)!=NULL) 
		{
		strcpy(filenames[i], line);
		LastCharDelete(filenames[i]);
		i++;
		if (i==20)
		break;
		}
	totalfiles = i;
	totalproblems = i;
	head = malloc(sizeof(node_problems));
	if (head == NULL) 
	{
	FILE * errorlog;
	errorlog = fopen("Error_log.txt" , "w");
	fflush(errorlog);
	fprintf(errorlog , "Error! Out of Memory\nContact Ahmadrezadl@aut.ac.ir for more help.");
	printf("Error! Out of Memory.\n Check Error_log.txt for more info");
	fclose(errorlog);
    return 1;
	}
	FILE *filep;
	filep = fopen(filenames[0],"r");
	if(filep == NULL)
	{
		FILE * errorlog;
		errorlog = fopen("Error_log.txt" ,"w");
		fflush(errorlog);
		fprintf(errorlog , "Error! Cannot find %s\nPlease make sure you putted %s in a same folder.",filenames[0] , filenames[0]);
		printf("Error! Cannot find %s" , filenames[0]);
		fclose(errorlog);
		return -1;
	}
	char buffer [5];
	head->problemnum = 0;
	counter[0] = 3;
	fgets(head->problem,200,filep);
	fgets(head->sol1,100,filep);
	fgets(buffer,5,filep);
	head->mardom1 = atoi(buffer);
	fgets(buffer,5,filep);
	head->darbar1 = atoi(buffer);
	fgets(buffer,5,filep);
	head->khazane1 = atoi(buffer);
	fgets(head->sol2,100,filep);
	fgets(buffer,5,filep);
	head->mardom2 = atoi(buffer);
	fgets(buffer,5,filep);
	head->darbar2 = atoi(buffer);
	fgets(buffer,5,filep);
	head->khazane2 = atoi(buffer);
	head->next = NULL;
	head->count = 3;
	for (i = 1;i < totalfiles;i++)
	{	
		node_problems * new_node = NULL;
		new_node = malloc(sizeof(node_problems));
		if (new_node == NULL) 
		{
			FILE * errorlog;
			errorlog = fopen("Error_log.txt" , "w");
			fflush(errorlog);
			fprintf(errorlog , "Error! Out of Memory\nContact Ahmadrezadl@aut.ac.ir for more help.");
			printf("Error! Out of Memory.\n Check Error_log.txt for more info");
			fclose(errorlog);
		    return 1;
		}
		filep = fopen(filenames[i],"r");
		if(filep == NULL)
		{
			FILE * errorlog;
			errorlog = fopen("Error_log.txt" ,"w");
			fflush(errorlog);
			fprintf(errorlog , "Error! Cannot find %s\nPlease make sure you putted %s in a same folder.",filenames[i] , filenames[i]);
			printf("Error! Cannot find %s" , filenames[i]);
			fclose(errorlog);
			return -1;
		}
		new_node->problemnum = i;
		counter[i] = 3;
		fgets(new_node->problem,200,filep);
		fgets(new_node->sol1,100,filep);
		fgets(buffer,5,filep);
		new_node->mardom1 = atoi(buffer);
		fgets(buffer,5,filep);
		new_node->darbar1 = atoi(buffer);
		fgets(buffer,5,filep);
		new_node->khazane1 = atoi(buffer);
		fgets(new_node->sol2,100,filep);
		fgets(buffer,5,filep);
		new_node->mardom2 = atoi(buffer);
		fgets(buffer,5,filep);
		new_node->darbar2 = atoi(buffer);
		fgets(buffer,5,filep);
		new_node->khazane2 = atoi(buffer);
		new_node->next = NULL;
		new_node->count = 3;
		Add_End(head,new_node);
		if (i == totalfiles-1)
		{
			new_node->next = head;
		}
	}
	fclose(filep);
		}
		currentproblem = head;
		srand(time(NULL));
		int np = rand();
		np = (np%(totalproblems)) + 1;
		char choosesol;
		currentproblem = Find_Node(head,currentproblem,np);
		PrintProblem(currentproblem);
		fflush(stdin);
		choosesol = getch();
		while (choosesol != '1' && choosesol != '2' && choosesol !='0')choosesol = getch();
		if (choosesol == '0')
		{
			system("@cls||clear");
			printf("Exit Game.\n\n Save Game?\n1- Yes\n2- No");
			fflush(stdin);
			choosesol = getch();
			while (choosesol != '1' && choosesol != '2')
			{
				choosesol = getch();
			}
			if (choosesol == '1')
			{
				FILE *save;
				save = fopen(name,"wb");
				if (save == NULL)
				{
					printf("Error! Cannot Save Game!");
					FILE * errorlog;
					errorlog = fopen("Error_log.txt" ,"w");
					fflush(errorlog);
					fprintf(errorlog , "Error! Cannot Save Game!");
					fclose(errorlog);
					return -1;
				}
				int one = 1;
				fwrite(&one, sizeof(int), 1, save);
				fwrite(&mardom,sizeof(int) ,1,save);
				fwrite(&darbar,sizeof(int) ,1,save);
				fwrite(&khazane,sizeof(int) ,1,save);
				fwrite(&totalfiles,sizeof(int) , 1 , save);
				for(int k = 0; k < totalfiles;k++)
				{
					fwrite(&counter[k],sizeof(int),1,save);
				}
				return 0;
			}
			if (choosesol == '2')
			return 0;
		}
		if (choosesol == '1')
		{
			mardom += currentproblem->mardom1;
			khazane += currentproblem->khazane1;
			darbar += currentproblem->darbar1;
			if(darbar>100)darbar = 100;
			if(mardom>100)mardom = 100;
			if(khazane>100)khazane = 100;
			counter[currentproblem->problemnum]--;
			Remove_Node(head,np);
			
			continue;
			
		}
		if (choosesol == '2')
		{
			
			mardom += currentproblem->mardom2;
			khazane += currentproblem->khazane2;
			darbar += currentproblem->darbar2;
			if(darbar>100)darbar = 100;
			if(mardom>100)mardom = 100;
			if(khazane>100)khazane = 100;
			counter[currentproblem->problemnum]--;
			Remove_Node(head,np);
			
			continue;
		}
	}
	system("@cls||clear");
	printf("Exit Game.\n\n Save Game?\n1- Yes\n2- No");
	char n;
	fflush(stdin);
	n = getch();
			while (n != '1' && n != '2')
			{
				n = getch();
			}
	if (n == '2')
	return 0;
	FILE *save;
	save = fopen(name,"wb");
	if (save == NULL)
	{
		printf("Error! Cannot Save Game!");
		FILE * errorlog;
		errorlog = fopen("Error_log.txt" ,"w");
		fflush(errorlog);
		fprintf(errorlog , "Error! Cannot Save Game!");
		fclose(errorlog);
		return -1;
	}
	fflush(save);
	
	int zero = 0;
	fwrite(&zero, sizeof(int),1,save);
	return 0;
}
}
