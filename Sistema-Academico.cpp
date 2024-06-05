#include <iostream>
using namespace std;

struct Aluno {
    string nome;
    int matricula;
    string curso;
    string turno;
    string cpf;
    string ingresso;
    string dataNascimento;
    int periodo;
};

struct Disciplina {
    string componenteCurricular;
    string professor;
    int horaAula; 
    string horario; 
    Disciplina *proximo;
};
struct Dados{
    Aluno p;
    Disciplina *disciplinas;
    Dados *proximo;
  
};

void cadastroDisciplina(Dados *&dado){
  // 
    if(dado->disciplinas == nullptr){
        cout << "Insira o componente curricular: " << endl;
        cin >> dado->disciplinas->componenteCurricular;
        cout << "Insira o Professor do componente curricular: " << endl;
        cin >> dado->disciplinas->professor;
        cout << "Insira o total de horas de " << dado->disciplinas->componenteCurricular <<": " << endl;
        cin >> dado->disciplinas->horaAula; 
        cout << "Insira os horario das aulas de " << dado->disciplinas->componenteCurricular << ": " << endl;
        cin >> dado->disciplinas->horario;
        dado->disciplinas->proximo = nullptr;
    }else{
        Dados *aux = dado;
        Dados *axu2 = nullptr;
        while(aux->proximo != nullptr){
            aux = aux->proximo;
        }
        cout << "Insira o componente curricular: " << endl;
        cin >> axu2->disciplinas->componenteCurricular;
        cout << "Insira o Professor do componente curricular: " << endl;
        cin >> axu2->disciplinas->professor;
        cout << "Insira o total de horas de " << axu2->disciplinas->componenteCurricular <<": " << endl;
        cin >> axu2->disciplinas->horaAula; 
        cout << "Insira os horario das aulas de " << axu2->disciplinas->componenteCurricular << ": " << endl;
        cin >> axu2->disciplinas->horario;
        dado->disciplinas->proximo = nullptr;
        axu2->proximo = nullptr;
        aux->proximo = axu2;

    }


}

void CadastroAluno(Dados *&dado){
     int total;
    if(dado == nullptr){
       
        cout << "=============================================================================" << endl;
        cout << "Insira o nome do aluno a ser cadastrado: " << endl;
        cin >> dado->p.nome;
        cout << "Insira o CPF do aluno " << dado->p.nome << ": " << endl;
        cin >> dado->p.cpf;
        cout << "Insira a data de nascimento do aluno " << dado->p.nome << ": " << endl;
        cin >> dado->p.dataNascimento;
        cout << " " <<endl;
        cout << "Insira o curso do aluno " << dado->p.nome << ": "<<  endl;
        cin >> dado->p.curso;
        cout << " " <<endl;
        cout << "Insira o turno do curso: " << endl;
        cin >> dado->p.turno;
        cout << " " <<endl;
        cout << "Insira a data de ingresso do aluno " << dado->p.nome << ": " << endl;
        cin >> dado->p.ingresso;
        cout << " " <<endl;
        cout << "Insira o numero da matricula do aluno " << dado->p.nome << ": " << endl;
        cin >> dado->p.matricula;
        cout << " " <<endl;
        cout << "Insira o periodo do aluno " << dado->p.nome << ": " << endl;
        cin >> dado->p.periodo;
        cout << "Quantas disciplinas deseja cadastrar? " << endl;
        cin >> total;
        for(int i = 0; i < total; i++){
            cadastroDisciplina(dado);
        };
        dado->proximo = nullptr;
        cout << "=============================================================================" <<endl;
        cout << " " <<endl;

    }else{
        Dados *aux = dado;
        Dados *aux2;
        while(aux != nullptr){
            aux = aux->proximo;
        }
        cout << "=============================================================================" << endl;
        cout << "Insira o nome do aluno a ser cadastrado: " << endl;
        cin >> aux2->p.nome;
        cout << " " <<endl;
        cout << "Insira o CPF do aluno " << aux2->p.nome << ": " << endl;
        cin >> aux2->p.cpf;
        cout << " " <<endl;
        cout << "Insira a data de nascimento do aluno " << aux2->p.nome << ": " << endl;
        cin >> aux2->p.dataNascimento;
        cout << " " <<endl;
        cout << "Insira o curso do aluno " << aux2->p.nome << ": "<<  endl;
        cin >> aux2->p.curso;
        cout << " " <<endl;
        cout << "Insira o turno do curso: " << endl;
        cin >> aux2->p.turno;
        cout << " " <<endl;
        cout << "Insira a data de ingresso do aluno " << aux2->p.nome << ": " << endl;
        cin >> aux2->p.ingresso;
        cout << " " <<endl;
        cout << "Insira o numero da matricula do aluno " << aux2->p.nome << ": " << endl;
        cin >> aux2->p.matricula;
        cout << " " <<endl;
        cout << "Insira o periodo do aluno " << aux2->p.nome << ": " << endl;
        cin >> aux2->p.periodo;
        cout << "Quantas disciplinas deseja cadastrar? " << endl;
        cin >> total;
        for(int i = 0; i < total; i++){
            cadastroDisciplina(aux2);
        };
        aux2->proximo = nullptr;
        aux->proximo = aux2;
        cout << "=============================================================================" <<endl;
        cout << " " <<endl;

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

void exibirDisciplina(Disciplina *&disciplinas){
    Disciplina* nDisciplinas = disciplinas;
    if(nDisciplinas != nullptr){
        while(nDisciplinas != nullptr){
            cout << "Componente Curricular: " << nDisciplinas->componenteCurricular << endl;
            cout << "Professor: " << nDisciplinas->professor << endl;
            cout << "Total de Horas: " << nDisciplinas->horaAula << endl;
            cout << "Horarios das aulas: " << nDisciplinas->horario << endl;
            nDisciplinas = nDisciplinas->proximo;
        }
    }
    else{
        cout << "Nenhuma disciplina cadastrada" << endl; 
    }
}
void exibirDados(Dados *&dados){
    Dados *novosDados = dados;
    if(novosDados != nullptr){
        while(novosDados != nullptr){
            cout << "=============================================================================" << endl;
            cout << "Dados do aluno (" << novosDados->p.matricula << ")" << endl;
            cout << " " << endl;
            cout << "Nome: " << novosDados->p.nome << endl;
            cout << "Matricula: (" << novosDados->p.matricula << ")" << endl;
            cout << "CPF: " << novosDados->p.cpf << endl;
            cout << "Data de nascimento: " <<novosDados->p.dataNascimento << endl;
            cout << "Curso: " << novosDados->p.curso << endl;
            cout << "Turno: " << novosDados->p.turno << endl;
            cout << "Data de ingresso: " << novosDados->p.ingresso << endl;
            cout << "Periodo atual: " << novosDados->p.periodo << "ª" << endl;
            cout << "=============================================================================" << endl; 
            cout << " " <<endl;
            exibirDisciplina(novosDados->disciplinas);
            novosDados = novosDados->proximo;
        }
    }else{
        cout << "Nenhum dado cadastrado" << endl; 
    }
}

void cadastroDados(Dados *&dado){
    if(dado == nullptr){
        CadastroAluno(dado);
        dado->proximo = nullptr;
    }else{
        Dados *aux = dado;
       // Dados *aux2;
        while(aux->proximo != nullptr){
            aux = aux->proximo;
        }
        CadastroAluno(dado);
        dado->proximo = nullptr;
    }
}


void menuInicial(bool &iniciarSistema, Dados *&x)
{
    
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
    bool iniciarSistema;
    Dados *x;

    menuInicial(iniciarSistema,x);

  return 0;
}
