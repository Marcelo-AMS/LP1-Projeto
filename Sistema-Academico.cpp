#include <iostream>
#include <locale.h>
#include <string>
#include <vector>
#define MAX 100

using namespace std;

struct Grade {
    string componenteCurricular;
    string professor;
    int horaAula;
    string horario;
};

struct Notas {
    float nota1;
    float nota2;
    float media;
};

struct Disciplinas {
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

struct Turma {
    int ID;
    Grade disciplina;
    Aluno alunos[40];
    int totalAlunos = 0;
    float media;
};

void cadastroDisciplina(Grade& disciplinas) {
    setlocale(LC_ALL, "portuguese");
    cout << "Insira o componente curricular: ";
    cin >> disciplinas.componenteCurricular;
    cout << "Insira o Professor do componente curricular: ";
    cin >> disciplinas.professor;
    cout << "Insira o total de horas de " << disciplinas.componenteCurricular << ": ";
    cin >> disciplinas.horaAula;
    cout << "Insira os horarios das aulas de " << disciplinas.componenteCurricular << ": ";
    cin >> disciplinas.horario;
}

void cadastroAluno(Aluno& aluno) {
    setlocale(LC_ALL, "portuguese");
    cout << "=============================================================================" << endl;
    cout << "Insira o nome do aluno a ser cadastrado: ";
    cin >> aluno.nome;
    cout << " " << endl;
    cout << "Insira o numero do CPF do aluno " << aluno.nome << ": ";
    cin >> aluno.cpf;
    cout << " " << endl;
    cout << "Insira a data de nascimento do aluno " << aluno.nome << ": ";
    cin >> aluno.dataNascimento;
    cout << " " << endl;
    cout << "Insira o curso do aluno " << aluno.nome << ": ";
    cin >> aluno.curso;
    cout << " " << endl;
    cout << "Insira o turno do curso: ";
    cin >> aluno.turno;
    cout << " " << endl;
    cout << "Insira a data de ingresso do aluno " << aluno.nome << ": ";
    cin >> aluno.ingresso;
    cout << " " << endl;
    cout << "Insira o numero da matricula do aluno " << aluno.nome << ": ";
    cin >> aluno.matricula;
    cout << " " << endl;
    cout << "Insira o numero do periodo do aluno " << aluno.nome << ": ";
    cin >> aluno.periodo;
    cout << "=============================================================================" << endl;
    cout << " " << endl;
}

void calcularnotas(Aluno aluno[], int totalAlunos) {
    setlocale(LC_ALL, "portuguese");

    string palavra, componente;
    int matricu;
    palavra = "sim";
    while (palavra == "sim") {
        cout << "================================" << endl;
        cout << "      Atribuicao de notas" << endl;
        cout << "================================" << endl;
        cout << "Qual aluno deseja fazer a atribuicao? Insira a matricula: ";
        cin >> matricu;
        cout << "Insira a disciplina: ";
        cin >> componente;
        for (int cont = 0; cont < totalAlunos; cont++) {
            if (matricu == aluno[cont].matricula) {
                for (int i = 0; i < 2; i++) {
                    if (componente == aluno[cont].disciplinas[i].disciplina.componenteCurricular) {
                        cout << "Insira a primeira nota: ";
                        cin >> aluno[cont].disciplinas[i].notas.nota1;
                        cout << "Insira a segunda nota: ";
                        cin >> aluno[cont].disciplinas[i].notas.nota2;
                        aluno[cont].disciplinas[i].notas.media = (aluno[cont].disciplinas[i].notas.nota1 + aluno[cont].disciplinas[i].notas.nota2) / 2;
                    }
                }
            }
        }
        cout << "Deseja atribuir outras notas? sim ou nao: ";
        cin >> palavra;
        system("cls");
    }
}

void armazenar(Aluno aluno[], int& totalAlunos) {
    setlocale(LC_ALL, "portuguese");
    string palavra = "sim";
    while (palavra == "sim" && totalAlunos < MAX) {
        cout << "=================================" << endl;
        cout << "         Cadastro Aluno" << endl;
        cout << "=================================" << endl;
        cadastroAluno(aluno[totalAlunos]);
        cout << "=================================" << endl;
        cout << "        Aluno cadastrado" << endl;
        cout << "=================================" << endl;
        cout << "Deseja cadastrar aluno? sim ou nao: ";
        cin >> palavra;
        totalAlunos++;
    }
}

void cadastroTurma(Turma turma[], Aluno aluno[], int totalAlunos, int& totalTurmas) {
    setlocale(LC_ALL, "portuguese");
    string confirmacao = "sim";
    while (confirmacao == "sim" && totalTurmas < MAX) {
        cout << "================================" << endl;
        cout << "     Cadastro da disciplina" << endl;
        cout << "================================" << endl;
        cout << " " << endl;
        cout << "Insira o ID da Turma: ";
        cin >> turma[totalTurmas].ID;
        cadastroDisciplina(turma[totalTurmas].disciplina);
        cout << "===============================" << endl;
        cout << "     Disciplina cadastrada" << endl;
        cout << "===============================" << endl;
        system("cls");
        int matricu;
        string palavra = "sim";
        while (palavra == "sim") {
            cout << "================================" << endl;
            cout << "        Matricular Aluno" << endl;
            cout << "================================" << endl;
            cout << " " << endl;
            cout << "Insira o numero da matricula do aluno a ser matriculado na disciplina: ";
            cin >> matricu;
            bool alunoEncontrado = false;
            for (int i = 0; i < totalAlunos; i++) {
                if (matricu == aluno[i].matricula) {
                    turma[totalTurmas].alunos[turma[totalTurmas].totalAlunos] = aluno[i];
                    for (int l = 0; l < 2; l++) {
                        if (aluno[i].disciplinas[l].disciplina.componenteCurricular.empty() &&
                            aluno[i].disciplinas[l].disciplina.professor.empty() &&
                            aluno[i].disciplinas[l].disciplina.horario.empty() &&
                            aluno[i].disciplinas[l].disciplina.horaAula == 0) {
                            aluno[i].disciplinas[l].disciplina = turma[totalTurmas].disciplina;
                        }
                    }
                    cout << "================================" << endl;
                    cout << "        Aluno matriculado" << endl;
                    cout << "================================" << endl;
                    alunoEncontrado = true;
                    break;
                }
            }
            if (!alunoEncontrado) {
                cout << "Aluno nao encontrado, verifique se digitou corretamente " << endl;
            }
            turma[totalTurmas].totalAlunos++;
            system("cls");
            cout << "Deseja matricular aluno? sim ou nao: ";
            cin >> palavra;
            system("cls");
        }
        totalTurmas++;
        system("cls");
        cout << "Deseja cadastrar outra disciplina? sim ou nao: ";
        cin >> confirmacao;
        system("cls");
    }
}

void mediaTurma(Turma turma[], int totalTurmas) {
    setlocale(LC_ALL, "portuguese");
    int num;
    cout << "Digite o ID da turma: ";
    cin >> num;
    for (int i = 0; i < totalTurmas; i++) {
        if (num == turma[i].ID) {
            cout << "================================" << endl;
            cout << "        Media da turma (" << turma[i].ID << ")" << endl;
            cout << "================================" << endl;
            int soma = 0;
            for (int j = 0; j < turma[i].totalAlunos; j++) {
                soma += turma[i].alunos[j].disciplinas[0].notas.media;
            }
            turma[i].media = static_cast<float>(soma) / turma[i].totalAlunos;
            cout << "Media da turma de " << turma[i].disciplina.componenteCurricular << ": " << turma[i].media << endl;
            return;
        }
    }
    cout << "Turma com ID: " << num << " nao encontrada." << endl;
}

void pause() {
    cout << '\n' << "Pressione Enter:";
    cin.ignore();
    cin.get();
}

void exibirTurma(Turma turma[], int totalTurmas) {
    setlocale(LC_ALL, "portuguese");
    int idDisciplina;

    cout << "Qual o ID da disciplina que deseja exibir a turma: ";
    cin >> idDisciplina;

    for (int i = 0; i < totalTurmas; i++) {
        if (idDisciplina == turma[i].ID) {
            cout << "================================" << endl;
            cout << "    Dados da turma - ID: " << turma[i].ID << endl;
            cout << "================================" << endl;
            cout << "Disciplina: " << turma[i].disciplina.componenteCurricular << endl;
            cout << "Professor: " << turma[i].disciplina.professor << endl;
            cout << "Horario: " << turma[i].disciplina.horario << endl;
            cout << "Total de Alunos: " << turma[i].totalAlunos << endl;
            for (int j = 0; j < turma[i].totalAlunos; j++) {
                cout << "--------------------------------" << endl;
                cout << "Aluno " << j + 1 << ":" << endl;
                cout << "Nome: " << turma[i].alunos[j].nome << endl;
                cout << "CPF: " << turma[i].alunos[j].cpf << endl;
                cout << "Data de Nascimento: " << turma[i].alunos[j].dataNascimento << endl;
                cout << "Curso: " << turma[i].alunos[j].curso << endl;
                cout << "Turno: " << turma[i].alunos[j].turno << endl;
                cout << "Matricula: " << turma[i].alunos[j].matricula << endl;
                cout << "Periodo: " << turma[i].alunos[j].periodo << endl;
                cout << "Notas: " << turma[i].alunos[j].disciplinas[0].notas.nota1 << ", " << turma[i].alunos[j].disciplinas[0].notas.nota2 << endl;
                cout << "Media: " << turma[i].alunos[j].disciplinas[0].notas.media << endl;
            }
            return;
        }
    }
    cout << "Turma com ID: " << idDisciplina << " não encontrada." << endl;
}

int main() {
    Aluno aluno[MAX];
    Turma turma[MAX];
    int totalAlunos = 0;
    int totalTurmas = 0;
    int escolha;

    setlocale(LC_ALL, "portuguese");

    while (true) {
        cout << "================================" << endl;
        cout << "          Menu Principal" << endl;
        cout << "================================" << endl;
        cout << "1. Cadastrar Aluno" << endl;
        cout << "2. Cadastrar Turma" << endl;
        cout << "3. Atribuir Notas" << endl;
        cout << "4. Calcular Média da Turma" << endl;
        cout << "5. Exibir Turma" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                armazenar(aluno, totalAlunos);
                break;
            case 2:
                cadastroTurma(turma, aluno, totalAlunos, totalTurmas);
                break;
            case 3:
                calcularnotas(aluno, totalAlunos);
                break;
            case 4:
                mediaTurma(turma, totalTurmas);
                break;
            case 5:
                exibirTurma(turma, totalTurmas);
                break;
            case 0:
                return 0;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
        pause();
    }

    return 0;
}


