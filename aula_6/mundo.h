#ifndef _MUNDO_H_

#define _MUNDO_H_

#include"pessoa.h"
#include"Professor.h"
#include"aluno.h"
#include "universidade.h"
#include "departamento.h"
#include "diciplina.h"
#include "elemento_diciplina.h"
#include "elemento_departamento.h"
#include "elemento_universidade.h"
#include "lista_departamento.h"
#include "lista_diciplina.h"
#include "lista_universidade.h"
class Mundo {
	private:
		Professor Simao;
		Professor Einstein;
		Professor Newton;
		Aluno Melissa;
		Aluno Abner;
		Aluno Joas;
		Universidade UTFPR;
		Universidade Cambridge;
		Universidade Nova_Jessy;
		Departamento Dainf;
		Departamento matematica_cambridge;
		Departamento fisica_princeton;
		Departamento Dafis;
		Departamento Damat;
		Departamento Daeln;
		Departamento Dadim;
		Departamento Daqbi;
		Departamento Daelt;
		Departamento Daest;
		Diciplina tec_prog;
		Diciplina EDO;
		Diciplina calculo_2;
		Diciplina logica;
		Diciplina matematica_discreta;
		Diciplina ED_2;
		int diaM;
		int mesM;
		int anoM;
		ListaDepartamento LDepartamento;
		ListaDiciplina LDiciplina;
		ListaUniversidade LUniversidade;
		int id;

	public:
		void inicializar();
		void inicializar_diciplinas();
		void inicializar_universidades();
		void inicializar_departamentos();
		void inicializar_professores();
		void inicializar_alunos();
		Mundo();
		~Mundo();
		void execudar();
		void informe_dia();
		void composicao_universidade();
		void informacao_aluno();
		void informe_trabalho();
		void trabalho_departamento();
		void trabalho_universidade();
		void diciplinas_departamento();
		void diciplina_aluno();
		void executa_tudo();
		void diciplnaExe();
		void diciplinaCadastro();
		void departamentoExe();
		void departamentoCadastro();
		void universidadeExe();
		void universidadeCadastro();
		void menuExe();
		void menuCadastro();
		void menu();

};
#endif