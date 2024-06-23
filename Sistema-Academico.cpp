#include <iostream>
#include <locale.h>
#include <string>
#include <vector>

using namespace std;

struct Grade{
    string componenteCurricular;
    string professor;
    int horaAula; 
    string horario; 
};

struct Notas{
    float nota1;
    float nota2;
    float media;
};


struct Disciplinas{
    Grade disciplina;
    Notas notas;
};

struct Aluno {
    string nome;
    int matricula;
    string curso;
    string turno;
    string cpf;
    string ingresso;
    string dataNascimento;
    int periodo;
    Disciplinas disciplinas[2];

};
struct Turma{
    int ID;
    Grade disciplina;
    Aluno *alunos[40];
    int totalAlunos = 0;
    float media;

};

Turma *armazemT[100];
Aluno *armazem[100];

void cadastroDisciplina(Grade disciplinas){
    setlocale(LC_ALL, "portuguese");
    cout << "Insira o componente curricular: " << endl;
    getline(cin, disciplinas.componenteCurricular);
    cout << "Insira o Professor do componente curricular: " << endl;
    getline(cin, disciplinas.professor);
    cout << "Insira o total de horas de " << disciplinas.componenteCurricular <<": " << endl;
    cin >> disciplinas.horaAula; 
    cout << "Insira os horários das aulas de " << disciplinas.componenteCurricular << ": " << endl;
    getline(cin, disciplinas.horario);
}

void cadastroAluno(){
    setlocale(LC_ALL, "portuguese");
    string palavra = "sim;";
    int cont = 0 ;
    while(palavra == "sim"){
    cout << "=============================================================================" << endl;
    cout << "Insira o nome do aluno a ser cadastrado: " << endl;
    getline(cin, armazem[cont]->nome);
    cout << "Insira o número do CPF do aluno " << armazem[cont]->nome << ": " << endl;
    cin >> armazem[cont]->cpf;
    cout << "Insira a data de nascimento do aluno " << armazem[cont]->nome << ": " << endl;
    getline(cin, armazem[cont]->dataNascimento);
    cout << " " <<endl;
    cout << "Insira o curso do aluno " << armazem[cont]->nome << ": "<<  endl;
    getline(cin, armazem[cont]->curso);
    cout << " " <<endl;
    cout << "Insira o turno do curso: " << endl;
    getline(cin, armazem[cont]->turno);
    cout << " " <<endl;
    cout << "Insira a data de ingresso do aluno " << armazem[cont]->nome << ": " << endl;
    getline(cin, armazem[cont]->ingresso);
    cout << " " <<endl;
    cout << "Insira o número da matricula do aluno " << armazem[cont]->nome << ": " << endl;
    cin >> armazem[cont]->matricula;
    cout << " " <<endl;
    cout << "Insira o numero do período do aluno " << armazem[cont]->nome << ": " << endl;
    cin >> armazem[cont]->periodo;
    cout << "=============================================================================" <<endl;
    cout << " " <<endl;
        }

}
void calcularnotas(){
    
    setlocale(LC_ALL, "portuguese");

    string palavra, componente;
    int matricu;
    int cont = 0;
    palavra = "sim";
    while(palavra == "sim"){
        cout << "================================" << endl;
        cout << "      Atribuição de notas" << endl;
        cout << "================================" << endl;
        cout << "Qual aluno deseja fazer a atribuição? Insira a matricula: " << endl;
        cin >> matricu; 
        cout << "Insira a disciplina: " << endl;
        cin >> componente;
        if(matricu == armazem[cont]->matricula){
            for(int i = 0; i < 2; i++){
                if(componente == armazem[cont]->disciplinas[i].disciplina.componenteCurricular){
                    cout << "Insira a primeira nota: " << endl;
                    cin >> armazem[cont]->disciplinas[i].notas.nota1;
                    cout << "Insira a segunda nota: " << endl;
                    cin >> armazem[cont]->disciplinas[i].notas.nota2;
                    armazem[cont]->disciplinas[i].notas.media = (armazem[cont]->disciplinas[i].notas.nota1 + armazem[cont]->disciplinas[i].notas.nota2) /2;
                }
            }
        }
        cout << "Deseja atribuir outras notas? sim ou não" << endl;
        cin >> palavra;
        system("cls");
    }
}
void armazenar(){
    setlocale(LC_ALL, "portuguese");

    string palavra;
    cout << "Deseja cadastrar aluno? " << endl;
    cin >> palavra;
    while(palavra == "sim"){
        cout << "=================================" << endl;
        cout << "         Cadastro Aluno" << endl;
        cout << "=================================" << endl;
        cadastroAluno();
        cout << "=================================" << endl;
        cout << "        Aluno cadastrado" << endl;
        cout << "=================================" << endl;
        system("cls");
        cout << "Deseja cadastrar aluno? sim ou nao " << endl;
        cin >> palavra;
    }
}
void cadastroTurma(){
    setlocale(LC_ALL, "portuguese");
    string confirmacao = "sim";
    int aux3 = 0;
    while(confirmacao == "sim"){
        
        cout << "================================" << endl;
        cout << "     Cadastro da disciplina" << endl;
        cout << "================================" << endl;
        cout << " " << endl;
        cout << "Insira o ID da Turma: " << endl;
        cin >> armazemT[aux3]->ID;
        cadastroDisciplina(armazemT[aux3]->disciplina);
        cout << "===============================" << endl;
        cout << "     Disciplina cadastrada" << endl;
        cout << "===============================" << endl;
        system("cls");
        int matricu;
        string palavra = "sim";
        while(palavra == "sim"){
            cout << "================================" << endl;
            cout << "        Matricular Aluno" << endl;
            cout << "================================" << endl;
            cout << " " << endl;
            cout << "Insira o número da matricula do aluno a ser matriculado na disciplina: " << endl;
            cin >> matricu;
            for(int i = 0; i < 100; i++){
                if(matricu == armazem[i]->matricula){
                    armazemT[aux3]->alunos[armazemT[aux3]->totalAlunos] = armazem[i];
                    for (int l = 0; l < 2; l++){
                        if(armazem[i]->disciplinas[l].disciplina.componenteCurricular.empty() && 
                        armazem[i]->disciplinas[l].disciplina.professor.empty() && armazem[i]->disciplinas[l].disciplina.horario.empty() && 
                        armazem[i]->disciplinas[l].disciplina.horaAula == 0){
                            armazem[i]->disciplinas[l].disciplina = armazemT[aux3]->disciplina;
                        
                        }
                    }                
                }
                    
                cout << "================================" << endl;
                cout << "        Aluno matriculado" << endl;
                cout << "================================" << endl;
                
            }
            armazemT[aux3]->totalAlunos++;
            
            system("cls");
            cout << "Deseja matricular aluno? sim ou nao" << endl;
            cin >> palavra;
            system("cls");
        }
        aux3++;
        system("cls");
        cout << "Dejesa cadastrar outra disciplina? sim ou não" << endl;
        cin >> confirmacao;
        system("cls");
 
    } 
}   

