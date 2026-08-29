#include"mundo.h"
void Mundo::inicializar() {
	inicializar_universidades();
	inicializar_departamentos();
	inicializar_diciplinas();
	inicializar_professores();
	inicializar_alunos();
}
void Mundo::inicializar_universidades() {
	UTFPR.sua_uni("UTFPR");
	Cambridge.sua_uni("universidade de Cambridge");
	Nova_Jessy.sua_uni("universidade de Princeton");
	UTFPR.inclue_departamento(&Dainf);
	Cambridge.inclue_departamento(&matematica_cambridge);
	Nova_Jessy.inclue_departamento(&fisica_princeton);
	UTFPR.inclue_departamento(&matematica_cambridge);
	UTFPR.inclue_departamento(&fisica_princeton);
	UTFPR.inclue_departamento(&Dafis);
	UTFPR.inclue_departamento(&Damat);
	UTFPR.inclue_departamento(&Dadim);
	UTFPR.inclue_departamento(&Daest);
	UTFPR.inclue_departamento(&Daeln);
	UTFPR.inclue_departamento(&Daelt);
	UTFPR.inclue_departamento(&Daqbi);
}
void Mundo::inicializar_departamentos() {
	Dainf.set_departamento("DAINF");
	matematica_cambridge.set_departamento("departamento de matematica");
	fisica_princeton.set_departamento("departamento de fisica");
	Dafis.set_departamento("DAFIS");
	Damat.set_departamento("DAMAT");
	Dadim.set_departamento("DADIN");
	Daest.set_departamento("DAEST");
	Daeln.set_departamento("DAELN");
	Daelt.set_departamento("DAELT");
	Daqbi.set_departamento("DAQBi");
	Dadim.set_uni(&UTFPR);
	Daeln.set_uni(&UTFPR);
	Daelt.set_uni(&UTFPR);
	Daest.set_uni(&UTFPR);
	Dafis.set_uni(&UTFPR);
	Dainf.set_uni(&UTFPR);
	Damat.set_uni(&UTFPR);
	Daqbi.set_uni(&UTFPR);
	matematica_cambridge.set_uni(&Cambridge);
	fisica_princeton.set_uni(&Nova_Jessy);
}
void Mundo::inicializar_diciplinas() {
	tec_prog.set_id(1);
	tec_prog.set_nome("tecnicas de programação");
	tec_prog.set_depDis(&Dainf);
	ED_2.set_id(2);
	ED_2.set_nome("estrutura de dados 2");
	ED_2.set_depDis(&Dainf);
	logica.set_id(3);
	logica.set_nome("Logica");
	logica.set_depDis(&Dainf);
	matematica_discreta.set_id(4);
	matematica_discreta.set_nome("Matematica discreta");
	matematica_discreta.set_depDis(&Dainf);
	EDO.set_id(5);
	EDO.set_nome("equaçoes diferenciais ordinarias");
	EDO.set_depDis(&Damat);
	calculo_2.set_id(6);
	calculo_2.set_nome("calculo 2");
	calculo_2.set_depDis(&Damat);
}
void Mundo::inicializar_professores() {
	Simao.inicializar(3, 10, 1976, "Jean Simão");
	Einstein.inicializar(14, 3, 1879, "Albert Einstein");
	Newton.inicializar(4, 1, 1643, "Isacc Newton");
	Simao.setar_trabalho(&UTFPR);
	Einstein.setar_trabalho(&Cambridge);
	Newton.setar_trabalho(&Nova_Jessy);
	Simao.setar_derpa(&Dainf);
	Einstein.setar_derpa(&fisica_princeton);
	Newton.setar_derpa(&matematica_cambridge);
}
void Mundo::inicializar_alunos() {
	Melissa.inicializar(2, 6, 2006, "Melissa truck");
	Abner.inicializar(4,7,2007,"Abner da silva");
	Joas.inicializar(1, 1, 2006, "Joas arhig mello");
	Melissa.set_RA(400006);
	Abner.set_RA(122098);
	Joas.set_RA(278905);
}
Mundo::Mundo() :
	Simao(),
	Einstein(),
	Newton()
{
	inicializar();
}
 Mundo::~Mundo() {

 }
void Mundo :: informe_dia() {
	int dia = -1, mes = -1, ano = -1;
	cout << "informe o dia de hoje" << endl;
	cin >> dia >> mes >> ano;
	Simao.calcu_idade(dia, mes, ano);
	Einstein.calcu_idade(dia, mes, ano);
	Newton.calcu_idade(dia, mes, ano);
	Simao.print_idade();
	Einstein.print_idade();
	Newton.print_idade();
}
void Mundo::informe_trabalho() {
	trabalho_universidade();
	trabalho_departamento();
}
void Mundo:: execudar() {
	informe_dia();
	composicao_universidade();
	informe_trabalho();
	informacao_aluno();
	diciplinas_departamento();
	diciplina_aluno();
}
void Mundo::informacao_aluno() {
	Melissa.print_RA();
}
void Mundo::composicao_universidade() {
	Dainf.print_uni();
	UTFPR.print_departamento();
	UTFPR.printR_departamento();
}
void Mundo::trabalho_universidade() {
	Simao.onde_trabalho();
	Einstein.onde_trabalho();
	Newton.onde_trabalho();
	
}
void Mundo::trabalho_departamento() {
	Simao.qual_derpa();
	Einstein.qual_derpa();
	Newton.qual_derpa();
}
void Mundo::diciplinas_departamento() {
	Dainf.print_diciplina();
	Damat.print_reverse();
}
void Mundo::diciplina_aluno() {
	tec_prog.inclue_aluno(&Melissa);
	tec_prog.inclue_aluno(&Abner);
	tec_prog.inclue_aluno(&Joas);
	tec_prog.printR_aluno();
	tec_prog.print_aluno();
}