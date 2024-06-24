#include <iostream>
#include <locale.h>
#include <string>
#include <vector>
#define MAX 100

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
    Aluno alunos[40];
    int totalAlunos = 0;
    float media;

};



void cadastroDisciplina(Grade disciplinas){
    setlocale(LC_ALL, "portuguese");
    cout << "Insira o componente curricular: " << endl;
    cin >> disciplinas.componenteCurricular;
    cout << "Insira o Professor do componente curricular: " << endl;
    cin >> disciplinas.professor;
    cout << "Insira o total de horas de " << disciplinas.componenteCurricular <<": " << endl;
    cin >> disciplinas.horaAula; 
    cout << "Insira os horários das aulas de " << disciplinas.componenteCurricular << ": " << endl;
    cin >> disciplinas.horario;
}

Aluno cadastroAluno(Aluno aluno[], int i){
    setlocale(LC_ALL, "portuguese");
    cout << "=============================================================================" << endl;
    cout << "Insira o nome do aluno a ser cadastrado: " << endl;
    cin >> aluno[i].nome;
    cout << " " <<endl;
    cout << "Insira o numero do CPF do aluno " << aluno[i].nome << ": " << endl;
    cin >> aluno[i].cpf;
    cout << " " <<endl;
    cout << "Insira a data de nascimento do aluno " << aluno[i].nome << ": " << endl;
    cin >> aluno[i].dataNascimento;
    cout << " " <<endl;
    cout << "Insira o curso do aluno " << aluno[i].nome << ": "<<  endl;
    cin >> aluno[i].curso;
    cout << " " <<endl;
    cout << "Insira o turno do curso: " << endl;
    cin >> aluno[i].turno;
    cout << " " <<endl;
    cout << "Insira a data de ingresso do aluno " << aluno[i].nome << ": " << endl;
    cin >> aluno[i].ingresso;
    cout << " " <<endl;
    cout << "Insira o numero da matricula do aluno " << aluno[i].nome << ": " << endl;
    cin >> aluno[i].matricula;
    cout << " " <<endl;
    cout << "Insira o numero do periodo do aluno " << aluno[i].nome << ": " << endl;
    cin >> aluno[i].periodo;
    cout << "=============================================================================" <<endl;
    cout << " " <<endl;
    return aluno[100];
        

}
void calcularnotas(Aluno aluno[]){
    
    setlocale(LC_ALL, "portuguese");

    string palavra, componente;
    int matricu;
    int cont = 0;
    palavra = "sim";
    while(palavra == "sim"){
        cout << "================================" << endl;
        cout << "      Atribuicao de notas" << endl;
        cout << "================================" << endl;
        cout << "Qual aluno deseja fazer a atribuicao? Insira a matricula: " << endl;
        cin >> matricu; 
        cout << "Insira a disciplina: " << endl;
        cin >> componente;
        if(matricu == aluno[cont].matricula){
            for(int i = 0; i < 2; i++){
                if(componente == aluno[cont].disciplinas[i].disciplina.componenteCurricular){
                    cout << "Insira a primeira nota: " << endl;
                    cin >> aluno[cont].disciplinas[i].notas.nota1;
                    cout << "Insira a segunda nota: " << endl;
                    cin >> aluno[cont].disciplinas[i].notas.nota2;
                    aluno[cont].disciplinas[i].notas.media = (aluno[cont].disciplinas[i].notas.nota1 + aluno[cont].disciplinas[i].notas.nota2) /2;
                }
            }
        }
        cout << "Deseja atribuir outras notas? sim ou nao" << endl;
        cin >> palavra;
        system("cls");
    }
}
Aluno armazenar(){
    setlocale(LC_ALL, "portuguese");
    Aluno aluno[100];
    int cont = 0;
    Aluno array[100];
    string palavra;
    cout << "Deseja cadastrar aluno? " << endl;
    cin >> palavra;
    while(palavra == "sim"){
        cout << "=================================" << endl;
        cout << "         Cadastro Aluno" << endl;
        cout << "=================================" << endl;
        aluno[cont] = cadastroAluno(array, cont);
        cout << "=================================" << endl;
        cout << "        Aluno cadastrado" << endl;
        cout << "=================================" << endl;
        cout << "Deseja cadastrar aluno? sim ou nao " << endl;
        cin >> palavra;
        cont++;
    }
    return aluno[100];
}
Turma cadastroTurma(Turma turma[], Aluno aluno[]){
    setlocale(LC_ALL, "portuguese");
    string confirmacao = "sim";
    int aux3 = 0;
    while(confirmacao == "sim"){
        
        cout << "================================" << endl;
        cout << "     Cadastro da disciplina" << endl;
        cout << "================================" << endl;
        cout << " " << endl;
        cout << "Insira o ID da Turma: " << endl;
        cin >> turma[aux3].ID;
        cadastroDisciplina(turma[aux3].disciplina);
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
                if(matricu == aluno[i].matricula){
                    turma[aux3].alunos[turma[aux3].totalAlunos] = aluno[i];
                    for (int l = 0; l < 2; l++){
                        if(aluno[i].disciplinas[l].disciplina.componenteCurricular.empty() && 
                        aluno[i].disciplinas[l].disciplina.professor.empty() && aluno[i].disciplinas[l].disciplina.horario.empty() && 
                        aluno[i].disciplinas[l].disciplina.horaAula == 0){
                            aluno[i].disciplinas[l].disciplina = turma[aux3].disciplina;
                        
                        }
                    }
                    cout << "================================" << endl;
                    cout << "        Aluno matriculado" << endl;
                    cout << "================================" << endl;
                                
                }else if(matricu != aluno[100].matricula){
                    cout << "Aluno nao encontrado, verifique se digitou corretamente " << endl;
                }
            }
            turma[aux3].totalAlunos++;
            
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
    return turma[aux3];
}   
void mediaTurma(Turma turma[]){
    setlocale(LC_ALL, "portuguese");
    int num;
    cout << "Digite o ID da turma: " << endl;
    cin >> num;
    int soma = 0;
    for(int i = 0; i < 100; i++){
        if(num == turma[i].ID){
            cout << "================================" << endl;
            cout << "        Media da turma ("")" << endl;
            cout << "================================" << endl;
            for(int j = 0; j < turma[i].totalAlunos; j++){
                soma += turma[i].alunos[j].disciplinas->notas.media;
                turma[i].media = soma / turma[i].totalAlunos;    
            }
            cout << "Media da turma de " << turma[i].disciplina.componenteCurricular << ": " << turma[i].media << endl;
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
void exibirTurma(Turma turma[]){
    setlocale(LC_ALL, "portuguese");
    int idDisciplina;

    cout << "Qual o ID da disciplina que deseja exibir a turma: " << "\n";
    cin >> idDisciplina;

    for(int i = 0; i < 100; ++i){
        if(turma[i].ID == idDisciplina){
            cout << "================================" << endl;
            cout << "         Dados da Turma" << endl;
            cout << "================================" << endl;
            cout << "ID da Turma: " << turma[i].ID << endl;
            cout << "Componente Curricular: "<< turma[i].disciplina.componenteCurricular << endl;
            cout << "Professor: " << turma[i].disciplina.professor << endl;
            cout << "Total de horas: " << turma[i].disciplina.horaAula << endl;
            cout << "Horario: " << turma[i].disciplina.horario << endl;
            cout << "Total de Alunos na turma: "<< turma[i].totalAlunos << endl;
            for(int i = 0; i < turma[i].totalAlunos; i++){
                cout << "Aluno " << i + 1 << ":" << turma[i].alunos[i].nome << "\n" << "Matricula: " << turma[i].alunos[i].matricula << endl;
                cout << "-------------------------------------------------" << endl;
            }

            return;
            
        }else if(idDisciplina != turma[100].ID){
        cout << "Essa turma não foi encontrada. Verifique se o ID foi digitado corretamente e tente novamente!" << endl;}
    }
    mediaTurma(turma);
}
void exibirNotaAluno(Turma turma[]){
    setlocale(LC_ALL, "portuguese");
    int matriculaAluno, idDisciplina;

    cout << "Digite a matrícula do aluno que deseja visualizar as notas: " << endl;
    cin >> matriculaAluno;
    cout << "Digite o ID da disciplina: " << endl;
    cin >> idDisciplina;

    for(int i = 0; i < 100; ++i){
        if(turma[i].ID == idDisciplina){
            for(int j = 0; j < turma[i].totalAlunos; ++j){
                if(turma[i].alunos[j].matricula == matriculaAluno){
                    cout << "================================" << endl;
                    cout << " Notas do Aluno - Matricula: " << matriculaAluno << endl;
                    cout << "================================" << endl;
                    cout << "Aluno: " << turma[i]. alunos[j] . nome << endl;
                    cout << "Nota 1: " << turma[i].alunos[j].disciplinas[0].notas.nota1 << endl;
                    cout << "Nota 2: " << turma[i].alunos[j].disciplinas[0].notas.nota2 << endl;
                    cout << "Média: " << turma[i].alunos[j].disciplinas[0].notas.media << endl;
                    return;
                }else if(turma[i].alunos[40].matricula != matriculaAluno){
                    cout << "Aluno com matricula: " << matriculaAluno << "nao encontrada na disciplina de ID: " << idDisciplina << "." << "\n" << "Confira se a matricula esta escrita corretamente e tente novamente."<< endl;
                    return; 

                }
            } 
        }else if(turma[100].ID != idDisciplina){
            cout << "A Disciplina com o ID: " << idDisciplina << "não foi encontrada." << "\n" << "Confira se o ID foi escrito de forma corretamente e tente novamente" << endl;
        }
    }
}
void exibirDados(Aluno aluno[]){
    setlocale(LC_ALL, "portuguese");
    int aux1;
    cout << "Digite a matricula do aluno que deseja vizualiar: " << endl;
    cin >> aux1;
    for(int i = 0; i < 100; i++){
        if(aux1 == aluno[i].matricula){
            cout << "=============================================================================" << endl;
            cout << "Dados do aluno (" << aluno[i].matricula << ")" << endl;
            cout << " " << endl;
            cout << "Nome: " << aluno[i].nome << endl;
            cout << "Matricula: (" << aluno[i].matricula << ")" << endl;
            cout << "CPF: " << aluno[i].cpf << endl;
            cout << "Data de nascimento: " <<aluno[i].dataNascimento << endl;
            cout << "Curso: " << aluno[i].curso << endl;
            cout << "Turno: " << aluno[i].turno << endl;
            cout << "Data de ingresso: " << aluno[i].ingresso << endl;
            cout << "Periodo atual: " << aluno[i].periodo << "ª" << endl;
            cout << "=============================================================================" << endl; 
            cout << " " <<endl;
        }else if(aluno[100].matricula != aux1){
            cout << "O aluno com a matricula: " << aux1 << "não foi encontrada." << "\n" << "Confira se o ID foi escrito de forma corretamente e tente novamente" << endl;

        }
    }     
}
void menuInicial(bool &iniciarSistema, Aluno array[100], Turma turma[100]){
    setlocale(LC_ALL, "portuguese");
    Turma aux[100];
    char escolha;
    int cont = 0;
    do
     {
        setlocale(LC_ALL, "portuguese");
        cout << "Selecione uma das opções para prosseguir:" << '\n'
            << "** 1. Cadastrar Aluno" << '\n'
            << "** 2. Cadastrar Turma" << '\n'
            << "** 3. Exibir dados do Aluno" << '\n'
            << "** 4. Exibir notas do Aluno" << '\n'
            << "** 5. Exibir dados da turma" << '\n'
            << "** 6. Desenvolvedores" << '\n'
            << "** 7. Sair" << '\n'
            << ">> ";


        cin >> escolha;

        switch (escolha)
        {
        case '1':
            array[cont] = armazenar();
            pause();
            system("cls");
            menuInicial(iniciarSistema, array, turma);
            
            break;
        case '2':
            turma[cont] = cadastroTurma(aux, array);
            pause();
            menuInicial(iniciarSistema, array, turma);
            
            break;
        case '3':
            exibirDados(array);
            pause();
            menuInicial(iniciarSistema, array, turma);

            break;
        case '4':
            exibirNotaAluno(turma);
            pause();
            menuInicial(iniciarSistema,  array, turma);

            break;            
        case '5':
            exibirTurma(turma);
            pause();
            menuInicial(iniciarSistema,  array, turma);

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
    Aluno *alunos[100];
    Turma *turma[100];
    
    setlocale(LC_ALL, "portuguese");
    bool iniciarSistema;


    menuInicial(iniciarSistema, alunos[100], turma[100]);


  return 0;
}
