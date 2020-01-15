/*
U mnie pernamentnie oznacza dodatnie do pliku ~/.bashrc. Można w zależności od systemu dodawać do pliku /etc/enviroment lub ~/.bash_profile. U mnie to nie występuje.
W specyfikacji nie ma ściśle określone, że na wszystkich systemach Linux, więc na MX Linux program działa (fork Debiana, wykorzystujacy basha jako shella).
Mój skrypt bedzie wymagał otworzenia nowego okna terminala by zobaczyć ustawioną ścieżke, a tym samym dodać/usunąć kolejne. Tak działa linux, innej metody nie znalazłem.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>

char *strremove(char *string, const char *remove) {
    size_t len = strlen(remove);
    if (len > 0) {
        char *p = string;
        while ((p = strstr(p, remove)) != NULL) {
            memmove(p, p + len, strlen(p + len) + 1);
        }
    }
    return string;
}	

char *addOrDeletePath(char path[]){
	char *newPath = realpath(path,NULL); //ujednolicenie ścieżek do katalogu
		
	if(newPath != NULL){
		strncat(newPath, ":", 1); //żeby wyróżnić katalog w PATH dodaje się mu na koniec : jako znak rozdzielenia.
		
		if(strstr(getenv("PATH"),newPath) == NULL){ //Sprawdzanie czy katalog znajduje się w zmiennej PATH
			printf("Takiego katalogu nie ma w PATH, zostanie dodany\n");
			
			strncat(newPath,getenv("PATH"),strlen(getenv("PATH"))+1);
			
			return newPath;
			
		}else{
			printf("Taki katalog znajduje się w PATH, zostanie usunięty\n");
			
			char *rightPath = strremove(getenv("PATH"),newPath);
			
			return rightPath;
		
		}
	}else{
		printf("Wpisz poprawna sciezke\n");
		
		return NULL;
	}
	
}

void savePermanent(char *path)
{
	FILE *mainBashRC;
	FILE *newBashRC;
	
	char BashRCfile[PATH_MAX]; // otworz glowny .bashrc
	strcat(BashRCfile, getenv("HOME"));
	strcat(BashRCfile, "/.bashrc");

	char BashRCfileBak[PATH_MAX] = ""; //otworzy backupowy .bashrc
	strcat(BashRCfileBak, getenv("HOME"));
	strcat(BashRCfileBak, "/.bashrc.bak");

	char newFile[PATH_MAX] = ""; //otworz nowy .bashrc
	strcat(newFile, getenv("HOME"));
	strcat(newFile, "/.bashrc.new");
	
	char pathLineDescriptor2[PATH_MAX] = "#NNJG2634LN2GS2TN";
	char pathLineDescriptor[PATH_MAX] = "export PATH=";	
		
	char lineStart[PATH_MAX];
	
	mainBashRC = fopen(BashRCfile, "r");
	newBashRC = fopen(newFile, "w");
	
	if(mainBashRC == NULL)
		perror(strcat("NIE OTWORZYLEM: ", BashRCfile));
	
	if(newBashRC == NULL)
		perror(strcat("NIE OTWORZYLEM: ", newFile));
		
	//przepisz caly plik, ignoruj linie z pathlineDescripto2 i pathlineDescriptor
	while(fgets(lineStart, PATH_MAX, mainBashRC ) != NULL){
		if ((strstr(lineStart, pathLineDescriptor)) != NULL || (strstr(lineStart, pathLineDescriptor2)) != NULL){
            continue;
        }else {
			fputs(lineStart, newBashRC);
        }
	}
	
	fclose(mainBashRC);
	
	//dodaj linijki linijki
	fputs("#NNJG2634LN2GS2TN", newBashRC);
	fputc('\n', newBashRC);	
	fputs("export PATH=", newBashRC);
	fputs(path, newBashRC);
	fputc('\n', newBashRC);	
	
	
	fclose(newBashRC);
	
	// zmiana nazw plikow
	rename(BashRCfile, BashRCfileBak);
	rename(newFile, BashRCfile);
	chmod(BashRCfile,0755);
}

int main(int argc, char **argv)
{	
	char *path;
	
	if(argc == 2){ //przekazanie katalogu do dodania do path jako paramentr
		path = addOrDeletePath(argv[1]);
	}else if(argc <= 2){ // jeżeli nie ma parametru, to bierze bierzący katalog
		path = addOrDeletePath(getenv("PWD"));		
	}else{
		printf("Nie poprawne użycie programu: program przyjmuje jeden parametr jako katalog albo jeżeli wywołanie nastepuje bez parametru to pobiera bierzący katalog\n");
		return 1;
	}
	
	if(path == NULL){
		printf("Modyfikacja ściezki nie powiodła się\n");
	}else{
		savePermanent(path);
		printf("Wykonano, otwórz nowe okno terminala by wczytać ustawienia\n");
		return 0;
	}
	
	
}