void mediaTurma(){
    setlocale(LC_ALL, "portuguese");
    int num;
    cout << "Digite o ID da turma: " << endl;
    cin >> num;
    int soma = 0;
    for(int i = 0; i < 100; i++){
        if(num == armazemT[i]->ID){
            cout << "================================" << endl;
            cout << "        Media da turma ("")" << endl;
            cout << "================================" << endl;
            for(int j = 0; j < armazemT[i]->totalAlunos; j++){
                soma += armazemT[i]->alunos[j]->disciplinas->notas.media;
                armazemT[i]->media = soma / armazemT[i]->totalAlunos;    
            }
            cout << "Media da turma: " << armazemT[i]->media << endl;
        }   
    }
}

void pause(){
    cout << '\n'
         << "Pressione Enter:";
    char a;
    cin.ignore();
    cin.get(a);
}

void exibirTurma(){
    setlocale(LC_ALL, "portuguese");
    int idDisciplina;

    cout << "Qual o ID da disciplina que deseja exibir a turma: " << "\n";
    cin >> idDisciplina;

    for(int i = 0; i < 100; ++i){
        if(armazemT[i]->ID == idDisciplina){
            cout << "================================" << endl;
            cout << "         Dados da Turma" << endl;
            cout << "================================" << endl;
            cout << "ID da Turma: " << armazemT[i]->ID << endl;
            cout << "Componente Curricular: "<< armazemT[i]->disciplina.componenteCurricular << endl;
            cout << "Professor: " << armazemT[i]->disciplina.professor << endl;
            cout << "Total de horas: " << armazemT[i]->disciplina.horaAula << endl;
            cout << "Horário: " << armazemT[i]->disciplina.horario << endl;
            cout << "Total de Alunos na turma: "<< armazemT[i]->totalAlunos << endl;
            for(int i = 0; i < armazemT[i]->totalAlunos; i++){
                cout << "Aluno " << i + 1 << ":" << armazemT[i]->alunos[i]->nome << "\n" << "Matrícula: " << armazemT[i]->alunos[i]-> matricula << endl;
                cout << "-------------------------------------------------" << endl;
            }

            return;
            
        }
        cout << "Essa turma não foi encontrada. Verifique se o ID foi digitado corretamente e tente novamente!" << endl;
    }
    mediaTurma();
}

