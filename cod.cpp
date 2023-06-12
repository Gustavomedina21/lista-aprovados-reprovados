#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOTAS 30
#define MAX_NOMES 30


typedef struct {   //notas
		int matricula;
		float not1;
		float not2;
		float not3;
	} nota;
	float media (float m1,float m2,float m3){
	return (m1+m2+m3)/3; //media 
	}
	
 typedef struct {
		int matricul;
		char nome [51];
	} nome;
	   
int main() {
	FILE *no; //nome e notas
	FILE *aprovados; //aprovados
	FILE *reprovados; //reprovados
	FILE *notz;//nomes e matriculas
	nota n;
	char linha [30];
	nota notas[MAX_NOTAS];
	nome nomes[MAX_NOMES];
	int num_notas = 0;
	int num_nomes = 0;
	
	no = fopen("notas.txt", "r") ;
	if (no == NULL) {
		printf("Erro na abertura\n");
	
		exit (1);
	}
	//linhas das notas
	while (fgets(linha, 30, no) != NULL && num_notas < MAX_NOTAS) {
		sscanf(linha, "%d %f %f %f", &notas[num_notas].matricula, &notas[num_notas].not1, &notas[num_notas].not2, &notas[num_notas].not3);
		num_notas++;
	}
		
    for (int i = 0; i < num_notas; i++) {
        printf("%d %.2f %.2f %.2f\n", notas[i].matricula, notas[i].not1, notas[i].not2, notas[i].not3);          
    }		//linhas da matricula e nomes
		notz = fopen("nomes.txt", "r") ;
	if (notz == NULL) {
		printf("Erro na abertura\n");
		
		exit (1);
	}
	 //linhas da media
	while(fgets(linha, 30, notz) != NULL && num_nomes < MAX_NOMES) {
		
		sscanf(linha, "%d %[^\n]\n", &(nomes[num_nomes].matricul), nomes[num_nomes].nome);
		num_nomes++;
	}
	
    for (int i = 0; i < num_nomes; i++) {
        printf("%d %s\n", nomes[i].matricul, nomes[i].nome);          
    }
	for (int i = 0; i < num_nomes; i++) {
    float media_aluno = media(notas[i].not1, notas[i].not2, notas[i].not3);
    printf("Matricula: %d - Nome: %s - Media: %.2f\n", nomes[i].matricul, nomes[i].nome, media_aluno);          
}
 //linhas aprovados
aprovados = fopen("aprovados.txt", "w");
if (aprovados == NULL) {
    printf("Erro na abertura do arquivo de aprovados\n");
   
    exit(1);
}
for (int i = 0; i < num_notas; i++) {
    float media_aluno = media(notas[i].not1, notas[i].not2, notas[i].not3);
    if (media_aluno >= 6.0) {
        fprintf(aprovados, "%d %s %.3f\n", nomes[i].matricul, nomes[i].nome, media_aluno);
    }
}

fclose(aprovados);
  //linhas dos reprovados
 reprovados = fopen("reprovados.txt", "w");
if (reprovados == NULL) {
    printf("Erro na abertura do arquivo de reprovados\n");
   
    exit(1);
}
for (int i = 0; i < num_notas; i++) {
    float media_aluno = media(notas[i].not1, notas[i].not2, notas[i].not3);
    if (media_aluno < 6.0) {
        fprintf(reprovados, "%d %s %.3f\n", nomes[i].matricul, nomes[i].nome, media_aluno);
    }
}
fclose(reprovados);

float class_sum = 0;
int num_students = 0;

for (int i = 0; i < num_nomes; i++) {
    float media_aluno = media(notas[i].not1, notas[i].not2, notas[i].not3);
    printf("Matricula: %d - Nome: %s - Media: %.2f\n", nomes[i].matricul, nomes[i].nome, media_aluno);
    class_sum += media_aluno;
    num_students++;
}

float class_avg = class_sum / num_students;
printf("Class average: %.2f\n", class_avg);
		
	return 0;

}
