#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

#define BUFF_SIZE 1024
#define PATHS_BUFF_SIZE 32000

#define USAGE "Usage: ./add2path [PATH]"
#define RCFILE ".bashrc"

/*
 * Dopisuje linijkę "source ~/.add2path" do pliku RCFILE (domyślnie .bashrc)
 */
void inject_add2path() {
	char rcpath[BUFF_SIZE];
	sprintf(rcpath, "%s/%s", getenv("HOME"), RCFILE);

	// tryb "a+" oznacza możliwość czytania i dopisywania na koniec pliku
	FILE *rcfile = fopen(rcpath, "a+");
	if (rcfile == NULL) {
		perror(RCFILE);
		exit(EXIT_FAILURE);
	}

	// szukamy linijki "source ~/.add2path"
	char buffer[BUFF_SIZE];
	while (fgets(buffer, BUFF_SIZE, rcfile)) {
		if (strcmp(buffer, "source ~/.add2path\n") == 0) {
			break;
		}
	}

	// sprawdz czy pętla zatrzymała się z powodu jakiegoś błędu
	if (ferror(rcfile)) {
		fprintf(stderr, "Wystąpił błąd podczas czytania pliku %s\n", RCFILE);
		exit(EXIT_FAILURE);
	}

	// jesli przeczytano cały plik, tzn. że nie znaleziono linijki, zatem dopisujemy
	if (feof(rcfile)) {
		fprintf(rcfile, "source ~/.add2path\n");
	}

	fclose(rcfile);
}

/*
 * Otwiera plik .add2path i wczytuje zawartość zmiennej ADD2PATH
 */
char *load_paths(void) {
	char dotpath[BUFF_SIZE];
	sprintf(dotpath, "%s/%s", getenv("HOME"), ".add2path");
	FILE *file = fopen(dotpath, "r");

	char *paths = calloc(PATHS_BUFF_SIZE, sizeof(char));
	if (file != NULL) {
		fscanf(file, "ADD2PATHS=\"%[^\"]s", paths);
		fclose(file);
	}

	return paths;
}

/*
 * Konwertuje stringa zawierającego ścieżki odzielone ":" na
 * tablicę ścieżek do łatwiejszego manipulowania w programie
 */
char **split_paths(char *paths) {
	// alokujemy pierwszy poziom tablicy, tj. miejsce na pointery do ścieżek
	char **result = calloc(sizeof(result), 1024);
	if (result == NULL) {
		fprintf(stderr, "Błąd alokacji pamięci\n");
		exit(EXIT_FAILURE);
	}

	int n = 0;
	int len;

	char *token = strtok(paths, ":");
	while (token != NULL) {
		len = strlen(token);
		// alokujemy miejsce dla ścieżki w naszej tablicy
		result[n] = calloc(sizeof(char), len + 1);
		// kopiujemy to co znalazł strtok do naszej tablicy
		strcpy(result[n], token);
		n++;
		// szukamy kolejny token
		token = strtok(NULL, ":");
	}

	return result;
}

/*
 * Dla każdej ścieżki we wcześniej obliczonej tablicy ścieżek
 * wpisujemy ją na nowo do pliku .add2paths chyba, że zadana
 * ścieżka jest ścieżką podaną na wejsciu - wtedy jej nie zapisujemy
 * co w efekcie usuwa ją z pliku .add2paths
 */
void save_paths(char **paths, const char *path) {
	char dotpath[BUFF_SIZE];
	sprintf(dotpath, "%s/%s", getenv("HOME"), ".add2path");

	// otwieramy plik w trybie "w" czyli usuwamy w nim wszystko co było
	FILE *file = fopen(dotpath, "w");

	if (file == NULL) {
		perror(dotpath);
		exit(EXIT_FAILURE);
	}

	fprintf(file, "ADD2PATHS=\"");

	int found = 0;
	for (int i = 0; paths[i]; i++) {
		if (strcmp(paths[i], path) == 0) {
			// scieżką jest ścieżką podaną na wejsciu więc jej do pliku nie wpisujemy
			printf("'%s' zostało usunięte\n", path);
			found = 1;
		} else {
			// w p.p wpisujemy ją do pliku
			fprintf(file, ":%s", paths[i]);
		}
	}

	// jeśli nie znaleziono scieżki podanej na wejściu w tablicy scieżek to znaczy
	// ze musimy ją teraz dopisać
	if (!found) {
		printf("'%s' zostało dodane\n", path);
		fprintf(file, ":%s", path);
	}
	
	fprintf(file, "\"\nexport PATH=\"${PATH}${ADD2PATHS}\"\n");
	fclose(file);
}

void add2path(const char *path) {
	inject_add2path();

	char *paths = load_paths();
	char **splitted_paths = split_paths(paths);

	save_paths(splitted_paths, path);
}

int main(int argc, char* argv[]) {
	const char *path = argc > 1 ? argv[1] : getcwd(NULL, 0);

	// normalizuj ścieżkę (wykrywa błędne ścieżki, zamienia relatywne na absolutne itp.
	const char *rpath = realpath(path, NULL);
	
	if (rpath == NULL) {
		perror(path);
		exit(EXIT_FAILURE);
	}

	add2path(path);

	return 0;
}