#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <mutex>
#include <iterator>
#include <chrono>
#include <iomanip>
#include <fileapi.h>

typedef struct
{
	HANDLE  hePipeStart;
	HANDLE  hePipeReply;

	HANDLE  child_in;
	HANDLE  parent_out;
	HANDLE  child_out;
	HANDLE  parent_in;
	
	char    read[1024];     
	char    send[1024];    
}TheadParms;

namespace Practice3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::IO;
	using namespace System::Threading;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			DateTime datetime = DateTime::Now;
			this->label4->Text = "Дата: " + datetime.ToString(); // запись времени и даты в label 4 на форму
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;

	protected:


	private: System::Windows::Forms::TextBox^ textBox2;



	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: Thread^ t1;
	private: Thread^ t2; // создание потоков
	private: System::Windows::Forms::Button^ File1ShowButton;
	private: System::Windows::Forms::Button^ SortFileButton;
	private: System::Windows::Forms::Button^ File1CreateButton;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label6;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->File1ShowButton = (gcnew System::Windows::Forms::Button());
			this->SortFileButton = (gcnew System::Windows::Forms::Button());
			this->File1CreateButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(94, 290);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(253, 179);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::White;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(413, 289);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(308, 225);
			this->textBox2->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(89, 694);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(219, 25);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Филисова Т.Ю., 500 гр";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(408, 694);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 25);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Дата:";
			// 
			// File1ShowButton
			// 
			this->File1ShowButton->BackColor = System::Drawing::Color::Transparent;
			this->File1ShowButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->File1ShowButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->File1ShowButton->Location = System::Drawing::Point(126, 210);
			this->File1ShowButton->Margin = System::Windows::Forms::Padding(2);
			this->File1ShowButton->Name = L"File1ShowButton";
			this->File1ShowButton->Size = System::Drawing::Size(182, 60);
			this->File1ShowButton->TabIndex = 7;
			this->File1ShowButton->Text = L"Отобразить исходный файл";
			this->File1ShowButton->UseVisualStyleBackColor = false;
			this->File1ShowButton->Click += gcnew System::EventHandler(this, &MyForm::File1ShowButton_Click);
			// 
			// SortFileButton
			// 
			this->SortFileButton->BackColor = System::Drawing::Color::Transparent;
			this->SortFileButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SortFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SortFileButton->Location = System::Drawing::Point(474, 210);
			this->SortFileButton->Margin = System::Windows::Forms::Padding(2);
			this->SortFileButton->Name = L"SortFileButton";
			this->SortFileButton->Size = System::Drawing::Size(205, 60);
			this->SortFileButton->TabIndex = 5;
			this->SortFileButton->Text = L"Поменять разрешение файла на .csv";
			this->SortFileButton->UseVisualStyleBackColor = false;
			this->SortFileButton->Click += gcnew System::EventHandler(this, &MyForm::SortFileButton_Click);
			// 
			// File1CreateButton
			// 
			this->File1CreateButton->BackColor = System::Drawing::Color::Transparent;
			this->File1CreateButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->File1CreateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->File1CreateButton->Location = System::Drawing::Point(709, 1);
			this->File1CreateButton->Margin = System::Windows::Forms::Padding(2);
			this->File1CreateButton->Name = L"File1CreateButton";
			this->File1CreateButton->Size = System::Drawing::Size(12, 12);
			this->File1CreateButton->TabIndex = 1;
			this->File1CreateButton->Text = L"Заполнить исходный файл буквами (если он пустой)";
			this->File1CreateButton->UseVisualStyleBackColor = false;
			this->File1CreateButton->Click += gcnew System::EventHandler(this, &MyForm::File1CreateButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(235, 11);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(132, 25);
			this->label1->TabIndex = 11;
			this->label1->Text = L"авторизация";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(120, 56);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 25);
			this->label2->TabIndex = 12;
			this->label2->Text = L"логин";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(120, 96);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(77, 25);
			this->label5->TabIndex = 13;
			this->label5->Text = L"пароль";
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::White;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(231, 55);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(272, 25);
			this->textBox3->TabIndex = 14;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::White;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(231, 96);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(272, 25);
			this->textBox4->TabIndex = 15;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(125, 141);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(379, 40);
			this->button1->TabIndex = 16;
			this->button1->Text = L"авторизоваться";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(380, 611);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(110, 29);
			this->button2->TabIndex = 17;
			this->button2->Text = L"Сортировка";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::Color::White;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(94, 505);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(253, 148);
			this->label6->TabIndex = 18;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->ClientSize = System::Drawing::Size(767, 769);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->SortFileButton);
			this->Controls->Add(this->File1CreateButton);
			this->Controls->Add(this->File1ShowButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		string ExecuteExternalFile(string csExeName, string csArguments)
		{
			string csExecute;
			csExecute = csExeName + " " + csArguments;

			SECURITY_ATTRIBUTES secattr;
			ZeroMemory(&secattr, sizeof(secattr));
			secattr.nLength = sizeof(secattr);
			secattr.bInheritHandle = TRUE;

			HANDLE rPipe, wPipe;

			//Create pipes to write and read data

			CreatePipe(&rPipe, &wPipe, &secattr, 0);
			//

			STARTUPINFO sInfo;
			ZeroMemory(&sInfo, sizeof(sInfo));
			PROCESS_INFORMATION pInfo;
			ZeroMemory(&pInfo, sizeof(pInfo));
			sInfo.cb = sizeof(sInfo);
			sInfo.dwFlags = STARTF_USESTDHANDLES;
			sInfo.hStdInput = NULL;
			sInfo.hStdOutput = wPipe;
			sInfo.hStdError = wPipe;

			//Create the process here.

			CreateProcess(0, (LPWSTR)csExecute.c_str(), 0, 0, TRUE, NORMAL_PRIORITY_CLASS | CREATE_NO_WINDOW, 0, 0, &sInfo, &pInfo);
			CloseHandle(wPipe);

			//now read the output pipe here.

			char buf[100];
			DWORD reDword;
			string m_csOutput, csTemp;
			BOOL res;
			do
			{
				res = ::ReadFile(rPipe, buf, 100, &reDword, 0);
				csTemp = buf;
				m_csOutput += csTemp;
			} while (res);
			return m_csOutput;
		}

	private: System::Void File1CreateButton_Click(System::Object^ sender, System::EventArgs^ e) { // кнопка для заполнения файла 100 буквами, если это не было сделано вручную
		srand(time(NULL));
		char letters[100];
		fstream file1; // создание объекта класса fstream 
		file1.open("pp.txt"); // связывание объекта класса fstream с файлом, который будет использоваться для операций ввода-вывода
		for (int i = 0; i < 100; i++)
		{
			letters[i] = (rand() % ('z' - 'a' + 1)) + 'a'; //присваиваем букве рандомное значение из алфавита
			file1 << letters[i]; // добавляем букву в файл
		}
		file1.close(); //закрываем файл
	}

	private: System::Void File1ShowButton_Click(System::Object^ sender, System::EventArgs^ e) { //кнопка для отображения содержимого 1-го файла (1.txt) в textbox1
		String^ file1Path = "pp.txt"; // создаем переменную для хранения пути к файлу
		try
		{
			String^ file = File::ReadAllText(file1Path, System::Text::Encoding::GetEncoding(1251)); //открываем файл
			textBox1->Text = file; //записываем содержимое файла в TextBox
		}
		catch (Exception^ e)
		{
			MessageBox::Show(this, "Файл не был открыт", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		/* авторизация пользователя */

		if (textBox4->Text->ToLower() == "12345" && textBox3->Text == "500") {
			MessageBox::Show("Успешно", "Авторизация", MessageBoxButtons::OK);
		}
		else {
			MessageBox::Show("Неверные логин или пароль", "Ошибка!!!", MessageBoxButtons::OK);
		}
	}

	private: System::Void SortFileButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ file1Path = "sort.csv"; // создаем переменную для хранения пути к файлу
		try
		{
			String^ file = File::ReadAllText(file1Path, System::Text::Encoding::GetEncoding(1251)); //открываем файл
			textBox2->Text = file; //записываем содержимое файла в TextBox
		}
		catch (Exception^ e)
		{
			MessageBox::Show(this, "Файл не был открыт", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}
		vector<char> myVector;

		string name = "sort.txt";

		ifstream fin;

		fin.open(name);

		if (!fin.is_open())
		{
			cout << "Ошибка открытия файла!" << endl;
		}
		else
		{
			cout << "Файл открыт" << endl;
		}

		static char  buff[1024][1024];
		int i = 0;

		cout << "\n";


		cout << "\nНачальный вид файла\n\n";
		while (!fin.eof())
		{
			fin.getline(buff[i], sizeof(buff));
			cout << buff[i] << "\n";
			++i;
		}

		fin.close();

		fin.open(name);

		char ch;
		int numb;
		int numb2;
		numb = 0;
		numb2 = 1;

		ofstream fout;
		fout.open("sort.csv");

		cout << "\n\n";
		cout << "\nVector \n\n";
		while (fin.get(ch))
		{
			myVector.push_back(ch);
			numb++;


			cout << ch;
			fout << ch;
			if (numb)
			{
				fout << ";";
			}
			if (numb == 10)
			{
				fout << "\n";
				numb = 0;
				numb2++;
			}
		}
		fout.close();
		system("start sort.csv");
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		string name = "sort.txt";
		ofstream fout;
		fout.open("sort.txt");

		setlocale(LC_ALL, "rus");
		string path = "pp.txt";
		fstream file;
		string pathSort = "sort.txt";
		ifstream fin;
		file.open(path, fstream::in | fstream::out | fstream::app);
		string s;
		string test;
		int i;
		cout << "100 русских букв из текстового файла: " << endl;
		while (getline(file, s)) {
			cout << s << endl;
			test = s;
			file.close();
		}

		char* Str;
		Str = new char[100];
		strcpy(Str, test.c_str());
		cout << endl << endl << "Отсортированный файл с помощью STL sort" << endl;
		vector<char> arra;
		for (i = 0; i < 100; i++) {
			arra.push_back(Str[i]);
		}
		sort(arra.begin(), arra.end());
		char sr[100];
		int f = 0;
		for (auto element : arra)
		{
			sr[f] = element;
			f++;
		}
		cout << sr;
		fout << sr;
		string t = sr;
		String^ str = gcnew String(t.c_str());
		label6->Text = str;

		fout.close();
	};
	};
}