void exibirNotaAluno(){
    setlocale(LC_ALL, "portuguese");
    int matriculaAluno, idDisciplina;

    cout << "Digite a matrícula do aluno que deseja visualizar as notas: " << endl;
    cin >> matriculaAluno;
    cout << "Digite o ID da disciplina: " << endl;
    cin >> idDisciplina;

    for(int i = 0; i < 100; ++i){
        if(armazemT[i]->ID == idDisciplina){
            for(int j = 0; j < armazemT[i]->totalAlunos; ++j){
                if(armazemT[i]->alunos[j]->matricula == matriculaAluno){
                    cout << "================================" << endl;
                    cout << " Notas do Aluno - Matrícula: " << matriculaAluno << endl;
                    cout << "================================" << endl;
                    cout << "Aluno: " << armazemT[i]-> alunos[j] -> nome << endl;
                    cout << "Nota 1: " << armazemT[i]->alunos[j]->disciplinas[0].notas.nota1 << endl;
                    cout << "Nota 2: " << armazemT[i]->alunos[j]->disciplinas[0].notas.nota2 << endl;
                    cout << "Média: " << armazemT[i]->alunos[j]->disciplinas[0].notas.media << endl;
                    return;
                }
            }    
            cout << "Aluno com matricula: " << matriculaAluno << "não encontrada na disciplina de ID: " << idDisciplina << "." << "\n" << "Confira se a matricula esta escrita corretamente e tente novamente."<< endl;
            return; 
        }
        cout << "A Disciplina com o ID: " << idDisciplina << "não foi encontrada." << "\n" << "Confira se o ID foi escrito de forma corretamente e tente novamente" << endl;
    }
}

void exibirDados(){
    setlocale(LC_ALL, "portuguese");
    int aux1;
    cout << "Digite a matricula do aluno que deseja vizualiar: " << endl;
    cin >> aux1;
    for(int i = 0; i < 100; i++){
        if(aux1 == armazem[i]->matricula){
            cout << "=============================================================================" << endl;
            cout << "Dados do aluno (" << armazem[i]->matricula << ")" << endl;
            cout << " " << endl;
            cout << "Nome: " << armazem[i]->nome << endl;
            cout << "Matricula: (" << armazem[i]->matricula << ")" << endl;
            cout << "CPF: " << armazem[i]->cpf << endl;
            cout << "Data de nascimento: " <<armazem[i]->dataNascimento << endl;
            cout << "Curso: " << armazem[i]->curso << endl;
            cout << "Turno: " << armazem[i]->turno << endl;
            cout << "Data de ingresso: " << armazem[i]->ingresso << endl;
            cout << "Periodo atual: " << armazem[i]->periodo << "ª" << endl;
            cout << "=============================================================================" << endl; 
            cout << " " <<endl;
        }
    }     
}



void menuInicial(bool &iniciarSistema){
    setlocale(LC_ALL, "portuguese");
    
    char escolha;
    do
     {

        cout << "Selecione uma das opções para prosseguir:" << '\n'
            << "** 1. Cadastrar Aluno" << '\n'
            << "** 2. Cadastrar Turma" << '\n'
            << "** 3. Exibir dados do Aluno" << '\n'
            << "** 4. Exibir notas do Aluno"
            << "** 5. Exibir dados da turma" << '\n'
            << "** 6. Desenvolvedores" << '\n'
            << "** 7. Sair" << '\n'
            << ">> ";

        cin >> escolha;

        switch (escolha)
        {
        case '1':
            cadastroAluno();
            pause();
            menuInicial(iniciarSistema);
            
            break;
        case '2':
            cadastroTurma();
            pause();
            menuInicial(iniciarSistema);
            
            break;
        case '3':
            exibirDados();
            pause();
            menuInicial(iniciarSistema);

            break;
        case '4':
            exibirNotaAluno();
            pause();
            menuInicial(iniciarSistema);

            break;            
        case '5':
            exibirTurma();
            pause();
            menuInicial(iniciarSistema);

            break;
        case '6':
            cout << "=========== DESENVOLVEDORES ===========" << '\n';
            cout << "- Kemelly Klaricy Rufino de Lima" << '\n';
            cout << "- Marcelo Alisson M. Silva" << '\n';
            cout << '\n';
            pause();
            break;
            
        case '7':
            cout << "Saindo do programa..." << '\n';
            break;
        default:
            cout << "Opção inválida. Tente novamente." << '\n';
        break;
        }

    } while (escolha != '7' && escolha != '1');
}

int main(){
    setlocale(LC_ALL, "portuguese");
    bool iniciarSistema;


    menuInicial(iniciarSistema);

  return 0;
}
