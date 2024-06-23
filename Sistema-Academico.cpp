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
// struct Dados{
//     Aluno p;
//     Disciplinas disciplinas[2];
// };
Turma *armazemT[100];
Aluno *armazem[100];

void cadastroDisciplina(Grade disciplinas){
        setlocale(LC_ALL, "portuguese");
  // 
        cout << "Insira o componente curricular: " << endl;
        cin >> disciplinas.componenteCurricular;
        cout << "Insira o Professor do componente curricular: " << endl;
        cin >> disciplinas.professor;
        cout << "Insira o total de horas de " << disciplinas.componenteCurricular <<": " << endl;
        cin >> disciplinas.horaAula; 
        cout << "Insira os horário das aulas de " << disciplinas.componenteCurricular << ": " << endl;
        cin >> disciplinas.horario;
    }

Aluno* cadastroAluno(Aluno *dado){
        setlocale(LC_ALL, "portuguese");

        cout << "=============================================================================" << endl;
        cout << "Insira o nome do aluno a ser cadastrado: " << endl;
        cin >> dado->nome;
        cout << "Insira o número do CPF do aluno " << dado->nome << ": " << endl;
        cin >> dado->cpf;
        cout << "Insira a data de nascimento do aluno " << dado->nome << ": " << endl;
        cin >> dado->dataNascimento;
        cout << " " <<endl;
        cout << "Insira o curso do aluno " << dado->nome << ": "<<  endl;
        cin >> dado->curso;
        cout << " " <<endl;
        cout << "Insira o turno do curso: " << endl;
        cin >> dado->turno;
        cout << " " <<endl;
        cout << "Insira a data de ingresso do aluno " << dado->nome << ": " << endl;
        cin >> dado->ingresso;
        cout << " " <<endl;
        cout << "Insira o número da matricula do aluno " << dado->nome << ": " << endl;
        cin >> dado->matricula;
        cout << " " <<endl;
        cout << "Insira o período do aluno " << dado->nome << ": " << endl;
        cin >> dado->periodo;
        cout << "=============================================================================" <<endl;
        cout << " " <<endl;
        return dado;

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

    int cont = 0;
    string palavra;
    Aluno *dado;
    cout << "Deseja cadastrar aluno? " << endl;
    cin >> palavra;
    while(palavra == "sim"){
        cout << "=================================" << endl;
        cout << "         Cadastro Aluno" << endl;
        cout << "=================================" << endl;
        armazem[cont] = cadastroAluno(*&dado);
        cont++;
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
    int aux1 = 0;
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
        }   cout << "Media da turma: " << armazemT[i]->media << endl;
    }


}

void pause()
{
    cout << '\n'
         << "Pressione Enter:";
    char a;
    cin.ignore();
    cin.get(a);
}

void exibirTurma(){
    int idDisciplina;

    cout << "Qual o ID da disciplina que deseja exibir a turma: " << "/n";
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
                cout << "Aluno " << i + 1 << ":" << armazemT[i]->alunos[i]->nome << "/n" << "Matrícula: " << armazemT[i]->alunos[i]-> matricula << endl;
                cout << "-------------------------------------------------" << endl;
            }

            return;
            
        }
        cout << "Essa turma não foi encontrada. Verifique se o ID foi digitado corretamente e tente novamente" << endl;
    }
}

void exibirNotaAluno(){
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
                    cout << "    Notas do Aluno - Matrícula: " << matriculaAluno << endl;
                    cout << "================================" << endl;
                    cout << "Aluno: " << armazemT[i]-> alunos[j] -> nome << endl;
                    cout << "Nota 1: " << armazemT[i]->alunos[j]->disciplinas[0].notas.nota1 << endl;
                    cout << "Nota 2: " << armazemT[i]->alunos[j]->disciplinas[0].notas.nota2 << endl;
                    cout << "Média: " << armazemT[i]->alunos[j]->disciplinas[0].notas.media << endl;
                    return;
                }
            }    
            cout << "Aluno com matricula: " << matriculaAluno << "não encontrada na disciplina de ID: " << idDisciplina << "." << "/n" << "Confira se a matricula esta escrita corretamente e tente novamente."<< endl;
            return; 
        }
        cout << "A Disciplina com o ID: " << idDisciplina << "não foi encontrada." << "/n" << "Confira se o ID foi escrito de forma corretamente e tente novamente" << endl;
    }
    


}


// void exibirDados(Dados *&dados){
//     Dados *novosDados = dados;
//     if(novosDados != nullptr){
//         while(novosDados != nullptr){
//             cout << "=============================================================================" << endl;
//             cout << "Dados do aluno (" << novosDados->p.matricula << ")" << endl;
//             cout << " " << endl;
//             cout << "Nome: " << novosDados->p.nome << endl;
//             cout << "Matricula: (" << novosDados->p.matricula << ")" << endl;
//             cout << "CPF: " << novosDados->p.cpf << endl;
//             cout << "Data de nascimento: " <<novosDados->p.dataNascimento << endl;
//             cout << "Curso: " << novosDados->p.curso << endl;
//             cout << "Turno: " << novosDados->p.turno << endl;
//             cout << "Data de ingresso: " << novosDados->p.ingresso << endl;
//             cout << "Periodo atual: " << novosDados->p.periodo << "ª" << endl;
//             cout << "=============================================================================" << endl; 
//             cout << " " <<endl;
//             exibirDisciplina(novosDados->disciplinas);
//             novosDados = novosDados->proximo;
//         }
//     }else{
//         cout << "Nenhum dado cadastrado" << endl; 
//     }
// }

// void cadastroDados(Dados *&dado){
//     if(dado == nullptr){
//         CadastroAluno(dado);
//         dado->proximo = nullptr;
//     }else{
//         Dados *aux = dado;
//        // Dados *aux2;
//         while(aux->proximo != nullptr){
//             aux = aux->proximo;
//         }
//         CadastroAluno(dado);
//         dado->proximo = nullptr;
//     }
// }


void menuInicial(bool &iniciarSistema, Dados *&x)
{
    setlocale(LC_ALL, "portuguese");
    
    char escolha;
    do
    {

        cout << "Selecione uma das opções para prosseguir:" << '\n'
             << "** 1. Cadastrar Aluno" << '\n'
             << "** 2. Exibir Alunos cadastrados" << '\n'
             << "** 3. Desenvolvedores" << '\n'
             << "** 4. Sair" << '\n'
             << ">> ";
             //mais coisas serão adicionadas no Menu ao decorrer do projeto
        cin >> escolha;

        switch (escolha)
        {
        case '1':
            cadastroDados(*&x);
            pause();
            menuInicial(iniciarSistema, x);
            
            break;
        case '2':
            exibirDados(*&x);
            pause();
            menuInicial(iniciarSistema,x);
            
            break;
        case '3':
            cout << "=========== DESENVOLVEDORES ===========" << '\n';
            cout << "- Kemelly Klaricy Rufino de Lima" << '\n';
            cout << "- Marcelo Alisson M. Silva" << '\n';
            cout << '\n';
            pause();
            break;
        case '4':
            cout << "Saindo do programa..." << '\n';
            break;
        default:
            cout << "Opção inválida. Tente novamente." << '\n';
            break;
        }

    } while (escolha != '4' && escolha != '1');
}



int main(){
    setlocale(LC_ALL, "portuguese");
    //bool iniciarSistema;


    //menuInicial(iniciarSistema,x);

  return 0;
}
