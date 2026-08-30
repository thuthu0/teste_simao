#include"mundo.h"
void Mundo::inicializar() {
	id = rand();
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
	 diaM = -1, mesM = -1, anoM = -1;
	cout << "informe o dia de hoje" << endl;
	cin >> diaM >> mesM >> anoM;
	Simao.calcu_idade(diaM, mesM, anoM);
	Einstein.calcu_idade(diaM, mesM, anoM);
	Newton.calcu_idade(diaM, mesM, anoM);
	Simao.print_idade();
	Einstein.print_idade();
	Newton.print_idade();
}
void Mundo::informe_trabalho() {
	trabalho_universidade();
	trabalho_departamento();
}
void Mundo:: execudar() {
	srand((unsigned int)time(NULL));
	/*informe_dia();
	composicao_universidade();
	informe_trabalho();
	informacao_aluno();
	diciplinas_departamento();
	diciplina_aluno();*/
	menu();
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
void Mundo::executa_tudo() {
	ElemDiciplina* temDi = NULL;
	ElemDepartamento* temDep = NULL;
	ElemUniversidade* temUni = NULL;
	cout << "tudo que está cadastrado no sistema é" << endl;
	for (temUni = LUniversidade.get_cabecaUni(); temUni != NULL; temUni = temUni->universidadeG_proximo()) {
		cout << temUni->get_universidade()->qual_uni() << ":" << endl;
		for (temDep = LDepartamento.get_cabecaDep(); temDep != NULL; temDep = temDep->departamentoG_proximo()) {
			cout << "  " << temDep->get_departamento()->qual_departamento() << ":" << endl;
			for (temDi = LDiciplina.get_cabecaD(); temDi != NULL; temDi = temDi->diciplinaG_proximo())
				cout << "    " << temDi->posicao_diciplina()->get_nome() << endl;
			}
	}
	system("Pause");
}
void Mundo::diciplinaCadastro() {
	int salva = 0;
	char nomeUniver[50], nomeDerpa[50], nomeDici[50];
	Universidade* iUni = NULL;
	Departamento* iDep = NULL;
	Diciplina* iDi = NULL;
	cout << "insira o nome da universidade" << endl;
	cin >> nomeUniver;
	iUni = LUniversidade.buscaN_universidade(nomeUniver);
	if (iUni != NULL) {
		cout << "insira o nome do departamento" << endl;
		cin >> nomeDerpa;
		iDep = LDepartamento.buscaN_departamento(nomeDerpa);
		if (iDep != NULL) {
			cout << "insira o nome do diciplina" << endl;
			cin >> nomeDici;
			cout << "deseja salvar, digite 1 para confimar" << endl;
			cin >> salva;
			iDi = new Diciplina;
			LDiciplina.inclue_diciplina(iDi);
			if (salva == 1) {
				FILE* Fdiciplina = NULL;
				if (fopen_s(&Fdiciplina, "diciplina.bin", "wb") == 0) {
					fwrite(iDi, sizeof(*iDi), 1, Fdiciplina);
					fclose(Fdiciplina);
				}
			}
		}
	}
}
void Mundo::diciplnaExe() {
	LDiciplina.print_diciplina();
	system("Pause");
}
void Mundo::departamentoCadastro() {
	int salva = 0;
	char nomeUniver[50], nomeDerpa[50];
	Universidade* iUni = NULL;
	Departamento* iDep = NULL;
	cout << "insira o nome da universidade" << endl;
	cin >> nomeUniver;
	iUni = LUniversidade.buscaN_universidade(nomeUniver);
	if (iUni != NULL) {
		cout << "insira o nome do departamento" << endl;
		cin >> nomeDerpa;
		cout << "deseja salvar, digite 1 para confimar" << endl;
		cin >> salva;
		iDep = new Departamento;
		LDepartamento.inclue_departamento(iDep);
		if (salva == 1) {
			FILE* Fdepartamento = NULL;
			if (fopen_s(&Fdepartamento, "diciplina.bin", "wb") == 0) {
				fwrite(iDep, sizeof(*iDep), 1, Fdepartamento);
				fclose(Fdepartamento);
			}
		}
	}
}
void Mundo::departamentoExe() {
	LDepartamento.print_departamento();
	system("Pause");
}
void Mundo::universidadeCadastro() {
	int salva = 0;
	char nomeUniver[50];
	Universidade* iUni = NULL;
	cout << "insira o nome da universidade" << endl;
	cin >> nomeUniver;
	cout << "deseja salvar, digite 1 para confimar" << endl;
	cin >> salva;
	iUni = new Universidade;
	iUni->sua_uni(nomeUniver);
	LUniversidade.inclue_universidade(iUni);
	if (salva == 1) {
		FILE* Funiversidade = NULL;
		if (fopen_s(&Funiversidade, "diciplina.bin", "wb") == 0) {
			fwrite(iUni, sizeof(*iUni), 1, Funiversidade);
			fclose(Funiversidade);
		}
	}
}
void Mundo::universidadeExe() {
	LUniversidade.print_universidade();
	system("Pause");
}
void Mundo::menuCadastro() {
	int opcao = -1;
	while (opcao != 4) {
		system("cls");
		cout << "o que deseja cadastrar?" << endl;
		cout << "digite 1 para cadastrar uma diciplina" << endl;
		cout << "digite 2 para cadastrar um departamento" << endl;
		cout << "digite 3 para cadastrar uma universidade" << endl;
		cout << "digite 4 para voltar" << endl;
		cin >> opcao;
		switch (opcao) {
		case 1: { diciplinaCadastro(); }
			break;
		case 2: { departamentoCadastro(); }
			break;
		case 3: { universidadeCadastro(); }
			break;
		case 4: { cout << "voltando para o menu pricipal..." << endl; }
			break;
		default: { cout << "erro no menu de cadastro"<< endl; 
					system("Pause");
		}
		}
	}
}
void Mundo::menuExe() {
	int opcao = -1;
	while (opcao != 5) {
		system("cls");
		cout << "digite 1 para printar as diciplinas de um departamento" << endl;
		cout << "digite 2 para printar os departamentos de uma universidade" << endl;
		cout << "digite 3 para printar as universidades cadastradas" << endl;
		cout << "digite 4 para printar tudo que estar cadastrado" << endl;
		cout << "digite 5 para voltar para o menu principal" << endl;
		cin >> opcao;
		switch (opcao) {
			case 1: { diciplnaExe(); }
				break;
			case 2: { departamentoExe(); }
				break;
			case 3: { universidadeExe(); }
				break;
			case 4: { executa_tudo(); }
				break;
			case 5: { cout << "voltando pro menu pricipal..."; }
				break;
			default: {
				cout << "erro no menu executavel" << endl;
				system("Pause");
			}
		}
	}
}
void Mundo::menu() {
	int opcao = -1;
	while (opcao != 3) {
		system("cls");
		cout << "deseja cadastrar ou mostra algo" << endl;
		cout << "digite 1 para cadastrar uma diciplina, departamento ou universidade" << endl;
		cout << "degite 2 para printar na dela as diciplinas, departamentos e universidades" << endl;
		cout << "digite 3 para sair do sistema" << endl;
		cin >> opcao;
		switch (opcao) {
		case 1: { menuCadastro(); }
			break;
		case 2: {  menuExe();}
			break;
		case 3: { cout << "sistema fechado" << endl; }
			break;

		default:{
				cout << "erro no menu" << endl;
				system("Pause");
			}
		}
	}
}