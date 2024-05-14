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
};
struct Dados{
  Aluno p;
  Disciplina disciplinas[10];
  int totalDisciplinas;

};

void pause()
{
    cout << '\n'
         << "Pressione Enter:";
    char a;
    cin.ignore();
    cin.get(a);
}

void lerdados(Dados *x){


    cout << "=============================================================================" << endl;
    cout << "Insira o nome do aluno a ser cadastrado: " << endl;
    cin >> x->p.nome;
    cout << " " <<endl;
    cout << "Insira o CPF do aluno " << x->p.nome << ": " << endl;
    cin >> x->p.cpf;
    cout << " " <<endl;
    cout << "Insira a data de nascimento do aluno " << x->p.nome << ": " << endl;
    cin >> x->p.dataNascimento;
    cout << " " <<endl;
    cout << "Insira o curso do aluno " << x->p.nome << ": "<<  endl;
    cin >> x->p.curso;
    cout << " " <<endl;
    cout << "Insira o turno do curso: " << endl;
    cin >> x->p.turno;
    cout << " " <<endl;
    cout << "Insira a data de ingresso do aluno " << x->p.nome << ": " << endl;
    cin >> x->p.ingresso;
    cout << " " <<endl;
    cout << "Insira o numero da matricula do aluno " << x->p.nome << ": " << endl;
    cin >> x->p.matricula;
    cout << " " <<endl;
    cout << "Insira o periodo do aluno " << x->p.nome << ": " << endl;
    cin >> x->p.periodo;
    cout << "=============================================================================" <<endl;
    cout << " " <<endl;

  
  cout << "Insira o total de disciplinas do aluno a ser matriculado" << endl;
  cin >> x->totalDisciplinas;
  for( int i = 0; i < x->totalDisciplinas; i++){

      cout << "=============================================================================" <<endl;
      cout << "Insira o componente curricular: " << endl;
      cin >> x->disciplinas[i].componenteCurricular;
      cout << " " <<endl;
      cout << "Insira o professor(a) do componente curricular " << x->disciplinas[i].componenteCurricular << endl;
      cin >> x->disciplinas[i].professor;
      cout << " " <<endl;
      cout << "Insira o total de horas do componente curricular " << x->disciplinas[i].componenteCurricular << endl;
      cin >> x->disciplinas[i].horaAula;
      cout << " " <<endl;
      cout << "Insira os horarios das aulas do componente curricular " << x->disciplinas[i].componenteCurricular << endl;
      cin >> x->disciplinas[i].horario;
      cout << "=============================================================================" <<endl;
      cout << " " <<endl;

  }
  
}
void exibirDados(Dados *x){

  

  cout << "=============================================================================" << endl;
  cout << "Dados do aluno (" << x->p.matricula << ")" << endl;
  cout << " " << endl;
  cout << "Nome: " << x->p.nome << endl;
  cout << "CPF: " << x->p.cpf << endl;
  cout << "Data de nascimento: " <<x->p.dataNascimento << endl;
  cout << "Curso: " << x->p.curso << endl;
  cout << "Turno: " << x->p.turno << endl;
  cout << "Data de ingresso: " << x->p.ingresso << endl;
  cout << "Periodo atual: " << x->p.periodo << "ª" << endl;
  cout << "=============================================================================" << endl; 
  cout << " " <<endl;



for(int i = 0; i < x->totalDisciplinas; i++){
    cout << "=============================================================================" <<endl;
    cout << "Componente Curricular: " << x->disciplinas[i].componenteCurricular << ". Carga horaria: " << x->disciplinas[i].horaAula << endl;
    cout << " " <<endl;
    cout << "Discente: " << x->disciplinas[i].professor << endl;
    cout << " " <<endl;
    cout << "Horario das aulas: " << x->disciplinas[i].horario << endl;
    cout << "=============================================================================" <<endl;
    cout << " "<< endl;

}
}
void menuInicial(bool &iniciarSistema, Dados x)
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
            lerdados(&x);
            pause();
            menuInicial(iniciarSistema, x);
            
            break;
        case '2':
            exibirDados(&x);
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
//oi
    bool iniciarSistema;
    Dados x;

    menuInicial(iniciarSistema,x);

  return 0;
}
