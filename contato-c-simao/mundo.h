#ifndef _MUNDO_H_

#define _MUNDO_H_

#include"fufa.h"
#include"Professor.h"
#include"aluno.h"
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
		Derpatamento Dainf;
		Derpatamento matematica_cambridge;
		Derpatamento fisica_princeton;
		Derpatamento Dafis;
		Derpatamento Damat;
		Derpatamento Daeln;
		Derpatamento Dadim;
		Derpatamento Daqbi;
		Derpatamento Daelt;
		Derpatamento Daest;
		Diciplina tec_prog;
		Diciplina EDO;
		Diciplina calculo_2;
		Diciplina logica;
		Diciplina matematica_discreta;
		Diciplina ED_2;

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

};
#endif